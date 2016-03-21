#include <stdlib.h>
#include <stdio.h>
#include "Big_Numbers.h"

int main(int argc, char* argv[]){
	Big_Number* bigNum = createNewBigNumber(10, 1000);
	addIntToBig(bigNum, 5);
	printBigNumber(bigNum);
	subIntFromBig(bigNum, 3);
	addIntToBig(bigNum, 2000000000);
	printBigNumber(bigNum);
	addIntToBig(bigNum, 100000000);
	printBigNumber(bigNum);
	addIntToBig(bigNum, 999999999);
	//addIntToBig(bigNum, 999999999);
	printBigNumber(bigNum);
	return EXIT_SUCCESS;
}