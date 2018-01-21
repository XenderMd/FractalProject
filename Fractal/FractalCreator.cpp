#include "stdafx.h"
#include "FractalCreator.h"

using namespace caveofprogramming;


caveofprogramming::FractalCreator::FractalCreator(int width, int height): m_width(width), 
                   m_height(height), m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }), 
                   m_fractal(new int[width*height]), m_zoomList(m_width, m_height), m_bitmap(width, height)
{
	addZoom(Zoom(width / 2, height / 2, 4.0 / width)); 
}

caveofprogramming::FractalCreator::~FractalCreator()
{
}

void caveofprogramming::FractalCreator::calculateRangeTotals()
{
	int rangeIndex = 0;
	int overalltotal = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		int pixels = m_histogram[i];

		if (i >= m_ranges[rangeIndex + 1])
		{
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

void caveofprogramming::FractalCreator::calculateIterations()
{
	std::cout << "Calculating iterations ..." << std::endl;

	pair<double, double>coords;

	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
		{

			coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			if (iterations != Mandelbrot::MAX_ITERATIONS)

			{
				m_histogram[iterations]++;
				m_fractal[(y*m_width + x)] = iterations;
			}
		}
}

void caveofprogramming::FractalCreator::drawFractal()
{
	std::cout << "Drawing the fractal ..." << std::endl;

	RGB startColor(0, 0, 0);
	RGB endColor(0, 255, 0);
	RGB coloDiff = endColor - startColor;

	int total=0;

	for (int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += m_histogram[i];
	}

	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = m_fractal[y*m_width + x];

			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			double hue = 0.0;

			for (int i = 0; i <= iterations; i++)
			{
				hue += ((double)m_histogram[i]) / total;
			}

			red = startColor.red + coloDiff.red*hue;
			green = startColor.green + coloDiff.green*hue;
			blue = startColor.blue + coloDiff.blue*hue;

			m_bitmap.setPixel(x, y, red, green, blue);
		}
}

void caveofprogramming::FractalCreator::addZoom(const Zoom & zoom)
{
	m_zoomList.add(zoom);
}

void caveofprogramming::FractalCreator::addRange(double rangeEnd, const RGB & rgb)
{
	m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);
	if (m_bGotFirstRange)
	{
		m_rangeTotals.push_back(0);
	}
	m_bGotFirstRange = true;
}

void caveofprogramming::FractalCreator::writeBitmap(std::string name)
{
	std::cout << "Writing the bitmap ..." << std::endl;
	m_bitmap.write(name);
}

void caveofprogramming::FractalCreator::runfractalcreator(string name)
{
	
	calculateIterations();

	calculateRangeTotals();

	drawFractal();

	writeBitmap(name);
}
