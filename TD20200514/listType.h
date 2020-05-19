/**
 * \file listType.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to list
 */

#pragma once

#include <stdint.h>

// preprocessor symbols
//#define ELEM_DOUBLE
//#define ELEM_POINT2D
#define ELEM_INT

// preprocessor macros

// enumerated types

// structured types

#ifdef ELEM_DOUBLE
typedef double elem; // create the 'elem' type, based on the 'double' type
#endif

#ifdef ELEM_INT
typedef int32_t elem; // create the 'elem' type, based on the 'int32_t' type
#endif

#ifdef ELEM_POINT2D
typedef struct
{
    int32_t row;
    int32_t col;
} elem; // create the 'elem' type, based on a '2D point' type
#endif
// unions types

// functions prototypes

// externals

// end of listType.h
