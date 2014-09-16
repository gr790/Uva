#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int lcs_len(vector<int> &t1, vector<int> &t2)
{
  int t1_z = t1.size();
  int t2_z = t2.size();
  int c[101][101] = {0};
  for(int i = 0; i <= t1_z; ++i)
    c[i][0] = 0;
  for(int i = 0; i <= t2_z; ++i)
    c[0][i] = 0;

  for(int i = 0; i < t1_z; ++i)
  {
    for(int j = 0; j < t2_z; ++j)
    {
      if( t1[i] == t2[j])
        c[i+1][j+1] = c[i][j]+1;
      else if (c[i][j+1] >= c[i+1][j])
        c[i+1][j+1] = c[i][j+1];
      else
        c[i+1][j+1] = c[i+1][j];
    }
  }
  return c[t1_z][t2_z];
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n1, n2, val;
  int k = 0;
  while(cin >> n1 >> n2)
  {
    if(!n1 && !n2) break;
    printf("Twin Towers #%d\n", ++k);
    vector<int> t1;
    vector<int> t2;
    for(int i = 0; i < n1; ++i)
    {
      cin >> val;
      t1.push_back(val);
    }
    for(int i = 0; i < n2; ++i)
    {
      cin >> val;
      t2.push_back(val);
    }
  
    printf("Number of Tiles : %d\n", lcs_len(t1, t2));
    putchar('\n');
    t1.clear();
    t2.clear();
  }
  return 0;
}
