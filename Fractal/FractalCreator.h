#pragma once

#include <string>
#include "ZoomList.h"
#include "Bitmap.h"
#include <iostream>
#include "Mandelbrot.h"
#include "RGB.h"


namespace caveofprogramming 

{
	class FractalCreator
	{

	private:

		int m_width{ 0 };
		int m_height{ 0 };
		unique_ptr<int[]>m_histogram;
		unique_ptr<int[]>m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };
	
		void calculateRangeTotals();
		void calculateIterations();
		void drawFractal();
		void writeBitmap(std::string name);
		int getRange(int iterations) const;
		


	public:
		
		FractalCreator(int width, int height);
		void addZoom(const Zoom &zoom);
		void addRange(double rangeEnd, const RGB &rgb);
		void SetZooms();
		void SetColorRanges();
		~FractalCreator();

		void runfractalcreator(string name);
	
	};

}