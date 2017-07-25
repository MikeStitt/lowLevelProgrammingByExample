//  ------------------------------------------------------------------------------
/// @addtogroup scaffolding
///
/// @{
/// @file helpers.h
///
//
//  Copyright (c) 2017 Mike Stitt
//  ------------------------------------------------------------------------------

#ifndef __SCAFFOLDING_HELPERS_H
#define __SCAFFOLDING_HELPERS_H

#define WEAK __attribute__ ((weak))
#define INTERRUPT __attribute__((__interrupt__))
#define NAKED __attribute__( ( naked ) )

// @todo move these closer the memory map and linker scripts.

#define ISR_VECTOR_SECTION __attribute__ ((section(".isr_vector")))
#define RESET_STACK_SECTION __attribute__ ((section(".reset_stack")))


// calculate the number of elements in an array
//
// See http://stackoverflow.com/questions/1598773/is-there-a-standard-function-in-c-that-would-return-the-length-of-an-array/1598827#1598827
//
// Note that the macro uses a small trick of putting the array name in the
// index operator ('[]') instead of the 0 - this is done in case the
// macro is mistakenly used in C++ code with an item that overloads operator[]().
// The compiler will complain instead of giving a bad result.
//
// If a pointer is mistakenly passed as the argument, the compiler will complain
// in some cases - specifically if the pointer's size isn't evenly divisible by
// the size of the object the pointer points to. In that situation a divide-by-zero
// will cause the compiler to error out.
// That macro doesn't close the door on using it erroneously, but it comes close.
//

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#ifndef UNUSED
#define UNUSED(...) (void)(__VA_ARGS__)
#endif

//  ------------------------------------------------------------------------------
// DEFINED_AND_ONE tests if a macro is defined and is 1.
//
// usage:
//
// #undef SOME_MACRO
// if (DEFINED_AND_ONE(SOME_MACRO)) printf("This should not print.\n");
//
// #define SOME_MACRO
// if (DEFINED_AND_ONE(SOME_MACRO)) printf("This should not print.\n");
//
// #define SOME_MACRO 0
// if (DEFINED_AND_ONE(SOME_MACRO)) printf("This should not print.\n");
//
// #define SOME_MACRO 1
// if (DEFINED_AND_ONE(SOME_MACRO)) printf("This should print.\n");
//
//  ------------------------------------------------------------------------------

#define DEFINED_AND_ONE(name) DEFINED_AND_ONE_EVAL_(DEFINED_AND_ONE_DO_, name)
#define DEFINED_AND_ONE_EVAL_(macro, ...) macro(__VA_ARGS__)
#define DEFINED_AND_ONE_DO_(name) (#name[0] == '1' ? true : false)

#endif // __SCAFFOLDING_HELPERS_H

/// @}
