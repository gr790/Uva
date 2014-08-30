#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
map<string, int> freq;
map<char, int> tel;

string convert_to_us(string &line)
{
  string std = "";
  int sz = line.size();
  for(int i = 0; i < sz; ++i)
  {
    if(line[i] != '-')
    {
      if(isalpha(line[i]))
        std += tel[line[i]]+'0';
      else
        std += line[i];
    }
  }
  return std;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  tel['A'] = tel['B'] = tel['C'] = 2;
  tel['D'] = tel['E'] = tel['F'] = 3;
  tel['G'] = tel['H'] = tel['I'] = 4;
  tel['J'] = tel['K'] = tel['L'] = 5;
  tel['M'] = tel['N'] = tel['O'] = 6;
  tel['P'] = tel['R'] = tel['S'] = 7;
  tel['T'] = tel['U'] = tel['V'] = 8;
  tel['W'] = tel['X'] = tel['Y'] = 9;

  int test;
  cin >> test;
  cin.ignore();

  while(test--)
  {
    int no;
    cin >> no; 
    cin.ignore();
    while(no)
    {
      string line;
      getline(cin, line);
      string std_num = convert_to_us(line);
      freq[std_num]++;
      no--;
    }
    cin.ignore();
    map<string, int>::iterator it;
    bool found = false;
    for(it = freq.begin(); it != freq.end(); ++it)
    {
      if(it->second > 1)
      {
        found = true;
        cout << it->first.substr(0,3) <<'-'<< it->first.substr(3,7) <<' '<< it->second << endl;
      }
    }
    if(!found)
      cout << "No duplicates." << endl;
    freq.clear();
    if(test)
      cout << endl;
  }
  return 0;
}
