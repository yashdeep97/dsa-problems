// Very very important

#include <stdio.h>
#include <string.h>

void checkFunction(char * func){
	int array[9];
	for (int i = 0; i < 9; ++i)
	{
		array[i] = 0;
	}
	int index = 0;
	array[index] = (int)func[0] - 48;
	for (int i = 1; i < 17; ++i)
	{
		if (func[i] == '+')
		{
			index++;
			i++;
			array[index] = (int)func[i] - 48;
		}
		else if (func[i] == '-')
		{
			index++;
			i++;
			array[index] = 0 - ((int)func[i] - 48);
		}
		else if (func[i] == '*')
		{
			i++;
			if (array[index] < 0)
			{
				array[index] = array[index]*10 - ((int)func[i] - 48);
			}
			else array[index] = array[index]*10 + ((int)func[i] - 48);
		}
	}
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum += array[i];
	}
	if (sum == 100)
	{
		for (int i = 0; i < 17; ++i)
		{
			if (func[i] != '*')
			{
				printf("%c", func[i]);
			}			
		}
		printf("\n");
	}
	
	
}

void fillFunction(char * func, int index, char oper){
	if (index == 18)
	{
		checkFunction(func);
		return;
	}
	func[index-1] = oper;

	fillFunction(func,index+2,'+');
	if (index != 16)
	{
		fillFunction(func,index+2,'-');

		fillFunction(func,index+2,'*');
	}

}

int main(int argc, char const *argv[])
{
	char func[] = "10203040506070809\0";
	fillFunction(func,0,' ');
	return 0;
}