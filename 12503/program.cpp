#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int get_cmd(string &s)
{
  int len = s.size();
  int val = 0;
  for(int i = 0; i < len; ++i)
  {
     if( s[i] >= '0' && s[i] <= '9')
       val = (val * 10 ) + (s[i] - '0');
  }
  return val;
  
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int test;
  infile >> test;
  infile.ignore();

  while(test--)
  {
    int nis;
    infile >> nis;
    infile.ignore();
    map<int, string> set;
    int k = 1;
    while(k <= nis)
    {
      string inst;
      getline(infile, inst, '\n');
      set[k] = inst;
      k++;
    }
    
    int pos = 0;
    map<int, string>::iterator it;
    for(it = set.begin(); it != set.end(); ++it)
    {
      if( it->second == "LEFT")
      {
        pos--;
      } else if (it->second == "RIGHT") {
        pos++;
      } else {
        int cmd = get_cmd(it->second);
        if (set[cmd] == "LEFT")
        {
          pos--;
          set[it->first] = "LEFT";
        }
        else if ( set[cmd] == "RIGHT")
        {
          pos++;
          set[it->first] = "RIGHT";
        }
      }
    }
    cout << pos << endl;
    set.clear();
  }

  return 0;
}
