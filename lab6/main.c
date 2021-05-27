/*В текстовом файле содержатся n целых чисел в двоичной системе счисления (m бит каждое).
  Построить бинарное дерево, в котором числам соответствуют листья дерева, а путь по
  дереву определяется двоичным представлением числа (‘1’ – переход к правому потомку,
  ‘0’ – переход к левому потомку).
 */
#include "main.h"

int Length(char* text) {
    int length = 0;

    while(text[length] != '\0') {
        length++;
    }

    return length;
}

struct tree* treeBuilder(int n) {
    struct tree* root = (struct tree*) malloc(sizeof(struct tree));
    if(root != NULL) {
        if (n > 0) {;
            root -> right = treeBuilder(n - 1);
            root -> left = treeBuilder(n - 1);
        } else {
            root -> right = NULL;
            root -> left = NULL;
        }
        return root;
    }

    else exit(-1);
}

void Print(struct tree* root) {
    if(root -> right)
        Print(root -> right);

    printf("%d ", root -> data);

    if(root -> left)
        Print(root -> left);
}

void Fill(struct tree* root) {
    if(root -> right)
        Fill(root -> right);

    root -> data = 0;

    if(root -> left)
        Fill(root -> left);
}

int Remove(struct tree* root) {
    if (root != NULL) {
        Remove(root->left);
        Remove(root->right);
        free(root);
    }

    return 1;
}

void Task(struct tree* root, char* input, int height) {
    static int n = 0;
    if(n < height) {
        switch (input[n]) {
            case '1':
                n++;
                Task(root -> right, input, height);
                break;

            case '0':
                n++;
                Task(root -> left, input, height);
                break;
        }
    }

    if(n == height) {
        root -> data = 1;
        n = height + 1;
    }
}

#ifndef TESTING

int main() {
    FILE* file;
    char input[128];
    int height, n;

    file = fopen("/Users/vadinamo/Documents/программирование/lab6/input.txt", "r");
    if (!file) {
        printf("File open error!");
        exit(-1);
    }

    fgets(input, 128, file);
    fclose(file);

    height = Length(input);
    struct tree* root = treeBuilder(height);

    Fill(root);
    Task(root, input, height);
    Print(root);

    remove(root);
    return 0;
}

#endif
