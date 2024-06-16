class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int>result;
        for(char ch: seq){
            if(ch=='('){
                if(depth%2==0){
                    result.push_back(0);
                }else{
                    result.push_back(1);
                }
                depth++;
            }
            else if(ch==')'){
                depth--;
                if(depth%2==0){
                    result.push_back(0);
                }else{
                    result.push_back(1);
                }
            }
        }
        return result;
    }
};