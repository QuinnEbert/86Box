# Install script for directory: /Users/quinn/Sources/86box/src/qt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/PlugIns/platforms" TYPE FILE FILES "/opt/homebrew/opt/qt@6/share/qt/plugins/platforms/libqcocoa.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/PlugIns/styles" TYPE FILE FILES "/opt/homebrew/opt/qt@6/share/qt/plugins/styles/libqmacstyle.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/PlugIns/imageformats" TYPE FILE FILES "/opt/homebrew/opt/qt@6/share/qt/plugins/imageformats/libqico.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/PlugIns/imageformats" TYPE FILE FILES "/opt/homebrew/opt/qt@6/share/qt/plugins/imageformats/libqicns.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/Frameworks" TYPE FILE RENAME "libvdeplug.dylib" FILES "/opt/homebrew/Cellar/vde/2.3.3/lib/libvdeplug.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/86Box.app/Contents/Resources" TYPE FILE FILES "/Users/quinn/Sources/86box/build-qt/src/qt/qt.conf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
        include(BundleUtilities)
        get_filename_component(CMAKE_INSTALL_PREFIX_ABSOLUTE $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX} ABSOLUTE)
        fixup_bundle("${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app" "${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/PlugIns/platforms/libqcocoa.dylib;${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/PlugIns/styles/libqmacstyle.dylib;${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/PlugIns/imageformats/libqico.dylib;${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/PlugIns/imageformats/libqicns.dylib;${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/Frameworks/libvdeplug.dylib" "/opt/homebrew/opt/qt@6/bin;/opt/homebrew/opt/qt@6/lib;/opt/homebrew/opt/qt@6/lib/cmake/Qt6Widgets/../..")
        execute_process(
            COMMAND /usr/bin/install_name_tool -add_rpath "@executable_path/../Frameworks/"
            "${CMAKE_INSTALL_PREFIX_ABSOLUTE}/86Box.app/Contents/MacOS/86Box")
        
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/quinn/Sources/86box/build-qt/src/qt/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
