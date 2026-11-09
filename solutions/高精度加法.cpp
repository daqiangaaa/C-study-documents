#include <bits/stdc++.h>
using namespace std;

// 读入一个数，倒序存：v[0] 是个位
vector<int> readNum(){
    string s; cin >> s;
    vector<int> v;
    for (int i = (int)s.size() - 1; i >= 0; i--) v.push_back(s[i] - '0');
    return v;
}

// 打印，去掉前导 0；全是 0 就打印一个 0
void printNum(const vector<int>& v){
    int i = (int)v.size() - 1;
    while (i > 0 && v[i] == 0) i--;
    for (; i >= 0; i--) cout << v[i];
    cout << '\n';
}

// 加法：长度不用对齐，进位到头自动停
vector<int> add(const vector<int>& a, const vector<int>& b){
    vector<int> c;
    int carry = 0;
    int n = max((int)a.size(), (int)b.size());
    for (int i = 0; i < n || carry; i++){
        int t = carry;
        if (i < (int)a.size()) t += a[i];
        if (i < (int)b.size()) t += b[i];
        c.push_back(t % 10);
        carry = t / 10;
    }
    if (c.empty()) c.push_back(0);
    return c;
}

int main(){
    vector<int> a = readNum();
    vector<int> b = readNum();
    printNum(add(a, b));
    return 0;
}