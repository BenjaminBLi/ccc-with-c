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

int n, mn;

int main(){
	scanf("%d", &n);
	scanf("%d", &mn);
	fori(i, 1, n){
		int tmp;
		scanf("%d", &tmp);
		mn = min(mn, tmp);
	}
	printf("%d\n", mn);
	return 0;
}

