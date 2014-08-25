#include <iostream>
#include <string.h>
#include <strings.h>
#include <fstream>
using namespace std;

bool is_vowel(char ch)
{
  if( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
      ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;
  return false;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  int i = 0;
  char ch;
  while( (ch=getchar()) != EOF)
  {
      if(isalpha(ch)) {
        if(is_vowel(ch))
        {
          cout << ch;
          while(isalpha((ch=getchar())))
            putchar(ch);
          printf("ay");
          putchar(ch);
        }
        else {
          char chr;
          while((isalpha((chr=getchar()))))
            putchar(chr);
          putchar(ch);
          printf("ay");
          putchar(chr);
        }
     }
     else
      putchar(ch);
  }
  return 0;
}
