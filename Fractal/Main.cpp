// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FractalCreator.h"

using namespace caveofprogramming;
using namespace std;


int main()
{
	
	int height = 600;
	int width = 800;

	cout << "Started" << endl;

	FractalCreator fractalcreator (width, height);
	
	fractalcreator.addZoom(Zoom(295, height -202, 0.1));
	
	fractalcreator.addZoom(Zoom(304, height - 304, 0.1));
	
	fractalcreator.calculateIterations();
	
	fractalcreator.drawFractal();
	
	fractalcreator.writeBitmap("test.bmp");

	cout << "Finished" << endl;

    return 0;
}

