#include <queue>
#include <iostream>
using namespace std;
#define MAXN 1000010

int l[MAXN],r[MAXN];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int ch;
		int now=1;
		for(int i=0;i<=n+2;i++)r[i]=i+1;
		for(int i=1;i<=n+4;i++)l[i]=i-1;
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&ch);
			if(ch==1)now=l[now];
			else if(ch==2)now=r[now];
			else if(ch==3){
				l[r[now]]=l[now];
				r[l[now]]=r[now];
				q.push(now);
				now=r[now];
			}else if(ch==4){
				int x=q.top();
				q.pop();
				r[x]=r[now];
				l[r[x]]=x;
				l[x]=now;
				r[now]=x;
			}
		}
		int t=0;
		while(r[t]!=n+1)
		{
			if(t)printf(" ");
			t=r[t];
			printf("%d",t);
		}
		printf("\n");
	}
	return 0;
}



