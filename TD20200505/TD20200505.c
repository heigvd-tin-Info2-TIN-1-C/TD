/**
  \file      TD20200505.c
  \brief     multiple file compilation
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200505.h"

int main(int argc, char const *argv[])
{
  sPoint p1 = {0., 0.};
  sPoint p2 = {0., 0.};

  // call the displayError function of the errorManager module
  displayError(E_NO_ERROR);

  p1.x = 1.;
  p1.y = 1.;

  p2 = rotate(p1, -45);

  pointDisplay("P1", p1);
  pointDisplay("P2", p2);

  return 0;
}
