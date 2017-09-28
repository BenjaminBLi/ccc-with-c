#include <bits/stdc++.h>
using namespace std;

int N, currPos[1010];
bool ok[1010];

int main(){
	freopen("DATA31.txt", "r", stdin);
	int T = 10;
	for(;T--;){
		stack<int> stk1, stk2;
		scanf("%d", &N);
		bool sorted = true;
		for(int i = 0;i < N; i++){
			scanf("%d", currPos+i);
			sorted &= currPos[i] == i+1;
			stk1.push(currPos[i]);
		}
		for(int i = 0;i < N-1; i++){
			ok[currPos[i]] = currPos[i]+1 == currPos[i+1];
		}
		int cnt = 0, stN = N-1;
		while(!sorted && stN != 0){
			if(!ok[stN]){
				while(stk1.top() != stN){
					stk2.push(stk1.top()); stk1.pop();
				}
				stk1.pop();
				cnt += stk1.size();
				while(!stk1.empty()){
					stk2.push(stk1.top());stk1.pop();
				}
				stk1.push(stN);
				while(!stk2.empty()){
					stk1.push(stk2.top());stk2.pop();
				}
			}
			stN--;
		}
		printf("%d\n", cnt);
	}

	return 0;
}