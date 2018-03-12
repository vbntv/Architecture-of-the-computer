#ifndef UNTITLED1_LIBRARY_H
#define UNTITLED1_LIBRARY_H
#define FLAG_OVERFLOW 1
#define FLAG_DEVISION_BY_ZERO 2
#define FLAG_DUMP 3
#define FLAG_IGNOR_IMP 4
#define FLAG_WRONG_COMMAND 5

int ram[100];
int registr;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int * value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit(void);
int sc_regSet(int registr, int value);
int sc_regGet(int register, int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);
#endif
