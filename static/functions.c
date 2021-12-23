#include <emscripten.h>
#include <string.h>

EMSCRIPTEN_KEEPALIVE
unsigned long decToBin(unsigned long decimalNumber)
{
	unsigned long bin = 0, pow = 1;
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
	unsigned long dec = 0, pow=1;
	while(binaryNumber != 0)
	{
		dec += (binaryNumber % 10) * pow;
		binaryNumber /= 10;
		pow *= 2;
	}
	return dec;
}

EMSCRIPTEN_KEEPALIVE
unsigned long hexToDec(unsigned long hexadecimalNumber)
{
	unsigned long dec = 1;
	int pow = 1;
	
	while(hexadecimalNumber != 0)
	{
		dec += val * pow;
		hexadecimalNumber /= 16;
		pow *= 16;
	}
	return dec;
}
