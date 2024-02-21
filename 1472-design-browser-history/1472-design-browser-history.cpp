class node {
    public:
        string url;
        node *next;
        node *prev;
        node(string homepage){
            this -> url = homepage;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

class BrowserHistory {
public:
    node *history;
    BrowserHistory(string homepage) {
        history = new node(homepage);
    }
    
    void visit(string url) {
        auto temp = new node(url);
        temp -> prev = history;
        history -> next = temp;
        history = temp;
    }
    
    string back(int steps) {
        while(history -> prev && steps){
            history = history -> prev;
            steps--;
        }
        return history -> url;
    }
    
    string forward(int steps) {
        while(history -> next && steps){
            history = history -> next;
            steps--;
        }
        return history -> url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */