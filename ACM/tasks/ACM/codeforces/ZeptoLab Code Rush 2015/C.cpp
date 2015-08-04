//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

int main()
{
	ios::sync_with_stdio(false);
	ll c,hr,hb,wr,wb;
	cin>>c>>hr>>hb>>wr>>wb;
	ll ans=0;
	for(ll i=0;i*wr<=c&&i<=10000000;i++){
		ans=max(ans,i*hr+(c-i*wr)/wb*hb);
	}
	for(ll i=0;i*wb<=c&&i<=10000000;i++){
		ans=max(ans,i*hb+(c-i*wb)/wr*hr);
	}
	ll x=c/wr;
	for(ll i=0;i<=x&&i<=10000000;i++){
		ans=max(ans,(x-i)*hr+(c-(x-i)*wr)/wb*hb);
	}
	x=c/wb;
	for(ll i=0;i<=x&&i<=10000000;i++){
		ans=max(ans,(x-i)*hb+(c-(x-i)*wb)/wr*hr);
	}
	cout<<ans<<endl;
	
	//for(ll i=0;i*wr<=c;i++){
	//	ans=max(ans,i*hr+(c-i*wr)/wb*hb);
//	}cout<<ans<<endl;
	/*
	ll tmp=__gcd(wr,wb);
	tmp=wr/tmp*wb;
	ll ans=0;
	if(hr*wb<hb*wr){
		swap(hr,hb);
		swap(wr,wb);
	}else if(hr*wb==hb*wr&&wb<wr){
		swap(hr,hb);
		swap(wr,wb);
	}
	if(c<=10000000){
		 ans=0;
		for(ll i=0;i<=c;i++){
			if(i*wr>c)break;
			ans=max(ans,i*hr+(c-i*wr)/wb*hb);
		}
		cout<<ans<<endl;
		return 0;
	}
//	cout<<wr<<hr<<endl;
	ll x=tmp/wb+1;
	ans=c/wr*hr+(c-c/wr*wr)/wb*hb;
	ll lx=c-c/wr*wr-(c-c/wr*wr)/wb*wb;
	x=min(x,(c/wr*wr+lx)/wb);
	ll y=tmp/wr;
	y=min(y,c/wr);
	ll temp;
	ll cha;
	ll bur,bub;
	if(x<=y){
		for(ll i=0;i<=x;i++){
			temp=i*wb;
			cha = temp-lx;
			bur = (cha+wr-1)/wr;
			ans=max(ans,ans+i*hb-bur*hr);
		}
	}else{
		for(ll i=0;i<=y;i++){
			temp=i*wr+lx;
			bub=temp/wb;
			ans=max(ans,ans+bub*hb-i*hr);
		}
	}
	cout<<ans<<endl;
*/
	return 0;
}



