//https://leetcode.com/problems/word-search-ii/description/

class Solution {
public:
   bool result(vector<vector<char>>&board,int i,int j,vector<vector<bool>>&visited,string s,int k){
       int n =board.size(),m=board[0].size();
       if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || board[i][j] != s[k])
       return false;
       if(k >= s.length()-1)
       return true;
       
       visited[i][j] = true;

       if(i+1 < n && board[i+1][j] == s[k+1]){
           if(result(board,i+1,j,visited,s,k+1))
           return true;
       }
       if(i-1>=0 && board[i-1][j] == s[k+1]){
           if(result(board,i-1,j,visited,s,k+1))
           return true;
       }
        if(j+1 < m && board[i][j+1] == s[k+1]){
           if(result(board,i,j+1,visited,s,k+1))
           return true;
       }
        if(j-1 >= 0 && board[i][j-1] == s[k+1]){
           if(result(board,i,j-1,visited,s,k+1))
           return true;
       }
       visited[i][j] =false;
       return false;
   }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         int n =board.size(),m=board[0].size();
        map<char,vector<string>>mp;
        for(int i=0;i< words.size();i++){
            mp[words[i][0]].push_back(words[i]);
            
        }
       
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<board[i][j]<<" ";
                if(mp.find(board[i][j]) != mp.end()){
                    for(auto it:mp[board[i][j]]){
                    // cout<<it<<" ";
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                // if(result(board,i,j,visited,mp[board[i][j]],0))
                //   ans.push_back(mp[board[i][j]]);
                 if(result(board,i,j,visited,it,0)){
                     cout<<it<<" ";
                 if(find(ans.begin(),ans.end(),it) == ans.end())
                  ans.push_back(it);
                 }
             }
                }
            }
        }
        return ans;

    }
};

//Trie:-
class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        string word;
        TrieNode() : word(""), child(vector<TrieNode*>(26, nullptr)) {}
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int i = c - 'a';
                if (curr->child[i] == NULL) curr->child[i] = new TrieNode();
                curr = curr->child[i];
            }
            curr->word = w;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> out;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); ++i) 
            for(int j = 0; j < board[0].size(); ++j) 
                dfs(board, i, j, root, out);
        return out;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& out) {
        char c = board[i][j];
        if(c == '#' || curr->child[c - 'a'] == NULL) return;
        curr = curr->child[c - 'a'];
        if (curr->word != "") {
            out.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j , curr, out); 
        if(j > 0) dfs(board, i, j - 1, curr, out);
        if(i < board.size() - 1) dfs(board, i + 1, j, curr, out); 
        if(j < board[0].size() - 1) dfs(board, i, j + 1, curr, out); 
        board[i][j] = c;
    }
};
