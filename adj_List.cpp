#include<bits/stdc++.h>
using namespace std;
//Generic class.
template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T , T> > > adjlist;
    void addEdge(int u , int  v , int weight , bool direction){
        // direction == 0 than  this is undirected graph
        //direction == 1  than this is directed graph

        adjlist[u].push_back({v , weight});
        if(direction == 0){
            adjlist[v].push_back({u , weight});
        }
    }

    void printAdja(){
        for(auto  node: adjlist){
            cout<<node.first<<"->";

            for(auto neighbour: node.second){
                cout<<"("<<neighbour.first<<"," <<neighbour.second<<")";
            }
            cout<<endl;
        }
    }

};
int  main(){
    Graph <int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,8,1);
    g.addEdge(0 ,2,6,1);
    cout<<endl;
    g.printAdja();
     

}