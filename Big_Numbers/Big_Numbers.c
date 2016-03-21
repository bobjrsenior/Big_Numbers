#include "Big_Numbers.h"

Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision){
	Big_Number* bigNumber = (Big_Number*)malloc(sizeof(Big_Number));
	createBigNumber(bigNumber, decimalPrecision, intPrecision);
	return bigNumber;
}

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision){
	int length = 4 + decimalPrecision + intPrecision;
	int e = 4;
	bigNumber->number = (int*)calloc(length, sizeof(int));
	bigNumber->number[0] = length;
	bigNumber->number[1] = decimalPrecision;
	bigNumber->number[2] = decimalPrecision + 1;
	bigNumber->number[3] = 1;
	for (; e < 4 + decimalPrecision + 1; ++e){
		bigNumber->number[e] = 0;
	}
}

void addIntToBig(Big_Number* bigNumber, int number){
	int maxLength = bigNumber->number[0],
		cur = (4 + bigNumber->number[1]),
		length = (4 + bigNumber->number[2]);
	int remainder = 0;

	for (; cur < length; ++cur){
		bigNumber->number[cur] += (number + remainder);
		if (bigNumber->number[cur] >= 1000000000){
			bigNumber->number[cur] -= 1000000000;
			number = 0;
			remainder = 1;
		}
		else{

			remainder = 0;
			break;
		}
	}
	if (cur == length && remainder != 0){
		if (length == maxLength){
			return;
		}
		else{
			bigNumber->number[cur] = remainder;
			++bigNumber->number[2];
		}
	}
}

void printBigNumber(Big_Number* bigNumber){
	int cur = (4 + bigNumber->number[1]),
		length = (4 + bigNumber->number[2]) - 1;

	printf("%d", bigNumber->number[length]);

	for (--length; length >= cur; --length){
		printf("%09d", bigNumber->number[length]);
	}
	printf("\n");
}