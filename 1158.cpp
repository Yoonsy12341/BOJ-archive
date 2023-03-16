
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, tmp;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		tmp = q.front();
		cout << tmp << ", ";
		q.pop();
	}
	tmp = q.front();
	cout << tmp << ">\n";

}
=======
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, tmp;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}
		tmp = q.front();
		cout << tmp << ", ";
		q.pop();
	}
	tmp = q.front();
	cout << tmp << ">\n";

}
>>>>>>> aee0d1738e9da36a02dc556fa44e428e5f40f815
