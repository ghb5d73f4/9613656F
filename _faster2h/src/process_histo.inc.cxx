
if (!theMapper->IsStart(theChannelToWrite->ChannelNumber) && 
    theMapper->IsDefined(theChannelToWrite->ChannelNumber))
  {

    channel_distribution_all->Fill(theChannelToWrite->ChannelNumber);
    timestamp_distribution_all->Fill(theChannelToWrite->Timestamp);
    timestamp_channel->Fill(theChannelToWrite->Timestamp,theChannelToWrite->ChannelNumber);

    if (!theMapper->IsSync(theChannelToWrite->ChannelNumber))
      {
	if (flag_e_cal==1)
	  channel_e_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
	if (flag_e_uncal==1)
	  channel_e_all_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawEnergy);
      }
  }
if (!theMapper->IsStart(theChannelToWrite->ChannelNumber) && 
    theMapper->IsDefined(theChannelToWrite->ChannelNumber) && 0 ) // hack for exploaration
  {
    /* ALL */
    channel_e_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
    channel_e_all_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawEnergy);
    channel_delay_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay);
    channel_delay_all_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawDelay);

    channel_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay, theChannelToWrite->Energy);
    channel_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawDelay, theChannelToWrite->RawEnergy);


    /* CLEAN */
    if (!theChannelToWrite->PileUp && !theChannelToWrite->OutOfRange)
      {
	channel_distribution_clean->Fill(theChannelToWrite->ChannelNumber);
	channel_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay, theChannelToWrite->Energy);
	channel_e_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
	channel_e_clean_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawEnergy);
	channel_delay_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay);
	channel_delay_clean_uncal[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->RawDelay);
	timestamp_distribution_clean->Fill(theChannelToWrite->Timestamp);
	if (theCutter->IsInside(theChannelToWrite->ChannelNumber, theChannelToWrite->Delay, theChannelToWrite->Energy)==1)
	  {
	    channel_e_gated_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
	    channel_delay_gated_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay);
	  }
      }
    /* PU */
    else if (theChannelToWrite->PileUp)
      {
	channel_distribution_pu->Fill(theChannelToWrite->ChannelNumber);
	channel_e_pu[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
	channel_delay_pu[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay);
	channel_pu[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay, theChannelToWrite->Energy);
      }
    /* Gated */
    if (theCutter->IsInside(theChannelToWrite->ChannelNumber, theChannelToWrite->Delay, theChannelToWrite->Energy)==1)
      {
	channel_gated[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay, theChannelToWrite->Energy);
	channel_e_gated_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Energy);
	channel_delay_gated_all[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay);
	if (!theChannelToWrite->PileUp && !theChannelToWrite->OutOfRange)
	  channel_gated_clean[theChannelToWrite->ChannelNumber]->Fill(theChannelToWrite->Delay, theChannelToWrite->Energy);

      }
    /* Gated clean */
  }
//*/
