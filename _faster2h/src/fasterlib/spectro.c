#include "fasterac/spectro.h"

#define DELTA_T_LSB_NS 8.0   


double crrc4_spectro_delta_t_ns (crrc4_spectro data) {
  return data.delta_t * DELTA_T_LSB_NS;
}


double trapez_spectro_conv_dt_ns (int tdc) {
  return tdc * 0.03125;   //  sample 2.0 ns + 6bit tdc -> lsb = 2.0 / 2**6
}

