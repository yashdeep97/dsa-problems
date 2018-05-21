#include <stdio.h>

int factorial(int n)
{
    int fac=1;
    int i;
    for(i=1;i<=n;i++)
        fac=fac*i;
    return fac;
}

int main(int argc, char const *argv[])
{
	char str[100];
	scanf("%s",str);
	int q;
	scanf("%d",&q);
	int ans[q];
	for (int t = 0; t < q; ++t)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int alphabetCount[26];
		for (int i = 0; i < 26; ++i)
		{
			alphabetCount[i] = 0;
		}
		for (int i = l-1; i < r; ++i)
		{
			alphabetCount[(int)str[i] - 97]++;
		}
		int pairs = 0;
		int identicalPairs[26];
		for (int i = 0; i < 26; ++i)
		{
			pairs += alphabetCount[i]/2;
			identicalPairs[i] = alphabetCount[i]/2;
			alphabetCount[i] %= 2;
		}
		int singles = 0;
		for (int i = 0; i < 26; ++i)
		{
			singles += alphabetCount[i];
		}
		if (pairs == 0)
		{
			ans[t] = singles;
		}
		else
		{
			int permutations = factorial(pairs);
			for (int i = 0; i < 26; ++i)
			{
				permutations = permutations/factorial(identicalPairs[i]);
			}
			if (singles == 0)
			{
				ans[t] = permutations;
			}
			else{
				ans[t] = permutations*singles;
			}
		}
	}
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}