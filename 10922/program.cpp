#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int sum_digit(int num)
{
  int val = 0;
  while(num)
  {
    val += num%10;
    num /= 10;
  }
  return val;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  string num;
  while(cin >> num)
  {
    if(num=="0")
      break;
    int sz = num.size();
    unsigned int val = 0;
    for(int i = 0; i < sz; ++i)
      val += (num[i]-'0');

    int degree = 0;
    bool found = false;
    while(val!=0)
    {
      if(val%9==0)
        degree ++;
      else
        break;
      if(val==9)
      {
        found = true;
        break;
      }
      val = sum_digit(val);
    }
    if(found)
      cout << num <<" is a multiple of 9 and has 9-degree " << degree << "." << endl;
    else
      cout << num <<" is not a multiple of 9." << endl;
  }
  return 0;
}
