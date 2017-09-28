#include <bits/stdc++.h>
using namespace std;

int nearest[1000010];
int N, arr[1000010];

int main(){
    scanf("%d", &N);
	int k = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", arr+i);
		if(arr[i] == 1){
			k = i;
		}
		nearest[i] = k;
	}
    //for(int i = 1; i <= N; i++) printf("%d, ", nearest[i]); cout << endl;
	int Q;
	scanf("%d", &Q);
	for(int q = 0; q < Q; q++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(arr[y] == 1) printf("0\n");
		else if(nearest[y] < x){
			if((y-x+1)%2 == 1) printf("0\n");
			else printf("1\n");
		}else if(nearest[y] == x){
			if((y-x+1)%2 == 1) printf("1\n");
			else printf("0\n");
		}else{
            if((y-nearest[y]+1)%2 == 1) printf("0\n");
            else printf("1\n");
		}
	}

	return 0;
}