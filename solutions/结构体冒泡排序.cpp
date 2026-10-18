#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int id;
    int score;
};
int main()
{
    stu p[1005];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].id>>p[i].score;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].score<p[j + 1].score)
            {
                stu t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<p[i].id<<" "<<p[i].score<<'\n';
    }
}
