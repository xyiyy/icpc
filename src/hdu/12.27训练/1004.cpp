#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char a[10000];
	while(cin.getline(a,10000)&&a[0]!='\0')
	{
		int num=0;
		int len=strlen(a);
		int vis[len];
		for(int i=0;i<len;i++)
		{
			vis[i]=0;
		}
		for(int i=0;i<len;i++)
		{
			if(a[i]==104&&vis[i]==0)
			{
				vis[i]=1;
				for(int j=i+1;j<len;j++)
				{
					if(a[j]==97&&vis[j]==0)
					{
						vis[j]=1;
						for(int k=j+1;k<len;k++)
						{
							if(a[k]==112&&vis[k]==0)
							{
								vis[k]=1;
								for(int l=k+1;l<len;l++)
								{
									if(a[l]==112&&vis[l]==0)
									{
										vis[l]=1;
										for(int m=l+1;m<len;m++)
										{
											if(a[m]==121&&vis[m]==0)
											{
												vis[m]=1;
												num++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<num<<endl;
		for(int i=0;i<len;i++)
		{
			a[i]='\0';
		}
	}
	return 0;
}
		
		
		
		
