#include "library.h"
#include "string.h"
#include <stdio.h>

#include <stdlib.h>

int sc_memoryInit()
{
  	  memset(ram, 0, 4*sizeof(int));
	return 0;
}

int sc_regInit(void)
{
	registr = 0;
	return 0;
}

int sc_regSet(int flag, int value)
{
	if((value == 1) | (value == 0))
	{
		if(flag < 1 || flag > 5)
		{
			printf("Incorrect register");
			return 1;
		
		}
		if(value == 1)
		{
			registr =  (registr | (1 << (flag-1)));
			return 0;
		}
		if(value == 0)
		{
			registr =  (registr & (~(1 << (flag-1))));
			return 0;
		}
	}
	return 1;
}

int sc_regGet(int flag, int *value)
{
	/*if((registr < 1) || (registr > 5))
	{
		return 1;
	}
	*/
	
	return *value = ((registr >> (flag-1)));
}

int sc_memorySet(int address, int value)
{
	if(address < 1 || address > 100)
	{
		printf("Bad address, try again");
		sc_regSet(FLAG_DUMP, 1);
		return 1;
	}	
	ram[address] = value;
	return 0;
	
}

int sc_memoryGet(int address, int *value)
{
	if((address < 1) | (address > 100))
	{
		printf("DUMP");
		sc_regSet(FLAG_DUMP, 1);
		return 1;
	}
	else 
	return *value = ram[address];
	
}

int sc_commandEncode(int command, int operand, int *value)
{
	if((command < 10) || 
	((command > 11) & (command < 20)) ||
	((command > 21) & (command < 30)) ||
	((command > 33) & (command < 40)) ||
	((command > 43) & (command < 51)))
	{
		printf("Wrong command");
		sc_regSet(FLAG_WRONG_COMMAND, 1);
		return 1;
	}
	
	if((operand > 127) | (operand < 0) | (command > 127) |( command < 0))
	{
		return 1;
	}
	else
	{
		int temp = 0x00;
		temp |= operand;
		temp <<=7;
		temp |= command;
		temp |= 0 << 14;
		return *value = temp;	
	}
	return 1;
}

int sc_commandDecode(int value, int *command, int *operand)
{
	if((value & (1 << 14)) != 0)
	{
  	sc_regSet(FLAG_WRONG_COMMAND, 1);
	return 1;
	}
	else
	{
		*command = value & 0x7F;
		*operand = (value >> 7) & 0x7F;
		return 0;
	}
}

int sc_memorySave(char *filename)
{
	FILE* output;
	output = fopen(filename, "wb");
	if(output == NULL)
	{	
		printf("Error opening file");
		return 1;
	}
	fwrite(ram, sizeof(int), 100, output);
	fclose(output);
	return 0;

}

int sc_memoryLoad(char *filename)
{
	FILE* input;
	input = fopen(filename, "rb");
	fread(ram, sizeof(int), 100, input);
	fclose(input);
	return 0;
}

