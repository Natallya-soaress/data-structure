#include <stdio.h>

char  memory[154], // Memória RAM
	    IR,			  // Registrador de instrução, guarda o opcode
	    RO0,		  // Registrador 0
	    RO1,		  // Registrador 1

	    E,
      L,
      G,
      phase[50];

short int Reg[4], // GPR's, guardam os operando temporariamente
	        MAR,		// Guarda o endereço de memória;
	        IMM,		// Imediato, guarda o operando Imediato
	        PC;			// Contador de programa

int MBR; // Buffer, guarda a palavra lida