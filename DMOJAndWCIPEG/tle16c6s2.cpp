#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long double ld;
typedef pair<ld, ld> ii;


int xt1, yt1, xt2, yt2;
ii p1, p2;
double dist(ii pt){
	return sqrt(pt.f*pt.f) + sqrt(pt.s*p2.s);
}

int main(){
	scanf("%d %d %d %d", &xt1, &yt1, &xt2, &yt2);	
	//cout << x1 << ", " << y1<<endl;
		p1 = ii(xt1, yt1);
		p2 = ii(xt2, yt2);
	//printf("%lf %lf\n%lf %lf", p1.f, p1.s, p2.f, p2.s);
	double m = (p2.s-p1.s)/(p2.f-p1.f);
	if(m < 0){
		//cout << m << endl;
		if(xt1 == 0 && xt2 == 0) m = -1e20;
		if(yt1 == 0 && yt2 == 0) m = -1e-20;
		ii one;
		one.f = (m*p1.f-p1.s)/m;
		one.s = -m*p1.f+p1.s;
		one.f = one.f;
		//cout << one.f << ", " << one.s << endl;
	
		double a1 = one.f;
		a1 /= 2;
		a1 *= one.s;
	
		printf("%llf", a1);
	}else{
		ii p;
		if(dist(p1) > dist(p2)) p = p1;
		else p = p2;
		if(p.f == 0) m = -1;
		else if (p.s == 0) m = -1;
		else m = -(p.s/p.f);
		if(xt1 == 0 && xt2 == 0) m = -1e20;
		if(yt1 == 0 && yt2 == 0) m = -1e-20;
		//cout << m << endl;
		ii one;
		one.f = (m*p.f-p.s)/m;
		one.s = -m*p.f+p.s;
		one.f = one.f;
	//one.f /= m;
		//cout << one.f << ", " << one.s << endl;
	
		double a1 = one.f;
		a1 /= 2;
		a1 *= one.s;
	
		printf("%llf", a1);
	}

	return 0;
}