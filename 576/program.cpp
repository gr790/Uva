#include <bits/stdc++.h>
using namespace std;
bool is_vowel(char ch)
{
  string vowel = "aeiouy";
  return vowel.find(ch) != string::npos;
}
int is_ok(string &line)
{
  int cnt = 0;
  int sz = line.size();
  for(int i = 1; i <= sz; ++i)
  {
    if( is_vowel(line[i-1]) && !is_vowel(line[i]))
      cnt++;
  }
  return cnt;
}
int main()
{
  freopen("./sample.txt", "r", stdin);
  string file;
  while(getline(cin, file))
  {
    if( file == "e/o/i")
      break;
    vector<string> line(3, "");
    int j = 0, i = 0;
    int sz = file.size();
    /* get line 1 */
    while((i < sz) && (file[i] != '/'))
        line[j] += file[i++];
    j++;i++;
    /* get line 2 */
    while((i < sz) && (file[i] != '/'))
        line[j] += file[i++];
    j++;i++;
    /* get line 3 */
    while((i < sz) && (file[i] != '/'))
        line[j] += file[i++];
    
    if(is_ok(line[0]) != 5)
      printf("1\n");
    else if(is_ok(line[1]) != 7)
      printf("2\n");
    else if(is_ok(line[2]) != 5)
      printf("3\n");
    else
      printf("Y\n");
    file.clear();
  }
  return 0;

}
