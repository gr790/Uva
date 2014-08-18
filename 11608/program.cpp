#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void solve(vector<int> &prb, vector<int> &mnth)
{
  int psz = prb.size();
  int msz = mnth.size();
  int prb_rem, prb_cons;
  prb_rem = prb_cons = 0;
  for(int i = 0, j = 0; (i<=psz) && (j<msz); ++i, ++j)
  {
    prb_rem += prb[i];
    prb_cons += mnth[j];
    prb_rem -= prb_cons;
    if(prb_rem >= 0)
      cout << "No problem! :D" << endl;
    else
    {
      cout << "No problem. :(" << endl;
      prb_rem += prb_cons;
    }
    prb_cons = 0;
  }
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t, k = 0;
  
  while(cin >> t)
  {
    if(t < 0) break;
    vector<int> prb;
    vector<int> mnth;
    int val;
    prb.push_back(t);
    for(int i = 1; i <= 12; ++i)
    {
      cin >> val;
      prb.push_back(val);
    }
    for(int i = 0; i < 12; ++i)
    {
      cin >> val;
      mnth.push_back(val);
    }

    printf("Case %d:\n", ++k);
    solve(prb, mnth);
    prb.clear();
    mnth.clear();
  }
  return 0;
}
