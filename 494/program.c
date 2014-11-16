#include <stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
int main()
{
        char str[1000000] = {0};
        freopen("./sample.txt", "r", stdin);
        int word = 0;
        char ch;
        bool in_word = false;
        while( (ch = getchar()) != EOF)
        {
                if( islower(ch) || isupper(ch) )
                {
                        in_word = true;
                }
                if( ch == ' ' || ch == '\t' || ch == '.' || ch == ',' || ch == ';' || ch == '/' ||
                                ch == '-' || ch == '\'' || ch == ':' ||  ch == '~' || ch == '!' ||
                                ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' ||
                                ch == '*' || ch == '?' || ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
                                ch == '[' || ch == ']' || ch == '<' || ch == '>' || ch == '=' || ch == '"' ||
                                ch == '|' || ch == '_' || ch == '+' || isdigit(ch))
                {
                        if(in_word)
                                word++;
                        in_word = false;
                }


                if( ch == '\n')
                {
                        if(in_word)
                                word++;
                        if(word)
                                printf("%ld\n", word);
                        in_word = false;
                        word = 0;
                }

        }

        return 0;
}

