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

void printFloat(const float f)
{
	SpyFloat spyF;
	spyF.mFloatRep = f;

	cout 
		<< "Float " 
		<< scientific 
		<< f 
		<< endl 
		<< "\traw: " 
		<< hex 
		<< spyF.mUintDataRep 
		<< endl 
		<< "\tbinary (exp bias = 127): " 
		<< static_cast<bitset<32>>(spyF.mUintDataRep) 
		<< endl;
}

void printFloatError(const float f)
{
	cout
		<< "Float value: "
		<< scientific
		<< f
		<< " Max Error: "
		<< f * std::numeric_limits<float>::epsilon()
		<< endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Representation of some common types" << endl;

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

	cout << "Error limits for some 2^n types" << endl;

	for (int i = 0; i < 32; ++i)
	{
		const float currentVal = std::powf(2.0f, static_cast<float>(i));
		printFloatError(currentVal);
	}

	// For comparison against the Gamasutra Article:
	// http://www.gamasutra.com/view/feature/130382/visualizing_floats.php
	printFloatError(1.e6f);
	printFloatError(64.e6f);
	printFloatError(std::powf(2.0f, 23.0f));
	printFloatError(std::powf(2.0f, 32.0f));

	// Distance to the sun in km
	printFloatError(149597887.5f);
	
	return 0;
}

