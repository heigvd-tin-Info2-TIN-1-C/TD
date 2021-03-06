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

#ifdef ELEM_DOUBLE
  //insertElem(&l, 3.14, 10);
  insertElem(&l, 3.14, -1);
  displayList(&l);
  insertElem(&l, 9.81, 0);
  displayList(&l);
  insertElem(&l, 42.0, 1);
  displayList(&l);
#endif

#ifdef ELEM_INT
  insertElem(&l, 3, -1);
  displayList(&l);
  insertElem(&l, 9, 0);
  displayList(&l);
  insertElem(&l, 42, 1);
  displayList(&l);

  printf("element 42 found at pos %d\n", searchElem(&l, 42));
  printf("element 555 found at pos %d\n", searchElem(&l, 555));

#endif

#ifdef ELEM_POINT2D
  elem p1 = {1, 2};
  elem p2 = {10, 20};
  elem p3 = {31, 32};
  int32_t pos = -1;

  insertElem(&l, p1, -1);
  displayList(&l);
  insertElem(&l, p2, -1);
  displayList(&l);
  insertElem(&l, p3, -1);
  displayList(&l);

  // search for p2 in l
  pos = searchElem(&l, p2);
  printf("pos=%d\n", pos);

  removeElem(&l,pos);
  displayList(&l);


#endif

  return 0;
}


//////////////
/*
add a new type int32_t as element of the list.   
#define ELEM_INT
update displayElem and main.
15:57
*/













int mainAllTypes(int argc, char const *argv[])
{
  sList l;
  initList(&l);
  displayList(&l);
#ifdef ELEM_DOUBLE
  insertElem(&l, 1., 0);
  displayList(&l);
  insertElem(&l, 2., 0);
  displayList(&l);
  insertElem(&l, 3., 0);
  displayList(&l);
  insertElem(&l, 4., -1);
  displayList(&l);
  insertElem(&l, 5., -1);
  displayList(&l);
  insertElem(&l, 6., 2);
  displayList(&l);

  elem e = 1.0;
  printf("Found elem at pos %d\n", searchElem(&l, e));
#endif
#ifdef ELEM_INT32
  insertElem(&l, 1, 0);
  displayList(&l);
  insertElem(&l, 2, 0);
  displayList(&l);
  insertElem(&l, 3, 0);
  displayList(&l);
  insertElem(&l, 4, -1);
  displayList(&l);
  insertElem(&l, 5, -1);
  displayList(&l);
  insertElem(&l, 6, 2);
  displayList(&l);

  elem e = 6;
  printf("Found elem at pos %d\n", searchElem(&l, e));
#endif

#ifdef ELEM_POINT2D
  elem p1 = {1, 2};
  elem p2 = {12, 22};
  elem p3 = {10, 10};
  insertElem(&l, p1, 0);
  displayList(&l);
  insertElem(&l, p2, -1);
  displayList(&l);
  insertElem(&l, p3, -1);
  displayList(&l);

  elem e = {10, 10};
  printf("Found elem at pos %d\n", searchElem(&l, e));
#endif

  return 0;
}
