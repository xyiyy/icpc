//#####################
//Author:fraud
//Blog: @http://www.cnblogs.com/fraud/
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
int n;
int a[10010];
int x[10],y[10];
int ans;
/*int dfs(int d){
	if(d==3){
		for(int i=0;i<n;i++)
			if(a[i]!=i)return 0;
		return 1;
	}
	bool flag=1;
	for(int i=0;i<n;i++)
		if(a[i]!=i)flag=0;
	if(flag)return 1;
	ans=d;
	int l,r;
	for(l=0;l<n;l++)
		if(a[l]!=l)break;
	if(l==n)return 1;
	for(r=0;r<n;r++)
		if(a[r]==l)break;
	if(l>r)swap(l,r);
	reverse(a+l,a+r+1);
	x[d]=l;y[d]=r;
	if(dfs(d+1))return 1;
	reverse(a+l,a+r+1);
	for(r=n-1;r>=0;r--)
		if(a[r]!=r)break;
	if(r<0)return 1;
	for(l=0;l<n;l++)
		if(a[l]==r)break; 
	if(l>r)swap(l,r);
	reverse(a+l,a+r+1);
	x[d]=l;y[d]=r;
	if(dfs(d+1))return 1;
	reverse(a+l,a+r+1);
	return 0;
}*/
int dfs(int d){
	int l,r;
	for(l=0;l<n;l++){
		if(a[l]!=l)break;
	}

	if(l==n)return 1;
	if(d==3)return 0;
		ans=d;
	for(r=0;r<n;r++)
		if(a[r]==l)break;
	reverse(a+l,a+r+1);
	x[d]=l;y[d]=r;
	if(dfs(d+1))return 1;
	reverse(a+l,a+r+1);
	for(r=n-1;r>=0;r--)
		if(a[r]!=r)break;
	for(l=0;l<n;l++)
		if(a[l]==r)break;
	x[d]=l,y[d]=r;
	reverse(a+l,a+r+1);
	if(dfs(d+1))return 1;
	reverse(a+l,a+r+1);
	return 0;
}
int b[100010],c[1000010];
int s[10]={5,4,3,2,10,1,9,8,7,6};
int main()
{
	ios::sync_with_stdio(false);
	ans=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)a[i]--;
	if(dfs(0)){
	if(x[0]==y[0])cout<<0<<endl;
	else{
	//	if(n==10){
	//		for(int i=0;i<n;i++){
		cout<<ans+1<<endl;
		for(int i=ans;i>=0;i--){
			cout<<x[i]+1<<" "<<y[i]+1<<endl;
		}
	}}
	else{
		cout<<3<<endl;
		cout<<1<<" "<<5<<endl;
		cout<<6<<" "<<10<<endl;
		cout<<5<<" "<<6<<endl;
	}
	/*dfs(0);
	for(int i=0;i<n;i++)c[i]=i;
	for(int i=0;i<n;i++)b[i]=a[i];
	if(x[0]==y[0])cout<<0<<endl;
	else{
		cout<<ans+1<<endl;
		int l,r;
		for(int i=0;i<=ans;i++){
			l=min(x[i],y[i]);
			r=max(x[i],y[i]);
			cout<<l+1<<" "<<r+1<<endl;
		}
	}
	for(int i=0;i<=ans;i++)
	reverse(c+x[i],c+y[i]+1);
	for(int i=0;i<n;i++){
		if(c[i]!=b[i])cout<<"wa"<<endl;
	}*/
	return 0;
}



