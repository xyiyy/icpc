#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int i=0;
int b[4];
int a;
int k=1;
int num=0;
void print(int n)
{
	memset(b,0,sizeof(b));
	i=3;
	while(n)
	{
		b[i--]=n%2;
		n/=2;
	}
	for(i=0;i<4;i++)
	{
		if(b[i])cout<<"¡ö";
		else cout<<"¡õ";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	
	cin>>hex;
	while(cin>>a)
	{
		if(num%16==0)
		cout<<"Case "<<k++<<":"<<endl;
		num++;
		print(a/16);
		print(a%16);
		cin>>a;
		print(a/16);
		print(a%16);
		cout<<endl;
		
	}
	return 0;
}

