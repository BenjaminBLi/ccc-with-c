#include <bits/stdc++.h>
#define fori(i, n) for(int i =0; i < n; i++)
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, arr[110];

int main(){
	scanf("%d", &N);
	fori(i, N) scanf("%d", arr+i);
	sort(arr, arr+N);
	//fori(i, N) printf("%d, ", arr[i]);
	if(N&1){
		int p1 = (N>>1);
		int p2 = (N>>1)+1;
		printf("%d ", arr[p1--]);
		for(int i = N>>1; i > 0; i--){
			printf("%d ", arr[p2++]);
			printf("%d ", arr[p1--]);
		}
	}else{
		int p1 = (N>>1)-1;
		int p2 = N>>1;
		for(int i = N>>1; i > 0; i--){
			printf("%d ", arr[p1--]);
			printf("%d ", arr[p2++]);
		}
	}
	return 0;
}