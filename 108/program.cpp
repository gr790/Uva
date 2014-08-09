#include <iostream>
#include <stdio.h>

using namespace std;
#define M 101
#define N 101

void kadane(int input[], int n, int &max)
{
    int cur, i;
    max = 0;
    cur = 0;
    for(int i = 0; i<n; i++)
    {
        cur = cur+input[i];
        if(cur > max)
        {
            max = cur;
        }
        if (cur < 0)
        {
            cur = 0;
        }
    }
}


int main()
{
    int tmp[101], n;
    int cur, max_sum;
    int i,j,k;
    int input[M][N];
    max_sum = cur = 0;

    freopen("./sample.txt", "r", stdin);
    cin >> n;


    for(i=0; i<n; ++i)
      for(j=0; j<n; ++j)
        cin >> input[i][j];
	
    for (i=0; i< n; i++)
    {
        for(k=0; k<n; k++)
            tmp[k] = 0;

        for (j=i; j<n; j++)
        {
            for(k=0; k<n; k++)
                tmp[k] += input[j][k];
            kadane(tmp, n, cur);

            if (cur > max_sum)
            {
                max_sum = cur;
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}
