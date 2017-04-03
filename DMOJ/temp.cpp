#include <bits/stdc++.h>
#define fori(i, n) for(int i =0; i < (int) n; i++)
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m;
vi adj[150010];

int main(){
	scanf("%d %d", &n, &m);
	fori(i, m){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	return 0;
}