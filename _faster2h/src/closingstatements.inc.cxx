cout << "# [SAVE] will rite histograms files" <<endl;

char buff[500];
sprintf(buff, "%s/channel_distribution_all.h1.txt", outputfile);
channel_distribution_all->SaveAs(buff);
sprintf(buff, "%s/channel_distribution_clean.h1.txt", outputfile);
channel_distribution_clean->SaveAs(buff);


for (int n =0; n<NumberOfChannels; n++)
  {
    sprintf(buff, "%s/%s.h1.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
    channel_e_all[n]->SaveAs(buff);
    
    sprintf(buff, "%s/%s_clean.h1.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
    channel_e_clean[n]->SaveAs(buff);

    sprintf(buff, "%s/%s-delay.h1.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
    channel_delay_all[n]->SaveAs(buff);

    sprintf(buff, "%s/%s-delay_clean.h1.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
    channel_delay_clean[n]->SaveAs(buff);

     sprintf(buff, "%s/%s.h2.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
     bidim_all[n]->SaveAs(buff);
    
    sprintf(buff, "%s/%s_clean.h2.txt", outputfile,
	    theMapper->GetChannelNameFromIndex(n));
     bidim_clean[n]->SaveAs(buff);
  }


printf("# %i events were read \n", number_of_event_read);
printf("# First Time was: %f ns \n", FirstTimeStampEver);
printf("# Last Time was: %f ns \n", PreviousTimeStamp);
printf("# Time difference between first and last events: %5.3f seconds \n", 
       (PreviousTimeStamp-FirstTimeStampEver)/1.0e9);

