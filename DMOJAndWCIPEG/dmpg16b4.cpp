#include <bits/stdc++.h>
using namespace std;

int power(int x, int val){
	int ret = 1;
	for(int i =0;i < val; i++){
		ret *= x;
	}
	return ret;
}

int f(int x){
	//cout << log10(x) << endl;
	int sz = floor(log10(x))+1;
	//cout << sz << endl;
	int ret = 0;
	//cout << ret << endl;
	for(int i =0; i < sz; i++){
		int c = x%10;
		int ans = power(c, sz);
		//cout << ans << endl;
		//cout << c << endl;
		//cout << pow(c, sz) << endl;
		ret += ans;
		//cout << ret << endl;
		x /= 10;
	}
	return ret;
}

int T, M;
map<int, int> loop;

int main(){
	//cout << f(145);
	scanf("%d", &T);
	//T = 0;
	for(;T--;){
		int time = 0;
		scanf("%d", &M);
		int val;
		loop.clear();
		bool valid = true;
		int len = -1;
		while(true){
			cout << M << endl;
			if(loop.find(M) != loop.end()){
				valid = false;
				len = time-loop[M];
				time = loop[M];
				break;
			}else{
				loop[M] = time;
				if(M == f(M)) break;
				time++;
				M = f(M);
			}
		}
		if(!valid) printf("Instability: Loop of length %d encountered after %d seconds(s)!\n", len, time);
		else printf("Equilibrium: Bob's investment becomes $%d after %d second(s)!\n", M, time);
	}
	return 0;
}