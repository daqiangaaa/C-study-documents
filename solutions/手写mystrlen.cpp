#include <iostream>
using namespace std;
int mystrlen(char s[])
{
    int k = 0;
    while (s[k] != '\0')
    {
        k++;
    }
    return k;
}
int main()
{
    char s[105];
    cin >> s;
    cout << mystrlen(s) << "\n";
}