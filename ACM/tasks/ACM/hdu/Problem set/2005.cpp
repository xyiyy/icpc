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

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool is_leapyear(int year)
{
	return year%400==0||(year%4==0&&year%100!=0);
}

int main()
{
	ios::sync_with_stdio(false);
	int year,month,day;
	char a;
	while (cin>>year>>a>>month>>a>>day)
	{
		//if()
		if(is_leapyear(year))days[1]++;
		for(int i=0;i<month-1;i++)
		{
			day+=days[i];
		}
		days[1]=28;
		cout<<day<<endl;
	}
	
		
			//if()
	return 0;
}

