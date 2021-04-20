#include "main.h"
#include <assert.h>

int length_test() {
    assert(length("asdads") == 6);
    assert(length(" ") == 1);
    assert(length("12345678900987654321") == 20);
    assert(length("wasd\nwasd") == 9);
    assert(length("\n1\n2\n3\n4") == 8);

    return 1;
}

int bracket_test() {
    assert(bracket("[({})]", 0) == 0);
    assert(bracket("[({})]", 1) == 1);
    assert(bracket("[({})]", 2) == 0);
    assert(bracket("(()", 1) == 0);
    assert(bracket("(()", 0) == 1);
    assert(bracket("{()()}", 1) == 1);
    assert(bracket("{()()}", 3) == 0);

    return 1;
}

int brace_test() {
    assert(brace("[({})]", 0) == 0);
    assert(brace("[({})]", 1) == 0);
    assert(brace("[({})]", 2) == 1);
    assert(brace("{}}", 0) == 1);
    assert(brace("{[{}]}", 2) == 1);

    return 1;
}

int sq_bracket_test() {
    assert(sq_bracket("[({})]", 0) == 1);
    assert(sq_bracket("[({})]", 1) == 0);
    assert(sq_bracket("[({})]", 2) == 0);
    assert(sq_bracket("[{[()]}]", 0) == 1);
    assert(sq_bracket("[{[([)]}]", 2) == 1);
    assert(sq_bracket("[{[([)]}]", 4) == 0);

    return 1;
}

int bracket_check_test() {
    assert(bracket_check("(({([{[]}])}))") == 1);
    assert(bracket_check("([{]})") == 0);
    assert(bracket_check("(\n{abs\n[]})") == 1);
    assert(bracket_check("{}\n[]\n()") == 0);

    return 1;
}


#undef main

int main() {
    length_test();
    bracket_test();
    brace_test();
    sq_bracket_test();
    bracket_check_test();

    printf("Test succesfully completed");
    return 0;
}
