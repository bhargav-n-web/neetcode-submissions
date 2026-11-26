class Trie{
    public:
        Trie* trie[26];
        bool isEnd;
        Trie(){
            for(int i=0;i<26;i++){
                trie[i]=nullptr;}
            isEnd=false;
        }
};
class PrefixTree {
public:
    Trie* root;
    PrefixTree() {
      root=new Trie();  
    }
    void insert(string word) {
        Trie* curr=root;
        for(char c:word){
            int index=c-'a';
            if(curr->trie[index]==nullptr)
                curr->trie[index]=new Trie();
            curr=curr->trie[index];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Trie* curr=root;
        for(char ch:word){
            int index=ch-'a';
            curr=curr->trie[index];
            if(curr==nullptr){
                return false;
            }
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* curr=root;
        for(char ch:prefix){
            int index=ch-'a';
            curr=curr->trie[index];
            if(curr==nullptr){
                return false;
            }
        }
        return true;
    }
};
