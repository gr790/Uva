#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

void reformat(string &s)
{
  int sz = s.size();
  int j = 0;
  for(int i = 0; i < sz; ++i)
  {
    if(isalpha(s[i]))
      s[j++] = s[i];
  }
  s.resize(j);
}

bool is_square(int n)
{
  int i = 1;
  while (n > 0)
  {
    n -= i;
    i += 2;
  }
  return n == 0;
}

bool is_square_palin(string &s)
{
  int size = s.size();
  int row, col;
  row = col = (int)sqrt(size);
  
  char **magic = new char*[row];
  for(int i = 0; i < row; ++i)
    magic[i] = new char[col];

  /* create a matrix for n * n size */
  int i = 0, j = 0, k = 0;
  for(int i = 0; i < row; ++i)
  {
    for(int j = 0; j < col; ++j, ++k)
    {
       magic[i][j] = s[k];
    }
  }
  
#ifdef ME
  cout <<"Magic squre palindrome: " << endl;
  for(int i = 0; i < row; ++i)
  {
    for(int j = 0; j < col; ++j, ++k)
    {
       cout << magic[i][j];
    }
    cout << endl;
  }
#endif
  
  bool palin = true;
  for(int k = 0; k < row; ++k)
  {
    for(int i = k, j = k; (i < row) && (j < row); ++i, ++j)
    {
      if(magic[i][k] != magic[k][j])
      {
        palin = false;
        break;
      }
    }
  }
  if(palin)
  {
    if(magic[0][0] != magic[row-1][col-1])
      palin = false;
  }

  for(int i = 0; i < row ; ++i)
     delete [] magic[i];
  delete [] magic;

  return palin;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int t, k = 0;
  scanf("%d\n", &t);
  while(k < t)
  {
    printf("Case #%d:\n", ++k);
    string line;
    getline(cin, line);
    reformat(line);
    int size = line.size();
    if(!is_square(size))
      printf("No magic :(\n");
    else
    {
      if(is_square_palin((line)))
        printf("%d\n", (int)sqrt(line.size()));
      else
        printf("No magic :(\n");
    }
    line.clear();
  }
  return 0;
}
