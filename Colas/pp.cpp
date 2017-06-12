#include <bits/stdc++.h>
using namespace std;

int pp(string s){
	stack<char> pila;
	if(s.compare("\r\n") == 0) return 1;
	if(s[0] == ']' or s[0] == ')') return 0;
	
	for(int i = 0; i < s.length(); i++){
		switch(s[i]){
			case ']':
				if(pila.empty()) return 0;
				if(pila.top() == '[') pila.pop();
				else return 0;
				break;
			case ')':
				if(pila.empty()) return 0;
				if(pila.top() == '(') pila.pop();
				else return 0;
				break;
			default:
				pila.push(s[i]);
				break;
		}
	}
	
	return pila.empty();
}

int main(){
	int tc;
	cin >> tc;
	getchar();
	getchar();
	while(tc--){
		string s;
		getline(cin, s);
		cout << s << endl;
		int ans = pp(s);
		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}