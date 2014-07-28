// Floats.cpp : Defines the entry point for the console application.
//

#include <bitset>
#include <iostream>
#include <limits>
#include <stdint.h>
#include <tchar.h>

using namespace std;

union SpyFloat
{
	unsigned char mRawDataRep[4];
	uint32_t  mUintDataRep;
	float     mFloatRep;
};

void printFloat(float f)
{
	SpyFloat spyF;
	spyF.mFloatRep = f;

	cout << "The float " << f << " or " << scientific << f << 
		endl << "\traw: " << spyF.mUintDataRep <<
		endl << "\tbinary: " << static_cast<bitset<32>>(spyF.mUintDataRep) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// zero
	float zeroFloat = 0.0f;
	printFloat(zeroFloat);

	// INF, -INF
	printFloat(numeric_limits<float>::infinity());
	printFloat(-numeric_limits<float>::infinity());

	// NANs
	printFloat(numeric_limits<float>::quiet_NaN());
	printFloat(numeric_limits<float>::signaling_NaN());



	return 0;
}

