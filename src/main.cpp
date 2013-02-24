#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "process_io.h"
#include "img_proc.h"

using namespace std;

int main(int argc, char *argv[])
{
	int ctr = 0;
	process_io io ( argc , argv );
	img_proc pic ( io.height , io.width, io.percent );
	for ( int i = 0; i < io.files.size(); i++) { 
		if ( pic.resize_and_save ( io.files[i] ) == true )
			ctr++;
	}
	cout << ctr << " files saved successfully" << endl;
	return 0;
}
