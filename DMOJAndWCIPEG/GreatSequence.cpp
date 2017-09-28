#include <bits/stdc++.h>
using namespace std;

int N, K, Q;
vector<int> freq[2010];
int sum[100010];

int main(){
	scanf("%d %d %d", &N,&K,&Q);
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= N; i++){
		scanf("%d", sum+i);
		freq[sum[i]+1000].push_back(i);
		sum[i] += sum[i-1];
	}
	for(int i =0; i < 2010; i++){
		sort(freq[i].begin(), freq[i].end());
	}

	int l, r, x, y;
	for(int q = 1; q <= Q; q++){
		scanf("%d %d %d %d", &l, &r, &x, &y);
		l+= 1000; r += 1000;
		//cout << (sum[y]-sum[x-1]) << endl;
		if(sum[y]-sum[x-1] <= K) printf("No\n");
		else{
			int idx = lower_bound(freq[l].begin(), freq[l].end(), x)-freq[l].begin();
			if(idx >= freq[l].size()){
				printf("No\n"); continue;
			}
			int val = freq[l][idx];
			bool valid = val >= x && val <= y;
			if(!valid) {
				printf("No\n");
				continue;
			}
			//cout << valid << endl;
			idx = lower_bound(freq[r].begin(), freq[r].end(), x)-freq[r].begin();
			if(idx >= freq[r].size()){
				printf("No\n"); continue;
			}
			val = freq[r][idx];
			valid &= val >= x && val <= y;
			if(valid) printf("Yes\n");
			else printf("No\n");
		}

	}

	return 0;
}