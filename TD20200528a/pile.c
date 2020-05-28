/**
  \file      list.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "pile.h"

void initPile(sList *l) {
    initList(l);
    return;
}

void terminatePile(sList *l) {
    terminateList(l);
    return;
}

void push(sList *l, elem e) {
    insertElem(l, e, -1);
    return;
}

elem pop(sList *l) {
    
    elem e;
    e = getElem(l, -1);
    removeElem(l, l->numElements-1);
    return e;
}
