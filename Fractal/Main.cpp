// Fractal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RGB.h"
#include "FractalCreator.h"

using namespace caveofprogramming;
using namespace std;


int main()
{

	cout << "Started" << endl;

	FractalCreator fractalcreator(800, 600);
	
	fractalcreator.SetColorRanges();

	fractalcreator.SetZooms();

	fractalcreator.runfractalcreator("FractalImage.bmp");

	cout << "Finished" << endl;

    return 0;
}

