//10830번 행렬 제곱

#include <bits/stdc++.h>
using namespace std;
#define mod 1000

int matrix[5][5];
int new_matrix[5][5]={0};

void print_matrix(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<new_matrix[i][j]<<" ";
        cout<<"\n";
    }
}

void matrix_pow(int b, int n){
    for(int m=0; m<b; m++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    new_matrix[i][j]=(new_matrix[i][j]+(matrix[k][j]*matrix[i][k]))%mod;
                }
            }
        }
        cout<<"----------"<<"\n";
        print_matrix(n);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, b;
    cin>>n>>b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>matrix[i][j];
    }
    matrix_pow(b, n);
    print_matrix(n);
}