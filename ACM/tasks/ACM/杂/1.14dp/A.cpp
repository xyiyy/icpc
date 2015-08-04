#include<stdio.h>  
#include<stdlib.h>  
struct M  
{  
    int ban, pri;  
}man[105][105];  
int n,t,m[105];  
double minbp;  
int main()  
{  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
        {  
            scanf("%d",&m[i]);  
            for(int j=0;j<m[i];j++)  
            {  
                scanf("%d%d",&man[i][j].ban,&man[i][j].pri);  
            }  
        }  
        minbp=0;  
        int minPri;  
        for(int i=0;i<n;i++)  
        {  
            for(int j=0;j<m[i];j++)  
            {  
                int minBan=man[i][j].ban;  
                int sumPri=man[i][j].pri;  
                for(int k=0;k<n;k++)  
                {  
                    if(k==i)  
                    {  
                        continue;  
                    }  
                    minPri=0x7FFFFFFF;  
                    for(int l=0;l<m[k];l++)  
                    {  
                        if(minBan<=man[k][l].ban && minPri>man[k][l].pri)  
                        {  
                            minPri=man[k][l].pri;  
                        }  
                    }  
                    if(minPri==0x7FFFFFFF)  
                    {  
                        break;  
                    }  
                    sumPri+=minPri;  
                }  
                if(minPri==0x7FFFFFFF)  
                {  
                    break;  
                }  
                if(minbp<(double)minBan/sumPri)  
                {  
                    minbp=(double)minBan/sumPri;  
                }  
            }  
        }  
        printf("%.3lf\n",minbp);  
    }  
    return 0;  
}
