//
// Created by LIFE on 13.05.2015.
//

#ifndef LAB2_TREE_H
#define LAB2_TREE_H
#include "Node.h"
#include <iostream>
using namespace std;


class Tree {
    private:
        Node* root;
    public:
        Tree();
        Tree (int c)    {Tree* T = new Tree [c];}
        Tree(Tree& T);
        Node* CopyTree (Node* tmp1);
        void AddNode (int l);
        void Add (Node* tmp2, int k);
        Node* Search(int s);
	    Node* search (Node* tmp, int v);
        void DelNode (int D);
        void KillChildren (Node* tmp3);
        Tree& operator = (const Tree& T);
        friend ostream& operator << (ostream& s, const Tree& T);
        friend istream& operator >> (istream& s, Tree& T);
    ~Tree();

};

void print_Tree(Node* p, int level, ostream& s);

#endif //LAB2_TREE_H
