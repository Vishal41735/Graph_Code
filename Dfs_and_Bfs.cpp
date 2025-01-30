#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T , list< T  > >  adjlist;
    void addEdge(T u , T v , bool direction){

        adjlist[u].push_back(v);
        if(direction == 0){
            adjlist[v].push_back(u);
        }
    }

    // void print(){
    //     for(auto node : adjlist){
    //         cout<<node.first<<"->";

    //         for(auto neighbour : node.second){
    //             cout<<neighbour<<" ";
    //         }
    //         cout<<endl;
    //     }
    //  }

    void   bfs(int src , unordered_map<int , bool > &visited){
        queue<int> q;
        q.push(src);
        visited[src]  = true;

        while(!q.empty()){
            int fNode = q.front(); q.pop();
            cout<<fNode<<" ";

            //insert neighbour
            for(auto neighbour : adjlist[fNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

    }
    void dfs(int src , unordered_map<int  , bool > visited){
        cout<<src<<" ";
        visited[src] = true;
        for( auto neighbour : adjlist[src] ){
            if(!visited[neighbour]){
                dfs(neighbour , visited);
            }
        }

    }

};

int main(){
    Graph <int> g;
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);

    g.addEdge(0,2,0);

    g.addEdge(2,4,0);
    cout<<endl;

    //  g.print();

     //Best practice .

      unordered_map<int , bool> visited;
    //  for(int i = 0; i<5; i++){
    //     if(!visited[i]){
    //         g.bfs(i , visited);
    //     }
    //  }

    for(int i = 0; i<5; i++){
        if(!visited[i]){
            g.dfs(i , visited);
        }

    }

}