#include "Big_Numbers.h"

const int maxbitValue = 999999999;

const int maxbitValuePlus1 = 1000000000;

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
		if (bigNumber->number[cur] > maxbitValue){
			remainder = bigNumber->number[cur] / maxbitValuePlus1;
			bigNumber->number[cur] -= (maxbitValuePlus1 * remainder);
			number = 0;
		}
		else if (bigNumber->number[cur] < 0){
			remainder = 1 - (bigNumber->number[cur] / maxbitValuePlus1);
			bigNumber->number[cur] += (maxbitValuePlus1 * remainder);
			bigNumber->number[cur] = maxbitValuePlus1 - bigNumber->number[cur];
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
	int maxLength = bigNumber->maxSize,
		cur = bigNumber->decimalPrecision,
		length = bigNumber->currentSize;
	int remainder = 0;

	
	long long int temp;

	//Go through each position in the Big_Number
	for (; cur < length; ++cur){

		//Compute the new value for this position
		//and hold it in temp to prevent overflow
		temp = ((long long int)(bigNumber->number[cur]) * number) + remainder;

		//If temp > what can be held in a position
		if (temp > maxbitValue){
			//Get the number of overflows
			remainder = (int) (temp / maxbitValuePlus1);

			//Lower temp to it's normal value (with no overflow)
			temp -= maxbitValuePlus1 * remainder;

			//Set the big number position to temp
			bigNumber->number[cur] = (int) temp;

		}//If the new number is negative for some reason
		else if(temp < 0){
			//Get the number of underflows
			remainder = (int) (1 - (temp / maxbitValuePlus1));

			//Raise temp to it's normal value
			//EX: -3 + 10 = 7 (not 3)
			temp += maxbitValuePlus1 * remainder;
			//    10 - 7 = 3
			temp = maxbitValuePlus1 - temp;

			//Set the big number position to temp
			bigNumber->number[cur] = (int) temp;

			//Make sure the remainder is negative
			remainder *= -1;
		}//If there are no over/underflows
		else{
			//Make sure the remainder is 0
			remainder = 0;

			//Set the big number position to temp
			bigNumber->number[cur] = (int)temp;
		}
	}

	//If we made it to the end of bigNumber and there is a remainder
	if (cur == length && remainder != 0){
		if (length == maxLength){

		}
		else{
			//Make sure the sign is correct
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

void freeBigNumber(Big_Number* bigNumber){
	free(bigNumber->number);
	free(bigNumber);
}