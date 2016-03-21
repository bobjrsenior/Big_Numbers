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

	//Go through each position in the Big_Number
	for (; cur < length; ++cur){
		//Add the number and remainder
		bigNumber->number[cur] += (number + remainder);

		//If there is an overflow, send it to the next position
		if (bigNumber->number[cur] >= 1000000000){
			remainder = bigNumber->number[cur] / 1000000000;
			bigNumber->number[cur] -= (1000000000 * remainder);
			number = 0;
			
		}//If there is no overflow, we are done
		else{
			remainder = 0;
			break;
		}
	}

	//If we reached the end and had a remainder
	if (cur == length && remainder != 0){
		//Make sure we don't have a buffer overflow
		if (length == maxLength){
			return;
		}
		else{
			//Add the final remainder to the end and increment our size
			bigNumber->number[cur] = remainder;
			++bigNumber->number[2];
		}
	}
}

void printBigNumber(Big_Number* bigNumber){
	int cur = (4 + bigNumber->number[1]),
		length = (4 + bigNumber->number[2]) - 1;

	//Printing backwards since array stores number from leat to most significant

	//Print the first number without leading zeros
	printf("%d", bigNumber->number[length]);

	//Print the rest with leading zeros
	for (--length; length >= cur; --length){
		printf("%09d", bigNumber->number[length]);
	}
	printf("\n");
}