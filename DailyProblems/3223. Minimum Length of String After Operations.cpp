// 3223. Minimum Length of String After Operations
// Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

// You are given a string s.
// You can perform the following process on s any number of times:
// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], 
// and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.

// //1st Method
// The goal is to minimize the string length by deleting characters. We iterate through the string while maintaining a frequency array for 
// each character. If a character appears three times, we delete two of them to keep the frequency below three. The result is calculated as 
// the original string length minus the total number of deletions.
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        int result=0;
        for(char& ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a'] == 3){
                freq[ch-'a'] -= 2;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            result+= freq[i];
        }
        return result;
    }
};
//2nd Method

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        int deleted =0;
        for(char& ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a'] == 3){
                freq[ch-'a'] -= 2;
                deleted += 2;
            }
        }
        return n - deleted;
    }
};

//3rd Method
// This approach focuses on counting characters based on their frequency. First, we calculate the frequency of each character in the string.
// For each character, if its frequency is even, we add two to the result; if odd, we add one. This ensures we account for the minimum
// possible contribution of each character to the final string length.
class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        // int deleted =0;
        int result=0;
        for(char& ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a'] == 3){
                freq[ch-'a'] -= 2;
                // deleted += 2;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            if(freq[i]%2 == 0) result += 2;
            else result += 1;
        }
        // return n - deleted;
        return result;
    }
};
