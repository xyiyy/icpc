#include<iostream>
using namespace std;

int main()
{
	char a[100];
	cin.getline(a,100);
	for(int i=0;a[i]!='\0';i++)
	{
		if (a[i]>64 && a[i]<91) 
			a[i]+=32;
	}
	cout<<a;
	return 0;
}
