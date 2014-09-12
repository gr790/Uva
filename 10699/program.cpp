#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/* Prime Number */

#define SIZE 1000000LL
bitset<SIZE+1> prime;
vector<int> gpf;

void sieve()
{
   int sq = ceil(sqrt(SIZE));
   for(int i = 2; i <= sq; ++i)
   {
     if(!prime.test(i))
     {
        for(int j = i*i; j <= SIZE; j += i)
          prime.set(j,1);
     }
   }
   for(int i = 2;i <= SIZE; ++i)
   {
      if(!prime.test(i))
        gpf.push_back(i);
   }
}

bool is_sieve_prime(int num)
{
   return !prime.test(num);
}

int cal_pf(int num)
{
	bool found = false;
	int cnt = 0;
  vector<int>::iterator it;
  int sq = ceil(sqrt(num));
  for(it = gpf.begin(); (it != gpf.end() && *it <= sq); ++it)
  {
     int rem = 0;
     int p = *it;
     do
     {
       rem = num%p;
       if(!rem)
       {
	   		if(!found)
				{
					found = true;
					cnt++;
					
				}
        num = num/p;
      }
      else
			{
				found = false;
        break;
			}
    }while(num!=1);
  } 
  if(num!=1)
		cnt++;

	return cnt;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	sieve();
	int num;
	
	while ( infile >> num )
	{
		if(!num)
			break;
		printf("%d : %d\n", num, cal_pf(num));
	}

	return 0;
}
