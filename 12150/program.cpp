#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class pole {
  public:
    pole(int c, int p): car(c), pos(p) {}
    int car, pos;
};

int main()
{
  freopen("./sample.txt", "r", stdin);
  int num;
  while(cin >> num)
  {
    if(!num) break;
    pole p(-1, -1);
    vector<int> st_grid(num, -1); 
    vector<pole> pole_pos(num, p);
    int i = 0;
    bool np = false;
    int k = num;
    while(k--)
    {
      int car, pos;
      cin >> car >> pos; 
      pole_pos[i].car = car;
      pole_pos[i].pos = pos;
      i++;
    }
    
    int size = pole_pos.size();
    for(int i = 0; i < size; ++i)
    {
      int pos = pole_pos[i].pos;
      int car = pole_pos[i].car;

      if((i+pos) >= 0 && (i+pos) <= num && st_grid[i+pos] == -1) 
        st_grid[i+pos] = car; 
      else
      {
        np = true;
        cout << "-1" << endl;
        break;
      }
    }
    if(!np) {
      int i = 0;
      while(i < num-1)
      {
        cout << st_grid[i] <<' ';
        i++;
      }
      cout << st_grid[i] << endl;
    }
    st_grid.clear();
    pole_pos.clear();
  }
  return 0;
}
