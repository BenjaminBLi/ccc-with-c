#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

struct line{
	ll a, b, c;
	line(){a = b = c = 0;}
}lines[1010], init;


double mnx, mny, mxx, mxy;
ii home, school;
int n;

ll calc(line l, int x, int y){
	return  l.a * x + l.b * y + l.c; 
}

ll sgn(line l, int x, int y){
	if(calc(l, x, y) < 0) return -1;
	if(calc(l, x, y) > 0) return 1;
	return 0;
}

bool f(line l){
	return sgn(l, home.f, home.s) != sgn(l, school.f, school.s);
}

int main(){
	scanf("%d%d%d%d", &home.f, &home.s, &school.f, &school.s);
	if(home.f > school.f) swap(home, school);
	mnx = min(home.f, school.f);
	mxx = max(home.f, school.f);
	mny = min(home.s, school.s);
	mxy = max(home.s, school.s);
	scanf("%d", &n);
	int a, b, c;
	fori(i, 0, n){
		scanf("%lld%lld%lld", &lines[i].a, &lines[i].b, &lines[i].c);
	}

	int cnt = 0;
	fori(i, 0, n){
		if(f(lines[i])) cnt++;
	}
	cout << cnt << endl;

	return 0;
}

