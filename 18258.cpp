#include <iostream>
using namespace std;

class arrQueue {
public:
	arrQueue(int cap){
		arr = new int[cap];
		capacity = cap;
		frontIndex = rearIndex = 0;
		n = 0;
	}

	bool empty() { return n == 0; }
	int size() { return n; }
	int front() { 
		if (size() == 0) {
			return -1;
		}
		return arr[frontIndex]; 
	}
	int back() { 
		if (size() == 0) {
			return -1;
		}
		return arr[rearIndex-1]; 
	}

	void push(int data) {
		if (size() == capacity) { return; }
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		n++;
	}

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
			return;
		}
		else {
			cout << arr[frontIndex] << "\n";
			frontIndex = (frontIndex + 1) % capacity;
			n--;
		}
	}

private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int n;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, value;
	string str;
	cin >> N;

	arrQueue queue = { N };
	while (N--) {
		cin >> str;
		if (str == "empty") {
			cout << queue.empty() << "\n";
		}
		else if (str == "size") {
			cout << queue.size() << "\n";
		}
		else if (str == "front") {
			cout << queue.front() << "\n";
		}
		else if (str == "back") {
			cout << queue.back() << "\n";
		}
		else if (str == "pop") {
			queue.pop();
		}
		else if (str == "push") {
			cin >> value;
			queue.push(value);
		}

	}



}

