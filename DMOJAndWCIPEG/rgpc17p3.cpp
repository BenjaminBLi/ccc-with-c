#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

ll q, n, x, y, a, tmp, coe; vector <ll> tmp1, tmp2, tmp3, fin, v[15]; 

void distribute(){
	tmp1 = v[1]; 
	for (int i = 2; i <= n; i++){
		tmp2 = v[i];  tmp3.clear(); 
		for (int j = 0; j < tmp1.size(); j++){
			for (int k = 0; k < tmp2.size(); k++){
				if (j != 0 && k == 0) tmp3[tmp3.size()-1] += tmp1[j] * tmp2[k];
				else tmp3.pb(tmp1[j]*tmp2[k]); 
				//cout << j << ' ' << k << ' ' << tmp1[j] * tmp2[k] << endl; 
			}
		}
		tmp1 = tmp3;
	}
	fin = tmp3; 
}

ll solve (ll val){
	ll ret = 0; 
	for (int i = 0; i < fin.size(); i++){
		ret += fin[i] * pow(val, fin.size()-1-i); 
	}
	return ret; 
}

int main() {
	scan(q); 
	for (int i = 0; i < q; i++){
		scan(n); 
		for (int j = 1; j <= 11; j++){ v[j].clear(); v[j].pb(1); } 
		tmp1.clear(); tmp2.clear(); tmp3.clear(); fin.clear(); 
		for (int j = 1; j <= n; j++){ scan(a); v[j].pb(-a); }
		distribute(); 
		scan(x); scan(y); 
		tmp = solve(x); 
		coe = y/tmp; 
		for (int j = 0; j < fin.size(); j++) printf ("%lld ", fin[j]*coe); 
		printf ("\n"); 
	}
	return 0;
}