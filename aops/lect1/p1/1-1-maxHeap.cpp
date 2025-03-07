#include <bits/stdc++.h>

using namespace std;

const int mxN=5000;

int heap[mxN], arrsz=0;

void add(int v){
    heap[arrsz]=v;
    int idx=arrsz;
    arrsz++;
    while(true){
        if(idx==0){
            return;
        }
        int par=(idx-1)/2;
        if(heap[idx]<heap[par]){
            return;
        }
        swap(heap[idx], heap[par]);
        idx=par;
    }
}

void del(){
    heap[0]=heap[arrsz-1];
    arrsz--;
    int idx=0;
    while(true){
        int l=idx*2+1, r=idx*2+2, mxIdx=idx;
        if(l<arrsz && heap[mxIdx]<heap[l]){
            mxIdx=l;
        }
        if(r<arrsz && heap[mxIdx]<heap[r]){
            mxIdx=r;
        }
        if(idx==mxIdx){
            break;
        }
        swap(heap[idx], heap[mxIdx]);
        idx=mxIdx;
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>x;
        if(x==0){
            del();
        }else{ 
            add(x);
        }
        for(int j = 0; j<arrsz; j++){
            cout<<heap[j];
            if(j!=arrsz-1){
                cout<<" ";
            }
        }
        cout<<'\n';
    }
}