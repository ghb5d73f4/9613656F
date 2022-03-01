// define the default binning quanitties for energy, time (raw, calibrated)
// reading all this from TConf
const int nbins_e_uncal = config->ReadInt("energy_uncal_nbins",30000);
const double min_e_uncal = config->ReadFloat("energy_uncal_xmin",0.0);
const double max_e_uncal = config->ReadFloat("energy_uncal_xmax",150000);

const int nbins_delay_uncal = config->ReadInt("delay_uncal_nbins", 1250);
const double min_delay_uncal = config->ReadFloat("delay_uncal_xmin", -1000.);
const double max_delay_uncal = config->ReadFloat("delay_uncal_xmax", 7000.);

const int flag_bidim = config->ReadFlag("spect_bidim");
const int nbins_e_lowres = config->ReadInt("energy_bidim_nbins", 1500);
const int nbins_delay_lowres = config->ReadInt("delay_bidim_nbins", 625);

/* General histograms */

THisto *channel_distribution_all = new THisto(theMapper->Size(),
					      0-.5, theMapper->Size()-.5);
THisto *channel_distribution_clean = new THisto(theMapper->Size(),
						0-.5, theMapper->Size()-.5);

//TH1I *timestamp_distribution_all = makeTH1I("timestamp_distribution_all", "Timestamp; [10 ns]",


// Defining channel per channel histogram


THisto **channel_e_all = new THisto*[NumberOfChannels];
THisto **channel_e_clean = new THisto*[NumberOfChannels];
THisto **channel_delay_all = new THisto*[NumberOfChannels];
THisto **channel_delay_clean = new THisto*[NumberOfChannels];

THisto2D **bidim_all = new THisto2D*[NumberOfChannels];
THisto2D **bidim_clean = new THisto2D*[NumberOfChannels];

for (int n = 0; n < NumberOfChannels; n++)
  {
    if (theMapper->KnowThisIndex(n) == 1)
      {
        channel_e_all[n] = new THisto(nbins_e_uncal,
                          min_e_uncal, max_e_uncal);
        channel_e_clean[n] = new THisto(nbins_e_uncal,
                        min_e_uncal, max_e_uncal);
        channel_delay_all[n] = new THisto(nbins_delay_uncal,
                          min_delay_uncal, max_delay_uncal);
        channel_delay_clean[n] = new THisto(nbins_delay_uncal,
                            min_delay_uncal, max_delay_uncal);
        bidim_all[n] = new THisto2D(nbins_delay_lowres, min_delay_uncal, max_delay_uncal,
                                    nbins_e_lowres, min_e_uncal, max_e_uncal);
        bidim_clean[n] = new THisto2D(nbins_delay_lowres, min_delay_uncal, max_delay_uncal,
            nbins_e_lowres, min_e_uncal, max_e_uncal);
    }
}

