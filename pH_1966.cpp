#include <iostream>
#include <queue>
#include <algorithm>
#define endl \n;
using namespace std;

struct Doc {
	int _Nth;
	int _prt;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	int cnt = T;

	while (cnt--) {
		int n;
		int quest, prt;
		queue<Doc*> docQ;
		priority_queue<int,vector<int>, less<>> prtQ;
		
		cin >> n >> quest;
		Doc* qDoc = new Doc;
		qDoc->_Nth = 0;
		qDoc->_prt = 0;

		for (int i = 0; i < n; i++) {
			cin >> prt;
			Doc* newDoc = new Doc;
			newDoc->_Nth = i + 1;
			newDoc->_prt = prt;
			prtQ.push(prt);

			if (quest == i) {
				qDoc->_Nth = i + 1;
				qDoc->_prt = prt;
			}
			docQ.push(newDoc);
		}

		int Nth = 0;
		while (true) {
			if (docQ.front()->_prt != prtQ.top()) {
				Doc* fDoc = docQ.front();
				docQ.pop();
				docQ.push(fDoc);
			}
			else {
				if ((docQ.front()->_Nth == qDoc->_Nth) && (docQ.front()->_prt == qDoc->_prt)) {
					cout << ++Nth << '\n';
					break;
					Nth = 0;
				}
				docQ.pop();
				prtQ.pop();
				Nth++;
			}
		}
	}
}