#pragma once
#include "Zoom.h"
#include <vector>
#include <utility>

namespace caveofprogramming
{

	class ZoomList
	{
	private:
		double m_xCenter{0};
		double m_yCenter{0};
		double m_scale{1.0};
		int m_width{ 0 };
		int m_height{ 0 };
		//std::vector <Zoom> zooms;

	public:

		ZoomList(int width, int height);

		void add(const Zoom &zoom);

		std::pair <double, double> doZoom(int x, int y);
		
	};
}
