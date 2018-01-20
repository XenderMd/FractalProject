// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include <iostream>
#include <cstdint>
#include <map>
#include <math.h>


using namespace caveofprogramming;
using namespace std;


int main()
{
	int const WIDTH = 800;
	int  const HEIGHT = 600;
	double min = 99999;
	double max = -99999;
	int total = HEIGHT*WIDTH;


	Bitmap bitmap(WIDTH, HEIGHT);

	//cout << (unsigned int)((uint8_t)(pow((double)255, 0.325))) << endl;



	//ZoomList zoomList(WIDTH, HEIGHT);

	//zoomList.add(Zoom(WIDTH/2, HEIGHT/2,1));

	//unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	//unique_ptr<int[]>fractals(new int[WIDTH*HEIGHT]);

	//Mandelbrot::pixelCount = 0;
	//

	//bitmap.setPixel(WIDTH / 2, HEIGHT/2,117, 0, 100);

	//bitmap.colorimage(117, 0,100);

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
		{
		
			double xFractal = (x-WIDTH/2-200)*(2.0/ HEIGHT);

			double yFractal = (y - HEIGHT / 2)*(2.0 / HEIGHT);

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			uint8_t color =(uint8_t)(256*(double)iterations / Mandelbrot::MAX_ITERATIONS);

			color = color*color*color;

			bitmap.setPixel(x, y, 0, color, 0);

			//if (iterations != Mandelbrot::MAX_ITERATIONS) { histogram[iterations]++; };
			
			//fractals[(y*WIDTH + x)] = iterations;

		}


	bitmap.write("test.bmp");
	cout << "Finished" << endl;

    return 0;
}

