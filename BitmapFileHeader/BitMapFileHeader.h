#pragma once
#pragma pack(2)
#include<cstdint>


struct BitMapFileHeader
{
	char header[2]{'B', 'M'};
	int32_t filesize;
	int32_t reserved{ 0 };
	int32_t dataOffset;

};
