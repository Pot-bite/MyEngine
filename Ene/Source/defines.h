#pragma once




typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef int b32;
typedef char b8;


#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT Static_assert
#else 
#define STATAIC_ASSERT static_assert
#endif 

STATAIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte");
STATAIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 byte");
STATAIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 byte");
STATAIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 byte");

STATAIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATAIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 byte");
STATAIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 byte");
STATAIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 byte");

STATAIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 byte");
STATAIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 byte");

#define TRUE 1
#define FALSE 0
//Detecting of Platform
#if defined(WIN32) || (_WIN32) || defined(__WIN32__) 
#define KPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif

#elif defined(__linux__) || defined(__gnu__linux__)
//Linux OS
#define KPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
//catch anything not caught by above
#define KPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
//posix
#define KPLATFORM_POSIX 1
#elif __APPLE__
//Apple platforms
#define KPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
//ios simulator
#define KPLATFORM_IOS 1
#define KPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define KPLATFORM_IOS 1
//IOS device
#elif TARGET_OS_MAC
//other kinds of mac os
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform"
#endif

#ifdef KEXPORT
//Export
#ifdef _MSC_VER
#define KAPI __declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default"))) 
#endif
#else
//imports
#ifdef _MSC_VER
#define KAPI_declspec(dllimport)
#else
#define KAPI
#endif 
#endif