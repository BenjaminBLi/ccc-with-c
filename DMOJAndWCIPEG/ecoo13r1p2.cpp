#include <bits/stdc++.h>
using namespace std;

char num[110];

int f(int x){
	int ret = x*2;
	ret = ret/10 + ret%10;
	ret = ret/10 + ret%10;
	return ret;
}

int giveDigit(){
	long long ret = 0;
	for(int i = (int)strlen(num)-1; i >= 0;i -= 2){
		//cout << num[i]-'0';
		ret += f((num[i]-'0'));
	}
	//cout <<  " " << ret << endl;
	for(int i = (int)strlen(num)-2;i >= 0; i-=2){
		ret += num[i]-'0';
	}
	for(int i = 0;i < 10; i++){
		if((ret+i)%10 == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	//num[0] = '4', num[1] = '2', num[2] = '3', num[3] = '9';
	//cout << giveDigit() << endl;
	
	int T = 5;
	for(;T--;){
		for(int i =0;i < 5; i++){
			scanf("%s", num);
			printf("%d", giveDigit());
		}
		printf("\n");
	}

	return 0;
}