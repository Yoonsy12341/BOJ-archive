#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned int ans{};
    unsigned int K, N;
    cin >> K >> N;

    unsigned int arr[10000];
    unsigned int maxi = 0;

    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    unsigned int left = 1, right = maxi, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        unsigned int total = 0;

        for (int i = 0; i < K; i++) {
            total += arr[i] / mid;
        }

        if (total >= N) {
            left = mid + 1;

            ans = max(ans, mid);
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
}