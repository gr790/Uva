#include <iostream>
#include <stdio.h>

using namespace std;
typedef unsigned long long int ullong;

ullong reverse(ullong num)
{
  ullong n = 0;
	while(num!=0)
	{
		n = (n  * 10 ) + num % 10;
    num = num / 10;
  }

  return n;
}

bool check(ullong num)
{
  if( num == reverse(num) )
     return true;
  return false;
}

void check_palim(ullong num, int &iter, ullong &palim)
{
  bool is_palim = false;
  do {
       num += reverse(num);
       iter++;
       is_palim = check(num);
  }while(!is_palim);

  if(is_palim)
    palim = num;

  return;
}
int main()
{
  int n;
  freopen("./10018.txt", "r", stdin);
  cin >> n;
  int i=0;
  while(i < n)
  {
     int iter;
     ullong num, palim;
     iter = palim = 0;
     cin >> num;
     check_palim(num, iter, palim);
     cout << iter <<" "<< palim << endl;
     i++;
  }

  return 0;
}
