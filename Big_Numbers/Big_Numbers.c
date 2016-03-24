#include "Big_Numbers.h"

Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision){
	Big_Number* bigNumber = (Big_Number*)malloc(sizeof(Big_Number));
	createBigNumber(bigNumber, decimalPrecision, intPrecision);
	return bigNumber;
}

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision){
	int length = decimalPrecision + intPrecision;
	int e = 0;
	bigNumber->number = (int*)calloc(length, sizeof(int));
	bigNumber->maxSize = length;
	bigNumber->decimalPrecision = decimalPrecision;
	bigNumber->currentSize = decimalPrecision + 1;
	bigNumber->signBit = 1;
	for (; e < decimalPrecision + 1; ++e){
		bigNumber->number[e] = 0;
	}
}

void addIntToBig(Big_Number* bigNumber, int number){
	int maxLength = bigNumber->maxSize,
		cur = bigNumber->decimalPrecision,
		length = bigNumber->currentSize;
	int remainder = 0;

	number *= bigNumber->signBit;

	//Go through each position in the Big_Number
	for (; cur < length; ++cur){
		//Add the number and remainder
		bigNumber->number[cur] += (number + remainder);

		//If there is an overflow, send it to the next position
		if (bigNumber->number[cur] >= 1000000000){
			remainder = bigNumber->number[cur] / 1000000000;
			bigNumber->number[cur] -= (1000000000 * remainder);
			number = 0;
		}
		else if (bigNumber->number[cur] < 0){
			remainder = 1-(bigNumber->number[cur] / 1000000000);
			bigNumber->number[cur] += (1000000000 * remainder);
			bigNumber->number[cur] = 1000000000 - bigNumber->number[cur];
			//++remainder;
			remainder *= -1;
			
			number = 0;
		}
		//If there is no overflow, we are done
		else{
			remainder = 0;
			break;
		}
	}

	//If we reached the end and had a remainder
	if (cur == length && remainder != 0){
		//Make sure we don't have a buffer overflow
		if (length == maxLength){
			if (remainder < 0){
				bigNumber->signBit *= -1;
			}
			else{
				bigNumber->signBit *= 1;
			}
			return;
		}
		else{
			if (remainder < 0){
				bigNumber->signBit *= -1;
			}
			else{
				bigNumber->signBit *= 1;

				//Add the final remainder to the end and increment our size
				bigNumber->number[cur] = remainder;
				++bigNumber->currentSize;
			}
		}
	}
}

void mulIntToBig(Big_Number* bigNumber, int number){
	/*int maxLength = bigNumber->maxSize,
		cur = (4 + bigNumber->decimalPrecision),
		length = (4 + bigNumber->currentSize);
	int remainder = 0;

	long long int temp;

	//Go through each position in the Big_Number
	for (; cur < length; ++cur){
		temp = (bigNumber->[cur] * number) + remainder;

	}*/
}


void printBigNumber(Big_Number* bigNumber){
	int cur = bigNumber->decimalPrecision,
		length = bigNumber->currentSize - 1;

	//Printing backwards since array stores number from leat to most significant

	//Print the first number without leading zeros
	printf("%s%d", (bigNumber->signBit == 1 ? "" : "-"), bigNumber->number[length]);

	//Print the rest with leading zeros

	for (--length; length >= cur; --length){
		printf("%09d", bigNumber->number[length]);
	}
	printf("\n");
}