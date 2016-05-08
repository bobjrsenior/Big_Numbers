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
#include <stdint.h>
#include <math.h>

/* ===== STRUCTS ===== */
typedef struct Big_Number{
	int maxSize;
	int decimalPrecision;
	int currentSize;
	int signBit;
	int* number;
}Big_Number;

typedef struct Prime_Array{
	int primeSize;
	int* primeFrequencies;
}Prime_Array;

/* ===== CONSTANTS ===== */
extern const int maxbitValue;

extern const int maxbitValuePlus1;

int generatePrimes(int maxPrime);

/* ===== CREATE FUNCTIONS ===== */
Big_Number* createNewBigNumber(int decimalPrecision, int intPrecision);

void createBigNumber(Big_Number* bigNumber, int decimalPrecision, int intPrecision);

Prime_Array* createNewPrimeArray(int primeSize);

void createPrimeArray(Prime_Array* primeArray, int primeSize);

/* ===== SIMPLE MATH FUNCTIONS ===== */
void setIntToBig(Big_Number* bigNumber, int number);

void addIntToBig(Big_Number* bigNumber, int number);

#define subIntFromBig(bigNumber, number) (addIntToBig((bigNumber), (-(number))))

void AddBigToBig(Big_Number* bigNumber, Big_Number* bigNumber2, int offsetBits);

void mulIntToBig(Big_Number* bigNumber, int number);

void divIntFromBig(Big_Number* bigNumber, int number);

void multBigToBigInt(Big_Number* bigNumber, Big_Number* bigNumber2);

/* ===== NON-SIMPLE MATH FUNCTIONS ===== */
Big_Number* bigFactorialNew(int number);

void bigFactorial(Big_Number* bigNumber, int number);

Prime_Array* newPrimeFactorial(int number);

void primeFactorial(Prime_Array* primeArray, int number);

int piNumber(int number);

/* ===== OTHER FUNCTIONS ===== */

void copyBigNumber(Big_Number* bigNumber, Big_Number* bigNumber2);

void printBigNumber(Big_Number* bigNumber);

void printPrimeArray(Prime_Array* primeArray);

void freeBigNumber(Big_Number* bigNumber);

void freePrimeArray(Prime_Array* primeArray);