#include <bits/stdc++.h>
using namespace std;
map <int, set<int> > m;
queue <int> q;
set <int> s;
int n,a,b;
int main(){
    cout<<"Enter number of tops\n";
    cin>>n;
    cout<<"Enter start and end of edge\n";
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        m[a].insert(b);
    }
    int start;
    cout<<"Enter top to dfs\n";
    cin>>start;
    q.push(start);
    while(!q.empty()){
        int  t = q.front();
        q.pop();
        s.insert(t);
        for(auto it = m[t].begin();it!=m[t].end();++it){
            if(s.count(*it)==0){q.push(*it);}
        }
    }
    cout<<"Tops linked with "<<start<<" top: ";
    for(auto it = s.begin();it!=s.end();++it)
        cout<<*it<<' ';
}
