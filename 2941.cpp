#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0;
    string str[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

    string T;
    cin >> T;
    for (const string al : str) {
        while (T.find(al) != -1) {
            int fd = T.find(al);
            if (fd != -1) {
                cnt++;
                T.replace(T.find(al), al.size(), " ");
            }
        }
    }
    T.erase(remove(T.begin(), T.end(), ' '), T.end());
    cnt += T.size();
    cout << cnt;
}