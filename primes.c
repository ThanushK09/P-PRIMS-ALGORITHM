#include<stdio.h>
#include<conio.h>
# define INF 999

int primes(int c[10][10],int n,int s){
    int v[10],i,j,u,min,d[10],sum=0,ver[10];
    
    for(i=1;i<=n;i++){
        d[i]=c[s][i];
        v[i]=0;
        ver[i]=s;
    }

    v[s]=1;
    for(i=1;i<=n;i++){
        min = INF;
        for(j=1;j<=n;j++)
        if(v[j]==0 && d[j]<min){
            min=d[j];
            u=j;
        }
        v[u]=1;
        sum=sum+d[u];
        printf("%d->%d is %d",ver[u],u,sum);
        for(j=1;j<=n;j++)
        if(v[j]==0 && c[u][j]<d[j])
        d[j]=d[u]+c[u][j];
        
    }
    return sum;
}

void main(){
    int c[10][10],n,s,d[10],i,j,res;
    clrscr();
    printf("enter the number of nodes");
    scanf("%d",&n);
    printf("enter the graph data");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&c[i][j]);
    printf("Enter the source node");
    scanf("%d",&s);
    res=primes(c,n,s);
    printf("the cost is %d",res);
    getch();
    }
    
