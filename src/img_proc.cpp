#include <iostream>
#include "img_proc.h"

void img_proc :: show ( string str )
{
	image = imread ( str.c_str ( ) , CV_LOAD_IMAGE_COLOR );
	namedWindow( str.c_str ( ) , CV_WINDOW_AUTOSIZE );
	imshow( str.c_str ( ) , image );
	waitKey(0);
}

bool img_proc :: resize_and_save ( string str )
{
	string temp;
	size_t pos;
	image = imread ( str.c_str ( ) , CV_LOAD_IMAGE_COLOR );
	if ( percent != 0 )
	{
		height = image.rows * percent / 100;
		width = image.cols * percent / 100;
	}
	dst = Mat (Size(width,height),CV_8UC3);
	cv::resize ( image, dst, dst.size(), 0, 0, INTER_LANCZOS4 );
	pos = str.find_last_of ( "/" );
	temp = str;
	if ( pos != std :: string :: npos )
	{
		temp.assign ( str.begin () + pos + 1 , str.end( ) );
	}
	temp = "Convert/" + temp;
	imwrite ( temp.c_str ( ) , dst ); 
	std :: cout << temp;
}
