#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
#define pi 3.14159265358979323846  
struct dot 
{  
    double Longitude;  
    double Lantitude;  
}point[110];
ll radio;
typedef struct
{
	long double key;
	int u,v;
}EDGE;
struct node
{
	struct node*p;
	int rank;
	int u;
};
typedef struct node NODE;
EDGE E[10000],T[110];
NODE V[110];

double Distance(double lat1, double lon1, double lat2, double lon2)  
{  
    double latitude1,longitude1,latitude2,longitude2;  
    double dlat,dlon;  
    latitude1=lat1;  
    longitude1=lon1;  
    latitude2=lat2;  
   longitude2=lon2;  

    double a,c,distance;  
    dlon =fabs((longitude2 - longitude1))*pi/180;  
    dlat =fabs((latitude2 - latitude1))*pi/180;  
    a = (sin(dlat/2)*sin(dlat/2)) + cos(latitude1*pi/180) * cos(latitude2*pi/180) * (sin(dlon/2)*sin(dlon/2));  
    if(a==1.0)  
        c=pi;  
    else  
        c = 2 * atan(sqrt(a)/sqrt(1-a));  
    distance= radio*c;  
 
    return distance;  
}  

void kruskal(NODE V[],EDGE[],EDGE T[],int n,int m)
{
	int i,j,k;
	EDGE e;
	NODE *u,*v;
	make_heap(E,m);
	for(int i=0;i<n;i++)
	{
		V[i].rank=0;V[i].p=NULL;
	}
	i=j=0;
	while((i<n-1)&&(m>0))
	{
		e=

int main()
{
	ios::sync_with_stdio(false);
	int N;
	ll len;
	int num;
	cin>>N;
	while(N--)
	{
		cin>>radio>>len>>num;
		for(int i=0;i<num;i++)
		cin>>point[i].Lantitude>>point[i].Longitude;
		for(int i=0;i<num;i++)
		{
			int j=1;j<num;j++)
			{
				EDGE[i*num+j].key=Distance(point[i].Lantitude,point[i].Longitude,point[j].Lantitude,point[j].Longitude);
				EDGE[i*num+j].u=i;
				EDGE[i*num+j].v=j;
			}
		}
		
				
		
		
	return 0;
}

