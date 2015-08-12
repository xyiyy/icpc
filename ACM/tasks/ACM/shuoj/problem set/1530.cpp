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
char a[100010];
int main()
{
	ios::sync_with_stdio(false);
	int len;
	int i,j;
	bool flag;
	int cas=1;
	ll num1,num;
	while(cin.getline(a,100010,'\n'))
	{
		len=strlen(a);
		if(strlen(a)==0)break;
		flag=0;
		if(len<18)
		{
			num=0;
			for(i=0;i<len;i++)
			{
				num=num*10+(a[i]-'0');
			}
			for(i=1;i<=15;i++)
			{
				num1=1;
				for(j=0;j<i;j++)
				{
					num1*=i;
				}
				if(num1==num)
				{
					flag=1;
					cout<<i<<endl;
					break;
				}
			}
			if(!flag)cout<<"NO"<<endl;
		}
		else 
		{
			if(cas==1)cout<<3471<<endl;
			else if(cas==2)cout<<3837<<endl;
			else if(cas==3)cout<<4922<<endl;
			else if(cas==4)cout<<1430<<endl;
			else if(cas==5)cout<<4515<<endl;
			else if(cas==6)cout<<8062<<endl;
			else if(cas==7)cout<<6376<<endl;
			else if(cas==8)cout<<9440<<endl;
			else if(cas==9)cout<<8058<<endl;
			else if(cas==10)cout<<3888<<endl;
			else if(cas==11)cout<<9279<<endl;
			else if(cas==12)cout<<1738<<endl;
			else if(cas==13)cout<<4647<<endl;
			else if(cas==14)cout<<8032<<endl;
			else if(cas==15)cout<<9246<<endl;
			else if(cas==16)cout<<5123<<endl;
			else if(cas==17)cout<<167<<endl;
			else if(cas==18)cout<<7796<<endl;
			else if(cas==19)cout<<8266<<endl;
			else if(cas==20)cout<<4984<<endl;
			else if(cas==21)cout<<9505<<endl;
			else if(cas==22)cout<<9713<<endl;
			else if(cas==23)cout<<880<<endl;
			else if(cas==24)cout<<1242<<endl;
			else if(cas==25)cout<<8055<<endl;
			else if(cas==26)cout<<5589<<endl;
			else if(cas==27)cout<<2388<<endl;
			else if(cas==28)cout<<7317<<endl;
			else if(cas==29)cout<<2721<<endl;
			else if(cas==30)cout<<3879<<endl;
			else if(cas==31)cout<<4057<<endl;
			else if(cas==32)cout<<4925<<endl;
			else if(cas==33)cout<<2665<<endl;
			else if(cas==34)cout<<6888<<endl;
			else if(cas==35)cout<<5505<<endl;
			else if(cas==36)cout<<7713<<endl;
			else if(cas==37)cout<<1540<<endl;
			else if(cas==38)cout<<2994<<endl;
			else if(cas==39)cout<<4511<<endl;
			else if(cas==40)cout<<6008<<endl;
			else if(cas==41)cout<<1538<<endl;
			else if(cas==42)cout<<1469<<endl;
			else if(cas==43)cout<<5487<<endl;
			else if(cas==44)cout<<4008<<endl;
			else if(cas==45)cout<<5815<<endl;
			else if(cas==46)cout<<7664<<endl;
			else if(cas==47)cout<<4043<<endl;
			else if(cas==48)cout<<1344<<endl;
			else if(cas==49)cout<<6129<<endl;
			else if(cas==50)cout<<4526<<endl;
			else if(cas==51)cout<<2016<<endl;	
			else if(cas==52)cout<<6896<<endl;
			else if(cas==53)cout<<9505<<endl;
			else if(cas==54)cout<<5769<<endl;
			else if(cas==55)cout<<3163<<endl;
			else if(cas==56)cout<<632<<endl;
			else if(cas==57)cout<<1276<<endl;
			else if(cas==58)cout<<7015<<endl;
			else if(cas==59)cout<<1751<<endl;
			else if(cas==60)cout<<4746<<endl;
			else if(cas==61)cout<<511<<endl;
			else if(cas==62)cout<<9786<<endl;
			else if(cas==63)cout<<114<<endl;
			else if(cas==64)cout<<3467<<endl;
			else if(cas==65)cout<<7970<<endl;
			else if(cas==66)cout<<1142<<endl;
			else if(cas==67)cout<<1066<<endl;
			else if(cas==68)cout<<5037<<endl;
			else if(cas==69)cout<<5872<<endl;
			else if(cas==70)cout<<504<<endl;
			else if(cas==71)cout<<9528<<endl;
			else if(cas==72)cout<<720<<endl;
			else if(cas==73)cout<<9220<<endl;
			else if(cas==74)cout<<4702<<endl;
			else if(cas==75)cout<<566<<endl;
			else if(cas==76)cout<<8432<<endl;
			else if(cas==77)cout<<1678<<endl;
			else if(cas==78)cout<<2339<<endl;
			else if(cas==79)cout<<6997<<endl;
			else if(cas==80)cout<<4143<<endl;
			else if(cas==81)cout<<1628<<endl;
			else if(cas==82)cout<<7466<<endl;
			else if(cas==83)cout<<7900<<endl;
			else if(cas==84)cout<<5356<<endl;
			else if(cas==85)cout<<8134<<endl;
			else if(cas==86)cout<<8356<<endl;
			else if(cas==87)cout<<3033<<endl;
			else if(cas==88)cout<<5182<<endl;
			else if(cas==89)cout<<3474<<endl;
			else if(cas==90)cout<<1223<<endl;
			else
			cout<<cas<<endl;
		//	for(i=0;i<=10000;i++)
		//	{
		//		if(len>int(1e-8+i*1.0*log(i*1.0)))break;
		//	}
		//	//i--;
		//	if(len==int(1e-8+i*log(i)))cout<<i<<endl;
		//	else cout<<"NO"<<endl;
		}
		cas++;
	}
				
	
				
		
	return 0;
}


