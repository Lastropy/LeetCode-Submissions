class node {
public: 
    node* next[26] = {NULL};
    bool is_word = false;
};

class Trie {
private:
    node* curr;
public:
    Trie() {
        this -> curr = new node();
    }
    
    void insert(string s) {
        auto temp = this -> curr;
        for(int i=0; i < s.size(); i++){
            if(!temp-> next[s[i] - 'a'])
                temp -> next[s[i] - 'a'] = new node();
            temp = temp -> next[s[i] - 'a'];
        }
        temp -> is_word = true;
    }
    
    bool search(string s) {
        auto temp = this -> curr;
        for(int i = 0; i < s.size(); i++){
            if(!temp -> next[s[i] -'a'])
                return false;
            temp = temp -> next[s[i]  - 'a'];
        }
        return temp -> is_word;
    }
    
    bool startsWith(string s) {
        auto temp = this -> curr;
        for(int i = 0; i < s.size(); i++){
            if(!temp -> next[s[i] -'a'])
                return false;
            temp = temp -> next[s[i]  - 'a'];
        }
        return true;
    }
};