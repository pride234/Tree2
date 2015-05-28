#include <conio.h>
#include "TREE.h"


using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Tree* T1 = new Tree;
    cin >> *T1;
    cout << *T1;
    delete T1;
    getch();
    return 0;
}