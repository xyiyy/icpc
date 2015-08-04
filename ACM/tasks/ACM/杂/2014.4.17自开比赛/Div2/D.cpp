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
int judge(int n)
{
     int i,s=0,flag=0;
     for(i=1; i<=n/2; i++)
     {
          if(n%i==0)
          {
               s+=i;
        	}
        }
        if(n==s)
        {
             flag=1;
        }
        return flag;
}

int main()
{
    int num;
    scanf("%d",&num);
    while(num--)
    {
		int i,a,b,count=0;
        int t;
        scanf("%d %d",&a,&b);
        if(a>b)
        {
            t=a;a=b;b=t;
		}
        for(i=a; i<=b; i++)
        {
            if(judge(i))
                count++;
        }
    	printf("%d\n",count);
	}
    return 0;
}

