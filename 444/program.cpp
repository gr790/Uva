#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int rev(int ch)
{
  int n = 0;
  while(ch)
  {
    n = (n*10) + ch%10;
    ch /= 10;
  }
  return n;
}

string to_str(int num)
{
  string s;
  while(num)
  {
    int r = num%10;
    s += r + '0';
    num /= 10;
  }
  return s;
}

string decode(string &enc)
{
  /* return the final reversible string */
  /* input is string having digits */
  int sz = enc.size();
  string s;
  for(int i = sz-1; i >= 0; --i)
  {
    if( enc[i] == '1')
    {
      s += ( (enc[i]-48)*100)+( (enc[i-1]-48)*10)+(enc[i-2]-48); 
      i = i - 2;
    }
    else
    {
      s += ( (enc[i]-48)*10)+(enc[i-1]-48);
      i--;
    }
  }
  return s;
}

string encode(string &dec)
{
  /* return the final reversible string */
  /* Non digit char in line */
  string str = "";
  int len = dec.size();
  str = to_str(dec[len-1]);
  for(int i = len-2; i >= 0; --i)
    str += to_str(dec[i]);
  return str;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  string line;
  while( getline(cin, line))
  {
    if( line[0] == '\n' || line[0] == '\0')
      cout << endl;
    else {
      string str;
      if(line[0] >= '0' && line [0] <= '9')
        str = decode(line);
      else
        str = encode(line);
      cout << str << endl;
    }
  }
  return 0;
}
