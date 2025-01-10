// 2185. Counting Words With a Given Prefix
// Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09
// You are given an array of strings words and a string pref.
// Return the number of strings in words that contain pref as a prefix.


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int n=words.size();
        for(int i=0;i<n;i++){
            // if(words[i].substr(0,pref.size()) == pref){
            //     count++;
            // }
            if(words[i].find(pref)==0){
                count++;
            }
        }
        return count;
    }
};
