#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    map<char,int>mp;
    for(int i=0;i<26;i++){
        mp[i+'A']=0;
    }
    int mx=0;
    while(cin>>c&&c!=EOF){
        if(c==' ')continue;
        if(c>='A'&&c<='Z')mp[c]++;
        if(mp[c]>mx)mx=mp[c];
    }
    int t=mx;
    for(int i=0;i<mx;i++){
        for(char s='A';s<='Z';s++){
            if(s!='A')cout<<" ";
            if(mp[s]==t){mp[s]--;cout<<"*";}
            else {cout<<" ";}
        }
        cout<<'\n';
        t--;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
}
