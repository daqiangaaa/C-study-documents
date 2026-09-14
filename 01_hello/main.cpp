#include <iostream>
using namespace std;

int main() {
    cout << "Hello C++ 你好，世界！" << endl;
    int sum = 0;
    for (int i = 1; i <= 100; ++i) sum += i;   // 断点打这一行
    cout << "1+2+...+100 = " << sum << endl;
    return 0;
}
