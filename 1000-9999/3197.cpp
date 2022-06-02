// 3197번 백조의 호수

#include <bits/stdc++.h>
using namespace std;

int parent[2250001], level[2250001]={1, }, arr[2250001], swan[2]={-1, -1};
bool visited[2250001];
int r, c, ans, y, x;
char board[1501][1501];
string s;
int mv[4][2]={
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
queue<int> q;

int sel(int y, int x){
	return y*c+x;
}

pair<int, int> ret(int s){
	return make_pair(s/c, s%c);
}

int find(int u){
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}

void merge(int u, int v){
	u=find(u); v=find(v);
	if(u==v) return;
	if(level[u]>level[v]){
		parent[v]=u;
		level[u]+=level[v];
	} else{
		parent[u]=v;
		level[v]+=level[u];
	}
}

void print(){
	cout<<"````````````````\n";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(sel(i, j)==swan[0] || sel(i, j)==swan[1]){
				int f=find(sel(i, j)); 
				for(int k=0; k<(4-to_string(f).size()); k++) cout<<" ";
				cout<<"*"<<f;
			} else{
				int f=find(sel(i, j));
				for(int k=0; k<(5-to_string(f).size()); k++) cout<<" ";
				cout<<f;
			}
		} cout<<"\n\n";
	}
}


void solve(){
	if(find(swan[0])==find(swan[1])) return;
	
	int cc=0;
	while(!q.empty()){
		tie(y, x)=ret(q.front()); q.pop();
		for(int i=0; i<4; i++){
			int my=mv[i][0]+y, mx=mv[i][1]+x;
			if(0<=my && my<r && 0<=mx && mx<c){
				if(visited[sel(my, mx)]) continue;
				if(board[my][mx]=='X'){
					arr[cc++]=sel(my, mx);
					visited[sel(my, mx)]=1;
				}
			}
		}
	}
	
	for(int i=0; i<cc; i++){
		tie(y, x)=ret(arr[i]);
		for(int j=0; j<4; j++){
			int my=mv[j][0]+y, mx=mv[j][1]+x;
			if(0<=my && my<r && 0<=mx && mx<c){
				if(board[my][mx]=='.' || board[my][mx]=='L') merge(sel(my, mx), sel(y, x));
			}
		}
		board[y][x]='.';
		q.push(arr[i]);
	}

	ans++;
	
	// print();
	
	if(cc) solve();
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=0; i<=2250000; i++) parent[i]=i;
	
	cin>>r>>c;
	for(int i=0; i<r; i++){
		cin>>s;
		for(int j=0; j<c; j++) board[i][j]=s[j];
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(board[i][j]=='.' || board[i][j]=='L'){
				for(int k=0; k<4; k++){
					int my=i+mv[k][0], mx=j+mv[k][1];
					if(0<=my && my<r && 0<=mx && mx<c){
						if(board[my][mx]=='X'){
							q.push(sel(i, j));
							break;
						}
					}
				}
				for(int k=0; k<4; k++){
					int my=i+mv[k][0], mx=j+mv[k][1];
					if(0<=my && my<r && 0<=mx && mx<c){
						if(board[my][mx]=='.' || board[my][mx]=='L'){
							merge(sel(i, j), sel(my, mx));
						}
					}
				}
				
				if(board[i][j]=='L'){
					if(swan[0]==-1) swan[0]=sel(i, j);
					else swan[1]=sel(i, j);
				}
			}
		}
	}
	solve();
	
	cout<<ans<<"\n";
}
