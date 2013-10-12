/*
calculate the second shortest path between node 1 and node N in a graph
*/
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<vector>
#include<map> 
#include<cmath>
using namespace std; 

typedef pair<int,int> P;
const int MAX_N = 50001;
const int INF = 10000000;

struct edge{
    int to;
    int cost;
    edge(int t=0,int c=0):to(t),cost(c){}
};

//calculte the second shortest path from source to other nodes 
void sec_short(vector<edge> * g, int N , int source){
    vector<int> dis1(N+1,INF);              //shortest path
    vector<int> dis2(N+1,INF);              //second shortest path 
    priority_queue<P> pque;
    pque.push(P(0,source));
    dis1[source] = 0;
    dis2[source] = 0;
    while(!pque.empty()){
        P p= pque.top();
        pque.pop();
        int node = p.second;
        //cout << node << endl;
        vector<edge> & edges=g[node];
        for(size_t i = 0; i < edges.size(); i ++){
            edge e = edges[i];
            if(dis1[e.to] > dis1[node] + e.cost){
                dis2[e.to] = dis1[e.to];
                dis1[e.to] = dis1[node] + e.cost;    
                pque.push(P(dis1[e.to],e.to));
            }else if(dis2[e.to] > dis1[node] + e.cost){
                dis2[e.to] = dis1[node] + e.cost; 
            }

        }
    }
    cout << dis2[N] << endl;
}

int main()
{
    int N,R;
    cin >> N >> R; 
    vector<edge> g[MAX_N];
    for(int i=0; i < R; i ++){
        int a , b , d;
        cin >> a >> b >> d;    
        g[a].push_back(edge(b,d));
    }

    sec_short(g,N,1);
}

