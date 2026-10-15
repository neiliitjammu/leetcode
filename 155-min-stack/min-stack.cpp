class MinStack {
public:
    
    int size = 0;
    int Top = -1;
    vector<int> stack;
    int min = INT_MAX;
    vector<int> mini;

    MinStack() {
        
    }
    
    void push(int value) {
       
        Top++;
        size++;
        stack.push_back(value);
        if(value <= min)
        {
            min = value;
            mini.push_back(value);
        }
    }
    
    void pop() {
        if(Top != -1 and stack[Top] == mini[mini.size() - 1])
        {
            Top--;
            stack.pop_back();
            mini.pop_back();
            if(mini.empty())
            {
                min = INT_MAX;
            }
            else
            {
                min = mini[mini.size() - 1];
            }
            size--;
            return;
        }
        
        else if(Top != -1)
        {
            Top--;
            size--;
            stack.pop_back();
            return;
        }
        return;

    }
    
    int top() {
        return stack[Top];
    }
    
    int getMin() {
        return mini[mini.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */