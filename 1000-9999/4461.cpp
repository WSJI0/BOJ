//4461 뱀파이어 김상근 백작 (미완성)

#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    return a%b==0? b:GCD(b, a%b);
}
int LCM(int a, int b){
    return a*b/GCD(a, b);
}
vector<int> divisor(int a){
    vector<int> div;
    for(int i=1; i*i<=a; i++){
        if(a%i==0){
            div.push_back(i);
            if(i!=a/i) div.push_back(a/i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;

    vector<int> num;
    for(int i=0; i<=21; i++) num.push_back(pow(i, 3));

    while(1){
        cin>>n; if(n==0) break;
        bool a=false;
        int ans[3]={0, 0, 0};

        int minAns=INT_MAX;
        for(int i=0; i<22; i++)
            for(int j=i+1; j<22; j++){
                if(num[i]+num[j]==n){
                    a=true;
                    for(auto d:divisor(LCM(num[i], num[j]))){
                        if(minAns<((d*2)+num[i]+num[j])){
                            minAns=((d*2)+num[i]+num[j]);
                            ans[0]=max(num[i], num[j]);
                            ans[1]=d;
                            ans[2]=min(num[i], num[j]);
                        }
                    }
                }
            }
        if(a) printf("(%d/%d)^3 + (%d/%d)^3 = %d\n", ans[0], ans[1], ans[2], ans[1], n);
        else cout<<"No value."<<"\n";
    }
}