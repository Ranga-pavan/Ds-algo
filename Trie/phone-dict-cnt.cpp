struct trie{
    int cnt=0;
    struct trie *children[26];
};
struct trie *getnode(void){
    trie *root=new trie();
    root->cnt=0;
    for(int i=0;i<26;i++){
        root->children[i]=NULL;
    }
    return root;
};
void insert(trie *temp,string word){
    trie *root=temp;
    int k=word.size();
    for(int i=0;i<k;i++){
        if(root->children[word[i]-'a']==NULL){
            root->children[word[i]-'a']=getnode();
        }
        root=root->children[word[i]-'a'];
        root->cnt++;
    }
    
}
int search(trie *temp,string word){
    trie *root=temp;
    int k=word.size();
    for(int i=0;i<k;i++){
        if(root->children[word[i]-'a']==NULL){
            return 0;
        }
        root=root->children[word[i]-'a'];
    }
    return root->cnt;
}
vector<int> contacts(vector<vector<string>> queries) {
    trie *root=new trie();
    vector<int> res;
    int k=queries.size();
    for(int i=0;i<k;i++){
        if(queries[i][0]=="add") insert(root,queries[i][1]);
        else{
            
            int k=search(root,queries[i][1]);
            res.push_back(k);
        }
    }
    return res;
}
