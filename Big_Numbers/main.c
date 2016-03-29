#include <stdlib.h>
#include <stdio.h>
#include "Big_Numbers.h"

int main(int argc, char* argv[]){

	printf("Addition and Subtraction Tests\n");
	Big_Number* bigNum = createNewBigNumber(10, 1000);
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

	printf("Factorial Tests\n");

	bigNum = createNewBigNumber(10, 1000);

	bigFactorial(bigNum, 1024);
	printf("1000!:\n");
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	printf("**********\n");
	return EXIT_SUCCESS;
}