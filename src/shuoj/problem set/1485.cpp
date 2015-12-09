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

double exp1(double n)
{
	double num=1.0,vis=1.0;
	for(double i=1.0;i<20;i++)
	{
		vis*=n/i;
		num+=vis;
	}
	return num;
}
double exp2(double n)
{
	double num=1.0,delta=1e-6,vis=1.0;
	double i=1.0;
	while(vis>=delta||vis<=-delta)
	{
		vis*=n/i;
		num+=vis;
		i++;
	}
	return num;
}

int main()
{
	double n;
	while(cin>>n)
	{
		cout<<"e1("<<fixed<<setprecision(3)<<n<<") = "<<setprecision(5)<<exp1(n)<<endl;
		cout<<"e2("<<fixed<<setprecision(3)<<n<<") = "<<setprecision(5)<<exp2(n)<<endl;
		cout<<endl;
	}
	return 0;
}




