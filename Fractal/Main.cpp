// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RGB.h"
#include "FractalCreator.h"

using namespace caveofprogramming;
using namespace std;


int main()
{
	RGB rgb1(4, 5, 6);
	RGB rgb2(6, 2, 3);
	RGB rgb3 = rgb1 - rgb2;

	cout << rgb3.red << ", " << rgb3.green << ", " << rgb3.blue << endl;
	

	FractalCreator fractalcreator(800, 600);

	cout << "Started" << endl;


	fractalcreator.addZoom(Zoom(295,  202, 0.1));

	fractalcreator.addZoom(Zoom(304,  304, 0.1));

	fractalcreator.runfractalcreator("test.bmp");

	cout << "Finished" << endl;

    return 0;
}

