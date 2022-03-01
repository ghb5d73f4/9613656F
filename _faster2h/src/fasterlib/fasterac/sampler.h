
//
//  Sampler CARAS data definitions
//



#ifndef SAMPLER_H
#define SAMPLER_H 1

#ifdef __cplusplus
extern "C" {
#endif


#include <string.h>
#include <stdio.h>

#include "fasterac/fasterac.h"


//  CONST

typedef enum {
  SAMPLER_DATA_TYPE_ALIAS    =  22,
  SAMPLER_COUNTER_TYPE_ALIAS =  23
} sampler_const;


static const char* SAMPLER_TYPE_NAME         = "SAMPLER";
static const char* SAMPLER_COUNTER_TYPE_NAME = "SAMPLER_COUNT";


//  DATA DEFINITIONS

typedef short* sampler_data;


typedef struct sampler_counter {
  unsigned trig : 32;
  unsigned calc : 32;
  unsigned sent : 32;
} sampler_counter;


//  DATA TO STRING (used by faster_disfast)

static inline void sampler_attributes_str (faster_data_p data, char* samp_str) {
  int          width_ns = faster_data_load_size (data);
  int          nb_pts   = width_ns / 2;
  sampler_data samp     = faster_data_load_p (data);
  sprintf (samp_str, "  width=%dns  nb_of_pts=%d   --   ", width_ns, nb_pts);
  if (nb_pts <= 10) {
    for (int i=0; i<nb_pts; i++) sprintf (samp_str, "%s%d  ", samp_str, samp [i]);
  } else {
    for (int i=0; i<10; i++)     sprintf (samp_str, "%s%d  ", samp_str, samp [i]);
                                 sprintf (samp_str, "%s ...",  samp_str);
  }
}


static inline void sampler_counter_attributes_str (faster_data_p data, char* count_str) {
   sampler_counter count;
   faster_data_load (data, &count);
   sprintf (count_str, "  trig=%d  calc=%d  sent=%d", count.trig, count.calc, count.sent);
}




#ifdef __cplusplus
}
#endif


#endif  // SAMPLER_H
