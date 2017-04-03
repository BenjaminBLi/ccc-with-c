#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class FT{
private:
    vi ft;
public:
    FT(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b&(-b)))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int) ft.size(); k += (k&(-k))) {
            ft[k] += v;
        }
    }
};

int N, Q, l, r;

int main(){
	scanf("%d", &N);
	FT bit(N);
	for(int i = 0; i < N; i++){
		scanf("%d", &l);
		if(l%2 == 0){
			bit.adjust(i+1, 1);
		}
	}
	scanf("%d", &Q);
	for(int i =0; i < Q; i++){
		scanf("%d %d", &l, &r);
		printf("%d\n", bit.rsq(l, r));
	}
	return 0;
}