#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

map<int, vector<string> > graph;

void reverse(string &str, int s, int e)
{
  while( s < e)
  {
    char tmp = str[s];
    str[s] = str[e];
    str[e] = tmp;
    s++;
    e--;
  }
}

string to_str(int num)
{
  string s;
  while(num!=0)
  {
      int r = num%10;
      s += r + '0';
      num /= 10;
  }
  reverse(s, 0, s.size()-1);
  return s;
}

void init()
{
  int lh, rh;
  graph[2].push_back("00");
  graph[2].push_back("01");
  int a = 11;
  while(a > 10 && a < 100)
  {
    lh = a/10;
    rh = a%10; 
    if( pow( (lh+rh), 2) == a )
       graph[2].push_back(to_str(a));
      a++;
  }
  graph[4].push_back("0000");
  graph[4].push_back("0001");
  a = 1000;
  while(a < 9999)
  {
    lh = a/100;
    rh = a%100;
    if( pow( (lh+rh), 2) == a )
      graph[4].push_back(to_str(a));
     a++;
  }
  graph[6].push_back("000000");
  graph[6].push_back("000001");
  a = 10000;
  while(a < 999999)
  {
    lh = a/1000;
    rh = a%1000;
    if( pow( (lh+rh), 2) == a )
    {
       if (a < 100000)
       {
         string tmp = to_str(a);
         string f = "0" + tmp;
         graph[6].push_back(f);
       }
       else  
         graph[6].push_back(to_str(a));
    }
    a++;
  }
     
  graph[8].push_back("00000000");
  graph[8].push_back("00000001");
  a = 1000000;
  while(a < 99999999)
  {
    lh = a/10000;
    rh = a%10000;
    if( pow( (lh+rh), 2) == a )
    {
      if (a < 10000000)
      {
        string tmp = to_str(a);
        string f = "0" + tmp;
        graph[8].push_back(f);
      }
     else  
        graph[8].push_back(to_str(a));
    }
    a++;
  }
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int len;

  init();

  while(infile >> len )
  {
      int size = graph[len].size();
      for(int i = 0; i < size; i++)
         cout << graph[len][i] << endl;
  }
  
  return 0;
}
