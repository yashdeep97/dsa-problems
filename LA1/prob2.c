#include <stdio.h>
#include <string.h>
int main(){
	char s[100], l[100];
	scanf("%[^\n]%*c",s);
	scanf("%[^\n]%*c",l);
	int x = 0;
	int count = 0;
	while(l[x] != '\0'){
		int a = 0;
		int flag = 0;
		while(s[a] != '\0'){
			if (l[x+a] == s[a])
			{
				flag++;
				a++;
			}
			else{
				flag = 0;
				break;
			}
		}

		if (flag == strlen(s))
		{
			if (x == 0 && (l[x+a]=='\0' || l[x+a]==' '))
			{
				count++;
			}
			else if (l[x-1] == ' ' && (l[x+a]=='\0' || l[x+a]==' '))
			{
				count++;
			}
		}
		x++;
	}
	printf("%d\n", count);
	return 0;
}