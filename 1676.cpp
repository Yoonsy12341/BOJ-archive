#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int ans = 0;
    cin >> num;

    for(int i = 5; i <= num; i*= 5){
        ans += num / i;
    }
    cout << ans;
}