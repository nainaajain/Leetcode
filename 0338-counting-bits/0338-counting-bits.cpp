#include<bits/stdc++.h>
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int count=0;
        for(int i=0;i<=n;i++){
            count+=__builtin_popcount(i);
            ans.push_back(count);
            count=0;
        }
        return ans;
    }
};