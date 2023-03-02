#include <iostream>
using namespace std;
int main() {
    int a[10000] = { 0, };
    int j = 1;
    for (int i = 1; i < 10000; i++) {
        while (j < 10000) {
            j += j / 1000 % 10 + j / 100 % 10 + j / 10 % 10 + j % 10;
            if (j < 10000) { a[j]++; }
        }
        j = i + 1;
    }
    for (int k = 1; k < 10000; k++) {
        if (a[k] == 0) {
            cout << k << "\n";
        }
    }
}
