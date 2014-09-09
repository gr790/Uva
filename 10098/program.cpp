#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t;
  scanf("%d\n", &t);
  while(t--)
  {
    char word[11];
    scanf("%s\n", word);
    string w(word);
    sort(w.begin(), w.end());
    do
    {

      printf("%s\n",w.c_str());      
    } while(next_permutation(w.begin(), w.end()));
    putchar('\n');
  }
  return 0;
}
