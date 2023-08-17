#include <iostream>
#include <algorithm>
using namespace std;

int AN;
long long arr[100010];
int MN;
long long temp;

void BiSearch(long long temp) {
	long long left = 0;
	long long right = AN - 1;
	long long mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == temp) {
			cout << "1\n";
			return;
		}
		else if (arr[mid] > temp) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "0\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> AN;
	for (int i = 0; i < AN; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	sort(arr, arr + AN);

	cin >> MN;

	for (int i = 0; i < MN; i++) {
		cin >> temp;
		BiSearch(temp);
	}
}
