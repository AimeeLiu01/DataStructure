//
//  main.cpp
//  1. Two Sum
//
//  Created by 刘畅 on 2017/6/12.
//  Copyright © 2017年 刘畅. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    struct cmp{
        
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
         
            return a.first < b.first;
        }
        
    };
    
    vector<int> twoSum(vector<int> &nums, int target){
        
        vector<pair<int, int>> newNums;
        for(int i = 0; i < nums.size(); i++){
            newNums.push_back(make_pair(nums[i],i));
        }
        sort(newNums.begin(), newNums.end());
        
        vector<int> res;
        int pa = 0; int pb = newNums.size() - 1;
        while(pa < pb){
            if(newNums[pa].first + newNums[pb].first == target){
                res.push_back(pa);
                res.push_back(pb);
                return res;
            }
            else if (newNums[pa].first + newNums[pb].first < target){
                pa++;
            }
            else
                pb--;
        }
        
        return res;
    }
        
    
};

class Solution2{
    
public:
    vector<int> twoSum2(vector<int> &nums, int target){
        
        map<int,int> map;
        vector<int> res;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(map.count(target-nums[i])){
                res.push_back(i);
                res.push_back(map[target-nums[i]]);
                return res;
            }
            map[nums[i]] = i;
        }
        
        return res;
        
    }
    
};


int main(int argc, const char * argv[]) {
    
    vector<int> vec;
    vector<int> res;
    vector<int> res2;
    
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(15);
    
    
    
    Solution s = *new Solution();
    res = s.twoSum(vec, 9);
    cout<<"The first method is ";
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    
    
    Solution2 s2 = *new Solution2();
    res2 = s2.twoSum2(vec, 9);
    cout<<"The second method is ";
    for(int i = 0; i < res2.size(); i++){
        cout<<res2[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}




