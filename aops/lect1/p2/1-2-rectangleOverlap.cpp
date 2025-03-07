#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxR=1e9;

priority_queue<array<int, 2>> chunk;
priority_queue<array<int, 3>> rect;
ll ans=0;

int main(){
    chunk.push({0, -mxR});
    int n, l, r, h, chunkH=0, chunkL=0; cin>>n;
    for(int i = 0; i<n; i++){
        cin>>l>>r>>h;
        rect.push({-l, -r, h});
    }
    while(!rect.empty()){
        auto [cl, cr, ch] = rect.top();
        rect.pop();
        chunkH = chunk.top()[0];
        if(ch>0){
            chunk.push({ch, cr});
            rect.push({cr, 0, 0});
        }else{
            while(chunk.top()[1]>=cl){
                chunk.pop();
            }
        }
        ans+=chunkH*((ll)chunkL-cl);
        chunkL=cl;
    }
    cout<<ans;
}