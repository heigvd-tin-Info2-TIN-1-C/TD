/**
  \file      TD20200602.c
  \brief     file FIFO
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200602.h"

int main(int argc, char const *argv[])
{
  sList fifo;
  elem e={0,0};

  initFifo(&fifo);

  displayFifo(&fifo);
  
  push(&fifo, (elem){.row=10, .col=11});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=12});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=13});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=14});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=15});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=16});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=17});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=18});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=19});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=20});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=21});
  displayFifo(&fifo);
  push(&fifo, (elem){.row=10, .col=22});
  displayFifo(&fifo);

  e = pop(&fifo);
  displayElem(e);
  puts("");
  displayFifo(&fifo);
  
  e = pop(&fifo);
  displayElem(e);
  puts("");
  displayFifo(&fifo);
  
  terminateFifo(&fifo);
  return 0;
}

