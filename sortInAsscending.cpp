#include<bits/stdc++.h>
using namespace std;

void sort(int a[],int s){
    int temp;
    for(int j  = 0 ; j < s;j++){
        for(int i = 0;i < s;i++){
        if(a[j] < a[i]){
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    }
}

void print(int a[],int s){
    for(int i = 0;i < s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {4,48,23,5,1,90};
    int sizeOfArray = 6;

    cout<<"Before sorting. . . !!!"<<endl;
    print(arr,sizeOfArray);

    sort(arr,sizeOfArray);

    cout<<"After sorting. . . !!!"<<endl;
    print(arr,sizeOfArray);
    
    return 0;
}