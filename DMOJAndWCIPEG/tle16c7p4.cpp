#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main(){
	scanf("%d", &T);
	
	for(;T--;){
		scanf("%lld", &n);
		unsigned long long x = n;
		int steps = 0;
		while(x){
			//cout << x << endl;
			if(x&1){
				if(x == 3) x--;
				else if((x&3) == 3){
					x++;
				}else{
					x--;
				}
			}else{
				x >>= 1;
			}
			steps++;
		}
		printf("%d\n", steps);
	}
	

	return 0;
}