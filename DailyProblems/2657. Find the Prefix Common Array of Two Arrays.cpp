// 2657. Find the Prefix Common Array of Two Arrays
// Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
// You are given two 0-indexed integer permutations A and B of length n.
// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in
// both A and B.
// Return the prefix common array of A and B.
// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

// Approach 1 (Brute Force):
// The brute force approach iterates over each prefix of the arrays A and B and checks if elements in A are present in B up to the current 
// index. This involves nested loops, leading to a time complexity of O(n3). The idea is straightforward but inefficient due to repeated 
// comparisons.
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int count=0;
            for(int a=0;a<=i;a++){
                for(int b=0;b<=i;b++){
                    if(B[b] == A[a]){
                        count++;
                        break;
                    }
                }
            }
            result[i] = count;
        }
        return result;
    }
};

// Approach 3 (Optimal Approach):
// The optimal approach leverages a hash map to track the frequency of elements from both arrays. When an element's frequency reaches 2, 
// it indicates it is common in the prefix. This approach avoids redundant checks and achieves a linear time complexity of O(n), making it 
// the most efficient solution.

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int> mp;
        vector<int> result(n);
        int count=0;
        for(int i=0;i<n;i++){
            
            mp[A[i]]++;
            if(mp[A[i]]==2){
                count++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;
            }
            result[i]=count;
        }
        return result;
    }
};
