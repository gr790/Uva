#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
typedef unsigned long long int ullong;
typedef unsigned long int uint32;
bool validate(string &str, uint32 base)
{
        bool is_ok = true;
        uint32 len = str.size();
        for(int i=0; i < len; ++i)
        {

                if( isalpha( str[i]))
                {
                        if( (str[i] + 10 - 'A') >= base)
                        {
                                is_ok = false;
                                break;
                        }
                }
                else
                {
                        if( (str[i] - '0') >= base)
                        {
                                is_ok = false;
                                break;
                        }
                }
        }
        return is_ok;
}

ullong decimal(string &str, int base)
{
        ullong value = 0;
        int len = str.size();
        for(int i=0; i < len; ++i)
        {
                if( (str[i] >= '0') && ( str[i] <= '9'))
                        value += ( str[i] - '0') * (long long int )pow( base, len-i-1);
                else if( (str[i] >= 'A') && ( str[i] <= 'Z'))
                        value += ( str[i] + 10 - 'A') * (long long int )pow( base, len-i-1);
        }

        return value;
}

void solve(string &num1, string &num2)
{
        int start_b = 2;
        int end_b = 36;
        for(int i=start_b; i <= end_b ; ++i)
        {
                ullong dec1 = 0;
                if( validate(num1, i))
                        dec1 = decimal(num1, i);
                else
                        continue;
                for(int j=2; j <= end_b; ++j)
                {
                        ullong dec2 = 0;
                        if( validate(num2, j))
                                dec2 = decimal(num2, j);
                        else
                                continue;
                        if( dec1 == dec2)
                        {
                                cout << num1 <<" (base "<< i <<")" <<" = "<< num2 <<" (base "<< j <<")"<< endl;
                                return;
                        }
                }
        }
        cout << num1 <<" is not equal to "<< num2 <<" in any base 2..36" << endl;
        return;

}

int main()
{
        string num1, num2;

        while( cin >> num1 >> num2 )
        {
                solve( num1, num2);
                num1.clear();
                num2.clear();
        }

        return 0;
}
