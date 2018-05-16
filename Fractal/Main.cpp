// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RGB.h"
#include "FractalCreator.h"

using namespace caveofprogramming;
using namespace std;


int main()
{

	FractalCreator fractalcreator(800, 600);


	cout << "Started" << endl;

	fractalcreator.addRange(0.0, RGB(0, 0, 0));

	fractalcreator.addRange(0.3, RGB(0, 255, 0));

	fractalcreator.addRange(0.5, RGB(117, 255, 0));

	fractalcreator.addRange(1.0, RGB(0, 255, 0));

	//fractalcreator.addZoom(Zoom(295,  202, 0.1));

	//fractalcreator.addZoom(Zoom(304,  304, 0.1));

	fractalcreator.runfractalcreator("test.bmp");

	cout << "Finished" << endl;

    return 0;
}

