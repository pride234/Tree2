//
// Created by LIFE on 13.05.2015.
//

#ifndef LAB2_NODE_H
#define LAB2_NODE_H



class Node {
private:
    int value;
    int rootvalue;
    Node* left;
    Node* right;
public:
    Node();
    Node (int c)    {Node* multinode = new Node[c];}
    Node (Node& N)  {right = N.right; left = N.left; value = N.GetValue();}
    void EnterValue (int svalue) { value = svalue;}
    int GetValue() {return value;}
    int GetRootValue() {return rootvalue;}
    void EnterRootValue(int V) {rootvalue = V;};
    void SetRight(Node* tmp) {
        right = tmp;
    }
    void SetLeft (Node* tmp){
        left = tmp;
    }
    Node* GetRight () {
        return right;
    }
    Node* GetLeft () {
        return left;
    }
};



#endif //LAB2_NODE_H
