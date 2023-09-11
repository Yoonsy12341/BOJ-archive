#include <iostream>
#include <deque>
#include <string>
#define endl \n;
using namespace std;

enum direction {
	E = 0,
	S,
	W,
	N
};

deque<int> deq;
direction dir = E;
int cntB = 0;
int cntW = 0;

//처음 동쪽으로 시작 // Ball 0, Wall 1 // 동남서북 0123 시계방향

void pushB() { // dir == N일 때는 넣자마자 떨어짐
	if (dir == N) {
		return;
	}
	if (dir == E || dir == W) {
		deq.push_back(0);
		cntB++;
	}
	else if (dir == S && cntW != 0) {
		deq.push_back(0);
		cntB++;
	}
}

void pushW() {
	deq.push_back(1);
	cntW++;
}

void pop() {
	if (deq.empty()) {
		return;
	}

	if (deq.front() == 0) {
		cntB--;
	}
	else {
		cntW--;
	}
	deq.pop_front();

	if (deq.empty()) {
		return;
	}

	// dir이 동, 서 일 때는 하나만 빠짐

	if (dir == S) { // 남
		while (deq.front() == 0) {
			deq.pop_front();
			cntB--;
			if (deq.empty()) {
				return;
			}
		}
	}
}

void rotateL() {
	if (dir == E) {
		dir = N;
	}
	else {
		dir = (direction)((dir - 1) % 4);
	}
	if (deq.empty()) {
		return;
	}

	if (dir == S) {
		while (deq.front() == 0) {
			deq.pop_front();
			cntB--;
			if (deq.empty()) {
				return;
			}
		}
	}
	else if (dir == N) {
		while (deq.back() == 0) {
			deq.pop_back();
			cntB--;
			if (deq.empty()) {
				return;
			}
		}
	}
}

void rotateR() {
	dir = (direction)((dir + 1) % 4);
	if (deq.empty()) {
		return;
	}

	if (dir == S) {
		while (deq.front() == 0) {
			deq.pop_front();
			cntB--;
			if (deq.empty()) {
				return;
			}
		}
	}
	else if (dir == N) {
		while (deq.back() == 0) {
			deq.pop_back();
			cntB--;
			if (deq.empty()) {
				return;
			}
		}
	}
}

void countB() {
	cout << cntB << '\n';
}

void countW() {
	cout << cntW << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin.ignore();

	while (n--) {
		getline(cin, str);
		if (str == "push b") {
			pushB();
		}
		else if (str == "push w") {
			pushW();
		}
		else if (str == "pop") {
			pop();
		}
		else if (str == "rotate l") {
			rotateL();
		}
		else if (str == "rotate r") {
			rotateR();
		}
		else if (str == "count b") {
			countB();
		}
		else if (str == "count w") {
			countW();
		}
	}
}