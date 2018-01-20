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
	
	Bitmap bitmap(WIDTH, HEIGHT);

	//cout << (unsigned int)((uint8_t)(pow((double)255, 0.325))) << endl;



	//ZoomList zoomList(WIDTH, HEIGHT);

	//zoomList.add(Zoom(WIDTH/2, HEIGHT/2,1));

	unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	unique_ptr<int[]>fractals(new int[WIDTH*HEIGHT]);


	//bitmap.setPixel(WIDTH / 2, HEIGHT/2,117, 0, 100);

	//bitmap.colorimage(117, 0,100);

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
		{
		
			double xFractal = (x-WIDTH/2-200)*(2.0/ HEIGHT);

			double yFractal = (y - HEIGHT / 2)*(2.0 / HEIGHT);

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			if (iterations != Mandelbrot::MAX_ITERATIONS)

			{
				histogram[iterations]++;
				fractals[(y*WIDTH + x)] = iterations;
			}
		}

	cout << endl;

	int total = 0;
	for (int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractals[y*WIDTH + x];

			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			double hue = 0.0;

			for (int i = 0; i <= iterations; i++)
			{
				hue += ((double)histogram[i]) / total;
			}
			
			green = pow((double) 255, hue);
			

			bitmap.setPixel(x, y, red, green, blue);

		}
	

	bitmap.write("test.bmp");
	cout << "Finished" << endl;

    return 0;
}

