/*
Number Attributes:
Start (least) or most significant bits?
Struct: 
[0] char max size
[1] char decimal precision
[2] char total current bits
[3] char sign bit
[4...(4 + [[1]] char decinal bits
[(4 + [1]) + 1...(4 + [2]) integer bits
[((4 + [2]) + 1...[0]] extra
*/

#include <stdlib.h>

typedef struct Big_Number{
	char* number;
}Big_Number;

Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision);

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision);