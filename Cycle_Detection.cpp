#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T , list<T> > adjList;
    
    void addEdge(T u , T v , bool direction){
        adjList[u].push_back(v);
        
        if(direction == 0){
            adjList[v].push_back(u);
        }
    }
    
    void print(){
        for(auto node : adjList){
            cout<<node.first<<"->";
            
            for(auto nbr : node.second){
                cout<<nbr<<" ";
            }
            
            cout<<endl;
        }
    }
    
    bool checkCycleUsingBfs(int src , unordered_map<int , bool> &visited){
        queue<int> q;
        unordered_map<int , int > parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
         
        
        while(!q.empty()){
            int Fnode = q.front();
            q.pop();
            
            for(auto nbr : adjList[Fnode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = Fnode;
                }
                else if(visited[nbr] && nbr != parent[Fnode]){
                    return true;
                }
            }
        }
         return false;
          
    }
    bool checkCycleUsingDfs(int src , unordered_map<int , bool > &visited , int parent){
        
        visited[src] = true;
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                bool checkAggeKAanswer = checkCycleUsingDfs(nbr , visited , src);
                
                if(checkAggeKAanswer == true)
                        return true;
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    Graph <int> g;
    
    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3 , 4, 1);
     g.addEdge(4  , 0 , 1);
    
    g.print();
    
    bool ans = false;
    unordered_map<int, bool> visited;
     
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            // ans = g.checkCycleUsingBfs(i , visited);
            
            ans = g.checkCycleUsingDfs(i , visited , -1);
            
            if(ans == true)
                break;
        }
    }
        
        if(ans == true){
            cout<<"Cycle is present in the graph "<<endl;
        }
        else{
            cout<<"Cycle is not present  in the graph"<<endl;
        }
    
    
     
    
    
}