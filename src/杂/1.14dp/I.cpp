#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M=100000;
int dpmax[60][60],dpmin[60][60];
char c[60];


int main(){
    int n;
    while(cin >> n)
	{
		getchar();
		for(int i=0;i<n;i++)
		{
            int num;
            scanf("%c %d",c+i,&num);
            getchar();
            dpmax[i][i]=num;
            dpmin[i][i]=num;
        }
        for(int j=1;j<n;j++)
		{
            for(int i=0;i<n;i++)
			{
                int a=(i+j)<n?(i+j):((i+j)%n);
                dpmax[i][a]=-M;
                dpmin[i][a]=M;
                for(int k=0;k<j;k++)
				{
                    if(c[(i+k+1)%n]=='t')
					{
                        if(dpmax[i][a]<dpmax[i][(i+k)%n]+dpmax[(i+k+1)%n][a])
                            dpmax[i][a]=dpmax[i][(i+k)%n]+dpmax[(i+k+1)%n][a];
                        if(dpmin[i][a]>dpmin[i][(i+k)%n]+dpmin[(i+k+1)%n][a])
                            dpmin[i][a]=dpmin[i][(i+k)%n]+dpmin[(i+k+1)%n][a];
                    }
                    else{
                        if(dpmax[i][a]<dpmax[i][(i+k)%n]*dpmax[(i+k+1)%n][a])
                            dpmax[i][a]=dpmax[i][(i+k)%n]*dpmax[(i+k+1)%n][a];
                        if(dpmax[i][a]<dpmax[i][(i+k)%n]*dpmin[(i+k+1)%n][a])
                            dpmax[i][a]=dpmax[i][(i+k)%n]*dpmin[(i+k+1)%n][a];
                        if(dpmax[i][a]<dpmin[i][(i+k)%n]*dpmax[(i+k+1)%n][a])
                            dpmax[i][a]=dpmin[i][(i+k)%n]*dpmax[(i+k+1)%n][a];
                        if(dpmax[i][a]<dpmin[i][(i+k)%n]*dpmin[(i+k+1)%n][a])
                            dpmax[i][a]=dpmin[i][(i+k)%n]*dpmin[(i+k+1)%n][a];
                        if(dpmin[i][a]>dpmax[i][(i+k)%n]*dpmax[(i+k+1)%n][a])
                            dpmin[i][a]=dpmax[i][(i+k)%n]*dpmax[(i+k+1)%n][a];
                        if(dpmin[i][a]>dpmax[i][(i+k)%n]*dpmin[(i+k+1)%n][a])
                            dpmin[i][a]=dpmax[i][(i+k)%n]*dpmin[(i+k+1)%n][a];
                        if(dpmin[i][a]>dpmin[i][(i+k)%n]*dpmax[(i+k+1)%n][a])
                            dpmin[i][a]=dpmin[i][(i+k)%n]*dpmax[(i+k+1)%n][a];
                        if(dpmin[i][a]>dpmin[i][(i+k)%n]*dpmin[(i+k+1)%n][a])
                            dpmin[i][a]=dpmin[i][(i+k)%n]*dpmin[(i+k+1)%n][a];
                    }
                }
            }
        }
        int a[60];
        int l=0,m=-M;
        for(int i=0;i<n;i++){
            m=max(m,dpmax[i][(i+n-1)%n]);
        }
        for(int i=0;i<n;i++)
            if(dpmax[i][(i+n-1)%n]==m) a[l++]=i+1;
            cout << m << endl;
        for(int i=0;i<l;i++){
            if(i>0) printf(" %d",a[i]);
            else printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
