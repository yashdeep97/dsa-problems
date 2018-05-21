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
	int i=0;
	while(s[i] != '\0'){
		for (int j = 0; j < 3; ++j)
		{
			if (s[i] == 'z')
			{
				s[i] = 'a';
			}
			else if (s[i] == ' ')
			{

			}
			else{
				s[i]++;
			}
		}
		i++;
	}

	int j = 0 ;

	int start = 0, end;

	while(s[j] != '\0'){
		j++;
		
		if(s[j] == ' ' || s[j] == '\0'){
			end = j;
			// printf("%d %d\n", start, end);
			reverse(s,start,end);
			start = end + 1;
			j++;
		}
	}

	printf("%s\n", s);
	return 0;
}