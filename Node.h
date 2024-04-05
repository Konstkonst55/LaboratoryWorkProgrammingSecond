#pragma once

#ifndef NODE_H
#define NODE_H

#include "Student.h"

struct Node {
    Student student;
    Node* next = nullptr;
};

struct DoubleNode {
    Student student;
    DoubleNode* next = nullptr;
    DoubleNode* prev = nullptr;
};

struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Student& s) : student(s), left(nullptr), right(nullptr) { }
};
#endif // !NODE_H
