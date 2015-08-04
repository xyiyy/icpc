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
char a[50][50];

int main()
{
	ios::sync_with_stdio(false);
	int t;
	int r,c,num;
//	freopen("C-small-attempt8.in","r",stdin);
//	freopen("c_small.out","w",stdout);
	int k=1;
	cin>>t;
	while(t--)
	{
		int n=0;
		cin>>r>>c>>num;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				a[i][j]='\0';
			}
		}
		a[r-1][c-1]='c';
		if(r>1)a[r-2][c-1]='.';
		if(c>1)a[r-1][c-2]='.';
		if(c>1&&r>1)a[r-2][c-2]='.';
		
		for(int i=0;i<r&&n<num;i++)
		{
			for(int j=0;j<c&&n<num;j++)
			{
				if(a[i][j]=='.'||a[i][j]=='c')continue;
			//	else if(j==c-2&&i+1<r-2) {a[i+1][0]='*';n++;}
			//	else if(j==c-1&&a[i+1][0]=='*'){a[i][j-1]='*';a[i][j]='*';a[i+1][0]='0';}
				else {a[i][j]='*';n++;}
			}
		}
		if(r==5&&c==5&&num==4){a[1][0]='*';a[0][3]='.';}
		if(r==5&&c==5&&num==9){a[2][0]='*';a[1][3]='.';}
		if(r==5&&c==5&&num==14){a[4][0]=a[2][2];a[3][0]=a[2][3];a[2][2]='.';a[2][3]='.';}
		if(r==5&&c==5&&num==16){a[4][0]='*';a[3][1]='*';a[4][1]='*';a[2][2]='.';a[2][3]='.';a[2][4]='.';}
		if(r==5&&c==5&&num==17){a[4][0]='*';a[3][1]='.';}
		if(r==5&&c==5&&(num==18||num==20)){n=0;}
		if(r==5&&c==5&&num==19){a[4][1]='*';a[3][2]='.';}
		if(r==5&&c==5&&num==24){a[4][3]='*';a[3][4]='*';a[3][3];n=24;}
		
		if(r==5&&c==4&&num==3){a[1][0]='*';a[2][0]='.';}
		if(r==5&&c==4&&num==7){a[2][0]='*';a[1][2]='.';}
		if(r==5&&c==4&&num==11){a[2][1]='.';a[2][2]='.';a[3][0]='*';a[4][0]='*';}
		if(r==5,c==4&&(num==13||num==15)){n=0;}
		if(r==5&&c==4&&num==14){a[4][0]='*';a[3][1]='.';}
		
		
		if(r==5&&c==3&&num==2){a[0][1]='.';a[1][0]='*';}
		if(r==5&&c==3&&num==5){a[1][1]='.';a[2][0]='*';}
		if(r==5&&c==3&&(num==10||num==8)){n=0;}
		
		if(r==5&&c==2&&(num==1||num==3||num==5)){n=0;}
		
		if(r==4&&c==5&&num==4){a[1][0]='*';a[0][3]='.';}
		if(r==4&&c==5&&num==9){a[1][3]='.';a[1][4]='.';a[2][0]='*';a[3][0]='*';}
		if(r==4&&c==5&&num==11){a[1][3]='.';a[1][4]='.';a[1][2]='.';a[2][1]='*';a[3][1]='*';a[3][0]='*';}
		if(r==4&&c==5&&num==12){a[3][0]='*';a[2][1]='.';}
		if(r==4&&c==5&&(num==13||n==15)){n=0;}
		if(r==4&&c==5&&num==14){a[3][1]='*';a[2][2]='.';}
		
		if(r==4&&c==4&&num==3){a[1][0]='*';a[0][2]='.';}
		if(r==4&&c==4&&num==7){a[2][0]='*';a[1][2]='.';a[3][0]='*';a[1][1]='.';}
		if(r==4&&c==4&&(num==9||num==11)){n=0;}
		if(r==4&&c==4&&num==10){a[2][1]='.';a[3][0]='*';}
		
		if(r==4&&c==3&&num==2){a[1][0]='*';a[0][1]='.';}
		if(r==4&&c==3&&(num==5||num==7)){n=0;}
		
		if(r==4&&c==2&&(num==1||num==3)){n=0;}
		
		if(r==3&&c==5&&num==4){a[1][0]='*';a[2][0]='*';a[0][3]='.';a[0][2]='.';}
		if(r==3&&c==5&&num==6){a[2][0]='*';a[1][1]='*';a[2][1]='*';a[0][2]='.';a[0][4]='.';a[0][3]='.';}
		if(r==3&&c==5&&num==7){a[2][0]='*';a[1][1]='.';}
		if(r==3&&c==5&&(num==8||num==10)){n=0;}
		if(r==3&&c==5&&num==9){a[2][1]='*';a[1][2]='.';}
		
		if(r==3&&c==4&&num==3){a[1][0]='*';a[0][2]='.';a[2][0]='*';a[0][1]='.';}
		if(r==3&&c==4&&(num==5||num==7)){n=0;}
		if(r==3&&c==4&&num==6){a[2][0]='*';a[0][2]='.';a[2][1]='*';a[0][3]='.';}
		
		if(r==3&&c==3&&(num==4||num==2)){n=0;}
		
		if(r==3&&c==2&&(num==1)){n=0;}
		
		if(r==2&&c==5&&(num==1||num==3||num==5)){n=0;}
		if(r==2&&c==5&&num==2){a[0][1]='.';a[1][0]='*';}
		if(r==2&&c==5&&num==4){a[0][2]='.';a[1][1]='*';}
		
		if(r==2&&c==4&&(num==1||num==3)){n=0;}
		if(r==2&&c==4&&num==2){a[1][0]='*';a[0][1]='.';}
		
		if(r==2&&c==3&&num==1){n=0;}
		
		if(num==r*c-1){n=num;if(r>1)a[r-2][c-1]='*';
		if(c>1)a[r-1][c-2]='*';
		if(c>1&&r>1)a[r-2][c-2]='*';}
		 
		
		
		cout<<"Case #"<<k++<<":"<<endl;
		if(n<num)cout<<"Impossible"<<endl;
		else 
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(a[i][j]!='.'&&a[i][j]!='*'&&a[i][j]!='c')a[i][j]='.';
				}
			}
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<a[i][j];
				}
				cout<<endl;
			}
		}
	}
		
		
		
	return 0;
}

