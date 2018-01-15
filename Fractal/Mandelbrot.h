#pragma once
class Mandelbrot
{
public:
	static int pixelCount;
	static const int MAX_ITERATIONS = 1000;
	
public:
	Mandelbrot();
	~Mandelbrot();

	static int getIterations(double x, double y);
};

