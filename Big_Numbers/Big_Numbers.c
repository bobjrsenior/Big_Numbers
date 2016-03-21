#include "Big_Numbers.h"

Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision){
	Big_Number* bigNumber = (Big_Number*)malloc(sizeof(Big_Number));
	createBigNumber(bigNumber, decimalPrecision, intPrecision);
	return bigNumber;
}

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision){
	int length = 4 + decimalPrecision + intPrecision;
	bigNumber->number = (char*)calloc(length, sizeof(char));
	bigNumber->number[0] = length;
	bigNumber->number[1] = decimalPrecision;
	bigNumber->number[2] = intPrecision;
	bigNumber->number[3] = 0;
}