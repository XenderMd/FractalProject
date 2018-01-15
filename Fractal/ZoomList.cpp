#include "stdafx.h"
#include "ZoomList.h"

using namespace caveofprogramming;

ZoomList::ZoomList(int width, int height): m_width(width), m_height(width)
{
}

void ZoomList::add(const Zoom & zoom)
{
	zooms.push_back(zoom);
}

std::pair<double, double> caveofprogramming::ZoomList::doZoom(int x, int y)
{

	return std::pair<double, double>();
}
