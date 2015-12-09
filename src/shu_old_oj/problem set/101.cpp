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

int gcd(int a,int b)
{
	int temp;
	while(b)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}


int main()
{
	long long a,b,n=0,m=0;
	int k=1;
	while(cin>>a>>b)
	{
		cout<<"Case "<<k<<":"<<endl;
		if(a==0&&b==0)
		{
			cout<<"no GCD"<<endl;
			cout<<"no LCM"<<endl;
		}
		else if(a!=0&&b!=0)
		{
			n=gcd(abs(a),abs(b));
			m=abs(a*b/gcd(abs(a),abs(b)));
			cout<<"GCD("<<a<<","<<b<<") = "<<n<<endl;
			cout<<"LCM("<<a<<","<<b<<") = "<<m<<endl;
		}
		else if(a==0&&b!=0||(a!=0&&b==0))
		{
			cout<<"GCD("<<a<<","<<b<<") = "<<a+b<<endl;
			cout<<"no LCM"<<endl;
		}
	
		cout<<endl;
	//	n=0;m=0;
		k++;
	}
	return 0;
}
			
		 
