/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : 2020 -*-
 -*- copyright: GH/IPHC 2020 -*-
 -*- purpose: get relevant infromation from faster event -*-
 */

#include "get_faster_event.h"

const TFasterEvent* get_faster_event(faster_data_p data)
{
    //std::cout << "get_faster_data : entry point" <<std::endl;
    TFasterEvent *ev = new TFasterEvent();
    //std::cout << "get_faster_data : data class instantiated" <<std::endl;
    ev->type = faster_data_type_alias(data);
	ev->label = faster_data_label (data);
    ev->clock = faster_data_hr_clock_ns(data);
	ev->energy = 0;
    ev->pileup=0;
    if (ev->type==62)
		{
        trapez_spectro         trapez_data;
		  faster_data_load(data, &trapez_data);
		  ev->energy = trapez_data.measure;
		  ev->pileup = trapez_data.pileup;
		}
	      else if (ev->type==61)
		{
              crrc4_spectro          crrc4_data;
		  faster_data_load(data, &crrc4_data);
		  ev->energy = crrc4_data.measure;
		  ev->pileup = crrc4_data.pileup; 
		}
    return (const TFasterEvent*) ev;
}