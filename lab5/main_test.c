#include <assert.h>
#include "main.h"

int Add_test() {
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    assert(Add(stk, 'c') == 1);
    assert(Add(stk, '1') == 1);
    assert(Add(stk, 'g') == 1);
    assert(Add(stk, '<') == 1);

    stk -> top = 128;
    assert(Add(stk, '<') == 0);

    return 1;
}

int Length_test() {
    assert(Length("asdads") == 6);
    assert(Length(" ") == 1);
    assert(Length("12345678900987654321") == 20);
    assert(Length("wasd\nwasd") == 9);
    assert(Length("\n1\n2\n3\n4") == 8);
    assert(Length("<>./\n152\n126abc") == 15);

    return 1;
}

int Palindrome_test(){
    struct stack *stk;
    int i;
    stk = (struct stack*)malloc(sizeof(struct stack));
    for(i = 0; i < 10; i++) {
        Add(stk, i);
    }

    assert(Palindrome(stk) == 0);

    for(i = 9; i >= 0; i--) {
        Add(stk, i);
    }

    assert(Palindrome(stk) == 0);

    return 1;
}

int ToStack_test(){
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    assert(ToStack(stk, "1233221") == 0);

    return 1;
}

#undef main

int main() {
    Add_test();
    Length_test();
    Palindrome_test();
    ToStack_test();

    printf("Test succesfully completed");
    return 0;
}
