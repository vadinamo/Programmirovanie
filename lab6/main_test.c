#include "main.h"
#include <assert.h>

int testLength() {
    assert(Length("asdads") == 6);
    assert(Length(" ") == 1);
    assert(Length("12345678900987654321") == 20);
    assert(Length("wasd\nwasd") == 9);
    assert(Length("\n1\n2\n3\n4") == 8);
    assert(Length("<>./\n152\n126abc") == 15);

    return 1;
}

int testRemove() {
    struct tree* root = treeBuilder(2);

    if(root == NULL) {
        printf("Can't allocate memory!");
        exit(-1);
    }

    assert(Remove(root) == 1);

    return 1;
}

#undef main

int main() {
    testLength();
    testRemove();

    printf("Test succesfully completed");
    return 0;
}
