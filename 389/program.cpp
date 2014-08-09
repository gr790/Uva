#include <iostream>
#include <iomanip>
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
                else if( (str[i] >= 'A') && ( str[i] <= 'F'))
                        value += ( str[i] + 10 - 'A') * (long long int )pow( base, len-i-1);
        }

        return value;
}

void reverse( string &s, int start, int end)
{
        if( start < end )
        {
                char tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                reverse( s, ++start, --end);
        }
}

void to_base( ullong dec, uint32 new_b, string &value)
{
        while(dec)
        {
                int rem = dec % new_b;
                if( (rem >= 0) && (rem <= 9))
                        value += ( rem + '0');
                else
                        value += ( rem + 'A' - 10);
                dec = dec / new_b;
        }

        reverse(value, 0, value.size() - 1);
}

void solve(string &num, uint32 orig_b, uint32 new_b)
{
        string value;
        ullong dec = decimal( num, orig_b);
        if( dec)
        {
                to_base( dec, new_b, value);
                if( value.size() > 7)
                        cout << setw(7) << right <<"ERROR"<< endl;
                else
                        cout << setw(7) << right << value << endl;
        }
        else
                cout << setw(7) << right << dec << endl;

}
int main()
{
        string num;
        uint32 orig_b, new_b;
        orig_b = new_b = 0;
        freopen("./sample.txt", "r", stdin);

        while( cin >> num >> orig_b >> new_b )
        {
                if( validate(num, orig_b) )
                        solve(num, orig_b, new_b);
                else
                        cout << setw(7) << right <<"ERROR"<< endl;
                num.clear();
                orig_b = new_b = 0;
        }

        return 0;
}
