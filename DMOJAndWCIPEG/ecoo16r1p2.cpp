#include <bits/stdc++.h>
using namespace std;
int N, spin[5010];
bool vals[1000010];
int main(){
	freopen("DATA22.txt", "r", stdin);
	for(int T = 0; T < 10; T++){
		//cout << "T: " << T << endl;
		scanf("%d", &N);
		int x;
		memset(vals, false, sizeof(vals));
		for(int i = 0; i < N ; i++){
			scanf("%d", spin+i);
			vals[spin[i]] = true;
		}
		for(int i = 0; i < 5; i++){
			//cout <<  "I: " << i << endl;
			scanf("%d", &x);
			bool ok = false;
			for(int a = 0; a < N && !ok; a++){
				for(int b = 0; b < N && !ok; b++){
					int vA = spin[a], vB = spin[b];
					if(x-vA-vB >= 0 && vals[x-vA-vB]){
						ok = true;
						break;
					}if(x%(vA+vB) == 0 && vals[x/(vA+vB)]){
						ok = true;
						break;
					}if(x-vA*vB >= 0 && vals[x-vA*vB]){
						ok = true;
						break;
					}if(x%vA == 0 && (x/vA)%vB == 0 && vals[x/vA/vB]){
						ok = true;
						break;
					}
				}
			}
			printf("%c", ok ? 'T' : 'F');
		}
		printf("\n");
	}
	return 0;
}