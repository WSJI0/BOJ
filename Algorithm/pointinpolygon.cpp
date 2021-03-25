// 다각형의 내부 외부 판별

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* 
    CCW
    1=반시계, 0=일직선, -1=시계
*/
int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    ll res=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

/* 선분이 교차되있는지 판별 */
bool cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d){
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
    
    int n; // 다각형의 꼭짓점 수

    /*
    p : 점의 좌표
    point : 다각형을 이루는 꼭짓점들의 좌표
    */
    pair<ll, ll> p, point[10001]; 

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>point[i].first>>point[i].second;
    }
    cin>>p.first>>p.second;

    // curL : 반직선의 끝점 좌표
    pair<ll, ll> cur=p, curL=make_pair(1000000001, p.second+1); //y에 +1
    bool check=false; int cnt=0;
    for(int j=0; j<n; j++){
        pair<ll, ll> a=point[j], b=point[j+1];
        if(j==n-1) b=point[0];
        
        // 다각형의 꼭짓점 위에 위치해 있을 경우
        if(a.first==cur.first && a.second==cur.second){ 
            check=true; break;
        } 
        // 다각형의 선분 위에 위치해 있을 경우
        else if(cross(cur, cur, a, b)){
            check=true; break;
        }
        // 교차 할때마다 cnt에 +1
        if(cross(cur, curL, a, b)) cnt++;
    }
    if(check) cout<<"내부"<<"\n";
    else{
        // 짝수일때 외부, 홀수일때 내부
        if(cnt%2==0) cout<<"외부"<<"\n";
        else cout<<"내부"<<"\n";
    }
}