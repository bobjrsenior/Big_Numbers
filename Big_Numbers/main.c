#include <stdlib.h>
#include <stdio.h>
#include "Big_Numbers.h"

int main(int argc, char* argv[]){

	printf("Addition and Subtraction Tests\n");
	Big_Number* bigNum = createNewBigNumber(10, 1000);
	Big_Number* bigNum2;
	addIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	subIntFromBig(bigNum, 8);
	printBigNumber(bigNum);
	addIntToBig(bigNum, 2000000000);
	printBigNumber(bigNum);
	addIntToBig(bigNum, 100000000);
	printBigNumber(bigNum);
	addIntToBig(bigNum, -999999999);
	//addIntToBig(bigNum, 999999999);
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	printf("**********\n");

	printf("Multiplication and Division Tests\n");

	bigNum = createNewBigNumber(10, 1000);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	addIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 10000000);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, 10000000);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, -1);
	printBigNumber(bigNum);
	mulIntToBig(bigNum, -2);
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	printf("**********\n");

	printf("Adding Two Big Numbers\n");
	bigNum = createNewBigNumber(10, 1000);
	bigNum2 = createNewBigNumber(10, 1000);

	setIntToBig(bigNum, 100000000);
	mulIntToBig(bigNum, 5);
	mulIntToBig(bigNum, 5);

	setIntToBig(bigNum2, 10000000);
	mulIntToBig(bigNum2, 5);
	mulIntToBig(bigNum, 6);
	mulIntToBig(bigNum, 5);

	printf("BigNum1: ");
	printBigNumber(bigNum);
	printf("BigNum2: ");
	printBigNumber(bigNum2);

	AddBigToBig(bigNum, bigNum2);
	printf("Additiong: ");
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	freeBigNumber(bigNum2);

	printf("**********\n");

	printf("Factorial Tests\n");

	printf("Unimplemented\n");

	/*
	bigNum = createNewBigNumber(10, 1000);

	bigFactorial(bigNum, 1024);
	printf("1000!:\n");
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	*/
	printf("**********\n");
	return EXIT_SUCCESS;
}