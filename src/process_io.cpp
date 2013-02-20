#include "process_io.h"

process_io :: process_io ( int argc , char *argv[] )
{
	height = width = percent = 0; 
	static struct option long_options[] = {
	    {"height",1,NULL,'H'},
	    {"width",1,NULL,'W'},
	    {"percent",1,NULL,'P'},
	    {"dir",1,NULL,'d'},
	    {"help",0,NULL,'h'},
	    {0,0,0,0}
	};
	char c;
	optind = 1;
	int option_index = 0;
	if ( argc < 3 )
	{
		
		print_usage ( argv[0] );
		exit ( 1 );
	}
	while ( 1 )
	{
		c = getopt_long(argc, argv, "H:W:P:d:h", long_options, &option_index);
		if ( c == -1 )
			break;
		switch ( c )
		{
			case 'h' : 
				print_usage ( argv[0] );
				exit ( 0 );
				break;
			case 'H' : 
				sscanf ( optarg , "%d" , &height );
				break;
			case 'W' : 
				sscanf ( optarg , "%d" , &width );
				break;
			case 'P' : 
				sscanf ( optarg , "%d" , &percent );
				break;
			case 'd' : 
				if ( dir.dir_files ( files , optarg ) == -1 )
				{
					fprintf ( stderr , "Error while reading %s ( %s )\n" , optarg , strerror ( errno ) );
					exit ( 1 );
				}
				break;
			default : 
				break;
		}
	}
	while ( optind < argc )
	{
		files.push_back ( std::string ( argv [ optind++ ] ) );
	}
	if ( percent != 0 && ( width != 0 || height != 0 ) )
	{
		fprintf ( stderr , "Please either use height-width combination or percent. Don't use both at same time.\n" );
		//printf ( "%d %d %d\n" , percent, height, width );
		exit ( 2 );
	}
}

inline void process_io :: print_usage ( char * prog )
{
	printf ( "%s usage\n" , prog );
	printf ( "%s <OPTIONS> <Images...>\n" , prog );
	printf ( "Options :\n"
		" -h, --help\t\t\t : Prints this message.\n"
		" -W, --width=PIXEL_VALUE\t : sets the width of all the images.\n"
		" -H, --height=PIXEL_VALUE\t : sets the height of all the images.\n"
		" -P, --percent=PIXEL_VALUE\t : scales the height and width according to their present dimentions.\n"
		" -d, --dir=/PATH/TO/INPUT/IMAGE/DIRECTORY\n"
		"\n"
		"All the converted files will be saved in \"Convert\" folder, previous files will be over written without any prior notice.\n"
		"\n"
		"Please either use height-width combination or percent. Don't use both at same time.\n");
}
