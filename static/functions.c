#include <emscripten.h>
#include <string.h>

static char js_str[] = "coucou";

EM_JS(void, SendAlertFromC, (), {
	console.log("Module ready to be used !");
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

EMSCRIPTEN_KEEPALIVE
unsigned long hexToDec(char* hexadecimalNumber)
{
	unsigned long dec = 0;
	int pow = 1, val;
	
	for(int i = strlen(hexadecimalNumber) - 1; i >= 0; i--)
	{
		char hex = hexadecimalNumber[i];
		if(hex >= '0' && hex <= '9')
		{
			val = hex - '0';
		}
		else if(hex >= 'A' && hex <= 'F')
		{
			val = hex - 'A' + 10;
		}
		else if(hex >= 'a' && hex <= 'f')
		{
			val = hex - 'a' + 10;
		}
		dec += val * pow;
		pow *= 16;
	}
	return dec;
}

EMSCRIPTEN_KEEPALIVE
char* decToHex(unsigned long decimalNumber)
{
	char hex[10];
	char *toReturn;
	int val, i=0;

	while(decimalNumber != 0)
	{
		val = (decimalNumber % 16);
		decimalNumber /= 16;
		// Sort letters and digits
		if(val >= 0 && val < 10)
		{
			hex[i] = val + '0';
		}
		else
		{
			hex[i] = val - 10 + 'A';
		}
		i++;
	}
	char reversedHex[10];
	int k = 0;
	for(int j = i - 1; j >= 0; j--)
	{
		reversedHex[k] = hex[j];
		k++;
	}
	reversedHex[i] = '\0';
	toReturn = reversedHex;
	return toReturn;
}

EMSCRIPTEN_KEEPALIVE
char* binToHex(unsigned long binaryNumber)
{
	char hex[10];
	char *toReturn;
	int val = 0, i = 0, count = 1, pow = 1;

	// Values are added in the wrong order
	while(binaryNumber != 0)
	{
		val += (binaryNumber % 2) * pow;
		// Divide by ten because the binary is in base 10
		binaryNumber /= 10;
        pow *= 2;

        // if we have 4 bits
        if(count %4 == 0)
        {
            if(val >= 0 && val < 10)
            {
                hex[i] = val + '0';
            }
            else
            {
                hex[i] = val + 'A' - 10;
            }
            val = 0;
            pow = 1;
            i++;
        }
        count++;
	}
	if((count - 1) %4 != 0)
    {
        if(val >= 0 && val < 10)
        {
            hex[i] = val + '0';
        }
        else
        {
            hex[i] = val + 'A' - 10;
        }
        i++;
    }
	char reversedHex[10];
	int k = 0;
	for(int j = i - 1; j >= 0; j--)
	{
		reversedHex[k] = hex[j];
		k++;
	}
	reversedHex[i] = '\0';
	toReturn = reversedHex;
	return toReturn;
}

EMSCRIPTEN_KEEPALIVE
unsigned long hexToBin(char* hexadecimalNumber)
{
	unsigned long bin = 0, pow = 1;
	for(int i = strlen(hexadecimalNumber) - 1; i >= 0; i--)
	{
		switch(hexadecimalNumber[i])
		{
			case '0':
			case '1':
				bin += (hexadecimalNumber[i] - '0')* pow;
				break;
			case '2':
				bin += 0010 * pow;
				break;
			case '3':
				bin += 0011 * pow;
				break;
			case '4':
				bin += 0100 * pow;
				break;
			case '5':
				bin += 0101 * pow;
				break;
			case '6':
				bin += 0110 * pow;
				break;
			case '7':
				bin += 0111 * pow;
				break;
			case '8':
				bin += 1000 * pow;
				break;
			case '9':
				bin += 1001 * pow;
				break;
			case 'A':
				bin += 1010 * pow;
				break;
			case 'B':
				bin += 1011 * pow;
				break;
			case 'C':
				bin += 1100 * pow;
				break;
			case 'D':
				bin += 1101 * pow;
				break;
			case 'E':
				bin += 1110 * pow;
				break;
			case 'F':
				bin += 1111 * pow;
				break;
		}
		pow *= 10000;
	}
	return bin;
}
