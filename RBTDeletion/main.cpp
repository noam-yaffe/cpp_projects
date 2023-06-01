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
Node* remove(Node* current, int num);
void deletionFix(Node* current, Node* parent);
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
            root = remove(root, actionNumber);
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

Node* remove(Node* current, int num) {
    if (current == NULL) {
        return current;
    }
    //searching for the node recursively
    if (num > current->data) {
        current->right = remove(current->right, num);
        return current;
    }
    if (num < current->data) {
        current->left = remove(current->left, num);
        return current;
    }
    //node has been found
    else {
        if (current->right == NULL && current->left == NULL) {//no children
            if (current == root) {
                delete current;
                return NULL;
            }
            if (current->color == 'R') {//current is red
                delete current;
                return NULL;
            }
            else {//current is black, double-black node
                Node* temp = current->right;
                delete current;
                deletionFix(temp, temp->parent);
                return temp;
            }
            return current;
        }
        //one right child
        else if (current->left == NULL) {//one right child
            if (current->color == 'R') {//current is red
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else {//current is black
                if (current->right->color == 'R') {//child is red
                    Node* temp = current->right;
                    delete current;
                    temp->color = 'B';
                    return temp;
                }
                else {//double-black node, initiate deletion cases
                    Node* temp = current->right;
                    delete current;
                    deletionFix(temp, temp->parent);
                    return temp;
                }
            }
            return current;
        }
        //one left child
        else if (current->right == NULL) {//one left child
            if (current->color == 'R') {//current is red
                Node* temp = current->left;
                delete current;
                return temp;
            }
            else {//current is black
                if (current->left->color == 'R') {//child is red
                    Node* temp = current->left;
                    delete current;
                    temp->color = 'B';
                    return temp;
                }
                else {//double-black node, intiate deletion cases
                    Node* temp = current->left;
                    delete current;
                    deletionFix(temp, temp->parent);
                    return temp;
                }
            }
            return current;
        }
        //two children
        else {
            Node* succParent = current;
            Node* succ = current->left;
            //find node to replace current with
            while (succ->right != NULL) {
                succParent = succ;
                succ = succ->right;
            }
            if (succParent != current) {
                succParent->right = succ->left;
                //check if we need to call deletionCheck method
                if (succ->color == 'B') {//successor was black
                    if (succParent->right != NULL && succParent->right->color == 'R') {//make sure the node is black
                        succParent->right->color = 'B';
                    }
                    else {//double-black node situation
                        deletionFix(succParent->right, succParent);
                    }
                }
            }
            //current's left is the replacement
            else {
                succParent->left = succ->left;
                //check if we need to call deletionCheck method
                if (succ->color == 'B') {//successor was black
                    if (succParent->left != NULL && succParent->left->color == 'R') {//make sure the node is black
                        succParent->left->color = 'B';
                    }
                    else {//double-black node situation
                        deletionFix(succParent->left, succParent);
                    }
                }
            }
            current->data = succ->data;
            delete succ;
            return current;
        }
    }
    return current;

}

void deletionFix(Node* current, Node * parent) {//current is the double-black node

    Node* sibling = NULL;

    if (current == root) {//case 1, double-black node is the root
        return;
    }
    else {
        //Node* parent = current->parent;
        if (parent->left == current) {
            sibling = parent->right;
        }
        else {
            sibling = parent->left;
        }
        //sibling = findSibling(current);
        if (sibling != NULL) {
            if (sibling->color == 'R' && parent->color == 'B') {//case 2, sibling is red, current & parent are black
                sibling->color = 'B';
                parent->color = 'R';
                if (isRightChild(sibling)) {
                    rotateLeft(parent);
                    //sibling = current->parent->right;//needs to be current->parent->right?
                }
                else {
                    rotateRight(parent);
                    //sibling = current->parent->left;//needs to be current->parent->left?
                }
            }
            if (sibling->color == 'B' && parent->color == 'B' && (sibling->left == NULL || sibling->left->color == 'B') && (sibling->right == NULL || sibling->right->color == 'B')) {//case 3, sibling, current, parent, and sibling's children are black
                sibling->color = 'R';
                deletionFix(parent, parent->parent);//needs to be current->parent?
            }
            else if (parent->color == 'R' && sibling->color == 'B' && (sibling->left == NULL || sibling->left->color == 'B') && (sibling->right == NULL || sibling->right->color == 'B')) {//case 4, parent is red, sibling and both its children are black
                parent->color = 'B';
                sibling->color = 'R';
                return;
            }
            else if (isLeftChild(sibling) && sibling->color == 'B' && (sibling->left == NULL || sibling->left->color == 'B') && sibling->right != NULL && sibling->right->color == 'R') {//case 5, sibling and its left child are black, sibling's right child is red, and current is a right child
                sibling->color = 'R';
                sibling->right->color = 'B';
                rotateLeft(sibling);
                //sibling = current->parent->left;
            }
            else if (isRightChild(sibling) && sibling->color == 'B' && (sibling->right == NULL || sibling->right->color == 'B') && sibling->left != NULL && sibling->left->color == 'R') {//case 5, sibling and its right child are black, sibling's left child is red, and current is a left child
                sibling->color = 'R';
                sibling->left->color = 'B';
                rotateRight(sibling);
                //sibling = current->parent->right;
            }
            if (sibling->color == 'B' && isLeftChild(sibling) && sibling->left != NULL && sibling->left->color == 'R') {//case 6, sibling is black, sibling's left child is red, and current is black
                sibling->color = parent->color;
                parent->color = 'B';
                rotateRight(parent);
                return;
            }
            else if (sibling->color == 'B' && isRightChild(sibling) && sibling->right != NULL && sibling->right->color == 'R') {//case 6, sibling is black, sibling's right child is red, and current is black
                sibling->color = parent->color;
                parent->color = 'B';
                rotateLeft(parent);
                return;
            }
        }
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
