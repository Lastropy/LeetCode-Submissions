class node {
private: 
    node* next[26] = {NULL};
    bool is_word = false;
public:
    bool doesExist(char c){
        return !!(this -> next[c]);
    }
    
    void makeExist(char c){
        this -> next[c] = new node();
    } 
    
    node* moveForward(char c){
        return this -> next[c];
    }
    void isWord(){
        this -> is_word = true;
    }
    
    bool checkIfWord(){
        return this -> is_word;
    }
    
};


class Trie {
private:
    node* curr;
    bool find(string &s, bool checkForPrefix = true){
        auto temp = this -> curr;
        for(char c: s){
            if(!temp-> doesExist(c - 'a'))
                return false;
            temp = temp -> moveForward(c - 'a');
        }
        return (checkForPrefix ? true:  temp -> checkIfWord());
    }
public:
    Trie() {
        this -> curr = new node();
    }
    
    void insert(string s) {
        auto temp = this -> curr;
        for(char c: s){
            if(!temp-> doesExist(c - 'a'))
                temp -> makeExist(c- 'a');
            temp = temp -> moveForward(c - 'a');
        }
        temp -> isWord();
    }
    
    bool search(string s) {
         return this -> find(s , false);
    }
    
    bool startsWith(string s) {
          return this -> find(s);
    }
};