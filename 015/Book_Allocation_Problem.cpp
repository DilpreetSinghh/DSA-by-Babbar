#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// n: total pages, m: no. of partitions
bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else{
            studentCount++;

            if (studentCount > m || arr[i] > mid) {
            return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int start = arr[0];
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }

    int end = sum;
    int ans = -1;
    int mid = start + (end-start)/2;
    
    while(start<=end){
        if(isPossible(arr,n,m,mid)){
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {9, 22, 37, 45, 51, 113};
    cout<<"Pivot is "<< allocateBooks(arr, 6, 2) << endl;
    return 0;
}