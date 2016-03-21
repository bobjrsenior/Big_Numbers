/*
Number Attributes:
Start (least) or most significant bits?
Struct: 
[0] int max size
[1] int decimal precision
[2] int total current bits
[3] int sign bit
[4...(4 + [[1]] int decinal bits
[(4 + [1]) + 1...(4 + [2]) integer bits
[((4 + [2]) + 1...[0]] extra
*/
/*
Digits per index: 9
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Big_Number{
	int* number;
}Big_Number;

Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision);

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision);

void addIntToBig(Big_Number* bigNumber, int number);

#define subIntFromBig(bigNumber, number) (addIntToBig((bigNumber), (-(number))))

void printBigNumber(Big_Number* bigNumber);