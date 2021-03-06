#include "stdafx.h"
#include "ZoomList.h"


using namespace caveofprogramming;


ZoomList::ZoomList(int width, int height): m_width(width), m_height(height)
{
}

void ZoomList::add(const Zoom & zoom)
{
	//zooms.push_back(zoom);
	
	m_xCenter += (zoom.x - m_width / 2)*m_scale;
	
	m_yCenter += -(zoom.y - m_height / 2)*m_scale;

	m_scale *= zoom.scale;

	//std::cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << std::endl;

}

std::pair<double, double> caveofprogramming::ZoomList::doZoom(int x, int y)
{
	double xFractal = m_xCenter + (x - m_width / 2)*m_scale;

	//std::cout << xFractal<<" ";

	//if (x == (m_width - 1)) { std::cout << std::endl; }
	
	double yFractal = m_yCenter + (y - m_height / 2)*m_scale;
	
	return std::pair<double, double>(xFractal,yFractal);
}
