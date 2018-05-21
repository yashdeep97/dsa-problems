#include <stdio.h>
#include <string.h>

void checkNewChar(char c, char * charArray, int occur[]){
	int len = strlen(charArray);
	for (int i = 0; i < len; ++i)
	{
		if (charArray[i] == c)
		{	
			occur[i]++;
			return;
		}
	}
	charArray[len] = c;
	charArray[len+1] = '\0';
	occur[len] = 1;
	return;
}

int main(){
	char s[100];
	scanf("%[^\n]%*c",s);
	char charArray[100];
	charArray[0] = '\0';
	int occur[100];
	int i = 0;
	while(s[i]!='\0'){
		checkNewChar(s[i],charArray,occur);
		i++;
	}
	for (int i = 0; i < strlen(charArray); ++i)
	{
		printf("%c %d\n", charArray[i],occur[i]);
	}
	return 0;
}