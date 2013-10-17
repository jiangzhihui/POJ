/*                                                                              
 ============================================================================
 Try to solve problem C by segment tree
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
#include<cstdio>
using namespace std; 

const int MAX_N = 1048576;
typedef struct Node{
    int l,r,mid,beater;
    bool visited;
    Node(int l=0, int r=0, int mid=0,int b=0,bool v=false):l(l),r(r),mid(mid),beater(b),visited(v){}
} Node;

Node tree[3*MAX_N];
int beater[MAX_N*2];

void make_tree(int l , int r,int n){
    Node & node = tree[n];
    int mid = (l+r)/2;
    node.l = l;
    node.r = r;
    node.mid = mid;
    if(l+1 != r){
        make_tree(l,mid,2*n);
        make_tree(mid,r,2*n+1);
    }
}

void insert(int l, int r, int w,int n){
    Node & node = tree[n];
    if(l == node.l && r == node.r){
        if(node.beater == 0 && !node.visited){
            node.beater = w;    
            for(int i = l ; i < r; i ++)
              if(beater[i] == 0) beater[i] = w;              
        }
             
        node.visited = true;
        return;
    }
    if( r <= node.mid){
        insert(l,r,w,2*n);
    }else if(l >= node.mid){
        insert(l,r,w,2*n+1);
    }else{
        insert(l,node.mid,w,2*n);
        insert(node.mid,r,w,2*n+1);
    }
}

int main()
{
    int n,m; 
    scanf("%d %d",&n,&m); 
    make_tree(1,n+1,1);
    for(int i = 0; i < m; i ++){
        int low,high,win; 
        scanf("%d %d %d",&low,&high,&win);
        if(low == win)
            insert(low+1,high+1,win,1);
        else if(high == win)
            insert(low,high,win,1);
        else {
            insert(low,win,win,1);
            insert(win+1,high+1,win,1);
        }
    }

    for(int i = 1;i <= n ; i ++)
        cout << beater[i] << " " ; 
    cout << endl;
}

