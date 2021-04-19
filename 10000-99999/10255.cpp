// 10255번 교차점

#include <bits/stdc++.h>
using namespace std;
#define p(X, Y) make_pair(X, Y)

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int res=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    int A=ccw(a, b, c)*ccw(a, b, d);
    int B=ccw(a, c, d)*ccw(b, c, d);
    if(A==0 && B==0){
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return (c<=b && a<=d);
    }
    return (A<=0 && B<=0);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t, xmin, ymin, xmax, ymax;
    pair<int, int> pos1, pos2;
    
    cin>>t;
    while(t--){
        cin>>xmin>>ymin>>xmax>>ymax;
        cin>>pos1.first>>pos1.second>>pos2.first>>pos2.second;

        int cnt=0;
        if(cross(pos1, pos2, p(xmin, ymin), p(xmin, ymax))) cnt++;
        if(cross(pos1, pos2, p(xmin, ymin), p(xmax, ymin))) cnt++;
        if(cross(pos1, pos2, p(xmax, ymax), p(xmin, ymax))) cnt++;
        if(cross(pos1, pos2, p(xmax, ymax), p(xmax, ymin))) cnt++;
        
        if(cross(pos1, pos2, p(xmin, ymin), p(xmin, ymin))) cnt--;
        if(cross(pos1, pos2, p(xmin, ymax), p(xmin, ymax))) cnt--;
        if(cross(pos1, pos2, p(xmax, ymin), p(xmax, ymin))) cnt--;
        if(cross(pos1, pos2, p(xmax, ymax), p(xmax, ymax))) cnt--;

        int x1=pos1.first, y1=pos1.second, x2=pos2.first, y2=pos2.second;
        if(x1>x2) swap(x1, x2);
        if(y1>y2) swap(y1, y2);
        if((y1==ymin && y2==ymin) || (y1==ymax && y2==ymax)){
            cnt=1;
            if((xmin<=x1 && x1<xmax) || (xmin<x2 && x2<=xmax)) cnt=4;
            if(x1<=xmin && x2>=xmax) cnt=4;
        }
        if((x1==xmin && x2==xmin) || (x1==xmax && x2==xmax)){
            cnt=1;
            if((ymin<=y1 && y1<ymax) || (ymin<y2 && y2<=ymax)) cnt=4;
            if(y1<=ymin && y2>=ymax) cnt=4;
        }
        
        cout<<cnt<<"\n";
    }
}