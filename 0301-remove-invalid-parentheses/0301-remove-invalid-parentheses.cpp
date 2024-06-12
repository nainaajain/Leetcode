#include<bits/stdc++.h>

class Solution {
public:
vector<string>res;
unordered_map<string,int>mp;
int getmininvalid(string &s){
    stack<char>stck;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stck.push('(');
        }
        else if(s[i]==')'){
            if(!stck.empty() && stck.top()=='('){
                stck.pop();
            }
            else {
                stck.push(')');
            }
        }
    }
    return stck.size();
}

void solve (string s, int mininvalid){
//checking for duplicates
if(mp[s]!=0){
    //means that string can be there in the res no need to push 
    return;
}
else{
    //if its 0 increase its frequency to 1
    mp[s]++;
}

 
    if(mininvalid<0){
        return ;
    }
    if(mininvalid==0){
        //again push in stack and check whether the stack size is 0 or not 
        if(!getmininvalid(s)){ // will be all 0 means valid push the ansh
            res.push_back(s);
            return ;
        }
    }
    //now recursion check for all possible cases 
    for(int i=0;i<s.size();i++){
        if(s[i] != '(' && s[i] != ')') {
                continue;
            }
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        solve(left+right,mininvalid-1);// if there are 2 paranthesis reduce on the basis of this 
    }
   

}

    vector<string> removeInvalidParentheses(string s) {
        int d=getmininvalid(s);
        solve(s,d);
        return res;
        
    }
};