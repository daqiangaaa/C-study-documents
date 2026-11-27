bool cmp(const game &x,const game &y){
    if(x.during!=y.during)return x.during<y.during;
    return x.start<y.start;
}
int main(){
    int n; cin>>n;
    vector<game>v(n);
    int last=0;
    for(int i=0;i<n;i++){
        cin>>v[i].start>>v[i].end;
        v[i].during=v[i].end-v[i].start;
        if(v[i].end>last)last=v[i].end;
    }
    sort(v.begin(),v.end(),cmp);
    long long ans=0;
    vector<bool>can(last,true);
    for(int i=0;i<n;i++){
        int ok=1;
        for(int j=v[i].start+1;j<=v[i].end;j+=1){
            if(!can[j])ok=0;
        }
        if(ok){
            ans++;
            for(int j=v[i].start;j<=v[i].end;j+=1){ can[j]=false; }
        }
    }
    cout<<ans<<'\n';
}