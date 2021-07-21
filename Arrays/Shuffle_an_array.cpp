#include<bits/stdc++.h>
class Solution {
public:
    vector<int> arr;
    vector<int> temp;
    vector<int> res;
    
    Solution(vector<int>& nums) {
        srand((unsigned)time(NULL));
        arr = nums;
        temp = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = arr.size();
        res.clear();
        
        for(int i = n-1; i >= 0; i--){
            int rand_ind = rand() % (i+1);
            res.push_back(arr[rand_ind]);
            swap(arr[rand_ind], arr[i]);
            arr.pop_back();
        }
        
        arr = temp;
        return res;
    }
};

//OR

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> arr;
    
    /** Initializes the object with the integer array nums. */
    Solution(vector<int>& nums) {
        srand((unsigned)time(NULL));
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = arr.size();
        vector<int> temp = arr;
        vector<int> res;
        
        for(int i = n-1; i >= 0; i--){
            int rand_ind = rand() % (i+1);
            res.push_back(arr[rand_ind]);
            swap(arr[rand_ind], arr[i]);
            arr.pop_back();
        }
        
        arr = temp;
        return res;
    }
};

//OR

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> arr;
    vector<int> res;
    
    Solution(vector<int>& nums) {
        srand((unsigned)time(NULL));
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = arr.size();
        res = arr;
        
        for(int i = 0; i < n; i++){
            swap(res[i], res[rand() % n]);
        }
 
        return res;
    }
};