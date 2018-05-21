#include <stdio.h>
 int main(int argc, char const *argv[])
 {
 	char program[1000];
 	scanf("%[^\n]%*c", program);
 	int i = 0; 
 	int commBeg, commEnd;
 	while(program[i] != '\0'){
 		if (program[i] == '/' && program[i+1] == '*')
 		{
 			commBeg = i;
 			i++;
 		}
 		else if (program[i+1] == '/' && program[i] == '*')
 		{
 			commEnd = i+2;
 			i++;
 			int j = 0;
 			while(program[commEnd + j]!= '\0'){
 				program[j + commBeg] = program[commEnd + j];
 				j++;
 			}
 			program[commBeg + j] = '\0';
 		}
 		else if (program[i] == '/' && program[i+1] == '/')	//Single line comments ?????? 
 		{
 						
 		}
 		i++;
 	}
 	printf("%s\n", program);

 	return 0;
 }