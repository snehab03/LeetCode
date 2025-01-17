// 1. Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int needMore = target-nums[i];  //
            if(mp.find(needMore) != mp.end()){
                return {mp[needMore],i};   //index of current element as well as index of needMore if seen earlier in map
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
