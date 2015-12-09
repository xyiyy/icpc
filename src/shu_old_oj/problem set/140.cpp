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
string  str[10]={"Áã","Ò¼","·¡","Èþ","ËÁ","Îé","Â½","Æâ","°Æ","¾Á"};
string str1[10]={"ÍòÒÚ","ÒÚ","Íò","Çª","°Û","Ê°","Ôª","½Ç","·Ö"};
char a[200];
int main()
{
	ios::sync_with_stdio(false);
	double n;
	ll m;
	int k=1,j;
	int mark;
	CLR(a,'\0');
	bool flag=0;
	while(cin.getline(a,200,'\n'))
	{
		mark=0;
		flag=0;
		while(a[mark]!='.'&&mark<strlen(a))
		{
			mark++;
		}
		if(mark==strlen(a)){a[mark]='.';a[mark+1]='0';a[mark+2]='0';}
		if(strlen(a)==mark+2){a[mark+2]='0';}
		if(mark+1==strlen(a)){a[mark+1]='0';a[mark+2]='0';}
		cout<<"Case "<<k++<<": ±Ò";
		m=0;
		if(mark>12)
		{
			m=a[0]-'0';
		}
		if(m)
		{
			cout<<str[m]<<str1[0];
			flag=1;
		}
		m=0;
		if(mark>8)
			for(int i=max(mark-12,0);i<mark-8;i++)
			{
				m*=10;
				m+=a[i]-'0';
			}
	//	else m=0;
		if(m||flag)
		{
			if(m>999||flag)
			{
				cout<<str[m/1000]<<str1[3];
			}
			if(m>99||flag)
			{
				cout<<str[(m/100)%10]<<str1[4];
			}
			if(m>9||flag)
			{
				cout<<str[(m/10)%10]<<str1[5];
			}
			if(m||flag)cout<<str[m%10]<<str1[1];
			flag=1;
		}
		m=0;
		if(mark>4)
			for(int i=max(mark-8,0);i<mark-4;i++)
			{
				m*=10;
				m+=a[i]-'0';
			}
		else m=0;
		if(m||flag)
		{
			if(m>999||flag)
			{
				cout<<str[m/1000]<<str1[3];
			}
			if(m>99||flag)
			{
				cout<<str[(m/100)%10]<<str1[4];
			}
			if(m>9||flag)
			{
				cout<<str[(m/10)%10]<<str1[5];
			}
			if(m||flag)cout<<str[m%10]<<str1[2];	
			flag=1;
		}
		m=0;
		if(mark>0)
			for(int i=max(mark-4,0);i<mark;i++)
			{
				m*=10;
				m+=a[i]-'0';
			}
		else m=0;
		if(m||flag)
		{
			if(m>999||flag)
			{
				cout<<str[m/1000]<<str1[3];
			}
			if(m>99||flag)
			{
				cout<<str[(m/100)%10]<<str1[4];
			}
			if(m>9||flag)
			{
				cout<<str[(m/10)%10]<<str1[5];
			}
			//if(m)
			
		}
		cout<<str[m%10]<<str1[6];
		m=0;
		for(int i=0;i<2&&mark+1+i<strlen(a);i++)
		{
			m*=10;
			m+=a[mark+1+i]-'0';
		}
		cout<<str[m/10]<<str1[7];
		cout<<str[m%10]<<str1[8];
		
		cout<<" £¤";
		for(j=0;j<mark;j++)
		{
			if((mark-j)%3==1&&(mark-j)!=1)
			{
				cout<<a[j]<<",";
			}
			else cout<<a[j];
		}
		cout<<"."<<a[mark+1]<<a[mark+2]<<"Ôª"<<endl;
		CLR(a,'\0');
	}
		
		 
		
	return 0;
}

