/**
 * \file linkedList.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to linkedList
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "listType.h"

// preprocessor symbols

// preprocessor macros

// enumerated types

// structured types
typedef struct elem
{
  struct elem *prev;
  struct elem *next;
  payload p;
} elem;

typedef struct
{

  struct elem *first;
  struct elem *last;
  uint32_t numElem;

} linkedList;
// unions types

// functions prototypes
void initList(linkedList *l);
elem *createElem(payload p);
void displayList(linkedList *l);
void displayElem(elem *e);
void insertElem(linkedList *l, elem *e, int32_t pos);

// externals

// end of list.h
