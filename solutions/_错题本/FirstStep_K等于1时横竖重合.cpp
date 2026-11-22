int main(){
    cin>>r>>c>>k;
    string s;
    for(int i=0;i<r;i++){ cin>>s; v.push_back(s); }
    int ans=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(heng(i,j))ans++;
            if(shu(i,j))ans++;
        }
    cout<<ans<<'\n';
}