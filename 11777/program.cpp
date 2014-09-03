#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t, k;
  cin >> t;
  cin.ignore();
  k = 0;
  while(k < t)
  {
    int trm1, trm2, attend, test1, test2, test3, final;
    cin >> trm1 >> trm2 >> final >> attend >> test1 >> test2 >> test3;
    vector<int> vi;
    vi.push_back(test1);
    vi.push_back(test2);
    vi.push_back(test3);
    sort(vi.begin(), vi.end());
    int avg = (int)(vi[1]+vi[2])/2;
    int mark = trm1 + trm2 + final + attend + avg;
    char ch = 'F';
    if( mark >= 90)
      ch = 'A';
    else if( mark >= 80 && mark < 90)
      ch = 'B';
    else if( mark >= 70 && mark < 80)
      ch = 'C';
    else if( mark >= 60 && mark < 70)
      ch = 'D';
    else
      ch = 'F';

    k++;
    printf("Case %d: %c\n", k, ch);
  }
  return 0;
}
