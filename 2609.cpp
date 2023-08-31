#include <iostream>
using namespace std;

int gcd(int a, int b){
    int c = a % b;
    while(c!= 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b){
    return (a * b) / gcd(a,b);
}

void Solve(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << '\n' << lcm(a,b);
}




int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
}