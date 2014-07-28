#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

/* main algorithm */
/* station is maintained as a stack, adding coaches in increasing order upto max_num */
/* pop the stack till it matches the input sequences */
/* it we are able to send all coaches on track b, return Yes, else No */

/* Solution is to determine, are we able to send coaches on track B in increasing sequences */
bool marshal(int *track, int max)
{
  stack<int> station;
  int cur = 1, in = 0;
  while(cur <= max )
	{
		station.push(cur);
		while( !station.empty() && station.top() == track[in])
		{
			station.pop();
      in++;
      if ( in > max) 
        break;
		}
    cur++;
  }
 
  if (station.empty()) return true;
  return false;
}

int main()
{
	ifstream infile;
  infile.open("./sample.txt");
  int max_num;
  
  while( infile >> max_num )
  {
    infile.ignore();
    bool exit_block = false;
		if ( max_num == 0 ) { 
       exit_block = true;
       break;
    }
    else {
       bool next_block = false;
       while(!next_block) { 
         int *track = new int[max_num];
       	 for(int i = 0; i < max_num; ++i ) {
           infile >> track[i];
           if(track[0] == 0) {
             next_block = true;
             break;
           }
         }
       	 if(next_block) {
           cout << endl;
           break;
         }
         /* Actual algorithm */
         bool departed = marshal(track, max_num);
         if(departed)
           cout <<"Yes" << endl;
         else
           cout <<"No" << endl;
			 }
		}
	}
	return 0;
}
