#ifndef BIR_FILES_H
#define BIR_FILES_H

#include <dirent.h>
#include <errno.h>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <cstdio>

class read_dir
{
	public : 
		read_dir ( );
		int dir_files ( std :: vector < std :: string > & , const char * );
	private :
		dirent * entry;
		int check_extention ( const char * );
		DIR * dir;
		std :: map < std :: string , int > allowed; 
};

#endif
