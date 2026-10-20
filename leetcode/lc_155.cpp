class MinStack {
public:
    MinStack() {}
    
    void push(int value) {
        if (minStack.empty()) {
            minStack.push_back({value, value});
        }
        else {
            minStack.push_back({value, min(value, minStack.back().second)});
        }
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back().first;
    }
    
    int getMin() {
        return minStack.back().second;
    }

private:

    vector<pair<int, int>> minStack;    // <value, minimum_so_far>
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
