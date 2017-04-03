#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef pair<ld, ld> ii;


ii sheeps[101];
int eaten[101];
int N;
double bestY;

double dist(ii a, double x){
	return (a.first-x)*(a.first-x) + a.second*a.second;
}

int main(){
	scanf("%d", &N);
	for(int i =0; i < N; i++) scanf("%lf %lf", &sheeps[i].first, &sheeps[i].second);
	ld x, y;
	int idx = 0, s;
	bool inc;
	ld d, m;
	for(ld x = 0; x <= 1000.0; x += 0.01){
		//cout << x << endl;
		s = 0;
		m = 99999999.0;
		for(int i =0; i < N; i++){
			d = dist(sheeps[i], x);
			if(d < m){
				m = d;
				s = i;
			}
		}
		//cout << "DONE" << endl;
		inc = false;
		for(int i = 0; i < idx; i++) 
			if(s == eaten[i]) inc = true;
		//cout << "DONE" << endl;
		if(!inc) {
			//cout << eaten[idx] << ", " << s << endl;
			eaten[idx++] = s;
			//cout << eaten[idx] << ", " << s << endl;
			//cout << s << endl;
		}
	}
	//sort(sheep, sheep+N);
	//for(int i =0; i < idx; i++) printf("%d, ", eaten[idx]);
	for(int i = 0; i < idx; i++){
		printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", sheeps[eaten[i]].first, sheeps[eaten[i]].second);
	}
	return 0;
}