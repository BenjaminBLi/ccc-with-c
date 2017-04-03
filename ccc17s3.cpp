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


/*
array freq to keep track of number of boards length N..........?
check each pair of size???
Li + Lj = x

basically make a histogram

TEST CASE:
10
1 2 3 4 1 2 3 4 1 3

freq:
  1  2  3  4
h[3, 2, 3, 2]

consider all sums from 2 - 4000
cnt:
  1  2  3  4  5  6  7  8
v[0, 1, 2, 4, 4, 3, ]
*/
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
	//fori(i, 2010) printf("%d: %d, ", i, freq[i]); cout << endl;
	//memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= 4000; i++){
		//cout << i << endl;
		//if(i == 3000) cout << "YES";
		for(int val = 2000; val >= i-val && i-val <= 2000; val--){
			//cout << val << ", " << (i-val) << endl;
			//if(i == 3000) cout << val << endl;
			//if(val == 1000) cout << "YES, " << i << endl;
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
			//cout << i << endl;
		}else if(len == cnt[i]){
			fcnt++;	
			//cout << i << endl;
		}
	}
	//fori(i, 4010) printf("%d: %d, ", i, cnt[i]); cout << endl;
	printf("%d %d\n", len, fcnt);

	return 0;
}