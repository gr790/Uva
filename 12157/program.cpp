#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int t;
  infile >> t;
  infile.ignore();
  int k = 0;
  while(k < t)
  {
    int n;
    infile >> n;
    infile.ignore();
    int val;
    int m_cost, j_cost;
    m_cost = j_cost = 0;
    while(n--)
    {
      infile >> val;
      m_cost += ( (val/30)+1);
      j_cost += ( (val/60)+1);
    }

    m_cost = m_cost*10;
    j_cost = j_cost*15;

    k++;
    if(m_cost < j_cost)
      printf("Case %d: Mile %d\n", k, m_cost);
    else if ( m_cost > j_cost)
      printf("Case %d: Juice %d\n", k, j_cost);
    else if( m_cost == j_cost)
      printf("Case %d: Mile Juice %d\n", k, m_cost);
  }
  return 0;
}
