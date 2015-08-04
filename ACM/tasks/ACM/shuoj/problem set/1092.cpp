#include<iostream>
using namespace std;

int main()
{
	char a[80],b[80];
	for(int i=0;i<80;i++)b[i]='\0';
	cin.getline(a,80);
	int num=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		{
			b[num]=a[i];
			num++;
		}
	}
	cout<<b<<endl;
	return 0;
}
		
