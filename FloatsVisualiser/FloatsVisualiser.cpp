// FloatsVisualiser
//
// Just going through the Wikipedia page for IEEE 754 floats. Thought I'd quickly visualise and test.
// http://en.wikipedia.org/wiki/IEEE_754-1985
// synchingfeeling@gmail.com

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

	cout << "Float " << scientific << f << 
		endl << "\traw: " << hex << spyF.mUintDataRep <<
		endl << "\tbinary (exp bias = 127): " << static_cast<bitset<32>>(spyF.mUintDataRep) << endl;
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

	// DEN, NORM min/max
	printFloat(numeric_limits<float>::denorm_min());
	printFloat(numeric_limits<float>::min());
	printFloat(numeric_limits<float>::max());

	// General
	printFloat(1.f);
	printFloat(1.1f);
	printFloat(524288.f);  // 2^20
	printFloat(1048576.f); // 2^21
	printFloat(2097152.f); // 2^22
	printFloat(4194304.f); // 2^23
	printFloat(8388608.f); // 2^24

	return 0;
}

