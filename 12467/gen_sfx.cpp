#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
  freopen("./sample.txt", "r", stdin);
  string line;
  getline(cin, line);
  int sz = line.size();
  for(int i = 0; i < sz; ++i)
  {
    for(int j = sz-1; j >= i; --j)
      cout << line.substr(i, sz-j) << endl;
  }
  return 0;
}
  
