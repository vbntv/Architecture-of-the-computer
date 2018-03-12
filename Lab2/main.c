#include "library.h"
#include <stdio.h>





int main(){
    sc_memoryInit();
	sc_memorySet(1, 10);
	printf("\n%d\n", ram[1]);
	int get = sc_memoryGet(1, &get);
	printf("\n MEMORY GET = % d\n", get);
	sc_memorySave("RAM.bin");
	sc_memoryLoad("RAM.bin");
	sc_regInit();
	printf("\nRegister = %d\n", registr);
	sc_regSet(FLAG_WRONG_COMMAND, 1);
	printf("\n Register = %d\n", registr);
	int flag = sc_regGet(FLAG_WRONG_COMMAND, &flag);
	printf("\nflag = %d\n", flag);
	int encode = sc_commandEncode(34, 4, &encode);
	printf("\n Encode result = %d", encode);
	int OP, CO;
	sc_commandDecode(encode, &CO, &OP);
	printf("\n\n command = %d, operand = %d", CO, OP);


	
return 0;
}
