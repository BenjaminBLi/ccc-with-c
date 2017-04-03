#include <bits/stdc++.h>
using namespace std;
map<int, int> vel;
int n;
int coords[60010];
int main(){
	scanf("%d", &n);
	double x = 0;
	for(int i =0; i < n; i++){
		scanf("%d", coords+i);
	}
	int tmp;
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		vel[coords[i]] = tmp;

	}
	sort(coords, coords+n);
	//leftmost goes right, rightmost goes left??
	//then all points travel to the middle??
	x = 1.0*(coords[n-1]+coords[0])/2.0;
	//cout << x << endl;


	return 0;
}