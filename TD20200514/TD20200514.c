/**
  \file      TD20200514.c
  \brief     table list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200514.h"

int main(int argc, char const *argv[])
{
  sList l;
  initList(&l);
  displayList(&l);
  insertElem(&l, 1, 0); displayList(&l);
  insertElem(&l, 2, 0); displayList(&l);
  insertElem(&l, 3, 0); displayList(&l);
  insertElem(&l, 4, -1); displayList(&l);
  insertElem(&l, 5, -1); displayList(&l);
  insertElem(&l, 6, 2); displayList(&l);
  
  return 0;
}
