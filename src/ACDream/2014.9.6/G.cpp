//gaoshenbaoyou  ------ pass system test
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
	//ios::sync_with_stdio(false);
	char a[110];

	long long key[10];
	key[0]=32768;
	key[1]=32767;
	key[2]=(ll)2147483648;
	key[3]=(ll)2147483647;
	key[4]=(ll)922337203;
	key[5]=(ll)6854775808;
	key[6]=(ll)922337203;
	key[7]=(ll)6854775807;
	while(cin>>a)
	{
		int flag=0;
		if(a[0]=='-')
		{
			int len=strlen(a);
			char b[110];
			CLR(b,0);
			long long c,d;
			c=d=0;
			int j=1;
			while(a[j]=='0')j++;
			for(int i=j;i<len;i++)
			{
				b[i-j]=a[i];
			}
			len=strlen(b);
			for(int i=max(len-10,0);i<len;i++)
			{
				c=c*10+b[i]-'0';
			}
			for(int i=0;i<=len-11;i++)
			{
				d=d*10+b[i]-'0';
			}
			if(len>19)flag=0;
			else if((!d)&&c<=key[0])flag=1;
			else if((!d)&&c<=key[2])flag=2;
			else if(d<key[4]||(d==key[4]&&c<=key[5]))flag=3;
		}
		else
		{
			int len=strlen(a);
			char b[110];
			CLR(b,0);
			long long c,d;
			c=d=0;
			int j=0;
			while(a[j]=='0')j++;
			for(int i=j;i<len;i++)
			{
				b[i-j]=a[i];
			}
			len=strlen(b);
			for(int i=max(len-10,0);i<len;i++)
			{
				c=c*10+b[i]-'0';
			}
		//	long long temp1=0;
		/*	while(c)
			{
				temp1=temp1*10+c%10;
				c/=10;
			}
			c=temp1;*/
			for(int i=0;i<=len-11;i++)
			{
				d=d*10+b[i]-'0';
			}
		//	cout<<c<<endl;
		//	cout<<d<<endl;
		//	cout<<(c<=key[3])<<endl;
			if(len>19)flag=0;
			else if((!d)&&c<=key[1])flag=1;
			else if((!d)&&c<=key[3])flag=2;
			else if(d<key[6]||(d==key[6]&&c<=key[7]))flag=3;
		}
		//cout<<flag<<endl;
		if(flag==1)cout<<"short"<<endl;
		else if(flag==2)cout<<"int"<<endl;
		else if(flag==3)cout<<"long long"<<endl;
		else cout<<"It is too big!"<<endl;
		
	}
	return 0;
}



