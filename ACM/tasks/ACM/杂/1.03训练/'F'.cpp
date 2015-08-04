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
const double eps=1e-6;
const int maxn=100010;
const double INF=1e20;

struct point 
{
	double x,y;
};
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/2;
}
point p[maxn];
point temp[maxn];

bool cmpxy(point a,point b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
bool cmpy(point a,point b)
{
	return a.y<b.y;
}
double cmp(int left,int right)
{
	double d=INF;
	if(left==right)return d;
	if(left==right-1)return dist(p[left],p[right]);
	int mid=(left+right)/2;
	double d1=cmp(left,mid);
	double d2=cmp(mid+1,right);
	d=min(d1,d2);
	int k=0;
	for(int i=left;i<=right;i++)
	{
		if(fabs(p[mid].x-p[i].x)<=d)
		{
			temp[k++]=p[i];
		}
	}
	sort(temp,temp+k,cmpy);
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k&&(temp[j].y-temp[i].y)<d;j++)
		{
			d=min(d,dist(temp[i],temp[j]));
		}
	}
	return d;
}	
int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
		sort(p,p+n,cmpxy);
		cout<<fixed<<setprecision(2)<<cmp(0,n-1)<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	
	
