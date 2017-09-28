#include <bits/stdc++.h>
using namespace std;

int n, cnt[100010];

int main(){
	scanf("%d", &n);
	int bst = 0, curr = 0;
	int c;
	for(int i =0;i < n<<1; i++){
		scanf("%d", &c);
		//cout << c << endl;
		if(cnt[c]){
			cnt[c] = 0;
			curr--;
		}else{
			curr++;
			cnt[c]++;
			bst = max(bst, curr);
		}
	}
	cout << bst << endl;

	return 0;
}