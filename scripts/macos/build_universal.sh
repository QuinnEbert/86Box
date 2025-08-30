#!/usr/bin/env bash
set -euo pipefail

# Universal Qt app bundling via two-slice builds + lipo
# Usage: run from repo root. Customize env vars if needed.

QT_VARIANT="qt5"    # qt5 or qt6

ARM_BUILD="build-xcode-${QT_VARIANT}-arm64"
X64_BUILD="build-xcode-${QT_VARIANT}-x86_64"
UNIV_OUT="build-xcode-${QT_VARIANT}-universal"

# Prefixes (adjust if using non-standard locations)
ARM_QT5_ROOT=${ARM_QT5_ROOT:-"$(brew --prefix qt@5)"}
ARM_OPENAL_ROOT=${ARM_OPENAL_ROOT:-"$(brew --prefix openal-soft)"}
ARM_LIBSERIALPORT_ROOT=${ARM_LIBSERIALPORT_ROOT:-"$(brew --prefix libserialport)"}

X86_PREFIX=${X86_PREFIX:-"/usr/local"}  # Intel Homebrew root
X86_QT5_ROOT=${X86_QT5_ROOT:-"${X86_PREFIX}/opt/qt@5"}
X86_OPENAL_ROOT=${X86_OPENAL_ROOT:-"${X86_PREFIX}/opt/openal-soft"}
X86_LIBSERIALPORT_ROOT=${X86_LIBSERIALPORT_ROOT:-"${X86_PREFIX}/opt/libserialport"}

function status() { echo "[universal] $*"; }

function gen_build() {
  local builddir="$1"; shift
  local arch="$1"; shift
  local cmake_args=("$@")
  status "Configuring ${builddir} for ${arch}"
  cmake -G Xcode -S . -B "${builddir}" -D QT=on -D USE_QT6=OFF -D CMAKE_OSX_ARCHITECTURES="${arch}" "${cmake_args[@]}"
}

function xcode_install() {
  local builddir="$1"
  status "Building install for ${builddir} (Release)"
  xcodebuild -project "${builddir}/86Box.xcodeproj" -target install -configuration Release -quiet
}

function make_universal() {
  local arm_app="$1"; shift
  local x86_app="$1"; shift
  local out_app="$1"; shift

  status "Creating universal app at ${out_app}"
  rm -rf "${out_app}"
  rsync -a "${arm_app}/" "${out_app}/"

  # lipo all Mach-O files present in both trees
  while IFS= read -r -d '' f; do
    rel="${f#${arm_app}/}"
    other="${x86_app}/${rel}"
    out="${out_app}/${rel}"
    if [[ -f "${other}" ]]; then
      if file -b "${f}" | grep -q "Mach-O"; then
        status "lipo ${rel}"
        lipo -create "${f}" "${other}" -output "${out}.univ"
        mv "${out}.univ" "${out}"
      fi
    fi
  done < <(find "${arm_app}" -type f -print0)

  status "Universal app created: ${out_app}"
}

# Prepare dirs
mkdir -p "${ARM_BUILD}" "${X64_BUILD}" "${UNIV_OUT}"

# Configure + install arm64 slice
gen_build "${ARM_BUILD}" "arm64" \
  -D CMAKE_PREFIX_PATH="/opt/homebrew" \
  -D PKG_CONFIG_EXECUTABLE="$(brew --prefix)/bin/pkg-config" \
  -D Qt5_ROOT="${ARM_QT5_ROOT}" \
  -D Qt5LinguistTools_ROOT="${ARM_QT5_ROOT}" \
  -D OpenAL_ROOT="${ARM_OPENAL_ROOT}" \
  -D LIBSERIALPORT_ROOT="${ARM_LIBSERIALPORT_ROOT}" \
  -D CMAKE_INSTALL_PREFIX="${PWD}/${ARM_BUILD}/install"
xcode_install "${ARM_BUILD}"

# Configure + install x86_64 slice (Rosetta)
status "Configuring x86_64 slice using prefix ${X86_PREFIX}"
arch -x86_64 cmake -G Xcode -S . -B "${X64_BUILD}" -D QT=on -D USE_QT6=OFF \
  -D CMAKE_OSX_ARCHITECTURES="x86_64" \
  -D CMAKE_PREFIX_PATH="/usr/local" \
  -D PKG_CONFIG_EXECUTABLE="/usr/local/bin/pkg-config" \
  -D Qt5_ROOT="${X86_QT5_ROOT}" -D Qt5LinguistTools_ROOT="${X86_QT5_ROOT}" \
  -D OpenAL_ROOT="${X86_OPENAL_ROOT}" \
  -D LIBSERIALPORT_ROOT="${X86_LIBSERIALPORT_ROOT}" \
  -D CMAKE_INSTALL_PREFIX="${PWD}/${X64_BUILD}/install"
arch -x86_64 xcodebuild -project "${X64_BUILD}/86Box.xcodeproj" -target install -configuration Release -quiet

ARM_APP="${ARM_BUILD}/install/86Box.app"
X86_APP="${X64_BUILD}/install/86Box.app"
OUT_APP="${UNIV_OUT}/86Box.app"

if [[ ! -d "${ARM_APP}" ]] || [[ ! -d "${X86_APP}" ]]; then
  echo "Error: One or both app bundles missing. Check build logs." >&2
  exit 2
fi

make_universal "${ARM_APP}" "${X86_APP}" "${OUT_APP}"

status "DONE. Sign and notarize: ${OUT_APP}"
