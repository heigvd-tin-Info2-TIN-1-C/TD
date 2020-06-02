/**
  \file      linkedList.c
  \brief     linkedList
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "linkedList.h"


void initList(linkedList *l) {
  l->first = NULL;
  l->last = NULL;
  l->numElem = 0;
}


elem *createElem(payload p) {
  elem *e = calloc(1, sizeof(elem));
  if(e!=NULL) {
    e->prev = NULL;
    e->next = NULL;
    memcpy(&(e->p), &p, sizeof(payload));
  }
  else {
    fprintf(stderr, "[createElem] error while allocating element.\n");
  }
  return e;
}
