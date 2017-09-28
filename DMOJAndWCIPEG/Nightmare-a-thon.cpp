#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
//use a seg tree to generate, shouldn't be too hard, don't need lazy prop.
//nvm don't need seg tree....
//look at left and right

ii rht[500010], lft[500010];
int arr[500010], N, Q, a, b;

int main(){
	scanf("%d %d", &N, &Q);
	scanf("%d", &arr[0]);
	rht[0] = ii(arr[0], 1);
	for(int i =1; i < N; i++){
		scanf("%d", arr+i);
		if(rht[i-1].first < arr[i])
			rht[i] = ii(arr[i], 1);
		else if (rht[i-1].first == arr[i]) rht[i] = ii(arr[i], rht[i-1].second+1);
		else rht[i] = rht[i-1];
	}

	lft[N-1] = ii(arr[N-1], 1);
	for(int i = N-2; i >= 0; i--){
		if(lft[i+1].first < arr[i]) lft[i] = ii(arr[i], 1);
		else if (lft[i+1].first == arr[i]) lft[i] = ii(arr[i], lft[i+1].second+1);
		else lft[i] = lft[i+1];
	}
	//for(int i =0; i < N; i++) printf("(%d, %d), ", rht[i].first, rht[i].second); cout << endl;
	//for(int i =0; i < N; i++) printf("(%d, %d), ", lft[i].first, lft[i].second); cout << endl;
	ii l, r;
	long long tot;
	for(int i =0; i < Q; i++){
		scanf("%d %d", &a, &b);
		a--; b--;
		if(a == 0 && b == N-1)  printf("0 0\n");
		else if (a == 0) printf("%d %d\n", lft[b+1].first, lft[b+1].second);
		else if (b == N-1) printf("%d %d\n", rht[a-1].first, rht[a-1].second);
		else{
			//printf("debug: %d %d\n", rht[a-1].first, lft[b+1].first);
			if(rht[a-1].first > lft[b+1].first) printf("%d %d\n", rht[a-1].first, rht[a-1].second);
			else if (lft[b+1].first > rht[a-1].first) printf("%d %d\n", lft[b+1].first, lft[b+1].second);
			else printf("%d %d\n", rht[a-1].first, lft[b+1].second+rht[a-1].second);
		}
	}
	return 0;
}