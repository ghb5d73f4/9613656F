
#include "fasterac/fast_data.h"

short faster_data_oscillo_nb_pts (faster_data_p data) {
   short lsize = 0;
   short nbpts = 0;
   if (faster_data_type_alias (data) == OSCILLO_TYPE_ALIAS) {
      lsize = faster_data_load_size (data);
      nbpts = (lsize - 28) / 2;
   }
   return nbpts;
}



double tref_conv_dt_ns  (int tdc) {
  return tdc * 7.8125e-3;              //        HR CLOCK LSB : 2.0 / 256 ns
}



double tref_get_tdc_sec (tref_tdc tref) {
  return tref_conv_dt_ns (tref.tdc) * 1.0e-9;
}


