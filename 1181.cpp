#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpWith(string str1, string str2) {
	if (str1.length() == str2.length()) {
		return str1 < str2;	
	}
	return str1.length() < str2.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	vector<string> strvec;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		if (find(strvec.begin(), strvec.end(), str) == strvec.end()){
			strvec.push_back(str);
		}
	}
	sort(strvec.begin(), strvec.end(), cmpWith);

	for (int i = 0; i < strvec.size(); i++) {
		cout << strvec[i] << "\n";
	}
}
