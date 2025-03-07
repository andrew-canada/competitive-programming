#include <bits/stdc++.h>

using namespace std;

const int mxN=2e4;

int heap[mxN+1];

void propToLeaf(int n){
    int l=n*2+1, r=n*2+2;
    if(heap[n]<max(heap[l], heap[r])){
        if(heap[l]>heap[r]){
            swap(heap[n], heap[l]);
            n=l;
        }else{
            swap(heap[n], heap[r]);
            n=r;
        }
    }else{
        return;
    }
    propToLeaf(n);
}

void propToRoot(int n){
    int par=(n-1)/2;
    if(heap[n]>heap[par]){
        swap(heap[n], heap[par]);
        propToRoot(par);
    }
}

void add(int x, int n){
    heap[n]=x;
    propToRoot(n);
}

void del(int x, int n){
    heap[0]=heap[n];
    propToLeaf(0);
}

// void add(int x, int n){
//     heap[n]=x;
//     while(n){
//         int par=(n-1)/2;
//         if(heap[n]>heap[par]){
//             swap(heap[n], heap[par]);
//         }else{
//             return;
//         }
//         n=par;
//     }
// }

// void del(int x, int n){
//     heap[0]=heap[n];
//     n=0;
//     int l=n*2+1, r=n*2+2;
//     while(heap[n]<max(heap[l], heap[r])){
//         if(heap[l]>heap[r]){
//             swap(heap[n], heap[l]);
//             n=l;
//         }else{
//             swap(heap[n], heap[r]);
//             n=r;
//         }
//         l=n*2+1, r=n*2+2;
//     }
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, x, n=0;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>x;
        if(x){
            add(x, n);
            ++n;
        }else{
            del(x, n);
            --n;
        }
        for(int j = 0; j<n; j++){
            if(j==n-1){
                cout<<heap[j];
            }else {
                cout<<heap[j]<<' ';
            }
        }
        if(i<q-1){
            cout<<'\n';
        }
    }
}