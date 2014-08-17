#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int n;
  while(cin >> n)
  {
    if(!n) break;
    vector<int> st;
    int val;
    while(n--)
    {
      cin >> val;
      st.push_back(val);
    }

    int end = 1422;
    sort(st.begin(), st.end());

    int size = st.size();
    bool np = true;
    for(int i = 1; i < size; ++i)
    { 
      if( abs(st[i]-st[i-1]) > 200)
      {
        np = false;
        break;
      }
    }

    /* return journey, if there is no charging station at DJ */
    if(np) { 
      if( 2*(end - st[size-1]) > 200)
        np = false;
    }

    if(np) cout << "POSSIBLE" << endl;
    else  cout << "IMPOSSIBLE" << endl;
    st.clear();
  }

  return 0;
}
