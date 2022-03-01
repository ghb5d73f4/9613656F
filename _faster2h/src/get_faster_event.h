/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : 2020 -*-
 -*- copyright: GH/IPHC 2020 -*-
 -*- purpose: get relevant infromation from faster event -*-
 */

#ifndef GET_FASTER_EVENT_H

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

//  fasterac includes
#include "fasterac/fasterac.h"
#include "fasterac/fast_data.h"
#include "fasterac/spectro.h"
#include "fasterac/utils.h"



// structure to hold the information 

class TFasterEvent
{
public:

    TFasterEvent() { alias=0; type=0; label=0; pileup=0; energy=0.0; clock = 0.0; } ;
    unsigned char  alias, type;
    unsigned short label, pileup;
    signed int energy;
    long double clock;
};


const TFasterEvent* get_faster_event(faster_data_p data);
#define GET_FASTER_EVENT_H
#endif

