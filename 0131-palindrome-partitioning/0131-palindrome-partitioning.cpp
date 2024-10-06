class Solution {
public:
bool ispalindrome(string x){
    string y=x;
    reverse(x.begin(),x.end());
    if(y==x)return true;
    else return false;
}
void helper(vector<string>&ds,vector<vector<string>>&ans,string &s){
    if(s.size()==0){
        ans.push_back(ds);
        return;
    }
    for(int i=1;i<=s.size();i++){
        string x=s.substr(0,i);
        if(ispalindrome(x)){
            ds.push_back(x);
            string y=s.substr(i,s.size()-1);
            helper(ds,ans,y);
            ds.pop_back();

        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        helper(ds,ans,s);
        return ans;
    }
};


















