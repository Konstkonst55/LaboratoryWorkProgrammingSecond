#pragma once

#ifndef LAB9_H
#define LAB9_H

#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "Node.h"
using namespace std;

class SLLStudents {
private:
	Node* _head;

public:
	SLLStudents();
	~SLLStudents();

	void addStudent(const Student&);
	void sort();
	void print();
};

class DLLStudents {
private:
	DoubleNode* _head;
	DoubleNode* _tail;

public:
	DLLStudents();
	~DLLStudents();

	void addStudent(const Student&);
    void removeStudents();
    void print();
};

class BinaryTree {
private:
	TreeNode* _root;

	void _deleteTree(TreeNode*);
	void _insert(TreeNode*&, const Student&);
	void _print(TreeNode*);
	void _printReverse(TreeNode*);
	TreeNode* _find(TreeNode*, const string&);

public:
	BinaryTree();
	~BinaryTree();

	void addStudent(const Student&);
	void print(bool = true);
	TreeNode* find(const string&);
};

#endif // !LAB9_H