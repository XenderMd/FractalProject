#pragma once

#include <string>
#include "ZoomList.h"
#include "Bitmap.h"
#include <iostream>
#include "Mandelbrot.h"


namespace caveofprogramming 

{


	class FractalCreator
	{
		int m_width{ 0 };
		int m_height{ 0 };
		unique_ptr<int[]>m_histogram;
		unique_ptr<int[]>m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
	

	public:
		FractalCreator(int width, int height);
		~FractalCreator();
		void calculateIterations();
		void drawFractal();
		void addZoom(const Zoom &zoom);
		void writeBitmap(std::string name);
	};

}