#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

long MatrixChain(int matrixNum,long *memoTable,int *dim,int *bestK)
{
	int i,j,len,k;
	for(int i=1;i<=matrixNum;i++)
		memoTable[i*matrixNum+i]=0;
	for(len=2;len<=matrixNum;len++)
	{
		for(i=1;i<=matrixNum-len+1;i++)
		{
			j=i+len-1;
			memoTable[i*matrixNum+j]=10000000;
			for(k=i;k<j;k++)
			{
				long ans=memoTable[i*matrixNum+k]+memoTable[(k+1)*matrixNum+j]+dim[i-1]*dim[k]*dim[j];
				if (ans<memoTable[i*matrixNum+j])
				{
					bestK[i*matrixNum+j]=k;
					memoTable[i*matrixNum+j]=ans;
				}
			}
		}
	}
	return memoTable[1*matrixNum+matrixNum];
}

void traceback(int i,int j,int *s,int matrixNum)
{
    if(i==j){cout<<"A"<<i;return;}
    else if(i+1==j&&(i!=1||j!=matrixNum))
    {
    	cout<<"(A"<<i<<"A"<<j<<")";
    }
    else if(i==1&&j==matrixNum)
    {
    	traceback(i,s[i*matrixNum+j],s,matrixNum);
		traceback(s[i*matrixNum+j]+1,j,s,matrixNum);
	}
	else
    {
    	cout<<"(";
		traceback(i,s[i*matrixNum+j],s,matrixNum);
		traceback(s[i*matrixNum+j]+1,j,s,matrixNum);
		cout<<")";
	}
}


int main()
{
	int i,matrixNum,k=1;
	while(scanf("%d",&matrixNum)!=EOF)
	{
		long memoTable[matrixNum*matrixNum];
		int dim[matrixNum];
		int bestK[matrixNum*matrixNum];
		for(int i=0;i<=matrixNum;i++)
		{
			scanf("%d",&dim[i]);
		}
		cout<<"Case "<<k<<endl;
		printf("%ld",MatrixChain(matrixNum,memoTable,dim,bestK));
		cout<<" ";
		traceback(1,matrixNum,bestK,matrixNum);
		cout<<endl;
		k++;
	}
	return 0;
}
				
				
				
				
				
