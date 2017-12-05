#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

unordered_map<int, int> id;
int t, rev[100010], init[100010], ft[100010];

void upd(int idx){
	for(; idx <= t; idx += idx & (-idx)) ft[idx]++; 
}

int qry(int idx){
	int ret = 0;
	for(; idx; idx -= idx & (-idx)) ret += ft[idx];
	return ret;
}

bool comp(int a, int b){ return a > b;}

int main(){
	scanf("%d", &t);
	fori(i, 0, t){
		scanf("%d", rev+i);
		init[i] = rev[i];
	}

	sort(rev, rev + t, comp);
	int en = unique(rev, rev + t) - rev;
	fori(i, 0, en) id[rev[i]] = i+1;

	ll ans = 0;
	fori(i, 0, t){
		int curr = init[i];
		ans += qry(id[curr]-1)+1;
		upd(id[curr]);
	}

	printf("%.2lf\n", (ans*100/t)/100.0);
	
	return 0;
} 