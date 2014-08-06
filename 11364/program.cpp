#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int test;
  infile >> test;
  infile.ignore();
  while(test--)
  {
    int ns, val;
    vector<int> vi;
    infile >> ns;
    for(int i = 0; i < ns; ++i)
    {
      infile >> val;
      vi.push_back(val);
    }
    sort(vi.begin(), vi.end());
    int walk = 0;
    for(int i = 1; i < ns; ++i)
      walk += vi[i] - vi[i-1];

    cout << walk * 2 << endl;
      
  }
  
  return 0;
}
