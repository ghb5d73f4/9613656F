//printf("# [WRITING] \t writing valid channels \n");

// for (int n =1; n<_k_NDAQChannels; n++)
//   {
//     if (!theMapper->IsStart(n) && theMapper->IsDefined(n) && !theMapper->IsSync(n))
//       {
// 	if (flag_e_cal==1)
// 	  channel_e_all[n]->Write();
// 	if (flag_e_uncal==1)
// 	  channel_e_all_uncal[n]->Write();
// 	// channel_e_clean[n]->Write();
// 	// channel_e_pu[n]->Write();
// 	// channel_e_all_uncal[n]->Write();
// 	// channel_e_clean_uncal[n]->Write();
// 	// channel_e_gated_all[n]->Write();
// 	// channel_e_gated_clean[n]->Write();
	
// 	// channel_delay_all[n]->Write();
// 	// channel_delay_clean[n]->Write();
// 	// channel_delay_pu[n]->Write();
// 	// channel_delay_all_uncal[n]->Write();
// 	// channel_delay_clean_uncal[n]->Write();
// 	// channel_delay_gated_all[n]->Write();
// 	// channel_delay_gated_clean[n]->Write();

// 	// channel_all[n]->Write();
// 	// channel_clean[n]->Write();
// 	// channel_gated[n]->Write();
// 	// channel_gated_clean[n]->Write();
// 	// channel_pu[n]->Write();
// 	// channel_uncal[n]->Write();

//       }
//   }

// //printf("# [WRITING] \t writing general histograms \n");
// channel_distribution_all->Write();
// channel_distribution_clean->Write();
// channel_distribution_pu->Write();
// timestamp_distribution_all->Write();
// timestamp_distribution_clean->Write();
// timestamp_channel->Write();
// delta_timestamp->Write();
// n_evt_per_ts->Write();
// coincidence_hitpattern->Write();
// coincidence_positive_negative_hitpattern->Write();
// if (flag_single_evt_energy_cal==1)
//   single_event_energy_cal->Write();
// if (flag_sum_energy_cal)
//   sum_energy_in_ts_cal->Write();
