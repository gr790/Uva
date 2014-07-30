#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long int ulint;

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int test;
	while(infile >> test)
	{
		if(!test)
			break;
		priority_queue<ulint, vector<ulint>, greater<ulint> > que;
		int num;
		while(test--)
		{
			infile >> num;
			que.push(num);
		}

		ulint sum = 0;
		while(que.size() > 1)
		{
			ulint tp1 = que.top(); que.pop();
			ulint tp2 = que.top(); que.pop();
			sum += (tp1 + tp2);
			que.push(tp1+tp2);
			
		}
		cout << sum << endl;
	}

	return 0;
}

