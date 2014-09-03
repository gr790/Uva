#include <iostream>
#include <fstream>
#include <list>
#include <vector>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;
  while(scanf("%d\n", &num)==1)
  {
    if(!num) break;
    list<int> stk;
    for(int i = 1; i <= num; ++i)
      stk.push_back(i);

    vector<int> dis;
    while(stk.size()!=1)
    {
      dis.push_back(stk.front());
      stk.pop_front();
      stk.push_back(stk.front());
      stk.pop_front();
    }
    cout <<"Discarded cards:";
    vector<int>::iterator it;
    vector<int>::iterator tmp;
    for(it = dis.begin(); it!=dis.end(); ++it)
    {
      tmp = it; 
      if(++tmp != dis.end())
        printf(" %d,", *it);
      else
        printf(" %d", *it);
    }
    cout << endl;
    cout <<"Remaining card: " << stk.front() << endl;
    stk.clear();
    dis.clear();
  }
  return 0;
}
