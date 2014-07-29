#include <iostream>
#include <fstream>
using namespace std;

void converts_to(int num)
{
  int new_num = 0;
  new_num = (num & 0x000000FF) << 24 | 
            (num & 0x0000FF00) << 8 |
            (num & 0x00FF0000) >> 8 |
            (num & 0xFF000000) >> 24;
  cout << num <<" converts to " << new_num << endl;
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int num;
  
  while ( infile >> num )
  {
    infile.ignore();
    converts_to(num);
  }
  return 0;

}
