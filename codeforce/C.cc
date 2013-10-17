/*                                                                              
 ============================================================================
 Name        : 
 Author      : Zhihui,Jiang             
 Email       : coboy123456@gmail.com    
 Version     : 0.0 
 Copyright   : Your copyright notice    
 Description :  
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

typedef struct Node{
    struct Node* pre;
    struct Node* next;
    int x;
    Node(Node* p , Node* n, int x):pre(p),next(n),x(x){}
}Node;

void print_size(Node * n){
    int l = 0; 
    while(n -> next ){
        l++;
        n = n -> next;
    }
    cout << l << endl;
}
void solve(int n, int m){
    vector<int> par(n+1,0); 
    vector<Node*> nodes;
    Node* head = new Node(NULL,NULL,1);
    Node* current = head; 
    nodes.push_back(current);
    for(int i = 2; i <= n; i ++){
        Node * temp = new Node(current,NULL,i);
        current->next = temp;
        nodes.push_back(temp);  
        current = temp;
    }
    
    /*
    nodes[1]->next = nodes[2]->next;
    nodes[3]->pre = nodes[2]->pre;
    while(head != NULL){
        cout << head->x << " "; 
        head = head->next;
    }
    for(int i = 0; i < nodes.size(); i ++){
        cout << nodes[i]->x << " " ; 
    }
    cout << endl;
    */ 

    int low,high,winner;
    for(int i = 0; i < m; i ++){
        scanf("%d %d %d",&low,&high,&winner);
        print_size(nodes[1]);
        //cin >> low >> high >> winner; 
        Node * nodel = nodes[low-1];
        Node * nodeh = nodes[high-1];
        //cout << "node low " << nodel->x << " node high " << nodeh->x << endl;
        while(par[nodel->x] != 0){
            nodel=nodel->next;
        }
        while(par[nodeh->x] != 0){
            nodeh=nodeh->pre;
        }
        //cout << "node low " << nodel->x << " node high " << nodeh->x << endl;
        //cout << nodel->x << " " << nodeh->x << endl;
        Node * winnode = new Node(nodel->pre,nodeh->next,winner);
        if(nodel->pre)
            nodel->pre->next = winnode;
        if(nodeh->next)
            nodeh->next->pre = winnode;
        while(nodel->x != nodeh->x){
            int x = nodel->x;
            nodes[x-1] = winnode;
            if(x != winner && par[x] == 0){
                par[x] = winner;
                //cout << x << " " << winner << endl;
            }
            Node* temp = nodel->next;  
            if(x > winner)
                nodel->pre = winnode;
            else 
                nodel->pre = winnode->pre;
            if(x < winner)
                nodel->next= winnode;
            else 
                nodel->next= winnode->next;
            nodel = temp;
        }
            int x = nodel->x;
            nodes[x-1] = winnode;
            if(x != winner && par[x] == 0){
                par[x] = winner;
                //cout << x << " " << winner << endl;
            }
    }
    for(size_t i = 1; i < par.size() ; i ++)
        printf("%d ",par[i]) ; 
        printf("\n");
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //cin >> n >> m;
    solve(n,m);
}

