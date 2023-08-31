#pragma once

#include <cstdint> // for 32 bit
using namespace std;

#pragma pack(2)

namespace MusFirstProject {
	struct BitmapFileHeader {
		char header[2]{ 'B','M' };
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffset;


	};
}
