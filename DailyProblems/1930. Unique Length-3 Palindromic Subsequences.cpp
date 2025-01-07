// 1930. Unique Length-3 Palindromic Subsequences

// Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// step1 : take char with index from extreme left and right of s string.
// step2 : each characters between left and right are number of unique palindromes of length three
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<char> st;
        int result=0;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        for(char l:st){
            int left_ind = -1;
            int right_ind = -1;
            for(int i=0;i<n;i++){
                if(s[i] == l){
                    if(left_ind == -1){
                        left_ind = i;
                    }
                    right_ind = i;
                }
            }
            unordered_set<char> mid_letters;
            for(int mid = left_ind + 1;mid < right_ind ; mid++){
                mid_letters.insert(s[mid]);
            }
            result += mid_letters.size();
        }
        return result;

    }
};
