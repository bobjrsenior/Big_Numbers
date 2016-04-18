#include <stdlib.h>
#include <stdio.h>
#include <sys\timeb.h>
#include "Big_Numbers.h"

int main(int argc, char* argv[]){

	struct timeb start, end;
	unsigned int diff;

	printf("Addition and Subtraction Tests\n");
	Big_Number* bigNum = createNewBigNumber(10, 1000);
	Big_Number* bigNum2;
	Prime_Array* primeArray;

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

	AddBigToBig(bigNum, bigNum2, 0);
	printf("Additiong: ");
	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	freeBigNumber(bigNum2);

	printf("**********\n");

	printf("Copying Tests\n");

	bigNum = createNewBigNumber(10, 1000);
	bigNum2 = createNewBigNumber(10, 1000);

	setIntToBig(bigNum, 100000000);
	mulIntToBig(bigNum, 11);
	mulIntToBig(bigNum, 5);

	copyBigNumber(bigNum2, bigNum);

	printf("First Num: ");
	printBigNumber(bigNum);
	printf("Copied Num: ");
	printBigNumber(bigNum2);

	freeBigNumber(bigNum);
	freeBigNumber(bigNum2);

	printf("**********\n");

	/*printf("Multiplying Two Big Numbers Tests\n");

	bigNum = createNewBigNumber(10, 1000);
	bigNum2 = createNewBigNumber(10, 1000);

	setIntToBig(bigNum, 100);
	copyBigNumber(bigNum2, bigNum);

	multBigToBigInt(bigNum, bigNum2);

	printBigNumber(bigNum);

	freeBigNumber(bigNum);
	freeBigNumber(bigNum2);


	printf("**********\n");
	*/
	printf("Big Factorial Tests\n");

	//printf("Unimplemented\n");

	
	int fact = 1024;

	bigNum = createNewBigNumber(10, fact);

	ftime(&start);

	bigFactorial(bigNum, fact);

	ftime(&end);

	diff = (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));


	//printBigNumber(bigNum);

	printf("%d!:\n", fact);

	printf("\nOperation took %u milliseconds\n", diff);

	freeBigNumber(bigNum);
	
	printf("**********\n");

	printf("Swing Factorial Tests\n");

	printf("Unimplemented\n");

	printf("**********\n");

	printf("Prime Factorial Tests\n");

	fact = 16384;

	primeArray = newPrimeFactorial(fact);

	printPrimeArray(primeArray);

	freePrimeArray(primeArray);

	printf("**********\n");

	return EXIT_SUCCESS;
}