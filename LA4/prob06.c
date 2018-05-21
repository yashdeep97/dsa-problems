// Important
#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end){
	int length = end-start;
	char temp;
	// printf("%s\n", str);
	for (int i = 0 ; i < length/2; ++i)
	{
		temp = str[start+i];
		str[start+i] = str[end-i-1];
		str[end-i-1] = temp;
	}

}

int main(){
	char s[100];
	scanf("%[^\n]%*c",s);
	int j = 0 ;
	int start = 0, end;
	while(s[j] != '\0'){
		j++;
		
		if(s[j] == ' ' || s[j] == '\0'){
			end = j;
			reverse(s,start,end);
			start = end + 1;
			j++;
		}
	}
	reverse(s,0,strlen(s));
	printf("%s\n", s);
	return 0;
}