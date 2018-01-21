#pragma once

namespace caveofprogramming
{



	class RGB
	{
	public:

		double red;
		double green;
		double blue;

	public:
		RGB(double red, double green, double blue);
	};

	RGB operator - (const RGB & first, const RGB &second);

}

