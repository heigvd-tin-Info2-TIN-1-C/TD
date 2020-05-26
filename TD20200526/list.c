/**
  \file      list.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "list.h"

void initList(sList *l)
{

    l->numElements = 0;
    l->capacity = 0;
    l->element = (elem *)calloc(DEFAULT_LIST_SIZE, sizeof(elem));
    if(l->element) {
        l->capacity = DEFAULT_LIST_SIZE;
    }
    return;
}

uint32_t getNumElem(sList *l)
{

    return l->numElements;
}

bool isListFull(sList *l)
{

    return (l->numElements == l->capacity);
}

bool isListEmpty(sList *l)
{

    return (l->numElements == 0);
}

void insertElem(sList *l, elem e, int32_t pos)
{

    int32_t k = 0;
 /*    elem *newArea = NULL;
   if (isListFull(l))
    {
        newArea = (elem *)realloc(l->element, (l->capacity + EXTENSION_LIST_SIZE) * sizeof(elem));
        if(newArea) {
            l->element = newArea;
            l->capacity += EXTENSION_LIST_SIZE;
        }
    }
    */
    if (!isListFull(l))
    {
        if (pos == -1)
        {
            pos = l->numElements;
        }
        if (0 <= pos && pos <= l->numElements)
        {

            for (k = l->numElements - 1; k >= pos; k--)
            {
                l->element[k + 1] = l->element[k];
            }

            l->element[pos] = e;
            l->numElements++;
        }
        else
        {
            puts("[insertElem] Error, bad position for insertion.");
        }
    }
    else
    {
        puts("[insertElem] Error, the list is full.");
    }
}

void displayElem(elem e)
{
#ifdef ELEM_DOUBLE
    printf("%+6.3lf ", e);
#endif
#ifdef ELEM_INT
    printf("%+6d ", e);
#endif
#ifdef ELEM_POINT2D
    printf(" (%3d,%3d) ", e.row, e.col);
#endif

    return;
}

void displayList(sList *l)
{
    uint32_t k = 0;
    printf("n=%3d   ", l->numElements);
    for (k = 0; k < l->numElements; k++)
        displayElem(l->element[k]);
    puts("");
    return;
}

// return -1 if e not found in l
// return the index of e in l if found
int32_t searchElem(sList *l, elem e)
{
    int32_t pos = -1;
    bool found = false;
    uint32_t k = 0;

    while( k<l->numElements && !found) {

        if(0==memcmp(&e, &(l->element[k]), sizeof(elem) ))
        {
            found = true;
            pos = k;
        }

        k++;
    }

    return pos;
}


uint32_t removeElem(sList *l, uint32_t pos) {

    
    if (pos < l->numElements)
    {
#if 1
        memmove(&(l->element[pos]), &(l->element[pos + 1]), (l->numElements - pos - 1) * sizeof(elem));
#else
        for (k = pos + 1; k < l->numElements;k++) {
            l->element[k - 1] = l->element[k];
        }
#endif
        l->numElements--;
    }
    return l->numElements;
}