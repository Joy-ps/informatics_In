#include <bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> inStack;  
    stack<int> outStack; 
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    void push(int x) {
        inStack.push(x);
    }
    int pop() {
        shiftStacks();
        int frontVal = outStack.top();
        outStack.pop();
        return frontVal;
    }
    int peek() {
        shiftStacks();
        return outStack.top();
    }
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};