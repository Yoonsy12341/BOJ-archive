#include <iostream>
#include <vector>
#include <stack>

#define endl \n;
using namespace std;

stack<char> preStk;
stack<char> postStk;

void cmdL() {
	if (preStk.empty()) {
		return;
	}
	char ch = preStk.top();
	preStk.pop();
	postStk.push(ch);
}

void cmdD() {
	if (postStk.empty()) {
		return;
	}
	char ch = postStk.top();
	postStk.pop();
	preStk.push(ch);
}

void cmdB() {
	if (preStk.empty()) {
		return;
	}
	preStk.pop();
}

void cmdP() {
	char ch;
	cin >> ch;
	preStk.push(ch);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//stack 2개를 이어 붙여 문자열 생각

	int n;
	string str, cmd;
	cin >> str >> n;

	for (int i = 0; i < str.length(); i++) {
		preStk.push(str[i]);
	}

	while (n--) {
		cin >> cmd;
		if (cmd == "L") {
			cmdL();
		}
		else if (cmd == "D") {
			cmdD();
		}
		else if (cmd == "B") {
			cmdB();
		}
		else if (cmd == "P") {
			cmdP();
		}
	}

	while (!preStk.empty()) {
		cmdL();
	}

	while (!postStk.empty()) {
		cout << postStk.top();
		postStk.pop();
	}
}