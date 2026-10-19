// bbport: force-included into every C++ file of the MinGW build (gpu/CMakeLists.txt).
// Newer libc++ headers (MSYS2 clang 23) no longer include these transitively; the vendored
// code (FidelityFX SDK, sirit, shadPS4) relied on that for std::abort, _countof, swprintf_s,
// placement new and the math functions.
#pragma once
// Before any C runtime header, as in platform/win32/include/bbport_win32.h (force-included
// after this one): a 64-bit off_t in every file, or mmap()'s offset differs between the C
// callers and posix_memory.cpp and offsets past 2 GiB come out sign-extended.
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <cmath>
#include <new>
