#include<iostream>
using namespace std;

int main()
{
	char a[100];
	cin.getline(a,100);
	int j=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>64&&a[i]<91||(a[i]>96&&a[i]<123))
		j++;
	}
	cout<<j;
	return 0;
}
