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
    Node (int c);
    Node (Node& N);
    void EnterValue (int svalue);
    int GetValue();
    int GetRootValue();
    void EnterRootValue(int V);
    void SetRight(Node* tmp);
    void SetLeft (Node* tmp);
    void Add (int k);
    Node* GetRight ();
    Node* GetLeft ();
};



#endif //LAB2_NODE_H
