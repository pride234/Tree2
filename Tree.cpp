//
// Created by LIFE on 13.05.2015.
//
#include "Tree.h"
#include <stdio.h>


//---------------------------------------------------------------------------
//--------------------------------ÊÎÍÑÒÐÓÊÒÎÐÛ-------------------------------
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
//--------------------------ÄÎÁÀÂËÅÍÈÅ ÓÇËÀ----------------------------------
//---------------------------------------------------------------------------

void Tree::AddNode(int l) {
	if (root == 0) {
		Node* node = new Node();
		root = node;
		root->EnterRootValue(l);
		root->EnterValue(l);
	}
	else if (root->GetRootValue() <= l) {
		if (!root->GetRight()) {
			Node* node = new Node;
			node->EnterValue(l);
			root->SetRight(node);
		}
		else root->GetRight()->Add(l);
	}
	else if (root->GetRootValue() > l) {
		if (!root->GetLeft()) {
			Node* node = new Node;
			node->EnterValue(l);
			root->SetLeft(node);
		}
		else root->GetLeft()->Add(l);
	}
}

//---------------------------------------------------------------------------
//---------------------------ÏÎÈÑÊ-------------------------------------------
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
//--------------------------------ÓÄÀËÅÍÈÅ, ÄÅÑÒÐÓÊÒÎÐ-----------------------
//---------------------------------------------------------------------------

void Tree::DelNode(int D) {
	Node* tmp = Search(D);
	if (tmp == 0) {
		printf("There's no Node with your number");
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
	if (root) KillChildren(root);
}

//---------------------------------------------------------------------------
//----------------------------ÏÅÐÅÃÐÓÇÊÈ-------------------------------------
//---------------------------------------------------------------------------

Tree &Tree::operator=(const Tree &T) {
	KillChildren(root);
	root = T.root;
	if (root->GetRight() != 0) CopyTree(root->GetRight());
	if (root->GetLeft()  != 0) CopyTree(root->GetLeft());
	return *this;
}

//---------------------------------------------------------------------------

ostream& operator << (ostream &s, const Tree &T) {
	print_Tree(T.root, 0, s);
	return s;
}


//---------------------------------------------------------------------------

istream& operator>>(istream& s, Tree& T) {
	string i;
	cout << "Do you want to add new node? Enter 0 or 1: ";
	cin >> i;
	if (i != "0" && i != "1") {
		while (i != "0" && i != "1") {
			cout << "Wrong! Try again: ";
			i = "";
			cin >> i;
		}
	}
	while (i == "1") {
		int v;
		cout << "Enter the node value: ";
		cin >> v;
		T.AddNode(v);
		cout << "Do you want to add new node? Enter 0 or 1: ";
		cin >> i;
		if (i != "0" && i != "1") {
			while (i == "0" || i == "1") {
				cout << "Wrong! Try again: ";
				i = "";
				cin >> i;
			}
		}
	}
	cout << "Bye" << endl;

}
//---------------------------------------------------------------------------
//----------------------ÄÎÏ. ÔÓÍÊÖÈÈ-----------------------------------------
//---------------------------------------------------------------------------

void print_Tree(Node* p, int level, ostream& s) {
	if(p){
		print_Tree(p->GetLeft(),level + 1, s);
		for(int i = 0;i< level;i++) cout << " ";
		s <<  p->GetValue() << endl;
		print_Tree(p->GetRight(), level + 1, s);
	}
}