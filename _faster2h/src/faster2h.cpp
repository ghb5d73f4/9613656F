/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : June 6th, 2014 -*-
 -*- copyright: GH/IPHC 2014 -*-
 -*- purpose: sorted merged evt files -*-
 */


#include "faster2h.h"

int main (const int argc, const char* argv[])
{

  clock_t run_timing = clock();
  /** 
      Setting up SIGINT catching
   **/
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = ctrl_c_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);

  /* Parsing opptions for input */
  #include "parseflags.inc.cxx"
  /* creating all objects */
  #include "createengineobjects.inc.cxx"

  #include "createhisto.inc.cxx"  
    
  #include "readingloop.inc.cxx"

  #include "closingstatements.inc.cxx"  

  run_timing = clock()-run_timing;
  printf ("# Sorted in %.1f seconds.\n",((float)run_timing)/CLOCKS_PER_SEC);
}
