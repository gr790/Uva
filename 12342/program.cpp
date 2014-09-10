#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
typedef unsigned long long int ullong;
#define CEIL(x) ((x-int(x))==0?(int)x : int(x+1))
double tax(ullong sal)
{
  if(sal <= 180000)
    return 0;
  /* get the first bracket */
  int fb = sal - 180000;
  double mt = 0, sb = 0, tb = 0, rb = 0;
  if ( fb <= 300000)
  {
    double t = (double)(fb*10)/100;
    if(t < 2000)
      return 2000.00;
    else
      return t;
  }
  else { 
    /* get the second bracket */
    sb = fb - (300000);
    mt += 30000;
  }
  if( sb <= 400000)
  {
    mt += (double)(sb*15)/100;
    return mt;
  }
  else {
    /* get the third bracket */
    tb = sb - 400000;
    mt += 60000;
  }
  if( tb <= 300000)
  {
    mt += (double)(tb*20)/100;
    return mt;
  }
  else
  {
    rb = tb - 300000;
    mt += 60000;
  }
  mt += (double)(rb*25)/100;
  return mt;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t,k = 0;
  scanf("%d\n", &t);
  while(k++ < t)
  {
    unsigned long long sal = 0;
    cin >> sal;
    double t = tax(sal);
    printf("Case %d: %d\n", k, CEIL(t));
  }
  return 0;
}
