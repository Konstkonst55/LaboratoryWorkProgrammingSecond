#include "Lab9.h"

SLLStudents::SLLStudents() : _head(nullptr) { }

SLLStudents::~SLLStudents() {
    while (_head) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    }
}

void SLLStudents::addStudent(const Student& student) {
    Node* newNode = new Node;

    newNode->student = student;
    newNode->next = _head;
    _head = newNode;
}

void SLLStudents::sort() {
    if (!_head || !_head->next) return;

    bool swapped;

    do {
        swapped = false;
        Node* current = _head;

        while (current->next) {
            if ((current->student.surname) > (current->next->student.surname)) {
                swap(current->student, current->next->student);
                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);
}

void SLLStudents::print() {
    Node* current = _head;

    while (current) {
        cout << current->student.surname << " ";

        for (int grade : current->student.grades) {
            cout << "[" << grade << "] ";
        }

        cout << endl;
        current = current->next;
    }

    cout << endl;
}

DLLStudents::DLLStudents() : _head(nullptr), _tail(nullptr) { }

DLLStudents::~DLLStudents() {
    while (_head) {
        DoubleNode* temp = _head;
        _head = _head->next;
        delete temp;
    }
}

void DLLStudents::addStudent(const Student& student) {
    DoubleNode* newNode = new DoubleNode;
    newNode->student = student;
    newNode->next = nullptr;
    newNode->prev = _tail;

    if (_tail) _tail->next = newNode;
    
    _tail = newNode;

    if (!_head) _head = _tail;
}

void DLLStudents::removeStudents() {
    DoubleNode* current = _head;

    while (current) {
        bool isBadStudent = false;

        for (int i = 0; i < 4; ++i) {
            if (current->student.grades[i] < 3) {
                isBadStudent = true;
                break;
            }
        }

        if (isBadStudent) {
            if (current->prev) current->prev->next = current->next;
            else _head = current->next;

            if (current->next) current->next->prev = current->prev;
            else _tail = current->prev;

            DoubleNode* temp = current;
            current = current->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void DLLStudents::print() {
    DoubleNode* current = _head;

    while (current) {
        cout << current->student.surname << " ";

        for (int grade : current->student.grades) {
            cout << "[" << grade << "] ";
        }

        cout << endl;
        current = current->next;
    }

    cout << endl;
}

BinaryTree::BinaryTree() : _root(nullptr) { }

BinaryTree::~BinaryTree() {
    _deleteTree(_root);
}

void BinaryTree::_deleteTree(TreeNode* node) {
    if (!node) return;
    _deleteTree(node->left);
    _deleteTree(node->right);
    delete node;
}

void BinaryTree::_insert(TreeNode*& node, const Student& s) {
    if (!node) node = new TreeNode(s);
    else if (s.surname < node->student.surname) _insert(node->left, s);
    else _insert(node->right, s);
}

TreeNode* BinaryTree::_find(TreeNode* node, const string& surname) {
    if (!node) return nullptr;

    if (node->student.surname == surname) return node;

    if (surname < node->student.surname) return _find(node->left, surname);

    return _find(node->right, surname);
}

void BinaryTree::_print(TreeNode* node) {
    if (!node) return;

    _print(node->left);

    cout << node->student.surname << endl;

    _print(node->right);
}

void BinaryTree::_printReverse(TreeNode* node) {
    if (!node) return;

    _printReverse(node->right);

    cout << node->student.surname << endl;

    _printReverse(node->left);
}

void BinaryTree::addStudent(const Student& s) {
    BinaryTree::_insert(_root, s);
}

void BinaryTree::print(bool isAsc) {
    if (isAsc) BinaryTree::_print(_root);
    else BinaryTree::_printReverse(_root);
}

TreeNode* BinaryTree::find(const string& surname) {
    return BinaryTree::_find(_root, surname);
}