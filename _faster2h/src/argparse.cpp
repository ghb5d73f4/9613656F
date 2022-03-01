/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- file: argparse.h -*-
 -*- author: G.Henning -*-
 -*- copyright: GH / IPHC (2013) -*-
 -*- date:  Sept 26 2013 -*-
 -*- purpose: Parse arguments from command line -*-
**/

/* includes */
#include "argparse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ParseFlag(const int argc,
		    const char* argv[],
		    const char* flag)
{
  /* 
     Returns 1 if "flag" is in argv
   */
  for (int n =0 ; n<argc; n++)
    if (strcmp(argv[n], flag)==0)
      return 1;
  return 0;
}

const int ParseInt(const int argc,
		   const char* argv[],
		   const char* arg,
		   const int orelse)
{
  /* 
     Returns the value parsed in arg (with sscanf)
     Or orelse if none was found
  */
  int retval;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, &retval)==1)
      return (const int) retval;
  return orelse;
}

const float ParseFloat(const int argc,
		       const char* argv[],
		       const char* arg,
		       const float orelse)
{
  /* 
     Returns the value parsed in arg (with sscanf)
     Or orelse if none was found
  */
  float retval;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, &retval)==1)
      return (const float) retval;
  return orelse;
}

const char* ParseString(const int argc,
			const char* argv[],
			const char* arg,
			const char* orelse)
{
  /* 
     Returns the value parsed in arg (with sscanf)
     Or orelse if none was found
  */
  char *retval;
  retval = (char*)malloc(1024*sizeof(char));
  if (retval==NULL)
    return orelse;
  for (int n =0 ; n<argc; n++)
    if (sscanf(argv[n], arg, retval)==1)
      return retval;
  return orelse;
}

