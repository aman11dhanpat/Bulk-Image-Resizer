#ifndef BIR_PROCESS_IO_H
#define BIR_PROCESS_IO_H

#include <getopt.h>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include "files.h"

class process_io
{
	private :
		inline void print_usage ( char * );
		read_dir dir;	
	public :
		process_io ( ) { height = width = percent = 0; }
		process_io ( int , char ** );
		std :: vector < std :: string > files;
		int height;
		int width;
		float percent;
};

#endif
