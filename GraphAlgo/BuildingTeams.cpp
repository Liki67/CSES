#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m, vector<int>(2));
    for(int i=0;i<m;i++) 
        cin>>edges[i][0] >> edges[i][1];
 
    vector<vector<int>>adj(n+1);
    vector<int>color(n+1,0);
    for(auto it:edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    queue<int>q;
    bool same=false;
    for(int i=1;i<=n;i++){
        if(color[i]!=0)continue;
        q.push(i);color[i]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it:adj[node]){
                if(color[it] == 0){
                    if(color[node]==1)
                        color[it]=2;
                    else
                        color[it]=1;
                    q.push(it);
                }else if(color[node]== color[it]){
                        cout<<"IMPOSSIBLE"<<endl;
                       return 0;
                    
                }
            }
                
        }
        
    }
    for(int i=1;i<=n;i++)
        cout<<color[i]<<" ";
        
        

    return 0;
}