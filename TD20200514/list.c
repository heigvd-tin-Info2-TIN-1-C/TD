/**
  \file      list.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "list.h"

void initList(sList *l){

    l->numElements = 0;
    return;
}

uint32_t getNumElem(sList *l){

    return l->numElements;
}

bool isListFull(sList *l){

    return (l->numElements == MAX_LIST_SIZE);
}

bool isListEmpty(sList *l){
    
    return (l->numElements == 0);
}

void insertElem(sList *l, elem e, int32_t pos) {

}

void displayList(sList *l) {
        return;
}