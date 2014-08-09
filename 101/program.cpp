#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

//#define UVA
int v2[25][25];
int nb;

void init(void)
{
	for(int i=0; i < nb; ++i)
	{
		v2[i][0] = i;
		for(int j=1; j<nb; ++j)
		{
			v2[i][j] = -1;
		}
	}
}

void display(int index)
{
	for(int j=0; j<nb ; ++j)
	{
		if(v2[index][j] != -1)
			cout <<" "<< v2[index][j];
        }
}

int find_next_pos( int row)
{
	int j=0;
	while(v2[row][j] != -1)
		j++;

	return --j;
	
}

void find(int a, int &row, int &col, bool op)
{

	for(int i=0; i<nb; ++i)
	{
		for(int j=0; j<nb; ++j)
		{
			if(v2[i][j] != -1)
			{
				if(v2[i][j] == a)
				{
					if(op)
					{
						row = i;
						col = find_next_pos(i);
					}
					else
					{
						row = i;
						col = j;
					}
				}
			}
		}
	}
}

void origp(int a)
{
	int i = a;
	int j = 0;
	while( v2[a][j] != -1)
		j++;
	v2[i][j] = a;	
	
}

void clear(int row, int col)
{
	int i = row;
	for(int j=col+1; j<nb; ++j)
	{
		int tmp = v2[i][j];
		if(tmp != -1)
		{
			origp(tmp);
			v2[i][j] = -1;
		}
	}
		
}

void move(int ra, int ca, int rb, int cb)
{
	int tmp = v2[ra][ca];
	v2[rb][cb+1] = tmp;
	v2[ra][ca] = -1;
}

void pile(int ra, int ca, int rb, int cb)
{
	int i = ca;
	int j = 1;
	while( v2[ra][i] != -1)
	{
		int tmp = v2[ra][i];
		v2[rb][cb+j] = tmp;
		v2[ra][i] = -1;
		++i;
		++j;
	}
}
	
		

void move_onto(int a, int b)
{
	int ra = 0, ca = 0, rb = 0, cb = 0;

	find(a, ra, ca, false);
	find(b, rb, cb, false);

	if( ra == rb)
		return ;

	clear(ra, ca);
	clear(rb, cb);

	move(ra, ca, rb, cb);
	
}

void move_over(int a, int b)
{
	int ra = 0, ca = 0, rb = 0, cb = 0;

	find(a, ra, ca, false); /* find next position where b can be fit */
	find(b, rb, cb, true);

	if( ra == rb)
		return ;

	clear(ra, ca);

	move(ra, ca, rb, cb);
}

void pile_onto(int a, int b)
{
	int ra = 0, ca = 0, rb = 0, cb = 0;

	find(a, ra, ca, false);
	find(b, rb, cb, false);

	if( ra == rb)
		return ;

	clear(rb, cb);
	
	pile(ra, ca, rb, cb);
}

void pile_over(int a, int b)
{
	int ra = 0, ca = 0, rb = 0, cb = 0;

	find(a, ra, ca, false);
	find(b, rb, cb, true);

	if( ra == rb)
		return ;

	pile(ra, ca, rb, cb);
}

int main()
{
	string cmd, sub_cmd;
	int a, b;
	istringstream ss;
	ifstream infile;
#ifndef UVA
	infile.open("./sample.txt");
	infile >> nb ;
	infile.ignore();
#else 
	cin >> nb ;
	cin.ignore();
#endif

	init();

	while(1)
	{
		ss.clear();

		string lstr;
#ifndef UVA
		getline(infile, lstr);
#else
		getline(cin, lstr);
#endif

		ss.str(lstr);

		ss >> cmd;
		ss >> a;
		ss >> sub_cmd;
		ss >> b; 
#ifndef UVA
		cout <<"cmd = " <<  cmd << endl;
		cout <<"sub_cmd = " <<  sub_cmd << endl;
#endif

		if( a == b) 
		{
			continue;
		}

		if( cmd == "quit")
		{
			break;
		}
		else if( (cmd == "move") && (sub_cmd == "onto") )
		{
#ifndef UVA
			cout <<" will process "<< cmd <<" "<< a <<" "<< sub_cmd <<" "<< b << endl;
#endif
			move_onto(a, b);
		}
		else if( (cmd =="move") && (sub_cmd =="over") )
		{
#ifndef UVA
			cout <<" will process "<< cmd <<" " << a <<" "<< sub_cmd <<" "<< b << endl;
#endif
			move_over(a, b);
		}
		else if( (cmd == "pile") && (sub_cmd =="onto") )
		{
#ifndef UVA
			cout <<" will process "<< cmd <<" "<< a <<" "<< sub_cmd <<" "<<  b << endl;
#endif
			pile_onto(a,b);
		}
		else if( (cmd =="pile") && (sub_cmd == "over") )
		{
#ifndef UVA
			cout <<" will process "<< cmd <<" "<< a <<" "<< sub_cmd <<" "<< b << endl;
#endif
			pile_over(a,b);
		}
		lstr.clear();

	}

	int i;
	for(i=0; i<nb; ++i)
	{
		cout << i <<":";
		display(i); 
		cout << endl;
	}
		
	return 0;
}
