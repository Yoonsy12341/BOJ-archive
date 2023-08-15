#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while(true){
        int flag = 0;
        cin >> str;
        if (str == "0") break;

        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - 1 - i]) {
                cout << "no\n";
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "yes\n";
        }
    }
}