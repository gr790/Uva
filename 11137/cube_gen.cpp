#include <iostream>
using namespace std;

int main()
{
  for(int i = 1; i < 300; ++i)
  {
    int j = i*i*i;
    if( j <= 9261)
       cout << j << endl;
  }
  return 0;
}
