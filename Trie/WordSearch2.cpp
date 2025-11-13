class TrieNode{
    public:
    TrieNode*children[26];
    string word;
    TrieNode(){
        word=""; // empty intially
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }

    }

};
void insert(TrieNode*root,const string&key){
    TrieNode*cur=root;
    for(auto &i:key){
        if(cur->children[i-'a']==nullptr){
            TrieNode*newNode=new TrieNode();
            cur->children[i-'a']=newNode;
        }
        cur=cur->children[i-'a'];
    }
    cur->word=key; // endn of word could be checked if key string matched word string
}

class Solution {
public:
    void dfs(vector<vector<char>>&board,int i,int j,TrieNode*node,vector<string>&res){
        char c=board[i][j];
        if(c=='#') return ;
        int idx=c-'a';
        if(!node->children[idx]) return;

        node=node->children[idx];
        //found a word
        if(!node->word.empty()){
            res.push_back(node->word);
            node->word.clear(); //avoid duplicates
        }

        board[i][j]='#';
        //explore 4 direction
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &d:dir){
            int ni=i+d[0],nj=j+d[1];
            if(ni>=0 && ni<(int)board.size() && nj>=0 && nj<(int)board[0].size()){
                dfs(board,ni,nj,node,res);
            }
        }
        // restore
        board[i][j]=c;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode*root=new TrieNode();
        for(auto i:words) insert(root,i);

        int row=board.size();
        if(row==0) return {};
        int col=board[0].size();
        vector<string>res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dfs(board,i,j,root,res);
            }
        }
        return res;
    }
};