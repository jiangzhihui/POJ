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
using namespace std; 

typedef struct dance{
    int a,b,c;
    dance(int a=0,int b=0,int c=0):a(a),b(b),c(c){}
} dance;


bool end = false;
void dfs(vector<dance> & ds , int depth, vector<int> & color){
    dance d = ds[depth];
    for(int i = 1; i <= 3; i ++){
        int color1 = i;
        if(color[d.a] > 0)
            color1 = color[d.a];
        for(int j = 1;j <= 3; j++){
            int color2 = j;
            if(color[d.b] > 0)
                color2 = color[d.b];
            for(int k = 1; k <= 3; k++){
                int color3 = k;
                if(color[d.c] > 0)
                    color3 = color[d.c]; 
                if(color1 != color2 && color2 != color3 && color1 != color3){
                    color[d.a]=color1;
                    color[d.b]=color2;
                    color[d.c]=color3;
                    if( depth == ds.size() -1){
                        //cout << d.a << " " << d.b << " " << d.c << endl;
                        //cout << depth << " " << ds.size() -1 << endl;
                        for(int x = 1; x < color.size() ; x++)
                            cout << color[x] << " " ;
                        cout << endl;
                        end = true;
                        return;
                    }
                    else {
                        if(!end)
                            dfs(ds,depth+1,color);
                    }
                }
            }
        }
    }

}

int main()
{
    int n , m;
    cin >> n >> m;
    vector<dance> ds(m,dance());
    for(int i = 0; i < m; ++i){
        dance &d = ds[i]; 
        cin >> d.a >> d.b >> d.c; 
        //cout << d.a << " " << d.b << " " << d.c <<endl;
    }
    vector<int> color(n+1,0);
    dfs(ds,0,color);
}

