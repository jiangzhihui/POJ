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

void solve(){
    int m;
    cin >> m; 
    vector<int> nums(1+m,0);
    int total = 0;
    for(int i = 1; i <= m; i ++){
        cin >> nums[i]; 
        total += nums[i];
    }
    int x,y;
    cin >> x >> y;
    int sum = 0; 
    int i ;
    for(i=1;i <= m; i ++){
            sum += nums[i];
            int sumy = total - sum;
            if( sum >= x && sum <= y && sumy >= x && sumy <=y)
                break;
    }
    if(i >= m)
        cout << 0 << endl;
    else 
        cout << i+1 << endl;

}
int main()
{
        solve();
}

