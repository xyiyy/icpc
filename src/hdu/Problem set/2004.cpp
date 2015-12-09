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


int main()
{
	ios::sync_with_stdio(false);
	int a;
	while(cin>>a)
	{
		if(a<=100&&a>=90)cout<<"A"<<endl;
		else if(a>=80&&a<90) cout<<"B"<<endl;
		else if(a>=70&&a<80) cout<<"C"<<endl;
		else if(a>=60&&a<70) cout<<"D"<<endl;
		else if(a<60&&a>=0) cout <<"E"<<endl;
		else cout<<"Score is error!"<<endl;
	}
	return 0;
}

