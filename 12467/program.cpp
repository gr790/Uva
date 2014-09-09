#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <strings.h>
using namespace std;
int next[1000001];
void compute_next(string &s)
{
  int slen = s.size();
  next[0] = 0; /* initially next[q] = 0, first character in pattern */
  int k = 0; /* no of char matched so far */
  int q = 1;
  while( q < slen )
  {
    while( k > 0 && s[k] != s[q] ) {
      k = next[k-1];
    }
    if(s[k] == s[q])
      k=k+1;
    next[q] = k;
    q++;
  }
}

int kmp_match(string &s, string &p)
{
  int slen = s.size();
  /* calculate the next function on input string */
  compute_next(p);
  int q = 0; /* no of char matched so far */
  int ind = 0, m = 0;
  while(ind < slen) {
    while(q > 0 && p[q] != s[ind])
      q = next[q-1]; /* if char doesn't match, shift by taking value from next array */
    if(p[q] == s[ind])
      q = q+1; /* if matches, shift by 1, higher the q, longer the match */
    m = max(m,q);
    ind++;
  }
  return m;
}



int main()
{
  freopen("./critical.txt", "r", stdin);
  int test;
  cin >> test;
  cin.ignore();
  while(test--)
  {
    string txt, sub;
    getline(cin, txt);
    int sz = txt.size();
    for(int i = 0; i < sz; ++i)
      sub += txt[sz-i-1];
    /* input become a pattern, and reverse of pattern become text */
    int mx = kmp_match(sub, txt); /* return the length of longest matched pattern */
    for(int i = mx-1; i>=0; --i)
      printf("%c", txt[i]);
    cout << endl;
    bzero(&next, sizeof(next));
  }
  return 0;
}
