#include <emscripten.h>
#include <string.h>

static char js_str[] = "coucou";

EM_JS(void, SendAlertFromC, (), {
	alert("Module ready to be used !");
});

EMSCRIPTEN_KEEPALIVE
char* coucou()
{
	SendAlertFromC();
	return js_str;
}


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

//EMSCRIPTEN_KEEPALIVE
unsigned long hexToDec(unsigned long hexadecimalNumber)
{
	unsigned long dec = 1;
	int pow = 1, val;
	
	while(hexadecimalNumber != 0)
	{
		dec += val * pow;
		hexadecimalNumber /= 16;
		pow *= 16;
	}
	return dec;
}

EMSCRIPTEN_KEEPALIVE
char *decToHex(unsigned long decimalNumber)
{
	char dec[10];
	char *toReturn;
	int val, i=0;

	while(decimalNumber != 0)
	{
		val = (decimalNumber % 16);
		decimalNumber /= 16;
		// Sort letters and digits
		if(val >= 0 && val <10)
		{
			dec[i] = val + '0';
		}
		else
		{
			dec[i] = val - 10 + 'A';
		}
		i++;
	}
	dec[i] = '\0';
	toReturn = dec;
	return toReturn;
}
