#include <iostream>
#include <cstring>
using namespace std;
int n,m,k,len;
string str[20];
char a[60][60];
int d[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int dfs(int x,int y,int l,int dir,int num)
{
	if(a[x][y]==str[num][l])
	{
		l++;
		if(l==len)return 1;
		if(dfs(x+d[dir][0],y+d[dir][1],l,dir,num))return 1;
		return 0;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int T,flag;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>='A'&&a[i][j]<='Z')a[i][j]+='a'-'A';
			}
		}
		cin>>k;
		for(int i=0;i<k;i++)
		{
			cin>>str[i];
			len=str[i].length();
			for(int j=0;j<len;j++)
			{
				if(str[i][j]>='A'&&str[i][j]<='Z')str[i][j]+='a'-'A';
			}
			for(int y=1;y<=m;y++)
			{
				for(int x=1;x<=n;x++)
				{
					for(int dir=0;dir<8;dir++)
					{
						flag=dfs(x,y,0,dir,i);
						if(flag)
						{
							cout<<x<<" "<<y<<endl;
							break;
						}
					}
					if(flag)break;
				}
				if(flag)break;
			}
		}
		if(T)cout<<endl;
	}
		
	return 0;
}


