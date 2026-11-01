#include <bits/stdc++.h>
using namespace std;
vector<char> rec;
void run(int need){
    int a = 0, b = 0;
    for (char c : rec) {
        if (c == 'W') ++a; else ++b;
        if (max(a,b) >= need && abs(a-b) >= 2) {
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }
    cout << a << ':' << b << '\n';
}
int main(){
    char c;
    while (cin >> c && c != 'E') rec.push_back(c);
    run(11);
    run(21);
}
