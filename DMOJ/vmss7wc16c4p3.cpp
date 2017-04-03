#include <bits/stdc++.h>
using namespace std;

int D, I, R;
long long memo[1010][1010];
string A, B;
//char A[1010], B[1010];
int min3(int a, int b, int c){
	return min(a, min(b, c));
}
int main(){
	scanf("%d %d %d", &D, &I, &R);
	cin>> A >> B;
	int szA = A.size(), szB = B.size();

	for(int i =0; i <= szA; i++) for(int j = 0; j <= szB; j++){
		if(i == 0 && j == 0) memo[i][j] = 0;
		else if(j == 0) memo[i][j] = i*D;
		else if(i == 0) memo[i][j] = j*I;
		else if(A[i-1] == B[j-1]) memo[i][j] = memo[i-1][j-1];
		else{
			memo[i][j] = min3(memo[i-1][j]+D, memo[i][j-1]+I, memo[i-1][j-1]+R);
		}
	}
	
	cout << memo[szA][szB];
	return 0;
}