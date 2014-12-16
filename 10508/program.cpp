#include <bits/stdc++.h>
using namespace std;
map<int, string> tbl;
int main()
{
  freopen("./sample.txt", "r", stdin);
  int word, letter, cnt;
  
  /* get the count of word and letter in each word */
  while (cin >> word >> letter)
  {
     vector <string> str;
     string org, mor, temp;
     str.resize(word);
     /* get the original word */
     cin >> org;
     cin >> mor;
 
     /* get the temp word one by one */
     for (int j = 2; j < word; ++j)
     { 
       cin >> temp;
       cnt = 0;
       /* calculate the total mismatching word between original word and temp word */
       for (int i = 0; i < letter; ++i)
       {
          if (org[i] != temp[i])
              ++cnt;
       }
       tbl.insert(make_pair(cnt, temp));
     }
     cout << org << endl;
     map<int, string>::iterator it;
     for(it = tbl.begin(); it != tbl.end(); ++it)
        cout << it->second << endl;
     cout << mor << endl;
     str.clear();
     tbl.clear();
  }
  return 0;
}
