#include <bits/stdc++.h>

using namespace std;

int arr1[3]={1, 2, 3};
vector<int> vect1 = {1, 2, 3};
vector<int> av1[] = {{4}, {1, 2, 3}, {5}};

void printArr(int*arr){
    for(int i = 0; i<3; i++){
        cout<<arr[i]<<" ";
    }
}

void printVect(vector<int>*vect){
    for(int i = 0; i<3; i++){
        cout<<vect->at(i)<<" ";
    }
}

void printVectIt(vector<int>*vect){
    for(auto it=vect->begin(); it!=vect->end(); it++){
        cout<<*it<<" ";
    }
}

void printAv1(vector<int>*vect){
    for(int i = 0; i<3; i++){
        for(auto it=vect[i].begin(); it!=vect[i].end(); it++){
        cout<<*it<<" ";
        }
        cout<<'\n';
    }
}

void printAv2(vector<int>* vect){
    for(int i = 0; i<3; i++){
        for(int j:vect[i]){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    printArr(arr1);
    cout<<'\n';
    printVect(&vect1);
    cout<<'\n';
    printVectIt(&vect1);
    cout<<'\n';
    printAv1(av1);
    cout<<'\n';
    printAv2(av1);
}