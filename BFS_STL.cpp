#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> g;
vector<bool> v;


void bfs(int ele){
    queue<int> q;
    int ele1;
    cout<<ele<<"\t";
    q.push(ele);
    v[ele]=true;
    while(!q.empty()){
       ele1=q.front();
       q.pop();
       for(auto i=g[ele1].begin();i<g[ele1].end();i++){
           if(!v[*i]){
               cout<<*i<<'\t';
               v[*i]=true;
               q.push(*i);
           }
       }

    }

}



int main(){
    int n,e;
    cout<<"Enter number of nodes and edges\n";
    cin>>n>>e;
    g.assign(n,vector<int>());
    v.assign(n,false);
    cout<<"Enter the edge list";
    int a,b;
    for(int i=0;i<e;i++){
      cin>>a>>b;
      g[a].push_back(b);
    }

    bfs(0);
}
