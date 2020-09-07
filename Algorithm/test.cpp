#include <cstdio>
int n, m, d[50], i, j, x, y, t;

int main(void){
    scanf("%d", &n);
    for(;i<n; i++) scanf("%d", d+i);
    scanf("%d", &m);
    for(i=0; i<n; i++){
        for(x=0, j=i; j<n&&j-i<=m; j++) {
            if(x<d[j]) {
                x=d[j], y=j;
            }
        }
        m-=(y-i);
        printf("%d %d\n", y, i);
        for( ;i<y; y--) {
            printf("%d %d change\n", d[y], d[y-1]);
            t=d[y], d[y]=d[y-1], d[y-1]=t;
        }
        printf("------------------\n");
    }
    for(int a=0; a<n; a++) printf("%d ", d[a]);
}