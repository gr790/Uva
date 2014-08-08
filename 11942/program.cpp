#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool is_inc(vector<int> &v)
{
  int size = v.size();
  for(int i = 1; i < size; ++i)
  { 
    if( v[i] > v[i-1])
      ;
    else
      return false;
  }
  return true;
}

bool is_dec(vector<int> &v)
{
  int size = v.size();
  for(int i = 1; i < size; ++i)
  { 
    if( v[i] < v[i-1])
      ;
    else
      return false;
  }
  return true;
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int test;
  infile >> test;
  infile.ignore();
  cout << "Lumberjacks:" << endl;
  while(test--)
  {
    int i = 0, num;
    vector<int> vi; 
    while(i++ < 10)
    {
      infile >> num;
      vi.push_back(num);
    }
    if (is_inc(vi) || is_dec(vi))
      cout << "Ordered" << endl;
    else
      cout << "Unordered" << endl;
  }
  return 0;
}
