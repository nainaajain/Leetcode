class Solution {
public:
bool calc(int i,int j,vector<vector<char>>& board,string word,int n,int m,int k,vector<vector<bool>>&vis){
    if(k==word.size())return true;
    if(i<0 || j<0||i==n||j==m||board[i][j]!=word[k]||vis[i][j]==1)return false;
    vis[i][j]=1;
    bool op1=calc(i+1,j,board,word,n,m,k+1,vis);
    bool op2=calc(i-1,j,board,word,n,m,k+1,vis);
    bool op3=calc(i,j+1,board,word,n,m,k+1,vis);
    bool op4=calc(i,j-1,board,word,n,m,k+1,vis);
    vis[i][j]=0;
    return op1||op2||op3||op4;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(calc(i,j,board,word,n,m,0,vis))return true;
                }
            }
        }
        return false;
    }
};