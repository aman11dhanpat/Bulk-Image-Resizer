#ifndef BIR_FILES_H
#define BIR_FILES_H

#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <cstring>

class read_dir
{
	public : 
		read_dir ( );
		int dir_files ( std :: vector < std :: string > & , const char * );
	private :
		dirent * entry;
		DIR * dir;
};

#endif
