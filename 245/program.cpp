#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <list>
using namespace std;

void number(int &num, char ch)
{
  num = (num * 10) + (ch-'0');
}

string find_node(list<string> &mylist, int num)
{
  list<string>::iterator it;
  int index = 1;
  for(it = mylist.begin(); it != mylist.end(); ++it)
  {
    if(index != num)
      index++;
    else
      break;
  }
  string node = *it;
  mylist.erase(it);
  mylist.push_front(node);
  return node;
}

int main()
{
  freopen("./sample.txt", "r", stdin);
  char ch;
  string word;
  list<string> mylist;
  map<string, int> mymap;
  int index = 0;
  int num = 0;
  while( (ch=getchar()) != EOF) 
  {
    if(isalpha(ch))
      word += ch;
    else if(isdigit(ch))
    {
      number(num,ch); 
      if(!num) break;
      while(isdigit(ch=getchar()))
        number(num, ch);
      string node = find_node(mylist, num);
      cout << node;
      num = 0;
      putchar(ch);
    }
    else
    {
      /* if word first occurance */
      if( isalpha(word[0]) && !mymap[word]) 
      {
        mylist.push_front(word);
        cout << word;
        index++;
      } 
      word.clear();
      putchar(ch);
    }
  }
  return 0;
}
