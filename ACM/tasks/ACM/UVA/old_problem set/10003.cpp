#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAXN 12100


int t[MAXN];
int sum;
int ans[90][90]={0};


int cmp(void const*a,void const *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int i,j,l,n,k,temp,min;
	
	while(cin>>l)
	{
		
		memset(t,0,sizeof(t));
		if (l==0) break;
		cin>>n;
		t[0]=0;
		for (i=1;i<=n;i=i+1)
			cin>>t[i];
		t[n+1]=l;
		//qsort(t,n,sizeof(int),cmp);
		
		for (i=0;i<=n+1;i=i+1)
			for (j=i+1;j<=n+1;j=j+1)
			{
				if (j==i+1) ans[i][j]=0;
				else ans[i][j]=MAXN;
			}
		
		for (k=2;k<=n+1;k=k+1)
			for (i=0;i+k<n+2;i=i+1)
				for (j=i;j<k+i;j=j+1)
				{
					temp=ans[i][j]+ans[j][i+k]+t[i+k]-t[i];
					if (temp<ans[i][i+k]) ans[i][i+k]=temp;
				}
					
		cout<<"The minimum cutting is "<<ans[0][n+1]<<"."<<endl;
	}
	return 0;
}
	

