/**
  \file      TD20200428.c
  \brief     getoptions
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200428.h"

eArgCode processArg(int argc, char *argv[])
{

  eArgCode arg = 0;

  int o = 0;
  int option_index = 0;

  struct option long_options[] = // struct option is defined in <getopt.h>
      {
          {"help", no_argument, 0, 'h'},
          {"file", required_argument, 0, 'f'},
          {"gravity", required_argument, 0, 'g'},
          {0, 0, 0, 0}};
  do
  {

    o = getopt_long(argc, argv, "f:g:h", long_options, &option_index);
    //printf("o=%d [%c]\n", o, o);

    switch (o)
    {
    case 'h': // --help or -h

      // 00000000000000000000000000000010 (help)
      // 10000000000000000000000000000000 (OK)
      // --------------------------------
      // 10000000000000000000000000000010
      arg |= E_ARG_HELP + E_ARG_OK;
      break;

    case 'f': // --file="data.txt" or -f="data.txt" or  --file "data.-txt" or -f "data.txt"
      arg |= E_ARG_FILE + E_ARG_OK; // equ. to:      arg = arg | (E_ARG_FILE + E_ARG_OK);
      // backup the string filename
      break;

    case 'g': // --gravity=9.81
      arg |= E_ARG_GRAVITY + E_ARG_OK;
      // bakcup the real value gravity
      break;

    case -1: // end of processing
      break;

    default: // unknown option
      printf("Unknown option.\n");
      break;
    }

  } while (o != -1);
  return arg;
}

int main(int argc, char *argv[])
{
  uint32_t k = 0;

  eArgCode arg = 0;

  // display args
  printf("num args=%u\n", argc);
  for (k = 0; k < argc; k++)
  {
    printf("Arg n°%u : [%s]\n", k, argv[k]);
  }
  puts("-----------\n");

  arg = processArg(argc, argv);
  printf("arg=%04X\n", arg);
  return 0;
}

