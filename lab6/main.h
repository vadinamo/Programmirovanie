#ifndef LAB6_MAIN_H
#define LAB6_MAIN_H

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

int Length(char* text);

struct tree* treeBuilder(int n);

void Print(struct tree* root);

void Fill(struct tree* root);

int Remove(struct tree* root);

void Task(struct tree* root, char* input, int height);

#endif
