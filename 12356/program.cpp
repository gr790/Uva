#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define MAX 100000
typedef struct {
  int left, right;
} buddy;

buddy line[MAX];

int main()
{
  freopen("./sample.txt", "r", stdin);
  int s, b;
  while(scanf("%d %d", &s, &b)) {
    if( !s && !b) break;

    for(int i = 1; i <= s; ++i)
    {
      line[i].left = i-1;
      line[i].right = i+1;
    }
    line[s].right = 0;

    int l, r;
    while(b--) { 
      scanf("%d %d", &l, &r);

      if(line[l].left)
        printf("%d ", line[l].left);
      else 
        printf("* ");
      if(line[r].right)
        printf("%d\n", line[r].right);
      else
        printf("*\n");

      /*   e.g --> 1 2 3 4 5 6 7 8 9 10 */
      /*   l = 2, r = 5 */
      /*   remaining soldiers : 1 6 7 8 9 10 */
      /*   right of l become right of r */
      /*   left of r.right become left of l */
      line[line[l].left].right = line[r].right;
      line[line[r].right].left = line[l].left;
    }
    printf("-\n");
  }
  return 0;
}
