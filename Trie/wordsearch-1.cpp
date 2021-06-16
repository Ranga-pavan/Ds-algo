class Solution {
public:
    bool flag=false;
    struct trie{
        bool isend;
        struct trie *children[256];
    };
    struct trie *getnode(void){
        trie *root=new trie();
        root->isend=false;
        for(int i=0;i<26;i++){
            root->children[i]=NULL;
        }
        return root;
    };
    void insert(trie *root,string word){
        for(auto i:word){
            if(root->children[i]==NULL){
                root->children[i]=getnode();
            }
            root=root->children[i];
        }
        root->isend=true;
    }
    void dfs(vector<vector<char>>& board,int i,int j,trie* root,string word,int index){
        if(board[i][j]=='#' || root==NULL ) return ;
        
        if(board[i][j]==word[index]){
            char ch=board[i][j];
            if(root->children[ch]!=NULL){
                //cout<<ch<<" "<<index<<" "<<word.size()<<endl;;
                if(index==word.size()-1){
                    //cout<<flag;
                    root=root->children[ch];
                    if(root!=NULL && root->isend==true) flag=true;   //if word find check last letter
                    //return ;                                       //root and isend
                }
                else{
                    root=root->children[ch];
                }
            }
        }
        else return ;
        char ch=board[i][j];
        board[i][j]='#';            //given The same letter cell may not be used more than once
        if(i>0) dfs(board,i-1,j,root,word,index+1);
        if(j>0) dfs(board,i,j-1,root,word,index+1);
        if(i<board.size()-1) dfs(board,i+1,j,root,word,index+1);
        if(j<board[0].size()-1) dfs(board,i,j+1,root,word,index+1);
        board[i][j]=ch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        trie *root=new trie();
        insert(root,word);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board,i,j,root,word,0);
            }
        }
        return flag;
    }
};
