#include <stdio.h>
#include <opencv2/cv.h>
#include <opencv2/cxcore.h>
#include <cvaux.h>
#include <highgui.h>

int *alloc_int_1D(int rows);
void free_int_1D(int *array);

int main(int argc, char** argv)
{
	int i, j, n = 0;
	IplImage* img;
	IplImage* img1;
	FILE *fp;
	int fp_size;
	int *wm;

	char* filename = argc >= 2 ? argv[1] : (char*)"Girl.jpg";
	char* outfilename = argc >=2 ? argv[2] : (char*)"Girl.emb.jpg";
	if( (img = cvLoadImage( filename, 1)) == 0 )
      return -1;

    img1 = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 3);

	fp = fopen( "../experimentalResults/originalWatermarks/titech.gray", "rb" );
	if( fp == NULL )
	{
		puts( "titech.grayが開けません" );
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	fp_size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	wm = (int *)alloc_int_1D(fp_size);
	for(i = 0; i < fp_size; i++){
		wm[i] = fgetc(fp);
	}

	CvScalar s,s1;
	int h=img->height;
	int w=img->width;

	for(i=0; i<w; i++){
		for(j=0; j<h; j++){
			s=cvGet2D(img,i,j);
			s1.val[0]=s.val[0] + (double)wm[n%fp_size]/255 - (double)((int)(s.val[0])%2);
			s1.val[1]=s.val[1];
			s1.val[2]=s.val[2];
			cvSet2D(img1,i,j,s1);
			n++;
		}
	}

	cvSaveImage(outfilename, img1, 0);

	cvReleaseImage(&img);
	cvReleaseImage(&img1);
	fclose(fp);

	return 1;
}