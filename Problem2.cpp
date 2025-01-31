// Time Complexity :O(N) N length of the decoded string.
// Space Complexity : O(N)  
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Decode String

#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int currNum = 0;
        string currStr = "";
        stack<pair<int,string>> numStr;
        //stack<string> strStack;
        
        int i = 0;
        while(i<s.length()){
            if(isdigit(s[i])){
                currNum = currNum*10 + s[i] - '0';
            }
            else if( s[i] == '['){
                numStr.push({currNum,currStr});
                currNum = 0;
                currStr = "";
            }
            else if(s[i] == ']'){
                int times = numStr.top().first;
                string res = "";
                for(int k = 0;k< times;k++){
                    res+= currStr;
                }
                currStr = numStr.top().second + res;
                numStr.pop();
            }
            else{
                currStr = currStr + s[i];
            }
            i++;
        }
        return currStr;
    }
};