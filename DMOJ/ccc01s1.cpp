#include <bits/stdc++.h>
using namespace std;
map<char, int> pts, id;
int tot[4];
vector<char> cards[4];

void gen(){
	id['C'] = 0;
	id['D'] = 1;
	id['H'] = 2;
	id['S'] = 3;

	pts['J'] = 1;
	pts['Q'] = 2;
	pts['K'] = 3;
	pts['A'] = 4;
	for(int i = 2; i < 10; i++) pts[(char) ('0'+i)] = 0;
	pts['T'] = 0;
}
string line, names[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int main(){
	gen();
	getline(cin, line);
	int idx = -1;
	for(int i = 0; i < line.size(); i++){
		char ch = line[i];
		//cout << ch << endl;
		if(id.find(ch) != id.end()) idx = id[ch];
		else{
			cards[idx].push_back(ch);
			tot[idx] += pts[ch];
		}
	}
	//for(int i =0; i < 4; i++) printf("%d\n", (int) cards[i].size());
	for(int i =0; i < 4; i++){
		if(cards[i].size() < 3){
			//cout << "YES" << endl;
			tot[i] += 3 - cards[i].size();
			//cout << tot[i] << endl;
		}
	}
	//string tst = "Cards Dealt              Points";
	int maxSz = 31, cSz;
	int total = 0;
	printf("Cards Dealt              Points\n");
	for(int i = 0; i < 4; i++){
		cSz = maxSz - names[i].size();
		//sort(cards[i].begin(), cards[i].end());
		cout << names[i];
		for(char ch : cards[i]){
			printf(" %c", ch);
			cSz -= 2;
		}
		if(tot[i] == 10) cSz--;

		for(int i =0 ; i < cSz-1; i++) printf(" ");
		printf("%d", tot[i]);
		printf("\n");
		total += tot[i];
	}
	cSz = maxSz;
	if(total < 10) cSz--;
	else cSz -= 2;
	cSz -= 5;
	//cSz--;
	for(int i =0 ; i < cSz-1; i++) printf(" ");

	printf("Total %d\n", total);
	return 0;
}