#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	if(N == 1){
		cout << "      \n      *\n      *\n      *\n      \n      *\n      *\n      *\n     \n";
	}if(N == 2){
		cout << " * * *\n      *\n      *\n      *\n * * *\n*      \n*      \n*      \n * * *\n";
	}if(N == 3){
		cout << " * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n      *\n * * *\n";
	}if(N == 4){
		cout << "      \n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n      \n";
	}if(N == 5){
		printf(" * * * \n*      \n*      \n*      \n * * * \n      *\n      *\n      *\n * * * \n");
	}if(N == 6){
		printf(" * * * \n*      \n*      \n*      \n * * * \n*     *\n*     *\n*     *\n * * * \n");
	}if(N == 7){
		cout << " * * *\n      *\n      *\n      *\n      \n      *\n      *\n      *\n      \n";
	}if(N == 8){
		printf(" * * * \n*     *\n*     *\n*     *\n * * * \n*     *\n*     *\n*     *\n * * * \n");
	}if(N == 9){
		printf(" * * * \n*     *\n*     *\n*     *\n * * * \n      *\n      *\n      *\n * * * \n");
	}
	return 0;
}