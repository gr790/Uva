#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int num;
  while( infile >> num)
  {
    if(!num) break;
    int q = num;
    infile.ignore();
    int xd, yd;
    infile >> xd >> yd;
    infile.ignore();
    while(q--)
    {
      int xc, yc;
      infile >> xc >> yc; 
      infile.ignore();
      if( xd == xc || yd == yc)
        cout << "divisa" << endl; 
      else if ( xc > xd && yc > yd )
        cout << "NE" << endl;
      else if ( xc < xd && yc > yd )
        cout << "NO" << endl;
      else if ( xc < xd && yc < yd )
        cout << "SO" << endl;
      else if ( xc > xd && yc < yd )
        cout << "SE" << endl;
    }
    
  } 

  return 0;
  
}
