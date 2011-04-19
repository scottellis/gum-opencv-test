#include <stdio.h>

#define CV_NO_BACKWARD_COMPATIBILITY
#include <cv.h>
#include <highgui.h>


int main(int argc, char **argv)
{
	IplImage *img;

	printf("Loading image\n");

	if (argc > 1)
		img = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
	else
		img = cvLoadImage("./opencv.jpg", CV_LOAD_IMAGE_UNCHANGED);

	if (!img) {
		printf("Failed image load\n");
		exit(1);
	}

	printf("Flipping image\n");
	cvFlip(img, NULL, 1);

	printf("Saving flipped image\n");
	cvSaveImage("./flipped.jpg", img, 0);

	return 0;
}

