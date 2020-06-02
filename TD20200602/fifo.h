/**
 * \file fifo.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to fifo
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

// preprocessor symbols

// preprocessor macros

// enumerated types

// structured types

// unions types

// functions prototypes
void initFifo(sList *l);
void terminateFifo(sList *l);
void push(sList *l, elem e);
elem pop(sList *l);
void displayFifo(sList *l);

// externals

// end of list.h
