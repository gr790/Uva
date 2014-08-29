#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  int k = 0;
  while(k++ < t)
  {
    printf("Case #%d:\n", k);
    string line;
    int wc = 0;
    int nc = 0;
    while( getline(cin, line))
    {
      if(line[0] == '\0' || line[0] == '\n') 
        break;
      string word, dec;
      int sz = line.size();
      int i = 0, j = 0, nc = 0;
      while(i < sz)
      {
        word.clear();
        while(i < sz && line[i] != ' ' && line[i] != '\n')
          word += line[i++];
        while(line[i]==' ')
          i++; /* for space and new ine */
        if(word.size() > nc)
          dec += word[nc++];
        else
          continue;
      }
      cout << dec << endl;
      line.clear();
      dec.clear();
    }
    if(k!=t)
      cout << endl;
  }
  return 0;
}
