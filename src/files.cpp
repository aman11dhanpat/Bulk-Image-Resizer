#include "files.h"

read_dir :: read_dir () 
{
	allowed.insert ( std :: make_pair ( "PNG" , 1 ) );
	allowed.insert ( std :: make_pair ( "png" , 1 ) );
	allowed.insert ( std :: make_pair ( "JPG" , 1 ) );
	allowed.insert ( std :: make_pair ( "jpg" , 1 ) );
	allowed.insert ( std :: make_pair ( "GIF" , 1 ) );
	allowed.insert ( std :: make_pair ( "gif" , 1 ) );
	allowed.insert ( std :: make_pair ( "JPEG" , 1 ) );
	allowed.insert ( std :: make_pair ( "jpeg" , 1 ) );
	allowed.insert ( std :: make_pair ( "tiff" , 1 ) );
	allowed.insert ( std :: make_pair ( "TIFF" , 1 ) ); 
}

int read_dir :: dir_files ( std::vector <std::string> & files , const char * cwd )
{
	if ( ( dir = opendir ( cwd ) ) == NULL )
	{
		return -1;
	}
	while ( ( entry = readdir ( dir ) ) != NULL )
	{
		if ( check_extention ( entry->d_name ) )
			files.push_back ( std::string ( cwd ) + "/" + std::string ( entry->d_name ) );
		else
			fprintf ( stderr , " Excluding file \" %s \" (Not an Image file) \n" , entry->d_name ); 
	}
	return 0;
}

int read_dir :: check_extention ( const char * file_name )
{
	std :: string temp , str (file_name);
	size_t pos;
	pos = str.find_last_of ( "." );
	if ( pos != std :: string :: npos )
	{
		temp.assign ( str.begin () + pos + 1 , str.end( ) );
	}
	if ( allowed [temp] == 1 )
		return 1;
	return 0;
}
