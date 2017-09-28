#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct build{
	int sz;
	vii pts;
}

build arr[110];

ii R, J;
int n;
int main(){
	scanf("%d %d %d %d", &R.f, &R.s, &J.f, &J.s);

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i].sz);
		for(int j = 0; j < arr[i].sz; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			arr[i].pts.push_back(ii(x, y));
		}
	}
	
	return 0;
}