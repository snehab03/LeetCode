// 1400. Construct K Palindrome Strings
// Link:https://leetcode.com/problems/construct-k-palindrome-strings/
// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n == k) return true;  //single element as palindrome(k)
        if(n < k) return false;  
        int count_odd=0;
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        for(auto& c:v){
            if(c%2 != 0){
                count_odd++;
            }
        }
        return count_odd <= k;
    }
};
