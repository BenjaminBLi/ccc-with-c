#include <bits/stdc++.h>
using namespace std;

int units[8], ppl[8];

int main(){
	for(int i =0; i < 8; i++) scanf("%d", units+i);
	for(int i =0; i < 8; i++) scanf("%d", ppl+i);

	int total = 0;
	int c;
	for(int i =0; i < 8; i++){
		c = min(units[i], ppl[i]);
		total += c;
		units[i] -= c;
		ppl[i] -= c;
		if(i&1){
			c = min(units[i-1], ppl[i]);
			total += c;
			units[i-1] -= c;
			ppl[i] -= c;
		}
	} 

	//covers all type O blood
	for(int j = 2; j <8; j += 2){
		c = min(units[0], ppl[j]);
		total += c;
		ppl[j] -= c;
		units[0] -= c;
	}
	for(int j = 3; j < 8; j += 2){
		c = min(units[1], ppl[j]);
		total += c;
		ppl[j] -= c;
		units[1] -= c;
		c = min(units[0], ppl[j]);
		total += c;
		ppl[j] -= c;
		units[0] -= c;
	}
	
	if(units[2]){
		c = min(units[2], ppl[6]);
		total += c;
		units[2] -= c;
		ppl[6] -= c;
	}if(units[4]){
		c = min(units[4], ppl[6]);
		total += c;
		units[4] -= c;
		ppl[6] -= c;
	}if(units[3]){
		c = min(units[3], ppl[7]);
		total += c;
		units[3] -= c;
		ppl[7] -= c;
		c = min(units[2], ppl[7]);
		total += c;
		units[2] -= c;
		ppl[7] -= c;
	}if(units[5]){
		c = min(units[5], ppl[7]);
		total += c;
		units[5] -= c;
		ppl[7] -= c;
		c = min(units[4], ppl[7]);
		total += c;
		units[4] -= c;
		ppl[7] -= c;
	}

	cout << total << endl;
	return 0;
}