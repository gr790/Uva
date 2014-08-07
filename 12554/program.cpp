#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void tokenize (string bstr, vector<string> &tokens)
{
  int len = bstr.size();
  string word;
  int i,j;
  for(i = 0, j = 0; i < len; ++i, j++)
  {
    if(bstr[i]!=' ')
      word += bstr[i];
    else
    {
      tokens.push_back(word);
      word.clear();
    }
  }
  /* put last word */
  if ( i == len)
      tokens.push_back(word);
  
}

int main()
{
  string bstr = "Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you";
  vector<string> tokens;
  tokenize(bstr, tokens);
  ifstream infile;
  infile.open("./sample.txt");
  int num;
  infile >> num;
  infile.ignore();
  
  vector<string> vs;
  for(int i = 0; i < num; ++i)
  {
    string  val;
    infile >> val;
    vs.push_back(val);
    infile.ignore();
  }

  vector<string>::iterator it;
  vector<string>::iterator tk;
  for(it = vs.begin(), tk = tokens.begin(); it != vs.end();)
  {
      if (tk != tokens.end())
      {
        cout << *it <<": " << *tk << endl;
        ++tk;
        ++it;
      }
      else
        tk = tokens.begin();
      
  }
  /* there are some token left, but all people have sung their word*/
  /* again iterate thru people, untill all remaining token consumed */
  it = vs.begin();
  while(tk!=tokens.end())
  {
    if( it != vs.end())
    {
     cout << *it <<": " << *tk << endl;
     ++it;
     ++tk;
    }
    else
      it = vs.begin();
  }
  return 0;
}
