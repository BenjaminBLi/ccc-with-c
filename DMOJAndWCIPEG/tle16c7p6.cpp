#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
/*
solve with string hashing or trie (obviously)
ex:
lst = {"a", "ab", "abc"}
how to hash the strings?
use a "seed": 131 (typically a prime number)
hash = 1
use each char as char - 'a'
hash = hash*seed + s[i]-'a';
hash &= 0x7fffffffff <-- making it a positive number
*/

int N, M;
string curr, words[100010];

unordered_map<ull, vi> prefix, entire;
ull seed = 37;
int main(){
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;//scanf("%d %d", &N, &M);
	for(int i = 0;i < N; i++){
		cin >> curr;
		ull hash = 1;
		for(int j = 0;j < curr.length(); j++){
			hash = hash*seed + (curr[j]-'a');
			prefix[hash].pb(i);
		}
		entire[hash].pb(i);
	}
	int l, r;
	
	for(;M--;){
		cin >> curr >> l >> r;
		l--; r--;
		ull hash = 1;
		int cnt = 0;
		for(int j =0;j < curr.length()-1; j++){
			hash = hash*seed + (curr[j]-'a');
			if(entire.count(hash) == 0) continue;
			auto it = lower_bound(entire[hash].begin(), entire[hash].end(), l);
			int lIdx = it-entire[hash].begin();
			if(entire[hash][lIdx] > r || it == entire[hash].end()) continue;
			it = upper_bound(entire[hash].begin(), entire[hash].end(), r)-1;
			int rIdx = it-entire[hash].begin();
			if(entire[hash][rIdx] > r) continue;
			//cout << "j: " << j << endl;
			cnt += rIdx-lIdx+1;
		}

		hash = hash*seed + (curr[curr.length()-1]-'a');

		auto it = lower_bound(prefix[hash].begin(), prefix[hash].end(), l);
		auto it1 = it;
		int lIdx = it-prefix[hash].begin();

		it = upper_bound(prefix[hash].begin(), prefix[hash].end(), r)-1;
		int rIdx = it-prefix[hash].begin();
		//cout << lIdx << ", " << rIdx << endl;
		if(it1 == prefix[hash].end() || rIdx < 0 || prefix[hash][lIdx] > r || prefix[hash][rIdx] > r){
			cout << cnt << "\n";//printf("%d\n", cnt);
		}else{
			cout << (cnt+rIdx-lIdx+1) << "\n";//printf("%d\n", cnt+rIdx-lIdx+1);
		}
	}
	
	return 0;
}