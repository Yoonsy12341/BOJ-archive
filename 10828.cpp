#include <iostream>
#include <string>
using namespace std;

int t = -1;
int S[10000];

void push(int X) {
	S[++t] = X; // t = -1로 초기화 되어있으니까
}
bool empty() {
	if (t == -1) {
		return true;
	}
	else {
		return false;
	}
}
int pop() {
	int temp;
	if (empty()) {
		return -1;
	}
	temp = S[t];
	S[t--] = -1;
	return temp;
}

void size() {
	cout << t + 1 << "\n";
}

void top() {
	if (empty()) {
		cout << "-1\n";
		return;
	}
	cout << S[t] << "\n";
}


int main() {

	int N, value;
	string str;

	cin >> N;


	while (N--) {
		cin >> str;
		if (str == "push") {
			cin >> value;
			push(value);
		}
		else if (str == "pop") {
			cout << pop() << "\n";
		}
		else if (str == "size") {
			size();
		}
		else if (str == "empty") {
			cout << empty() << "\n";
		}
		else if (str == "top") {
			top();
		}
	}
}
