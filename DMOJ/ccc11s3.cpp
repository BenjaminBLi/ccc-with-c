#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, m;
long long x, y;

bool mag(int m, long long x, long long y){
	//printf("m: %d x: %d y: %d\n", m, x, y);
	if(m == 1){
		if(y >= 2) return false;
		if(x == 0 || x == 4) return false;
		if(y == 1 && x != 2) return false;
		if(y == 0 && (x == 0 || x == 4)) return false;
		return true;
	}
	ll smol = pow(5, m-1);
	if(x/smol == 0 || x/smol == 4) return false;
	if(y/smol > 2) return false;
	if(y/smol == 0 && (x/smol > 0 && x/smol < 4)) return true;
	if(y/smol == 1 && x/smol == 2) return true;
	return mag(m-1, x%smol, y%smol);
	//return false;
}

int main(){
	scanf("%d", &T);
	for(;T--;){
		scanf("%d %lld %lld", &m, &x, &y);
		if(mag(m, x, y)) cout << "crystal" << endl;
		else cout << "empty" << endl;
	}
	return 0;
}