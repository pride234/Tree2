//
// Created by LIFE on 13.05.2015.
//

#include "Node.h"

Node::Node() {
    left = 0;
    right = 0;
}
//---------------------------------------------------------------------------

Node::Node(Node &N) {
    right = N.right; left = N.left; value = N.GetValue();
}
//---------------------------------------------------------------------------

Node::Node(int c) {
    Node* multinode = new Node[c];
}

//---------------------------------------------------------------------------

void Node::SetLeft(Node *tmp) {
    left = tmp;
}

//---------------------------------------------------------------------------

Node *Node::GetRight() {
    return right;
}

//---------------------------------------------------------------------------

Node *Node::GetLeft() {
    return left;
}

//---------------------------------------------------------------------------

void Node::SetRight(Node *tmp) {
    right = tmp;
}

//---------------------------------------------------------------------------

void Node::EnterRootValue(int V) {
    rootvalue = V;
}

//---------------------------------------------------------------------------

int Node::GetRootValue() {
    return rootvalue;
}

//---------------------------------------------------------------------------

int Node::GetValue() {
    return value;
}

//---------------------------------------------------------------------------

void Node::EnterValue(int svalue) {
    value = svalue;
}

//---------------------------------------------------------------------------

void Node::Add(int k) {
    if (this->GetValue() <= k) {
        if (this->GetRight()) this->GetRight()->Add(k);
        else {
            Node* node = new Node;
            node->EnterValue(k);
            this->SetRight(node);
        }
    }
    else if (this->GetValue() > k) {
        if (this->GetLeft()) this->GetLeft()->Add(k);
        else {
            Node* node = new Node;
            node->EnterValue(k);
            this->SetLeft(node);
        }
    }
}
//---------------------------------------------------------------------------
