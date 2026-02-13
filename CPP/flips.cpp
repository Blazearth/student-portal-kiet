#include<bits/stdc++.h>
using namespace std;
//i have to give the window size return
int window(int arr[],int n,int k){
    //i have the array and i have the size of n
    int left=0;
    int right=0;
    int window=right-left;
    int zeros=0;
    /*
    11	
    1 1 1 0 0 0 1 1 1 1 0	
    2
    */
    //okay so i will take in the window only if there are zeros=k and after that i will start reduction from the 
    //starting and then i will dynamically reduce or increase the array size
    while(right<n){
        if(arr[right]==0){
            //will increase the array from right one 
            zeros++;
        }
        while(zeros>k){
            if(arr[left]==0){
                zeros--;
            }
            //shrinking the window
            left++;
        }
        window=max(window,right-left+1);
        right++;
    }
    return window;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    //now i have everything 
    int win=window(a,n,k);
    cout<<win;
}