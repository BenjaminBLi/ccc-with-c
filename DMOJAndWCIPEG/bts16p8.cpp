#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, unsigned int> ii;
typedef long long ll;

const int MAXN = 524288, inf = 0x3f3f3f3f;
int n, s[MAXN], l[MAXN], w[MAXN], mx[MAXN<<2], ft[MAXN];

struct event{
	int x, y, val;
};
struct book{
	int s, l, w;
	bool operator< (book &o)&{
		if(s != o.s) return s < o.s;
		if(l != o.l) return l < o.l;
		return w < o.w;
	}
}books[MAXN];

void updft(int idx, int val){
	for(;idx <= MAXN; idx += idx & (-idx)) ft[idx] += val; 
}
ll qrft(int idx){
	ll ret = 0;
	for(;idx; idx -= idx & (-idx)) ret += ft[idx];
	return ret;
}



int main(){
	scanf("%d", &n);
	fori(i, 0, n) scanf("%d%d%d", s+i, l+i, w+i);
	///?????
	return 0;
}