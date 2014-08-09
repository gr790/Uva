#include <stdio.h>

int arr[51] = {0};

int sort(int n)
{
	int i=0;
	int op=0;
	int j=0;
	for(i; i<n-1; ++i)
	{
		for(j=i+1; j<n; ++j)
		{
			if(arr[i] > arr[j])
			{
				op++;
			}
		}
	}	
	return op;
}
int main()
{

	int n;	
	freopen("./sample.txt", "r", stdin);
	scanf("%d", &n);
	int i=0;
	while( i < n)
	{
		int l;
		scanf("%d", &l);
		int j;
		for(j=0; j<l; ++j)
		{
			scanf("%d", &arr[j]);
		}
		int op = sort(l);
		printf("Optimal train swapping takes %d swaps.\n", op);
		i++;
		
	}
	return 0;
}
