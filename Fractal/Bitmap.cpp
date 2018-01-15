#include "stdafx.h"
#include "Bitmap.h"
#include <fstream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;


caveofprogramming::Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixel(new uint8_t[width * height * 3]{})//initialize to default value - 0
{
}

bool caveofprogramming::Bitmap::write(string filename)
{
	BitmapInfoHeader infoHeader;
	BitmapFileHeader fileHeader;


	fileHeader.filesize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;

	file.open(filename, ios::binary);

	if (!file){return false;}

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)&*(m_pPixel.get()), m_width*m_height*3);


	file.close();
	if (!file) { return false; }
	
	return true;
}

void caveofprogramming::Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t *pPixel = m_pPixel.get();

	pPixel += (y * 3)*m_width + (x * 3);
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

void caveofprogramming::Bitmap::colorimage(uint8_t red, uint8_t green, uint8_t blue)
{

	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
			setPixel(col, row, red, green, blue);
}

caveofprogramming::Bitmap::~Bitmap()
{
}
