#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

class graph_area
{
    int nodes;
    list<int> *adj;

    public:
    graph_area(int nodes)
    {

        this->nodes=nodes;
        adj=new list<int>[nodes];
    }
    void add_edge(int v, int w)
    {

        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    bool check_cycle_area()
    {
        vector<bool>visited(nodes, false);
        queue<int> q;

        for(int i=0; i <nodes; i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(auto v: adj[u]){
                        if(!visited[v]){
                            visited[v]= true;
                            q.push(v);
                        }
                        else if(v != u){
                            return true;
                        }
                    }
                }

            }
        }
    return false;
}

};


    int main(){
        int nodes;
        cout << "Enter the number of nodes: ";
        cin >> nodes;
        graph_area g(nodes);
        int edges;
        cout <<"Enter the number of nodes: ";
        cin >> edges;

        for(int i=0; i<edges; i++){
            int v,w;
                cout << "Enter the vertices of edge"<< i+1 << ": ";
                cin >>v>>w;
                g.add_edge(v,w);
        }
        if(g.check_cycle_area()){
            cout <<"Cycle";
        }
        else {
            cout <<"Not Cycle";
        }
    }
