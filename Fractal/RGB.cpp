#include "stdafx.h"
#include "RGB.h"

caveofprogramming::RGB::RGB(double red, double green, double blue): red(red), green(green), blue (blue)
{
}

caveofprogramming::RGB caveofprogramming::operator-(const RGB & first, const RGB & second)
{
	return RGB(first.red-second.red, first.green - second.green, first.blue-second.blue);
}
