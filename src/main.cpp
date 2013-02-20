#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "process_io.h"

using namespace std;

int main(int argc, char *argv[])
{
	process_io io ( argc , argv );
	for ( int i = 0; i < io.files.size(); i++) {
		cout << io.files [i] << endl;
	}
	return 0;
}
