#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;
map<unsigned char, int> freq;
int main()
{
        int test;
        freopen("./sample.txt", "r", stdin);
        scanf("%d\n",&test);
        int j = 0;
        while( j < test )
        {
                int pc;
                scanf("%d\n", &pc);
                int k = 0;
                unsigned char ch;
                int val;
                char line[10010] = {0};
                while(k < pc)
                {

                        gets(line);
                        sscanf(line, "%c %d", &ch, &val);
                        freq[ch] = val;
                        k++;
                }

                int lines;
                scanf("%d\n", &lines);
                unsigned char lstr[20000] = {0};
                int m = 0;
                unsigned long long int sum = 0;
                while( m < lines )
                {
                        scanf("%[^\n]", &lstr);
                        getchar();
                        int len = strlen((const char*)lstr);
                        for( int i = 0; i < len; ++i)
                        {
                                unsigned char ch = lstr[i];
                                if(freq[ch])
                                {
                                        sum += freq[ch];
                                }
                        }
                        m++;
                        memset(&lstr, 0, sizeof(lstr));
                }
                double amount = (double)(sum/100.00);
                printf("%.2lf$\n", amount);
                freq.clear();
                j++;
        }
        return 0;
}
