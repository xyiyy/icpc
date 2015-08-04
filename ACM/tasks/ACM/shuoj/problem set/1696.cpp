#include<iostream>
using namespace std;

int mat[500][500],vis[500][500];
int l,h;
void dfs(int x,int y,int &size)
{
	if(x==l||y==h||x<0||y<0)return;
	if(mat[x][y]==1)return;
	else
	{
		if(vis[x][y]==1)return ;
		else
		{
			vis[x][y]=1;
			size++;
			dfs(x-1,y,size);
			dfs(x,y-1,size);
			dfs(x+1,y,size);
			dfs(x,y+1,size);
		}
	}
}


int main()
{
	int len,hig;
	while(cin>>len>>hig)
	{
	l=len;h=hig;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<hig;j++)
		{ 
			cin>>mat[i][j];
			vis[i][j]=0;
		}
	}
	int m=0;int num=0;
	for(int i=0;i<len;i++)
	{	
		for(int j=0;j<hig;j++)
		{
			int size=0;
			dfs(i,j,size);
			if(m<size)
			m=size;
			if(size!=0)
			num++;
		}
	}
	cout<<num<<' '<<m<<endl;
}
	return 0;
}
	
