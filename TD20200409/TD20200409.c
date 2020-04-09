/**
  \file      TD20200407.c
  \brief     preprocessing
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200409.h"

#define DISPLAY 0 // 1 or 0

void testConditionalCompilation(void) {

  const uint32_t kmin = 1;
  const uint32_t kmax = 10;

  uint32_t k = 0;
  uint32_t s = 0;

  s = 0;
  for (k = kmin; k <= kmax; k++)
  {
    s += k;
  
#if DISPLAY==1
    printf("iteration n°%3u : s = %3u\n", k, s);
    ça ne compilera pas
#endif
  }

  printf("s = %3u\n", s);

  return;
}



#define TEST_CASE 1  // 1,2,3
#define M 1

void testConditionalCompilation2(void) {

  double m1 = 0.;
  double p1 = 0.;
  double m2 = 0.;
  double p2 = 0.;

#if TEST_CASE==1 && M<2
  m1 = 0.5;
  p1 = 3.;
#elif TEST_CASE == 2
  m1 = 0.;
  p1 = 1.;
#elif  TEST_CASE==3
  m1 = 9.;
  p1 = 5.
#else
#error "BAD TEST_CASE VALUE"
#endif

  p2 = 0.;

  if(m1==0.) {
    printf("Error, m1 is nul.\n");
  } 
  else {
    m2 = -1 / m1;

    printf("Test case %d\n", TEST_CASE);
    printf("m1=%+6.3lf p1=%+6.3lf\n", m1, p1);
    printf("m2=%+6.3lf p2=%+6.3lf\n", m2, p2);

  }

  return;
}

uint32_t trianglePascal(uint32_t l,uint32_t c) {

  // condition de fin de récursivité
  if(c==0 || l==c)
    return 1;
  // récursivité elle-même
  else
    return trianglePascal(l - 1, c - 1) + trianglePascal(l - 1, c);
}


int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;

#if 0
    testConditionalCompilation();
#elif 0
    testConditionalCompilation2();
#elif 1
    uint32_t l = 9;
    uint32_t c = 3;
    printf("trianglePascal(%u,%u)=%u\n", l, c, trianglePascal(l, c));
#endif
    return returnCode;
}
