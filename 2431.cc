#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<map> 
#include<cmath>
using namespace std; 

bool compare(const pair<int,int> & p1, const pair<int,int> & p2){
    return p1.first < p2.first;
}

int main()
{
    int N,L,p; 
    vector<pair<int,int> > stops;
    priority_queue<int> pque;
    cin >> N; 
    for(int i = 0; i < N; i ++){
        int a,b;
        cin >> a >> b;
        stops.push_back(pair<int,int>(a,b));
    }
    cin >> L >> p;
    if( p >= L){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N; ++ i){
        stops[i].first = L - stops[i].first;
    }
    sort(stops.begin(),stops.end(),compare);
    stops.push_back(pair<int,int>(L,0));
    int i = -1;
    int s = 0;
    int count = 0;
    while(i < N){
        while(!pque.empty() && p < stops[i+1].first-s){
            ++ count; 
            p += pque.top();
            pque.pop();
        }
        if( pque.empty() && p < stops[i+1].first - s){
            count = -1;
            break;
        }
        ++i;
        p = p - (stops[i].first - s); 
        pque.push(stops[i].second);
        s = stops[i].first;
    }
    cout << count << endl;
}

