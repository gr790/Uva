#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int find(int num, int m )
{
	list<int> clist;

	for(int i = 1; i <= num; ++i)
		clist.push_back(i);

	list<int>::iterator iter;
	list<int>::iterator next;

	/* start from the beginning, remove the first element in each case */
	iter = clist.begin();
	next = iter;
	++next;
	clist.erase(iter);

	for(iter = next; clist.size()!=1; iter = next)
	{
		for(int i = 1; i < m; ++i)
		{
			++iter;
			if(iter == clist.end())
				iter = clist.begin();
		}

		next = iter; 
		/* next player will be one after the removed player */
		++next;
		clist.erase(iter);
		/* if next is also the end of list, it will point to the begin of list */
		if(next == clist.end())
			next = clist.begin();

#if 0
		list<int>::iterator print;
		for(print = clist.begin(); print!=clist.end(); ++print)
			cout << *print <<' ';
		cout << endl;
#endif
	}
	return *iter;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");

	int num;
	while( infile >> num )
	{
		if(!num)
			break;
	
		int m = 1;
		int found = 0;
		while( (found = find(num, m)) != 13) 
		{
			m++;
		}
		cout << m << endl;
	}

	return 0;
}
