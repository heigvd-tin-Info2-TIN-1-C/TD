/**
 * \file list.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to list
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "listType.h"

// preprocessor symbols
#define MAX_LIST_SIZE (100)

// preprocessor macros

// enumerated types

// structured types
typedef struct {
    uint32_t numElements;
    elem element[MAX_LIST_SIZE];
} sList;

// unions types

// functions prototypes
void initList(sList *l);
uint32_t getNumElem(sList *l);
bool isListFull(sList *l);
bool isListEmpty(sList *l);
void insertElem(sList *l, elem e, int32_t pos);
void displayList(sList *l);

// externals

// end of list.h


















int32_t searchElem(sList *l, elem e);
