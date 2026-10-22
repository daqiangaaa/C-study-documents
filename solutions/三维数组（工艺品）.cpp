#include <iostream>
using namespace std;
int a[25][25][25];
int main()
{
    int w,x,h;
    cin>>w>>x>>h;
    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1; i<=x2; i++)
            for(int k=y1; k<=y2; k++)
                for(int j=z1; j<=z2; j++)
                    a[i][k][j]=1;
    }
    int ans=0;
    for(int i=1; i<=w; i++)
        for(int k=1; k<=x; k++)
            for(int j=1; j<=h; j++)
                if(!a[i][k][j])ans++;
    cout<<ans<<endl;
}
