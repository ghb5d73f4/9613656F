TConf *config =new TConf(conffile); // config file for histo in particular
config->echo =  config->ReadFlag("config_echo");
const int flag_read_progress_echo = config->ReadFlag("event_reader_progress_echo");

/* creating mapper */
TMapper * theMapper = new TMapper(mapfile);
if (config->ReadFlag("mapper_echo"))
  theMapper->DumpMap();

const int NumberOfChannels = theMapper->Size();

const int sync_channel = config->ReadInt("sync_channel", 0);

/* Creating variable place holders */
//TChannel * theChannelToWrite = new TChannel();
//unsigned long int number_of_event_read = 0;

/*Histo procesor */
//THistoProcessor *theHistoProcessor = new THistoProcessor(config,
//							 outputfile,
//							 theMapper,
//							 _k_NDAQChannels);
//theHistoProcessor->CreateHistos();

