#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, val = 666, num = 0;
    string str;

    cin >> N;
    while (true) {
        str = to_string(val);
        for (int i = 0; i < str.size() - 2; i++) {
            if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
                num++;
                break;
            }
        }
        if (num == N) {
            cout << val;
            return 0 ;
        }
        val++;
    }

}