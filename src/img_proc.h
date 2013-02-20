#ifndef BIR_IMG_PROC_H
#define BIR_IMG_PROC_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

using namespace cv;

class img_proc
{
	private :
		Mat image , dst;
		int height;
		int width;
		float percent;
	public : 
		img_proc ( ) { }
		img_proc ( int h , int w , float p ) 
		{
			height = h;
			width = w;
			percent = p;
		}
		bool resize_and_save ( std :: string );
		void show ( std :: string );
};

#endif
