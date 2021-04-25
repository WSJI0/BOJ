#include <iostream>
#include<queue>
#include<string>

using namespace std;

struct Que {
	int x;
	int time;
};

bool vis[500001][2];

int sum(int n) {
	return n * (n + 1) / 2;
}


int main()
{
	int N, K;//언니 위치 : N, 동생위치 : K
	cin >> N >> K;
	
	queue<Que> Q;
	Q.push({ N,0 });
	vis[N][0] = true;
	
	int answer = -1, i = 0;
	int nk;

	while (1) {
		int size = Q.size();
		nk = K + sum(i);
		//cout << "nk=" << nk<<endl;
		if (nk < 0 or nk>500000) {
			break;
		}
		while (size--) {
			auto cur = Q.front();
			//cout << "cur.x=" <<cur.x << endl;
			Q.pop();
			if (cur.x == nk or vis[nk][i%2]==true) {
				answer = i;
				goto ijsilver;
			}
			if (cur.x - 1 >= 0 and vis[cur.x - 1][(cur.time + 1) % 2] == false) {
				Q.push({ cur.x - 1,cur.time + 1 });
				vis[cur.x - 1][(cur.time + 1) % 2]=true;
			}
			if (cur.x + 1 <= 500000 and vis[cur.x + 1][(cur.time + 1) % 2] == false) {
				Q.push({ cur.x + 1,cur.time + 1 });
				vis[cur.x + 1][(cur.time + 1) % 2]=true;
			}
			if (cur.x *2 <= 500000 and vis[cur.x *2][(cur.time + 1) % 2] == false) {
				Q.push({ cur.x*2,cur.time + 1 });
				vis[cur.x*2][(cur.time + 1) % 2]=true;
			}
		}
		i++;

	}
ijsilver:
	cout << answer << endl;

}