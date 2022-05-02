#include "variables.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>

// Trabalho feito por Nátallya Soares e Pedro Lucas


//Espera a tecla espaço ser digitada para prosseguir o programa
void waitEnter() {
    int value;
    printf("\nPressione ENTER");

    do {
        value = getchar();
    } while (value != '\n'); // 13 é o codigo ASCII do ENTER
}

// Inicia o vetor da memória zerando todas  as posições
void startMemory(char memory[154]) {
    int count = 0;
    for (count = 0; count < 154; count++) {
        memory[count] = 0;
    }
    E = '0';
    L = '0';
    G = '0';
}

// Atualiza a tela e mostra o valor das variáveis
void updateScreen() {
    system("clear||cls");
    printf("\n                      Máquina de Von Neuman\n\n");
    printf("Estágio: %s\n", phase);
    printf(
            "%s: 0x%x%10s: 0x%x%10s: 0x%x%10s: "
            "0x%x%10s: 0x%x%10s: 0x%x%10s: %d%10s: "
            "0x%x%10s: 0x%x%10s: 0x%x%10s: 0x%x"
            "%10s :%c%10s :%c%10s :%c",
            "R0", Reg[0],
            "R1", Reg[1],
            "R2", Reg[2],
            "R3", Reg[3],
            "RO0", RO0,
            "RO1", RO1,
            "\nIR", IR,
            "MBR", MBR,
            "MAR", MAR,
            "IMM", IMM,
            "PC", PC,
            "\nE", E,
            "L", L,
            "G", G);
    int p;
    printf("\n\nMemória:\n");
    for (p = 0; p < 154; p++) {
        short int mem = memory[p];
        if (mem < 0) {
            mem = mem - 65280;
        }
        printf("  %03x:0x%03x", p, mem);
        if (p % 7 == 6) {
            printf("\n");
        }
    }
}
void printbits( int x) {
    for (int i = sizeof(x) << 3; i; i--)
        printf("%c", '0' + ((x >> (i - 1)) & 1));
}

//Solicita os dados ao usuário e os armazena 
void loadMemory() {
    char s[50] = "Carregamento da Memoria";
    strcpy(phase, s);
    int adress;
    int value;
    do {
        printf("\nInsira o endereço de memória e o conteúdo:\n");
        scanf("%x %x", &adress, &value);
        fflush(stdin);
        __fpurge(stdin);
        if (MAR >= 0 && MAR <= sizeof(memory)) {
            if (adress != 3841 && value != 3841) {
                MAR = adress;
                MBR = value;
                memory[MAR] = MBR;
                updateScreen();
            }
        }
    } while (adress != 3841 && value != 3841);
}
int halt(){
  printf("\n halt\n");
  return 0;
}
void add_register(){
  printf("\n add_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0] + Reg[RO1];
}
void subtract_register(){
  printf("\n subtract_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0] - Reg[RO1];
}
void multiply_register(){
  printf("\n multiply_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0] * Reg[RO1];
}
void divide_register(){
  printf("\ndivide_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0] / Reg[RO1];
}
void compare_register(){
  printf("\ncompare_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  E=0; L=0; G=0;
  (Reg[RO0]==Reg[RO1])?E=1:0;
  (Reg[RO0]==Reg[RO1])?L=1:0;
  (Reg[RO0]==Reg[RO1])?G=1:0;  
}
void move_register(){
  printf("\nmove_register\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO1];
}
void logical_and(){
  printf("\nlogical_and\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0]&Reg[RO1];
}
void logical_or(){
  printf("\nlogical_or\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0]|Reg[RO1];
}
void logical_xor(){
  printf("\nlogical_xor\n");
  RO0 = (MBR<<21>>30)&0b11;
  RO1 = (MBR<<23>>30)&0b11;
  Reg[RO0] = Reg[RO0]^Reg[RO1];
}
void logical_not(){
  printf("\nlogical_not\n");
  RO0 = (MBR<<29>>30)&0b11;
  Reg[RO0] = Reg[RO0];
}
void jump_equal(){
  printf("\njump_equal\n");
  MAR = MBR & 0xffff;
  (E==1)?PC = MAR:0;
}
void jump_not_equal(){
  printf("\njump_not_equal\n");
  MAR = MBR & 0xffff;
  (E==0)?PC = MAR:0;
}
void jump_lower(){
  printf("\njump_lower\n");
  MAR = MBR & 0xffff;
  (L==1)?PC = MAR:0;
}
void jump_lower_equal(){
  printf("\njump_lower_equal\n");
  MAR = MBR & 0xffff;
  (L==1||E==1)?PC = MAR:0;
}
void jump_greater(){
  printf("\njump_greater\n");
  MAR = MBR & 0xffff;
  (G==1)?PC = MAR:0;
}
void jump_greater_equal(){
  printf("\njump_greater_equal\n");
  MAR = MBR & 0xffff;
  (G==1||E==1)?PC = MAR:0;
}
void jump(){
  printf("\njump\n");
  MAR = MBR &0xffff;
  PC = MAR & 0xffff;
}
void load(){
  printf("\nload");
  MAR = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  MBR = memory[MAR];
  MBR = MBR << 8;
  MAR++;
  MBR = MBR | memory[MAR];
  MBR = MBR & 0xffff;
  Reg[RO0]=MBR & 0xffff;
}
void store(){
  printf("\nstore\n");
  MAR = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  memory[MAR] = (Reg[RO0]>>8) & 0xff;
  MAR++;
  memory[MAR] = (Reg[RO0]) & 0xff;
}
void move_immediate(){
  printf("\nmove_immediate\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  Reg[RO0]=(IMM) & 0xffff;
}
void add_immediate(){
  printf("\nadd_immediate\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  Reg[RO0]=(Reg[RO0]+IMM) & 0xffff;

}
void subtract_immediate(){
  printf("\nsubtract_immediate\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  Reg[RO0]=(Reg[RO0]-IMM) & 0xffff;
}
void multiply_immediate(){
  printf("\nmultiply_immediate\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  Reg[RO0]=(Reg[RO0]*IMM) & 0xffff;
}
void divide_immediate(){
  printf("\ndivide_immediate\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  Reg[RO0]=(Reg[RO0]/IMM) & 0xffff;
}
void left_shift(){
  printf("\nleft_shift\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  MBR = (RO0 << IMM) & 0xffff;
}
void right_shift(){
  printf("\nright_shift\n");
  IMM = MBR & 0xffff;
  RO0 = (MBR<<13>>30)&0b11;
  MBR = (RO0 >> IMM) & 0xffff;
}

//Carrega toda intrução no buffer, e define a próxima instrução a ser executada
int search() {
    char s[50] = "Busca";
    strcpy(phase, s);
    updateScreen();
    waitEnter();

    IR = 0;
    IR = (memory[PC] >> 3) & 0x1f;
    if (IR == 0) {
        return halt();
    } else if (IR == 10) {
        MBR = memory[PC] & 0xff;
        PC++;
    } else if (IR <= 9) {
        MBR = memory[PC] & 0xff;
        PC++;
        MBR = MBR << 8;
        MBR = MBR | (memory[PC] & 0xff);
        MBR = MBR & 0xffff;
        PC++;
    } else if (IR >= 11 & IR<=26) {
        MBR = memory[PC] & 0xff;
        PC++;
        MBR = MBR << 8;
        MBR = MBR | (memory[PC] & 0xff);
        PC++;
        MBR = MBR << 8;
        MBR = MBR | (memory[PC] & 0xff);
        MBR = MBR & 0xffffff;
        PC++;
    }
    updateScreen();
    return 1;
}

//Executa a instrução correta de acordo com o opcode
void decode() {
    char s[50] = "Decoficação";
    strcpy(phase, s);
    updateScreen();
    waitEnter();

    (IR == 0b00000) ? halt() : 0;
    (IR == 0b00001) ? add_register() : 0;
    (IR == 0b00010) ? subtract_register() : 0;
    (IR == 0b00011) ? multiply_register() : 0;
    (IR == 0b00100) ? divide_register() : 0;
    (IR == 0b00101) ? compare_register() : 0;
    (IR == 0b00110) ? move_register() : 0;
    (IR == 0b00111) ? logical_and() : 0;
    (IR == 0b01000) ? logical_or() : 0;
    (IR == 0b01001) ? logical_xor() : 0;
    (IR == 0b01010) ? logical_not() : 0;
    (IR == 0b01011) ? jump_equal() : 0;
    (IR == 0b01100) ? jump_not_equal() : 0;
    (IR == 0b01101) ? jump_lower() : 0;
    (IR == 0b01110) ? jump_lower_equal() : 0;
    (IR == 0b01111) ? jump_greater() : 0;
    (IR == 0b10000) ? jump_greater_equal() : 0;
    (IR == 0b10001) ? jump() : 0;
    (IR == 0b10010) ? load() : 0;
    (IR == 0b10011) ? store() : 0;
    (IR == 0b10100) ? move_immediate() : 0;
    (IR == 0b10101) ? add_immediate() : 0;
    (IR == 0b10110) ? subtract_immediate() : 0;
    (IR == 0b10111) ? multiply_immediate() : 0;
    (IR == 0b11000) ? divide_immediate() : 0;
    (IR == 0b11001) ? left_shift() : 0;
    (IR == 0b11010) ? right_shift() : 0;
    updateScreen();
}
//Interrompe a execução quando o valor é zero
void executeProgram() {
    printf("--Iniciar Execução--\n");
    int find;
    int condition = 1;
    do {
        find = search();
        if (find == 0) {
            condition = 0;
        }else {
            decode();
        }
    } while (condition);

}

int main() {
    //waitEnter();
    startMemory(memory);
    updateScreen();
    loadMemory();
    executeProgram();
    return 0;
}
//Entrada teste
/*
 00 A0
01 00
02 20
03 98
04 00
05 90
06 A0
07 00
08 03
09 98
0a 00
0b 92
0c A0
0d 00
0e 04
0f 98
10 00
11 94
12 A0
13 00
14 05
15 98
16 00
17 96
18 A0
19 00
1a 03
1b 98
1c 00
1d 98
1e 90
1f 00
20 96
21 92
22 00
23 98
24 10
25 80
26 92
27 00
28 94
29 22
2a 00
2b 94
2c 00
2d 92
2e 1C
2f 80
30 92
31 00
32 90
33 0B
34 00
35 9A
36 00
37 88
38 00

f01 f01


 */