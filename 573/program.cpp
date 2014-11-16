#include <iostream>
#include <fstream>
using namespace std;

void snail(int h, int u, int d, int f)
{
	float init_hyt = 0.0;
	float today_hyt = 0.0;
	float today_climb = 0.0;
	float final_hyt = 0.0;
	float prev_day_hyt = 0.0;
	float total_climb = 0.0;
	bool climb = false;
	float fatigue = (float)(u * f)/100.00;
	int day = 0;
	while(1)
	{
		day++;
		if( day == 1)
		{
			today_hyt = total_climb = u;
			//cout <<"day 1 : "<< init_hyt <<"  "<< today_hyt <<"  "<< d <<"  "<< total_climb - d << endl;
		}
		else
		{
			if( (prev_day_hyt-fatigue) >= (float)0)
				today_hyt = prev_day_hyt - fatigue;
			else
				today_hyt = 0;
			total_climb = today_hyt + init_hyt;
			//cout <<"day : "<< day <<"  "<< init_hyt <<"  "<< today_hyt <<"  "<< total_climb << endl;
		}
		if(total_climb > (float)h )
		{
			climb = true;
			break;
		}
		final_hyt = total_climb - d;
		if(final_hyt < (float)0)
		{
			climb = false;
			break;
		}
		prev_day_hyt = today_hyt;
		init_hyt = final_hyt;
	};

	if(climb)
		cout <<"success on day " << day << endl;
	else
		cout <<"failure on day " << day << endl;
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	int hyt, up, down, fat;

	while( infile >> hyt >> up >> down >> fat )
	{
		if(!hyt)
			break;
		snail(hyt, up, down, fat);
	}

	return 0;
}
