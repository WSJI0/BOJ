#include <bits/stdc++.h>
using namespace std;

int arr[20]={1, 2, 10, 4, 107, 82, 10, 495, 267, 203, 93, 847, 34, 918, 993, 18, 84, 3, 12, 765};
int d=3;
queue<int> q[10];

void radixSort(int* arr){
    int res[20];
    for(int i=0; i<20; i++) res[i]=arr[i];
    for(int i=0; i<d; i++){
        for(int j=0; j<20; j++){
            int tmp=res[j];
            for(int k=0; k<i; k++) tmp/=10;
            q[tmp%10].push(res[j]);
        }
        int cur=0;
        for(int j=0; j<10; j++){
            while(!q[j].empty()){
                res[cur++]=q[j].front();
                q[j].pop();
            }
        }
    } 
    for(int i=0; i<20; i++) arr[i]=res[i];
}

int main(void){
    radixSort(arr);

    for(int i=0; i<20; i++) cout<<arr[i]<<" ";
}