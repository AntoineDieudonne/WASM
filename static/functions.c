#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
unsigned long decToBin(unsigned long decimalNumber)
{
	unsigned long bin = 0, rest = 0, pow = 1;
	while(decimalNumber != 0)
	{
		bin += (decimalNumber % 2) * pow;
		decimalNumber /= 2;
		pow *= 10;
	}
	return bin;
}

EMSCRIPTEN_KEEPALIVE
unsigned long binToDec(unsigned long binaryNumber)
{
	unsigned long dec = 0, rest = 0, pow=0;
	while(binaryNumber != 0)
	{
		dec = dec * 10 + binaryNumber;
		binaryNumber /= 2;
		pow ++;
	}
	return dec;
}
