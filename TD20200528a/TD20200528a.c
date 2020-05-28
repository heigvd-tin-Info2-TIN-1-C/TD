/**
  \file      TD20200528a.c
  \brief     pile LIFO
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200528a.h"

int main(int argc, char const *argv[])
{
  sList lifo;
  elem e;

  initPile(&lifo);
  displayList(&lifo);
  
  push(&lifo, (elem){.row=10, .col=11});
  push(&lifo, (elem){.row=10, .col=12});
  push(&lifo, (elem){.row=10, .col=13});
  push(&lifo, (elem){.row=10, .col=14});
  push(&lifo, (elem){.row=10, .col=15});
  push(&lifo, (elem){.row=10, .col=16});
  push(&lifo, (elem){.row=10, .col=17});
  push(&lifo, (elem){.row=10, .col=18});
  push(&lifo, (elem){.row=10, .col=19});
  push(&lifo, (elem){.row=10, .col=20});
  push(&lifo, (elem){.row=10, .col=21});
  push(&lifo, (elem){.row=10, .col=22});
  displayList(&lifo);

  e = pop(&lifo);
  displayElem(e);
  puts("");
  displayList(&lifo);
  terminateList(&lifo);
  return 0;
}

