#pragma once

#ifdef __clang__
#define PACKED_STRUCT( __Declaration__ ) __Declaration__ __attribute__((__packed__))

// These must be used for packed structs having :: and similar things in it.
#define PACKED_STRUCT_BEGIN
#define PACKED_STRUCT_END __attribute__((__packed__))
#endif

#ifdef _MSC_VER
#define PACKED_STRUCT( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )

// These must be used for packed structs having :: and similar things in it.
#define PACKED_STRUCT_BEGIN __pragma(pack(push, 1))
#define PACKED_STRUCT_END __pragma(pack(pop))
#endif