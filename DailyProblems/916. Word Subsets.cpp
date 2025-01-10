// 916. Word Subsets
// Link: https://leetcode.com/problems/word-subsets/description/
// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You may return the answer in any order.

class Solution {
public:
    bool isSubstr(vector<int>& freq2,vector<int>& temp){
        for(int i=0;i<26;i++){
            if(temp[i]<freq2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq2(26);
        for(auto &word:words2){
            vector<int> temp(26,0);
            for(auto &ch:word){
                temp[ch-'a']++;
                freq2[ch-'a']=max(freq2[ch-'a'],temp[ch-'a']);
            }  
        }
        for(auto &word:words1){
            vector<int> temp(26,0);
            for(auto &ch:word){
                temp[ch-'a']++;
            }  
            if(isSubstr(freq2,temp) == true){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
