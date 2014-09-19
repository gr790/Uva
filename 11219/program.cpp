#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int cdd, cmm, cyyyy, bdd, bmm, byyyy;

bool is_valid()
{
  if( cyyyy < byyyy )
    return false;
  if ( cyyyy == byyyy)
  {
    if ( cmm < bmm ) 
      return false;
    else if ( cmm == bmm)
    {
      if( cdd < bdd )
        return false;
    }
  }
  return true;
}

int count_age()
{
  int y = 0;
  /* get year */
  y = cyyyy - byyyy;
  /* if c month < b month, result would be -ve, decrement the year */
  if( (cmm - bmm) < 0)
    y--;
  /* if month is same, check the date also */
  if(cmm == bmm)
  {
    if( (cdd - bdd) < 0)
      y--;
  }
  return y;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t, k = 0;
  scanf("%d\n", &t);
  while(k < t)
  {
    k++;
    scanf("%d/%d/%d\n", &cdd, &cmm, &cyyyy);
    scanf("%d/%d/%d\n", &bdd, &bmm, &byyyy);
    bool invalid = is_valid();
    if(!invalid)
      printf("Case #%d: Invalid birth date\n", k); 
    else
    {
      int age = count_age();
      if(age > 130)
        printf("Case #%d: Check birth date\n", k); 
      else
        printf("Case #%d: %d\n", k, age); 
    }
    cdd = cmm = cyyyy = bdd = bmm = byyyy = 0;
  }
  return 0;
}
