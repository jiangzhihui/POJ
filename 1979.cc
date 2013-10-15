/*                                                                              
 ============================================================================
 poj 1979 red and black 
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
#include<queue>
using namespace std; 

char maze[21][21];
typedef pair<int,int> P;

int bfs(int rows,int cols, int sx,int sy){
    int res = 1;
    int dirx [] = {0,1,0,-1};
    int diry [] = {-1,0,1,0};
    vector< vector<bool> > visited(rows,vector<bool>(cols,false));
    queue<P> que;
    que.push(P(sx,sy)); 
    visited[sx][sy] = true;
    while(!que.empty()){
        P p = que.front();
        que.pop();
        for(int i = 0; i < 4; i ++){
            int xx = p.first + dirx[i];
            int yy = p.second + diry[i];      
            if( xx >= 0 && xx < rows && yy >= 0 && yy < cols && maze[xx][yy] == '.' &&  !visited[xx][yy]){
                visited[xx][yy] = true;
                que.push(P(xx,yy));
                res ++;
            }
        }
    }
    return res; 
}

int main()
{
    int h,w;
    while(cin >> h >> w) {
        //cout << h << " " << w << endl;
        if(0==h)
            break;
        int sx,sy;
        for(int row = 0; row < w;++row){
            for(int col = 0; col<h;++col){
                cin >> maze[row][col] ;
                if(maze[row][col] == '@'){
                    sx=row;
                    sy=col;    
                }
            }
        }
        
        int res = bfs(w,h,sx,sy); 
        cout << res << endl;
    }
}

