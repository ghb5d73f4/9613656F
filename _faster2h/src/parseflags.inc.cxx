/* Testing the flags and options */
if (ParseFlag(argc, argv, "--help")==1 || 
    ParseFlag(argc, argv, "-h")==1 || 
    argc==1)
  {
    std::cout << "Usage: faster2h [--help|-h] [--map=%s] [--output=%s] [--max-num-event=%i] [--conf=%s] --input=%s.fast" << std::endl << std::endl;
    std::cout << "   --help|-h : shows this help" <<std::endl;
    std::cout << "   --map : map file (default='grapheme.map')" <<std::endl;
    std::cout << "   --output : output dir (default='./output/')" <<std::endl;
    std::cout << "   --max-num-event : Max num. of event to read (default=-1 i.e infinity)" <<std::endl;
    std::cout << "   --conf : configuration file (default='/dev/null')" <<std::endl;
    std::cout << "   --input : input file (default='/dev/null')" <<std::endl;
    return 0;
  }
const char* outputfile = ParseString(argc, argv, 
				     "--output=%s", "./output/");
const char* mapfile = ParseString(argc, argv, 
				  "--map=%s", "grapheme.map");
const int maxnumevent = ParseInt(argc, argv,
				 "--max-num-event=%i",180000000);
const char* sourcefile = ParseString(argc, argv,
				     "--input=%s", "/dev/null");
const char* conffile = ParseString(argc, argv,
				   "--conf=%s", "/dev/null");
char sourcefile_work[2000];
strcpy(sourcefile_work, sourcefile);
char* sourcefile_base = basename(sourcefile_work);
char* sourcefile_dir = dirname(sourcefile_work);
char* current_dir = get_current_dir_name();

/* Echo of parameters values */
printf("# Current directory is %s \n", current_dir); 
printf("# File to read is %s in %s \n", sourcefile_base, sourcefile_dir);
printf("# Reading configuration from '%s' \n", conffile);
printf("# Reading at most %i events \n", maxnumevent);
printf("# Writing output in '%s'\n", outputfile);


