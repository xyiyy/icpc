#include<iostream>
#include<cstring>
using namespace std;
char a[256],vis[256];



int main()
{
	int i,j;
	 while (cin.getline(a,256))
	 {
	 	for(i=0;i<256;i++)
	 	{
	 		vis[i]=0;
	 	}
	 	for(i=0;a[i]!='\0';i++)
	 	{
	 		if(vis[i]==1)continue;
	 		if(a[i]==41||a[i]==62||a[i]==93||a[i]==125)
	 		{
	 		cout<<"NO"<<endl;
	 			break;
	 		}
	 		vis[i]=1;
	 		for(j=0;(a[j]!=a[i]+2||a[j]!=a[i]+1)&&a[j]!='\0';j++)
	 		{
	 			if(vis[j]==0)continue;
	 		}
	 		vis[j]=1;
	 		if(a[j]=='\0')
	 		{
	 			cout<<"NO"<<endl;
	 			break;
	 		}
	 	}
	 	if(a[j]!='\0'&&a[i]=='\0')
	 	cout<<"YES"<<endl;
	 }
	 return 0;
}
	 			
	 
