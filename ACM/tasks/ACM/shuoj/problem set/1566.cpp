#include<iostream>
using namespace std;
int a[5][5],fa[5][5],dist[5][5],vis[5][5],last_dir[5][5];
int q[25];
int dx[4]={-1,0,0,1};int dy[4]={0,1,-1,0};
int main()
{
	int T,d;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		int x=0,y=0;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cin>>a[i][j];
				q[5*i+j]=a[i][j];
				vis[i][j]=0;
				fa[i][j]=0;
				last_dir[i][j]=0;
			}
		}
		int front=0,rear=0,d,u=0;
		vis[0][0]=1;
		fa[0][0]=u;dist[0][0]=0;
		q[rear]=u;
		rear++;
		while(front<rear)
		{
			u=q[front++];
			x=u/5;y=u%5;
			for(d=0;d<4;d++)
			{
				int nx=x+dx[d];int ny=y+dy[d];
				if(nx>=0&&ny>=0&&nx<5&&ny<5&&a[nx][ny]==0&&vis[nx][ny]==0)
				{
					int v=nx*5+ny;
					q[rear++]=v;
					vis[nx][ny]=1;
					fa[nx][ny]=u;
					dist[nx][ny]=dist[x][y]+1;
					last_dir[nx][ny]=d;
				}
			}
		}
		
		int b[30],c[30];
		b[0] = c[0] = 4;
		int i;
		for(i = 1; b[i-1]!=0 || c[i-1]!=0; i++)
		{
			b[i]=b[i-1] - dx[last_dir[b[i-1]][c[i-1]]];
			c[i]=c[i-1] - dy[last_dir[b[i-1]][c[i-1]]];
		}
		
		cout<<"Case "<<k<<":"<<endl;
		for(i--; i>=0; i--)
		{
			cout<<"("<<b[i]<<", "<<c[i]<<")"<<endl;
		}
	}
	return 0;
}

 
