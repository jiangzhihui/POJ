/*                                                                              
 ============================================================================
 Poj 3009 curling 2.0 
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std; 


typedef vector<vector<int> > VVI;
typedef struct status{
    int sx,sy,depth;
    VVI maze;
    status(int x = 0, int y = 0,int d=0,VVI m = VVI()):sx(x),sy(y),depth(d),maze(m){
        /*
        for(int i = 0;i < m.size(); i++){
            vector<int> v; 
            for(int j=0 ; j < m[0].size(); j++){
                v.push_back(m[i][j]);
            }
            maze.push_back(v);
        }
        */
    }

}status;

void print(VVI v){
    for(size_t i = 0;i < v.size(); i++){
        for(size_t j = 0; j < v[0].size(); j++){
            cout << v[i][j] << " " ; 
        }
        cout << endl;
    }
    cout << endl;
}
int bfs(VVI & maze , int sx ,int sy , int dx, int dy){
    int res = -1; 
    int dirx[] = {0,1,0,-1};
    int diry[] = {-1,0,1,0};
    maze[sx][sy] = 0;
    queue<status> que;
    que.push(status(sx,sy,0,maze));
    while(!que.empty()){
        status s = que.front();
        que.pop();
        VVI m = s.maze;
        int rows = m.size();
        int cols = m[0].size();
        for(int i = 0; i < 4; i ++){
            int xx = s.sx + dirx[i];
            int yy = s.sy + diry[i];    
            if( xx < 0 || xx >= rows || yy < 0 || yy >= cols)
                continue; 
            if( m[xx][yy] == 1){
                continue;
            }
            while(m[xx][yy]==0){
                xx += dirx[i];
                yy += diry[i];    
                if( xx < 0 || xx >= rows || yy < 0 || yy >= cols)
                    break; 
            }
            if( xx < 0 || xx >= rows || yy < 0 || yy >= cols)
                continue;

                if(m[xx][yy] == 3){
                    return s.depth + 1;
                }else {
                    VVI mm = m; 
                    mm[xx][yy] = 0;
                    if(s.depth < 9)
                        que.push(status(xx-dirx[i],yy-diry[i],s.depth+1,mm));
                }
        }
    }

    return res;
}

int main()
{
    int rows, cols;
    while(true){
        scanf("%d %d",&rows,&cols);
        if(rows == 0)
            break;
        vector<vector<int> > maze(rows,vector<int>(cols,-1)); 
        int sx,sy,dx,dy;
        for(int i = 0; i < rows; i ++)
            for(int j = 0; j < cols; j++){
                scanf("%d",&maze[i][j]);
                if(maze[i][j] == 2){
                    sx = i;
                    sy = j;
                }
                if(maze[i][j] == 3){
                    dx = i;
                    dy = j;
                }
            }
        //cout << sx << " " << sy <<endl;        
        int res = bfs(maze,sx,sy,dx,dy);
        cout << res << endl;
    }
}

