//
// Created by LIFE on 13.05.2015.
//
#include "Tree.h"
#include <stdio.h>


//---------------------------------------------------------------------------

Tree::Tree() {
    root = 0;
}
//---------------------------------------------------------------------------

Tree::Tree(Tree &T) {
	Node* root = T.root;
	if (root->GetRight() != 0) CopyTree(root->GetRight());
	if (root->GetLeft()  != 0) CopyTree(root->GetLeft());
}
//---------------------------------------------------------------------------

Node* Tree::CopyTree(Node *tmp1) {
	if (tmp1 == 0) return 0;
	Node* newnode = new Node;
	newnode->EnterValue(tmp1->GetValue());
	newnode->SetLeft(CopyTree(tmp1->GetLeft()));
	newnode->SetRight(CopyTree(tmp1->GetRight()));
	return newnode;
}
//---------------------------------------------------------------------------

void Tree::AddNode(int l) {
	if (root == 0) {
		Node* node = new Node();
		root = node;
		root->EnterRootValue(l);
	}
	else if (root->GetRootValue() <= l) {
		if (!root->GetRight()) {
			Node* node = new Node;
			node->EnterValue(l);
			root->SetRight(node);
		}
		else Add(root->GetLeft(), l);
	}
	else if (root->GetRootValue() > l) {
		if (!root->GetLeft()) {
			Node* node = new Node;
			node->EnterValue(l);
			root->SetLeft(node);
		}
		else Add(root->GetLeft(), l);
	}
}
//---------------------------------------------------------------------------
void Tree::Add(Node *tmp2, int k) {
	if (tmp2->GetValue() <= k) {
		if (tmp2->GetRight()) Add(tmp2->GetRight(), k);
		else {
			Node* node = new Node;
			node->EnterValue(k);
			tmp2->SetRight(node);
		}
	}
	else if (tmp2->GetValue() > k) {
		if (tmp2->GetLeft()) Add(tmp2->GetLeft(), k);
		else {
			Node* node = new Node;
			node->EnterValue(k);
			tmp2->SetLeft(node);
		}
	}
}
//---------------------------------------------------------------------------

/*bool Tree::AddNode(int k) {
    if (root == 0) {
        Node *node = new Node;
        node->EnterValue(k);
        root = node;
        return true;
    }
    if (root->GetValue() <= k) {
        if (root->GetRight()) {
            return Add(root->GetRight(), k);
        }
        else {
            Node* node = new Node;
            node->EnterValue(k);
			root->SetRight (node);
            return 1;
        }
    }
    else if (root->GetValue() > k){
        if (root->GetLeft()) {
			Node* node = root->GetLeft();
            return Add(node, k);
        }
        else{
            	Node* node = new Node;
				node->EnterValue(k);
				root->SetLeft(node);
				return 1;
			}
		}
}*/
//---------------------------------------------------------------------------

/*bool Tree::Add(Node *tmp2, int l) {
		if (tmp2->GetValue() <= l) {
				if (tmp2->GetRight()) {
						return Add(tmp2->GetRight(), l);
				}
				else {
						Node *node = new Node;
						node->EnterValue(l);
						tmp2->SetRight(node);
						return 1;
				}
		}
		else if (tmp2->GetValue() > l) {
				if (tmp2->GetLeft()) {
						return Add(tmp2->GetLeft(), l);
				}
				else {
						Node *node = new Node;
						node->EnterValue(l);
						tmp2->SetLeft(node);
						return 1;
				}
		}
}*/
//---------------------------------------------------------------------------
Node* Tree::Search(int s) {
	if (root->GetRootValue() == s) return root;
	if (root->GetRootValue() > s) {
		if (root->GetRight() != 0) {
			return search(root->GetRight(), s);
		}
		else return 0;
	}
	else {
		if (root->GetLeft() != 0) {
			return search(root->GetLeft(), s);
		}
		else return 0;
	}
}
//---------------------------------------------------------------------------
Node* Tree::search(Node* tmp, int v) {
	if (tmp->GetValue() == v) return tmp;
	if (tmp->GetValue() > v) {
		if (tmp->GetRight() != 0) {
			return search(tmp->GetRight(), v);
		}
		else return 0;
	}
	else {
		if (tmp->GetLeft() != 0) {
			return search(tmp->GetLeft(), v);
		}
		else return 0;
	}
}
//---------------------------------------------------------------------------
void Tree::DelNode(int D) {
	Node* tmp = Search(D);
	if (tmp == 0) {
		printf("There's no NOde with your number");
		return;
	}
	if (tmp->GetRight() != 0) {
		KillChildren(tmp->GetRight());

	}
	if (tmp->GetLeft() != 0){
		KillChildren(tmp->GetLeft());
	}
	delete tmp;
}
//---------------------------------------------------------------------------
void Tree::KillChildren(Node *tmp3) {
	if (tmp3->GetRight() != 0) KillChildren(tmp3->GetRight());
	if (tmp3->GetLeft()  != 0) KillChildren(tmp3->GetLeft());
	delete tmp3;
}
//---------------------------------------------------------------------------
Tree::~Tree() {
	KillChildren(root);
}
Tree &Tree::operator=(const Tree &T) {
	KillChildren(root);
	root = T.root;
	if (root->GetRight() != 0) CopyTree(root->GetRight());
	if (root->GetLeft()  != 0) CopyTree(root->GetLeft());
	return *this;
}

void print_Tree(Node* p, int level, ostream& s)
{
	if(p)
	{
		print_Tree(p->GetLeft(),level + 1, s);
		for(int i = 0;i< level;i++) cout << " ";
		s <<  p->GetValue() << endl;
		print_Tree(p->GetRight(), level + 1, s);
	}
}
ostream& operator<<(ostream &s, const Tree &T) {
	print_Tree(T.root, 0, s);
	return s;
}

