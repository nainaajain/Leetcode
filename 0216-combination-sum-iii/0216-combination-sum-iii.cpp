class Solution {
public:
void helper(int ind,vector<int>&ds,vector<vector<int>>&ans,int sum,int k,int target){
    if(sum>target)return;
    if(k==0){
        if(target==sum){
            ans.push_back(ds);
            
        }
        return;
    }
    if(ind>9)return;
    //take
    sum+=ind;
    ds.push_back(ind);
    helper(ind+1,ds,ans,sum,k-1,target);
    ds.pop_back();
    sum-=ind;
    helper(ind+1,ds,ans,sum,k,target);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
    vector<int>ds;
    int sum=0;
    helper(1,ds,ans,sum,k,n);
    return ans;
    }
};