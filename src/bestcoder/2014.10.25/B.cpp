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

string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		if(n)
		{
			cin>>s1>>s2;
			string ans;
			if(s1=="ADD")ans="000001";
			else if(s1=="SUB")ans="000010";
			else if(s1=="DIV")ans="000011";
			else if(s1=="MUL")ans="000100";
			else if(s1=="MOVE")ans="000101";
			else if(s1=="SET")ans="000110";
			int i=0;
			while(s2[i]=='R')
			{
				i++;
			}
		//	cout<<endl;
			int num1=0;
			while(s2[i]>='0'&&s2[i]<='9')
			{
				num1=num1*10+s2[i]-'0';
				//cout<<s2[i];
				i++;
			}
			int num2=num1;
			//cout<<num1<<endl;
			char a[15];
			CLR(a,0);
			for(int j=4;j>=0;j--)
			{
				if(num1%2)a[j]='1';
				else a[j]='0';
				num1/=2;
			}
			char b[15];
			CLR(b,0);
			for(int i=0;i<5;i++)
			{
				b[i]=a[i];
			}
			//cout<<b;
			//cout<<num2<<endl;
			if(s1=="SET")
			{
				if(num2){
				cout<<ans<<b;
				cout<<"00000"<<endl;
				continue;}
				else 
				{
					cout<<"Error!"<<endl;
					continue;
				}
			}
			i++;
			while(s2[i]=='R')
			{
				i++;
			}
			num1=0;
			while(s2[i]>='0'&&s2[i]<='9')
			{
				num1=num1*10+s2[i]-'0';
				i++;
			}
			num2=num1;
			for(int j=4;j>=0;j--)
			{
				if(num1%2)a[j]='1';
				else a[j]='0';
				num1/=2;
			}
		//	if(num2)
		//	{
				cout<<ans<<b<<a<<endl;
		//	}
		//	else 
		//	{
		//		cout<<"Error!"<<endl;
		//	}
		}
		else 
		{
			char a[20];
			char b[20];
			cin>>a;
			int num=0;
			for(int i=0;i<6;i++)
			{
				b[i]=a[i];
			}
			s1=b;
			string ans;
			if(s1=="000001")ans="ADD";
			else if(s1=="000010")ans="SUB";
			else if(s1=="000011")ans="DIV";
			else if(s1=="000100")ans="MUL";
			else if(s1=="000101")ans="MOVE";
			else if(s1=="000110")ans="SET";
			else {cout<<"Error!"<<endl;continue;}
			for(int i=6;i<11;i++)
			{
				b[i-6]=a[i];
			}
			
			b[6]=0;
			
			num=0;
			for(int i=0;i<5;i++)
			{
				num=num*2+(b[i]-'0');
			}
			if(num==0)
			{
				cout<<"Error!"<<endl;continue;
			}
			int num2=num;
			//cout<<num<<endl;
			for(int i=11;i<16;i++)
			{
				b[i-11]=a[i];
			}
			
			b[6]=0;
			num=0;
			for(int i=0;i<5;i++)
			{
				num=num*2+(b[i]-'0');
			}
			//cout<<num<<endl;
			if(num==0&&s1!="000110")
			{
				cout<<"Error!"<<endl;continue;
			}
			else if(s1=="000110"&&num)
			{
				cout<<"Error!"<<endl;continue;
			}
			cout<<ans;
			cout<<" R";
			cout<<num2;
			if(s1!="000110")
			{
				cout<<",R";
				cout<<num<<endl;
			}
			else cout<<endl;
		}
			
	}
			
			
	return 0;
}



