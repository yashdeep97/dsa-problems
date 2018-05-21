#include <stdio.h>
void tensPos(int n){
	switch(n){
		case 2: printf("Twenty ");
		break;
		case 3: printf("Thirty ");
		break;
		case 4: printf("Forty ");
		break;
		case 5: printf("Fifty ");
		break;
		case 6: printf("Sixty ");
		break;
		case 7: printf("Seventy ");
		break;
		case 8: printf("Eighty ");
		break;
		case 9: printf("Ninety ");
		break;
		default: printf("Invalid No.\n");
		break;
	}
}
void specialCases(int n){
	switch(n){
		case 0: printf("Ten ");
		break;
		case 1: printf("Eleven ");
		break;
		case 2: printf("Twelve ");
		break;
		case 3: printf("Thirteen ");
		break;
		case 4: printf("Fourteen ");
		break;
		case 5: printf("Fifteen ");
		break;
		case 6: printf("Sixteen ");
		break;
		case 7: printf("Seventeen ");
		break;
		case 8: printf("Eighteen ");
		break;
		case 9: printf("Nineteen ");
		break;
		default: printf("Invalid No.\n");
		break;
	}
}
void numToWord(int n){
	switch(n){
		case 1: printf("One ");
		break;
		case 2: printf("Two ");
		break;
		case 3: printf("Three ");
		break;
		case 4: printf("Four ");
		break;
		case 5: printf("Five ");
		break;
		case 6: printf("Six ");
		break;
		case 7: printf("Seven ");
		break;
		case 8: printf("Eight ");
		break;
		case 9: printf("Nine ");
		break;
		default: printf("Invalid No.\n");
		break;
	}
}

 int main(int argc, char const *argv[])
 {
 	char num[5];
 	scanf("%s", num);
 	int numberOfdidgits;
 	for (int i = 0; i <= 4; ++i)
 	{
 		if (num[i] == '\0')
 		{
 			numberOfdidgits = i;
 			break;
 		}
 	}
 	char finNum[5];
 	for (int i = 0; i < 3; ++i)
 	{
 		finNum[i] = '0';
 	}
 	for (int i = 0; i < numberOfdidgits; ++i)
 	{
 		finNum[3-i] = num[numberOfdidgits - i -1];
 	}
 	finNum[4] = '\0';
 	if ((int)finNum[0]-48)
 	{
 		numToWord((int)finNum[0]-48);
 		printf("Thousand ");
 	}
 	if ((int)finNum[1]-48)
 	{
 		numToWord((int)finNum[1]-48);
 		printf("Hundred ");
 	}
 	if ((int)finNum[2]-48)
 	{
 		printf("and ");
 		if ((int)finNum[2]-48 != 1)
 		{
 			tensPos((int)finNum[2]-48);
 		}else{
 			specialCases((int)finNum[3]-48);
 		}
 		
 	}
 	if ((int)finNum[2]-48 != 1)
 	{
 		numToWord((int)finNum[3]-48);
 	}
 	
 	printf("\n");
 	return 0;
 }