#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

int N;
ll a1[100010], a2[100010];

int main(){
	scanf("%d", &N);
	//cout << N << endl;
	//for(int i =0; i < N; i++) cout << i << endl;
	for(int i =0; i < N; i++){
		scanf("%lld", &a1[i+1]);
		a1[i+1] += a1[i];
		//cout << i << endl;
	}
	//cout << "DONE" << endl;
	for(int i =0; i < N; i++){
		//cout << i << endl;
		scanf("%lld", &a2[i+1]);
		a2[i+1] += a2[i];
		//cout << i << endl;
	}
	//cout << "DONE" << endl;
	//fori(i, N) cout << a1[i+1] << endl;
	int bst;
	//cout << N << endl;
	//cout << "DONE" << endl;
	for(bst = N; bst >= 0; bst--){
		//cout << i << endl;
		//cout << a2[i] << ", " <<  a1[i] << endl;
		if(a2[bst] == a1[bst]) break;
	}
	cout << bst << endl;

	return 0;
}