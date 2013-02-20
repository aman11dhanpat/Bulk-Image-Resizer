#include "files.h"

read_dir :: read_dir () 
{ }

int read_dir :: dir_files ( std::vector <std::string> & files , const char * cwd )
{
	if ( ( dir = opendir ( cwd ) ) == NULL )
	{
		return -1;
	}
	while ( ( entry = readdir ( dir ) ) != NULL )
	{
		if ( strcmp (entry->d_name , ".") && strcmp (entry->d_name , "..") )
			files.push_back ( std::string ( entry->d_name ) );
	}
	return 0;
}
