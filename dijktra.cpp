#include <iostream>
#include <cstdio>
using namespace std;
int n,i,j,a[101][101],b[101],c[101]={0},x,y,path[102]={0},from[102]={0};
void dejkstra(int v)
{
c[v]=1;
for(i=1;i<=n;i++)
if(a[v][i]!=-1 && c[i]==0 && v!=i)
{
if(b[v]+a[v][i]<b[i]){ path[i]=v;
b[i]=min(b[i],b[v]+a[v][i]);from[i] = v;}
}
}
int min_ar()
{
int min=1000000,nm=0;
for(i=1;i<=n;i++)
if(min>b[i] && c[i]==0){min=b[i];nm=i;}
return nm;
}

int out(int v){
    cout<<endl<<"pair"<<endl;
    cout<<v<<' '<<from[v]<<' ';
    return from[v];
}

int main()
{

cout<<"Enter number of tops, start and finish tops\n";

cin>>n>>x>>y;
cout<<"Enter matrix\n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++){
  cin>>a[i][j];
}

b[i]=10000000;
}
if(a[x][y]==0){cout<<0;return 0;}

b[x]=0;
path[1]=x;
int t=1;
while(t==1)
{
t=0;
int v=min_ar();
if(c[v]==0 && v>0 ) {dejkstra(v); t=1;}
}

cout<<"The shortest way: "<<b[y]<<endl;
cout<<"Tops on the shortest way: ";
 int curr = y;
 while(curr!=x){
    curr = out(curr);
 }


}
