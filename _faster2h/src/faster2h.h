/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : June 6th, 2014 -*-
 -*- copyright: GH/IPHC 2014 -*-
 -*- purpose: sorted merged evt files -*-
 */

#ifndef MEVT_SORT_H


// My own classes
#include "TMapper.h"
#include "argparse.h"
#include "TConf.h"
#include "THisto.h"
#include "THisto2D.h"

// C++ includes
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>   
#include <libgen.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

//  fasterac includes
#include "fasterac/fasterac.h"
#include "fasterac/fast_data.h"
#include "fasterac/spectro.h"
#include "fasterac/utils.h"

#include "get_faster_event.h"

/* Ctrl-C catching */
short Running;

void ctrl_c_handler(int s){
  Running=0;
  cerr << "# Interrupted by Ctrl-C" << endl;
}
/* */

#define MEVT_SORT_H
#endif
