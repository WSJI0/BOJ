#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include<iostream>
#include <fstream>
#include <string>
using namespace std;
using ll = long long;

#if RAND_MAX < 32768
#define myrand() ((rand() << 15) | rand())
#else
#define myrand() rand()
#endif

const int MAX_V = 20000;
const int MAX_E = 300000;
const int MAX_W = 10;

set<int> adj[MAX_V + 1];

int main()
{
	ofstream writeFile;
	writeFile.open("output.txt");
	srand((unsigned int)time(NULL));

	int v = myrand() % (MAX_V - 1) + 2;
	int e = myrand() % min((ll)MAX_E, (ll)v * (v - 1)) + 1;

	printf("%d %d\n", v, e);

	for (int i = 0; i < e; )
	{
		int a = myrand() % v + 1;
		int b = myrand() % v + 1;
		if (a == b)
			continue;
		if (adj[a].find(b) != adj[a].end())
			continue;
		int w = myrand() % MAX_W + 1;
		adj[a].insert(b);
		writeFile.write(a, b, w);
		i++;
	}
	writeFile.close();
}