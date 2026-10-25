#include <bits/stdc++.h>
using namespace std;
static int d[1000005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a_i,b_i;
        cin>>a_i>>b_i;
        d[a_i]++;
        d[b_i+1]--;
    }
    int best=0,sum=0;
    for(int i=0;i<1000005;i++){
    sum+=d[i];
    if(sum>best)best=sum;
    }
    cout<<best<<'\n';
}
