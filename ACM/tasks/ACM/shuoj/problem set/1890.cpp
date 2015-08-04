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
#define MAXN 100010
char s[MAXN],t[MAXN];
const double pi=acos(-1.0);
struct Complex{
	double r,i;
	Complex(double _r=0,double _i=0){
		r=_r;i=_i;
	}
	Complex operator+(const Complex &b){
		return Complex(r+b.r,i+b.i);
	}
	Complex operator-(const Complex &b){
		return Complex(r-b.r,i-b.i);
	}
	Complex operator*(const Complex &b){
		return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
	}
}; 
void change(Complex *y,int len){
	for(int i=1,j=len/2;i<len-1;i++){
		if(i<j)swap(y[i],y[j]);
		int k=len/2;
		while(j>=k){
			j-=k;
			k/=2;
		}
		if(j<k)j+=k;
	}
}
void fft(Complex *y,int len,int on){
	change(y,len);
	for(int h=2;h<=len;h<<=1){
		Complex wn(cos(-on*2*pi/h),sin(-on*2*pi/h));
		for(int j=0;j<len;j+=h){
			Complex w(1,0);
			for(int k=j;k<j+h/2;k++){
				Complex u=y[k];
				Complex t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}
	if(on==-1){
		for(int i=0;i<len;i++){
			y[i].r/=len;
		}
	} 
}
Complex x3[MAXN*6],x1[4*MAXN],x2[4*MAXN];
int a[MAXN],b[MAXN];
int num[MAXN];
int sum[4*MAXN],sum1[MAXN];

int main()
{
	//ios::sync_with_stdio(false);
	while(~scanf("%s%s",s,t))
	{
		int len1=strlen(s);
		int len2=strlen(t);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int len=1;
		while(len<=len1+len2)len<<=1;
		for(int i=0;i<len1;i++)a[i]=s[i]=='a'?0:1;
		for(int i=0;i<len2;i++)b[i]=t[len2-1-i]=='a'?0:1;
		for(int i=0;i<len1;i++)x1[i]=Complex(a[i],0);
		for(int i=len1;i<len;i++)x1[i]=Complex(0,0);
		for(int i=0;i<len2;i++)x2[i]=Complex(b[i],0);
		for(int i=len2;i<len;i++)x2[i]=Complex(0,0);
		fft(x1,len,1);
		fft(x2,len,1);
		for(int i=0;i<len;i++)x1[i]=x1[i]*x2[i];
		fft(x1,len,-1);
		for(int i=0;i<len1-len2+1;i++){
			sum[i]=(int)(x1[i+len2-1].r+0.5);
			sum[i]*=-2;
		}
		int sum2=0;
		sum1[0]=0;
		for(int i=0;i<len1;i++)sum1[i+1]=a[i]+sum1[i];
		for(int i=0;i<len2;i++)sum2+=b[i];
		//cout<<sum2<<endl;
		//for(int i=0;i<len1;i++)cout<<sum1[i]<<len
		int ans=INF;
		for(int i=0;i<len1-len2+1;i++){
			sum[i]+=sum1[i+len2]-sum1[i]+sum2;
			ans=min(sum[i],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}



