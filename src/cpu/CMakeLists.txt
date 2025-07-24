#
# 86Box    A hypervisor and IBM PC system emulator that specializes in
#          running old operating systems and software designed for IBM
#          PC systems and compatibles from 1981 through fairly recent
#          system designs based on the PCI bus.
#
#          This file is part of the 86Box distribution.
#
#          CMake build script.
#
# Authors: David Hrdlička, <hrdlickadavid@outlook.com>
#          Jasmine Iwanek, <jriwanek@gmail.com>
#
#          Copyright 2020-2021 David Hrdlička.
#          Copyright 2024      Jasmine Iwanek.
#

add_library(cpu OBJECT
    cpu.c
    cpu_table.c
    fpu.c x86.c
    808x.c
    386.c
    386_common.c
    386_dynarec.c
    x86_ops_mmx.c
    x86seg_common.c
    x86seg.c
    x86seg_2386.c
    x87.c
    x87_timings.c
    i8080.c
)

if(AMD_K5)
    target_compile_definitions(cpu PRIVATE USE_AMD_K5)

if(DYNAREC)
    add_library(ctk5 OBJECT codegen_timing_k5.c)
    target_link_libraries(86Box ctk5)
endif()

endif()

if(DYNAREC)
    target_sources(cpu PRIVATE 386_dynarec_ops.c)

    add_library(cgt OBJECT
        codegen_timing_486.c
        codegen_timing_686.c
        codegen_timing_common.c
        codegen_timing_k6.c
        codegen_timing_pentium.c
        codegen_timing_p6.c
        codegen_timing_winchip.c
        codegen_timing_winchip2.c
    )
endif()

if(NEW_DYNAREC)
    include(CheckCCompilerFlag)
    set(NDR_CFLAGS "")
    check_c_compiler_flag("-O3" NDR_HAVE_O3)
    if(NDR_HAVE_O3)
        string(APPEND NDR_CFLAGS " -O3")
    endif()
    check_c_compiler_flag("-march=native" NDR_HAVE_MARCH_NATIVE)
    if(NDR_HAVE_MARCH_NATIVE)
        string(APPEND NDR_CFLAGS " -march=native")
    endif()
    check_c_compiler_flag("-flto" NDR_HAVE_FLTO)
    if(NDR_HAVE_FLTO)
        string(APPEND NDR_CFLAGS " -flto")
    endif()
    set_source_files_properties(386_dynarec.c PROPERTIES COMPILE_FLAGS "${NDR_CFLAGS}")
endif()

add_subdirectory(softfloat3e)
target_link_libraries(86Box softfloat3e)
