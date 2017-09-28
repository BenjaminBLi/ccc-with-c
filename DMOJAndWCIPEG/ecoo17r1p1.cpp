#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0;i < n; i++)
#define f first
#define s second
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
//
int main(){
	//freopen("DATA11.txt", "r", stdin);
	int T = 10;
	double y1, y2, y3, y4; 
	int N, target;
	for(;T--;){
		scanf("%d", &target);
		scanf("%lf %lf %lf %lf", &y1, &y2, &y3, &y4);
		scanf("%d", &N);
		int p1 = N*y1, p2 = N*y2, p3 = N*y3, p4 = N*y4;
		int missing = N-p1-p2-p3-p4;
		double sum = 0;
		if(y1 > y2 && y1 > y3 && y1 > y4){
			p1 += missing;
		}else if (y2 > y3 && y3 > y4){
			p2 += missing;
		}else if ()
		cout << missing << endl;
		cout << sum << endl;
		if(sum +1e-9 < (double) target){
			printf("YES\n");
		}else printf("NO\n");

	}

	return 0;
} 