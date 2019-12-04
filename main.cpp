#include <iostream>
using namespace std;
int ways[20], a[20][20],n,vis[20],vers[20],svers = 0, m,val,s,f;

int min_array(int n){
    int min = INT_MAX, nmin = 0;
    for(int i=1;i<=n;i++){
        if(ways[i]<min && vis[i]==0){
            min = ways[i];nmin = i;
        }
    }
    return  nmin;
}
int main() {
    cout<<"Enter amount of vertices and edges of graph\n";
    cin>>n>>m;
    cout<<"Enter number of start vertice,end vertice and edge weight between them\n";
    for(int i=1;i<=n;i++)
        ways[i] = INT_MAX;
    for(int i = 1;i<=m;i++){
        cin>>s>>f>>val;
        a[s][f] = val;
        a[f][s] = val;
    }
    ways[1] = 0;
    int start = 1;
    while(min_array(n)!=0){
        vis[start] = 1;
        for(int i=1;i<=n;i++){
            if(a[start][i]!=0 && vis[i] ==0  )ways[i] = min(ways[i], a[start][i]);
        }
            svers++;
        vers[svers] = start;
        start = min_array(n);
    }
    cout<<"The order of tops after algoritm passing\n";
    for(int i=1;i<=n;i++){
        cout<<vers[i]<<' ';
    }
}

