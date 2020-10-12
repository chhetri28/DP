/*

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false


*/

class Solution {
public:
    map<string,bool>mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto x:wordDict){
            st.insert(x);
        }
        if(st.find(s)!=st.end()){
            return true;
        }
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        for(int i=1;i<=s.length();i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            if(st.find(left)!=st.end() and wordBreak(right,wordDict)){
                mp[s]=true;
                return true;
            }
        }
        mp[s]=false;
        return false;
    }
};