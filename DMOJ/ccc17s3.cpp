#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

int N;
int freq[2010], cnt[4010];

int main(){
	scanf("%d", &N);
	int a;
	memset(freq, 0, sizeof(freq));
	fori(i, N){
		scanf("%d", &a);
		freq[a]++;
	}
	for(int i = 1; i <= 4000; i++){
		for(int val = 2000; val >= i-val && i-val <= 2000; val--){
			if(val == i-val){
				cnt[i] += freq[val]/2;
			}else{
				cnt[i] += min(freq[val],freq[i-val]);
			}
		}
	}
	int len = -1, fcnt = 0;
	for(int i = 1; i < 4010; i++){
		if(len < cnt[i]){
			len = cnt[i];
			fcnt = 1;
		}else if(len == cnt[i])
			fcnt++;	
	}
	printf("%d %d\n", len, fcnt);
	return 0;
}