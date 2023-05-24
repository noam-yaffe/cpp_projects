#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

void fileGenerator();
void manualGenerator();
void insert(Node*& current, int num);
void print(Node* current, int layer);
void search(Node* current, int number);
void recolor(Node*& current);
void checkForCases(Node*& current);
Node* remove(Node*& z);
void deletionFix(Node*& current);
Node* lookFor(int num);
Node* findSuccessor(Node* current);
void transplant(Node*& current, Node*& replacement);
Node* findSibling(Node* current);
bool isRightChild(Node* current);
bool isLeftChild(Node* current);
void redUncleRightParent(Node*& current);
void redUncleLeftParent(Node*& current);
Node* rotateRight(Node* x);
Node* rotateLeft(Node* x);

Node* root = NULL;

int main() {

    char input[20];
    int answer = 0;
    bool cont = false;

    cout << endl;
    cout << "Welcome to Binary Search Tree!" << endl;

    do {
        cout << endl;
        cout << "Type 1 to generate the numbers with a file (automatically generates 10 random numbers), type 2 to generate them manually\
: ";
        cin >> answer;
        cin.get();
        //generate through file input
        if (answer == 1) {
            fileGenerator();
            cont = true;
        }
        //generate through user input
        else if (answer == 2) {
            manualGenerator();
            cont = true;
        }
        //invalid input
        else {
            cout << endl;
            cout << "You didn't enter a valid choice! Try again." << endl;
        }
    } while (!cont);

    cout << endl;
    print(root, 0);

    cout << endl;
    cout << "Here are the commands you can use:" << endl;
    cout << "Type \"ADD\" to add a number to the tree." << endl;
    cout << "Type \"PRINT\" to print out the tree." << endl;
    cout << "Type \"SEARCH\" to search for a particular number in the tree." << endl;
    cout << "Type \"DELETE\" to delete a particular number from the tree." << endl;
    cout << "Type \"QUIT\" to end the program." << endl;

    int actionNumber = 0;

    //commands
    do {
        cout << endl;
        cout << "Enter a command: ";
        cin.get(input, 20);
        cin.get();
        //add a number
        if (strcmp(input, "ADD") == 0) {
            cout << endl;
            cout << "Enter the number you want to add: ";
            cin >> actionNumber;
            cin.get();
            insert(root, actionNumber);
            cout << "Number has been added!" << endl;
        }
        //print out the tree
        else if (strcmp(input, "PRINT") == 0) {
            cout << endl;
            print(root, 0);
        }
        //search for a number in the tree
        else if (strcmp(input, "SEARCH") == 0) {
            cout << endl;
            cout << "Enter the number you want to search for: ";
            cin >> actionNumber;
            cin.get();
            search(root, actionNumber);
        }
        //delete a number from the tree
        else if (strcmp(input, "DELETE") == 0) {
            cout << endl;
            cout << "Enter the number you want to delete: ";
            cin >> actionNumber;
            cin.get();
            Node* current = lookFor(actionNumber);
            if (current == NULL) {
                cout << "Your number isn't in the tree." << endl;
            }
            else {
                current = remove(current);
            }
        }
        //end the program
        else if (strcmp(input, "QUIT") == 0) {
            cout << endl;
            cout << "The program has ended." << endl;
        }
        else {
            cout << "You didn't enter a valid command. Try again." << endl;
        }
    } while (strcmp(input, "QUIT") != 0);

}

//generate initial binary tree via random file input
void fileGenerator() {

    cout << "file generation..." << endl;

    ifstream numbers("numbers.txt");
    srand(time(NULL));
    int num = 0;

    while (!numbers.eof()) {
        numbers >> num;
        insert(root, num);
    }

    cout << endl;

}

//generate initial binary tree via by user input
void manualGenerator() {

    int input = 0;
    int counter = 0;

    cout << endl;
    cout << "You will be prompted to manually enter numbers one-by-one." << endl;
    cout << "You can terminate the loop by entering the number -1, but it automatically ends after you've entered a total of 50 numbers\
." << endl;

    while (input != 0 || counter < 50) {
        cout << endl;
        cout << "Enter a number: ";
        cin >> input;
        if (input == -1) {
            break;
        }
        else {
            insert(root, input);
            cout << endl;
            cout << "Number has been entered into the tree!" << endl;
            counter++;
        }
    }

    cin.get();

}

//add data into the tree
void insert(Node*& current, int num) {

    if (current == NULL) {//root is NULL
        current = new Node(num, NULL, NULL, NULL, 'B');
        root = current;
        return;
    }
    //greater than or equal to the current node
    if (num >= current->data) {
        if (current->right == NULL) {
            current->right = new Node(num, NULL, NULL, current, 'R');
            checkForCases(current->right);
            return;
        }
        else {
            insert(current->right, num);
        }
    }
    //less than the current node
    else {
        if (current->left == NULL) {
            current->left = new Node(num, NULL, NULL, current, 'R');
            checkForCases(current->left);
            return;
        }
        else {
            insert(current->left, num);
        }
    }

}

//print out the tree (using the inOrder traversal algorithm)
void print(Node* current, int layer) {

    if (current == NULL) {
        return;
    }

    print(current->right, layer + 1);

    for (int i = 0; i < layer; i++) {
        cout << "    ";
    }

    cout << current->data << current->color << endl;

    print(current->left, layer + 1);

}

void search(Node* current, int num) {

    if (current == NULL) {//reached the end of the tree
        cout << "Your number is not in the tree." << endl;
        return;
    }
    else if (current->data == num) {//number has been found
        cout << "Your number is in the tree!" << endl;
        return;
    }
    else {//continue traversing down the tree
        if (num > current->data) {
            search(current->right, num);
        }
        else {
            search(current->left, num);
        }
    }

}

//recolors current (R --> B, B --> R)
void recolor(Node*& current) {

    if (current->color == 'R') {//change from red to black
        current->color = 'B';
    }
    else {//change from black to red
        current->color = 'R';
    }

}

//checks all cases every time a node is added
void checkForCases(Node*& current) {

    if (current == NULL || current->parent == NULL || current->parent->parent == NULL) {//base case, no grandparent-->no uncle-->no cases to check for
        return;
    }

    Node* grandparent = current->parent->parent;

    if (grandparent->right == current->parent) {//right parent
        Node* uncle = grandparent->left;
        if ((uncle != NULL) && (uncle->color == 'R')) {//uncle is red
            redUncleRightParent(current);
            checkForCases(grandparent);
        }
        else if (((uncle == NULL) || (uncle->color == 'B')) && current->parent->color == 'R') {//black uncle cases
            if (current->parent->left == current) {//current is a left child, parent is a right child (triangle case)
                Node* temp = rotateRight(current->parent);
                checkForCases(temp->right);
            }
            else {//current is a right child, parent is a right child (line case)
                recolor(current->parent);
                recolor(grandparent);
                Node* temp = rotateLeft(current->parent->parent);
                checkForCases(grandparent);
            }
        }
        if (root->color == 'R') {
            recolor(root);
        }
        return;
    }
    else {//left parent
        Node* uncle = grandparent->right;
        if ((uncle != NULL) && (uncle->color == 'R')) {//uncle is red
            redUncleLeftParent(current);
            checkForCases(grandparent);
        }
        else if (((uncle == NULL) || (uncle->color == 'B')) && current->parent->color == 'R') {//black uncle cases
            if (current->parent->right == current) {//current is a right child, parent is a left child (triangle case)
                Node* temp = rotateLeft(current->parent);
                checkForCases(temp->left);
            }
            else {//current is a left child, parent is a left child (line case)
                recolor(current->parent);
                recolor(grandparent);
                Node* temp = rotateRight(current->parent->parent);
                checkForCases(grandparent);
            }
        }
        if (root->color == 'R') {//always make sure the root is black
            recolor(root);
        }
        return;
    }

}

Node* remove(Node*& z) {

    //KEY: z = current, y = successor of current, x = child (of either current or successor)

    Node* y = z;
    char y_og_color = y->color;
    Node* x = NULL;

    if (z->left == NULL) {//case 1
        x = z->right;
        transplant(z, x);
    }
    else if (z->right == NULL) {//case 2
        x = z->left;
        transplant(z, x);
    }
    else {//case 3
        y = findSuccessor(z->right);
        y_og_color = y->color;
        x = y->right;

        if (y->parent == z && x != NULL) {
            if (x != NULL) {
                x->parent = y;
            }
        }
        else {
            transplant(y, x);
            y->right = z->right;
            if (x != NULL) {
                y->right->parent = y;
            }
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;

    }

    if (y_og_color == 'B') {
        deletionFix(x);
    }

    return x;

}

void deletionFix(Node*& x) {//current is the double-black node

  //KEY: x = double-black node, w = x's sibling

    while (x != root && x->color == 'B') {

        if (x->parent->left == x) {//x is a left child

            Node* w = x->parent->right;
            if (w->color == 'R') {//deletion fix case 1
                w->color = 'B';
                x->parent->color = 'R';
                rotateLeft(x->parent);
                w = x->parent->right;//I see an issue with this... I want the pointer to POINT to the new x's sibling, not replace itself
            }
            if (w->left->color == 'B' && w->right->color == 'B') {//deletion fix case 2
                w->color = 'R';
                x = x->parent;
            }
            else {
                if (w->right->color == 'B') {//deletion fix case 3
                    w->left->color = 'B';
                    w->color = 'R';
                    rotateRight(w);
                    w = x->parent->right;
                }//deletion fix case 4
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->right->color = 'B';
                rotateLeft(x->parent);
                x = root;
            }

        }
        else {

            Node* w = x->parent->left;
            if (w->color == 'R') {//deletion fix case 1
                w->color = 'B';
                x->parent->color = 'R';
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') {//deletion fix case 2
                w->color = 'R';
                x = x->parent;
            }
            else {
                if (w->left->color == 'B') {//deletion fix case 3
                    w->right->color = 'B';
                    w->color = 'R';
                    rotateLeft(w);
                    w = x->parent->left;
                }//deletion fix case 4
                w->color = x->parent->color;
                x->parent->color = 'B';
                w->left->color = 'B';
                rotateRight(x->parent);
                x = root;
            }

        }

    }

    if (x != NULL) {
        x->color = 'B';
    }

}

void transplant(Node*& current, Node*& replacement) {

    if (current->parent == NULL) {
        root = replacement;
    }
    else if (current == current->parent->left) {
        current->parent->left = replacement;
    }
    else {
        current->parent->right = replacement;
    }

    if (replacement != NULL) {
        replacement->parent = current->parent;
    }

}

Node* lookFor(int num) {

    Node* iterator = root;

    while (iterator != NULL && iterator->data != num) {
        if (num < iterator->data) {
            iterator = iterator->left;
        }
        else {
            iterator = iterator->right;
        }
    }

    return iterator;

}

Node* findSuccessor(Node* current) {

    while (current->left != NULL) {
        current = current->left;
    }

    return current;

}

Node* findSibling(Node* current) {

    if (current->parent->left == current) {//current is a left child, sibling is the right child
        return current->parent->right;
    }
    else {//current is a right child, sibling is the left child
        return current->parent->left;
    }

}

bool isRightChild(Node* current) {

    if (current->parent->right == current) {
        return true;
    }
    return false;

}

bool isLeftChild(Node* current) {

    if (current->parent->left == current) {
        return true;
    }
    return false;

}

//recolors current's parent, grandparent, and uncle (specific to right parent)
void redUncleRightParent(Node*& current) {

    recolor(current->parent);
    recolor(current->parent->parent);
    recolor(current->parent->parent->left);

}

//recolors current's parent, grandparent, and uncle (specific to left parent)
void redUncleLeftParent(Node*& current) {

    recolor(current->parent);
    recolor(current->parent->parent);
    recolor(current->parent->parent->right);

}

//NOTE: both my "rotateRight" and "rotateLeft" algorithms were referenced from the "CodesDope" website
//https://www.codesdope.com/course/data-structures-red-black-trees-insertion/

//right rotation
Node* rotateRight(Node* current) {

    Node* leftNode = current->left;
    current->left = leftNode->right;
    if (leftNode->right != NULL) {//child's right isn't null --> parent needs to be redirected
        leftNode->right->parent = current;
    }
    leftNode->right = current;
    leftNode->parent = current->parent;
    if (current->parent == NULL) {//node will be root after rotation
        root = leftNode;
    }
    else if (current == current->parent->left) {//current is a left child
        current->parent->left = leftNode;
    }
    else {//current is a right child
        current->parent->right = leftNode;
    }
    current->parent = leftNode;

    return leftNode;

}

//left rotation
Node* rotateLeft(Node* current) {

    Node* rightNode = current->right;
    current->right = rightNode->left;
    if (rightNode->left != NULL) {//child's left isn't null --> parent needs to be redirected
        rightNode->left->parent = current;
    }
    rightNode->left = current;
    rightNode->parent = current->parent;
    if (current->parent == NULL) { //node will be root after rotation
        root = rightNode;
    }
    else if (current == current->parent->left) { //current is a left child
        current->parent->left = rightNode;
    }
    else { //current is a right child
        current->parent->right = rightNode;
    }
    current->parent = rightNode;

    return rightNode;

}
