// 2116. Check if a Parentheses String Can Be Valid
// Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12


class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2 != 0) return false;

        stack<int> open;
        stack<int> openClose;

        for(int i=0;i<n;i++){
            if(locked[i] == '0'){
                openClose.push(i);
            }else if(s[i] == '('){
                open.push(i);
            }else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else if(!openClose.empty()){
                    openClose.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }
        return open.empty();
    }
};
