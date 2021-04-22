#include<bits/stdc++.h>
using namespace std;
typedef int ll;
 
ll arr[1508][1508];
ll ld[808][808];
ll rd[808][808];
ll lu[808][808];
ll ru[808][808];
 
int main(){
    ll i,j,k,l,m,n;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%1d",&arr[i][j]);
 
    for(i=n;i>=1;i--)
        for(j=1;j<=m;j++)
            if(arr[i][j]==1){
                ld[i][j]=ld[i+1][j-1]+1; //3
                rd[i][j]=rd[i+1][j+1]+1; //2
            }
 
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(arr[i][j]==1){
                lu[i][j]=lu[i-1][j-1]+1; //0
                ru[i][j]=ru[i-1][j+1]+1; //1
            } 

    ll ans=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            cout<<min(ru[i][j], rd[i][j])<<"\n";
            for(k=1;k<=min(ld[i][j],rd[i][j]);k++)
                if(arr[i+2*(k-1)][j]&&lu[i+2*(k-1)][j]>=k&&ru[i+2*(k-1)][j]>=k)
                    ans=max(ans,k);
            for(k=1;k<=min(ru[i][j],rd[i][j]);k++)
                if(arr[i][j+2*(k-1)]&&lu[i][j+2*(k-1)]>=k&&ld[i][j+2*(k-1)]>=k)
                    ans=max(ans,k);    
        }
    printf("%d",ans);
}