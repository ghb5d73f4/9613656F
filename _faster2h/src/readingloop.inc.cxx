/* START of reading loop */
Running=1;

unsigned short ServerReturn;
double FirstTimeStampEver = 0;
double LastTimeStampOfAllTimes = 0;
double PreviousTimeStamp = 0;
double DeltaTimestamp = 0 ;
double last_start_event_timestamp = 0;
double current_ts = 0.;
unsigned long int number_of_event_read = 0;


  /************/
  /*  FASTER  */
  /************/
  //  file reader
  faster_file_reader_p   reader;
  //  data
  faster_data_p          data;
unsigned char          alias, type;
unsigned short         label, pileup;
unsigned int index;
signed int energy;
long double clock_ns;
  //  group data
  faster_buffer_reader_p group_reader;
  char                   group_buffer [1500];
  unsigned short         lsize;
  faster_data_p          group_data;
  //  qdc tdc data  (from faster group)



reader = faster_file_reader_open (sourcefile);
cout << "# [LOOP] entering reading loop" << endl;
  // main loop
  while ( (data = faster_file_reader_next (reader)) != NULL &&
            number_of_event_read < maxnumevent)
    {
      //  read each data
      alias = faster_data_type_alias (data);
      PreviousTimeStamp = faster_data_hr_clock_ns(data);
      FirstTimeStampEver = (FirstTimeStampEver==0) ?  PreviousTimeStamp : FirstTimeStampEver;
      
      if (alias == GROUP_TYPE_ALIAS)
	{
          //cout << "# [inLOOP] [in-GROUP]" <<endl;
	  //  get group data
	  lsize = faster_data_load (data, group_buffer);
	  //  open group reader
	  group_reader = faster_buffer_reader_open (group_buffer, lsize);  
    // parsing thru the events...
	  while ((group_data = faster_buffer_reader_next (group_reader)) != NULL)
	    {  //  read data inside the group
          const TFasterEvent* ev = get_faster_event(group_data);
          if (theMapper->KnowThisChannel(ev->label)==0)
              continue;
	      index = theMapper->GetChannelIndex(ev->label);
	      DeltaTimestamp = ev->clock - PreviousTimeStamp ;
	      channel_distribution_all->Fill(index);
	      
	      channel_e_all[index]->Fill(ev->energy);
	      channel_delay_all[index]->Fill(DeltaTimestamp);
          bidim_all[index]->Fill(DeltaTimestamp, ev->energy);
	      if (ev->pileup==0)
		{
		  channel_distribution_clean->Fill(index);
		  channel_e_clean[index]->Fill(ev->energy);
		  channel_delay_clean[index]->Fill(DeltaTimestamp);
          bidim_clean[index]->Fill(DeltaTimestamp, ev->energy);
		}
	    } // end while in group
      faster_buffer_reader_close (group_reader);
	} //end if in group
      else
	{
	  const TFasterEvent* ev = get_faster_event(data);
          if (theMapper->KnowThisChannel(ev->label)==0)
              continue;
	   index = theMapper->GetChannelIndex(ev->label);
	   DeltaTimestamp = ev->clock - PreviousTimeStamp ;
       channel_distribution_all->Fill(index);
	      
	   channel_e_all[index]->Fill(ev->energy);
	   channel_delay_all[index]->Fill(DeltaTimestamp);
       bidim_all[index]->Fill(DeltaTimestamp, ev->energy);
	   if (ev->pileup==0)
		{
		  channel_distribution_clean->Fill(index);
		  channel_e_clean[index]->Fill(ev->energy);
		  channel_delay_clean[index]->Fill(DeltaTimestamp);
          bidim_clean[index]->Fill(DeltaTimestamp, ev->energy);
		}   
	}
      LastTimeStampOfAllTimes = (double) clock_ns;
      number_of_event_read++;
    } // end while

/* END of reading loop */
cout << "# [LOOP] exiting reading loop" << endl;