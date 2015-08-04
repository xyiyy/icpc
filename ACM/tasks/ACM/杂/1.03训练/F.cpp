#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct point
{
	double x;
	double y;
}aa[100000];

int main()
{
	int n;
	double min,temp;
	while(cin>>n&&n!=0)
	{
		min=0xffffff;
		for(int i=0;i<n;i++)
		{
			cin>>aa[i].x;
			cin>>aa[i].y;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				temp=sqrt((aa[i].x-aa[j].x)*(aa[i].x-aa[j].x)+(aa[i].y-aa[j].y)*(aa[i].y-aa[j].y))/2;
				if(temp<min)
				{
					min=temp;
				}
			}
		}
		cout<<fixed<<setprecision(2)<<min<<endl;
	}
	return 0;
}
	 
	 
	 
	 
	 
