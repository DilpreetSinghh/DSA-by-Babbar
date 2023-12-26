#include<iostream>
#include<bits/stdc++.h>

    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){            
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }

int main(){
    vector<int> nums = {9, 22, 37, 45, 51, 113};
    int arr = pivotIndex(nums);
    cout<<"Pivot is "<< arr <<endl;
}

// g++ -std=c++20 filename.cpp 
// use above command where vector is in use
// vscode