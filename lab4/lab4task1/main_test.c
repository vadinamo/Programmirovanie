#include "main.h"
#include <assert.h>

int length_test() {
    assert(length("asdads") == 6);
    assert(length(" ") == 1);
    assert(length("12345678900987654321") == 20);
    assert(length("wasd\nwasd") == 9);

    return 1;
}

int string_check_test() {
    assert(string_check("abs", "abs") == 1);
    assert(string_check(" ", "") == 0);
    assert(string_check("okfdsd'gkfpgksfdl;hfsh", "assalfasf") == 0);
    assert(string_check("wasd\n", "\nwasd") == 0);
    assert(string_check("qwertyu iop[]  sdfghjk  l;'", "qwertyu iop[]  sdfghjk  l;'") == 1);

    return 1;
}

#undef main

int main() {
    length_test();
    string_check_test();

    printf("Test succesfully completed");
    return 0;
}
