/**
  \file      TD20200428.c
  \brief     getoptions
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-04-21 13:41:24
  \details
    
**/

#include "TD20200428.h"

eArgCode processArg(int argc, char *argv[], sOptArg *opt)
{

  eArgCode arg = E_NO_ARG;

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
      arg &= ~E_NO_ARG;
      arg |= E_ARG_HELP + E_ARG_OK;
      break;

    case 'f': // --file="data.txt" or -f="data.txt" or  --file "data.-txt" or -f "data.txt"
      arg &= ~E_NO_ARG;
      arg |= E_ARG_FILE + E_ARG_OK; // equ. to:      arg = arg | (E_ARG_FILE + E_ARG_OK);
      // backup the string filename
      strcpy(opt->filename, optarg);

      break;

    case 'g': // --gravity=9.81
      arg &= ~E_NO_ARG;
      // bakcup the real value gravity
      if (1 == sscanf(optarg, "%lf", &opt->gravity)) // optarg="9.81"
      {
        arg |= E_ARG_GRAVITY + E_ARG_OK;
      }
      else
      {
        arg |= E_ARG_BAD_ARG;
      }

      break;

    case -1: // end of processing
      break;

    default: // unknown option
      arg |= E_ARG_BAD_ARG;
      printf("Unknown option.\n");
      break;
    }

  } while (o != -1);
  return arg;
}

void usage(void)
{
  puts("Usage:\n");
  puts("  ./app --help");
  puts("  ./app --file=filename");
  puts("  ./app --gravity=value\n");
  return;
}

int main(int argc, char *argv[])
{
  uint32_t k = 0;
  eReturnCode returnCode = E_RETURN_NO_ERROR;

  eArgCode arg = 0;
  sOptArg opt = {"", 0.};

  // display args
  printf("num args=%u\n", argc);
  for (k = 0; k < argc; k++)
  {
    printf("Arg n°%u : [%s]\n", k, argv[k]);
  }
  puts("-----------\n");

  arg = processArg(argc, argv, &opt);

  //printf("arg=%04X\n", arg);
  //printf("filename=[%s]\n", opt.filename);
  //printf("gravity=[%lf]\n", opt.gravity);

  if (arg & E_NO_ARG)
  {
    usage();
    returnCode = E_RETURN_NO_ARG;
  }
  else if (arg & E_ARG_HELP)
  {
    usage();
    returnCode = E_RETURN_NO_ERROR;
  }
  else if (arg & E_ARG_BAD_ARG)
  {
    returnCode = E_RETURN_BAD_ARG;
  }
  else
  { // all arg ar corrects
    if (arg & E_ARG_FILE)
    {
      printf("filename=[%s]\n", opt.filename);
      returnCode = E_RETURN_NO_ERROR;
    }
    if (arg & E_ARG_GRAVITY)
    {
      printf("gravity=[%lf]\n", opt.gravity);
      returnCode = E_RETURN_NO_ERROR;
    }
  }

  printf("returnCode=%d\n", returnCode);
  return returnCode;
}
