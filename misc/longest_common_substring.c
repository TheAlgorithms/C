#include <stdio.h>
#include <string.h>

int pd[10000][10000];

int max(int a, int b)
{
	return a > b ? a : b;
}

int longestcommonsubstring(char *a, char *b)
{
	int i, j, ans = 0;
	int t1 = strlen(a), t2 = strlen(b);
	for(i = 1; i < t1; i++)
	for(j = 1; j < t2; j++)
		if(a[i-1] == b[j-1])
			pd[i][j] = pd[i-1][j-1] + 1,
				ans = max(ans, pd[i][j]);
		else
			pd[i][j] = 0;
	return ans;
}

int main()
{
	char s1[55], s2[55];
	
	while(fgets(s1, 54, stdin) != NULL
		&& fgets(s2, 54, stdin) != NULL)	
		printf("%d\n", longestcommonsubstring(s1, s2));
		
	return 0;
}
