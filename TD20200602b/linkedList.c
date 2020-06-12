/**
  \file      linkedList.c
  \brief     linkedList
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details   implementation
    
**/

#include "linkedList.h"

void initList(linkedList *l)
{
  l->first = NULL;
  l->last = NULL;
  l->numElem = 0;
}

elem *createElem(payload p)
{
  elem *e = calloc(1, sizeof(elem));
  if (e != NULL)
  {
    e->prev = NULL;
    e->next = NULL;
    memcpy(&(e->p), &p, sizeof(payload));
  }
  else
  {
    fprintf(stderr, "[createElem] error while allocating element.\n");
  }
  return e;
}

void displayElem(elem *e)
{
  printf("(%3d,%3d) ", e->p.row, e->p.col);
  return;
}

void displayList(linkedList *l)
{
  elem *e = l->first;
  while (e != NULL)
  {
    displayElem(e);
    e = e->next;
  }
  puts("");
  return;
}

void insertElem(linkedList *l, elem *e, int32_t pos)
{
  elem *prev = NULL;
  elem *next = NULL;
  if (l->numElem == 0)
  {
    l->first = l->last = e;
    l->numElem++;
  }
  else
  {
    if (pos == 0)
    {
      // update the new element
      e->prev = NULL;
      e->next = l->first;

      // update the future old first element
      l->first->prev = e;

      // update the list descriptor
      l->first = e;
      l->numElem++;
    }
    else if (pos == -1 || pos == l->numElem)
    {
      e->next = NULL;
      e->prev = l->last;
      l->last->next = e;
      l->last = e;
      l->numElem++;
    }
    else if (pos > 0 && pos < l->numElem)
    {
      prev = l->first;
      while (--pos)
      {
        prev = prev->next;
      }
      next = prev->next;
      prev->next = e;
      next->prev = e;
      e->next = next;
      e->prev = prev;
      l->numElem++;
    }
    else
    {
      fprintf(stderr, "[insertElem] bad position for insertion (%d).\n", pos);
    }
  }

  return;
}