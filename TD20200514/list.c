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
    return;
}

uint32_t getNumElem(sList *l)
{

    return l->numElements;
}

bool isListFull(sList *l)
{

    return (l->numElements == MAX_LIST_SIZE);
}

bool isListEmpty(sList *l)
{

    return (l->numElements == 0);
}

void insertElem(sList *l, elem e, int32_t pos)
{

    int32_t k = 0;

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

int32_t searchElem(sList *l, elem e)
{
    int32_t pos = -1;
    bool found = false;
    uint32_t k = 0;

    while( k<l->numElements && !found) {

        if (l->element[k]==e) {
            found = true;
            pos = k;
        }

        k++;
    }

    return pos;
}
