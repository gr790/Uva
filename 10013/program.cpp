#include <bits/stdc++.h>
using namespace std;

void sum(vector<int> a, vector<int> b, vector<int> &result)
{
	vector<int>::iterator it;
	it = a.begin();
	++it;
	reverse(it, a.end());
	it = b.begin();
	++it;
	reverse(it, b.end());

	int len = a[0] > b[0] ? a[0] : b[0];
  int i, c = 0;

  for(i=1; i<=len; ++i)
  {
    int newdig = a[i] + b[i] + c;
    if(newdig > 9)
    {
       result[i] = newdig % 10;
       c = 1;
    }
		else
		{
			result[i] = newdig;
		 	c = 0;
		}
		result[0]++;
  }

  if(c != 0)
    result[++result[0]] = c;
	
	int j = result[0];
	while(result[j] == 0)
		j++;
  for(int i = j; i > 0; --i)
    cout << result[i];
  cout << endl;
}


int main()
{
	freopen("./sample.txt", "r", stdin);
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		int m, a, b;
		scanf("%d\n", &m);
	  vector<int> num1(m+1), num2(m+1), result(m+2);	
		int st = 1; 
		/* st index will be used to store the value */
		/* st == 0, will store the size of string */
		num1[0] = num2[0] = 0;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d\n", &a, &b);
			num1[st] = a;
			num2[st] = b;
			st++;
		}
		num1[0] = num2[0] = m;
		sum(num1, num2, result);
		if(t!= 0)
			cout << endl;
		num1.clear(); 
		num2.clear();
		result.clear();
	}
	return 0;
}
