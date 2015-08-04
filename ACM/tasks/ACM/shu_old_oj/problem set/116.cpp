#include <iostream>
#include <iomanip>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int y,m,d;
bool is_leapyear()
{
	if(y%4==0&&y%100!=0||y%400==0)
	return 1;
	else return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int k=1,sum;
	while(cin>>y>>m>>d)
	{
		sum=0;
		if(is_leapyear())month[1]=29;
		else month[1]=28;
		for(int i=0;i<m-1;i++)
		{
			sum+=month[i];
		}
		sum+=d;
		cout<<"Case "<<k++<<": "<<setfill('0')<<setw(2)<<m
			<<"/"<<setw(2)<<d<<"/"<<setw(4)<<y<<", "<<sum<<endl;
	}
		month[1]=28;
	return 0;
}

