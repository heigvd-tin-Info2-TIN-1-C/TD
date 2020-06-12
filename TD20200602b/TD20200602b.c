/**
  \file      TD20200602b.c
  \brief     linked list
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200602b.h"

int main(int argc, char const *argv[])
{
  linkedList l;
  elem *e;

  initList(&l);
  displayList(&l);

  e = createElem((payload){.row = 0, .col = 0});
  insertElem(&l, e, 0);
  displayList(&l); // (0,0)

  e = createElem((payload){.row = 1, .col = 1});
  insertElem(&l, e, 0);
  displayList(&l); // (1,1) (0,0)

  e = createElem((payload){.row = 2, .col = 2});
  insertElem(&l, e, 0);
  displayList(&l); // (2,2) (1,1) (0,0)

  e = createElem((payload){.row = 3, .col = 3});
  insertElem(&l, e, -1);
  displayList(&l); // (2,2) (1,1) (0,0) (3,3)

  e = createElem((payload){.row = 4, .col = 4});
  insertElem(&l, e, -1);
  displayList(&l); // (2,2) (1,1) (0,0) (3,3) (4,4)

  e = createElem((payload){.row = 5, .col = 5});
  insertElem(&l, e, 5);
  displayList(&l); // (2,2) (1,1) (0,0) (3,3) (4,4) (5,5)

  e = createElem((payload){.row = 6, .col = 6});
  insertElem(&l, e, 2);
  displayList(&l); // (2,2) (1,1) (6,6) (0,0) (3,3) (4,4) (5,5)

  e = createElem((payload){.row = 7, .col = 7});
  insertElem(&l, e, 6);
  displayList(&l); // (2,2) (1,1) (6,6) (0,0) (3,3) (4,4)(7,7) (5,5)

  e = createElem((payload){.row = 8, .col = 8});
  insertElem(&l, e, -6);
  displayList(&l); // (2,2) (1,1) (6,6) (0,0) (3,3) (4,4)(7,7) (5,5)
  insertElem(&l, e, 666);
  displayList(&l); // (2,2) (1,1) (6,6) (0,0) (3,3) (4,4)(7,7) (5,5)
  return 0;
}
