#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;
vector<bool> tf;
void dfs(int ele){
    if(!tf[ele]){
      cout<<ele<<"\t";
      tf[ele]=true;
    }
    for(auto i=v[ele].begin();i<v[ele].end();i++){
        if(!tf[*i]){
            dfs(*i);
        }
    }

}



int main(){
    int n,e;
    cout<<"Enter the number of nodes and edges\n";
    cin>>n>>e;
    tf.assign(n,false);
    v.assign(n,vector<int>());
    cout<<"Enter the edge list\n";
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    dfs(0);
}
