#include <stdio.h>

// void dbl (int *);
// void tpl (int *);
// void qdpl (int *);

void fun (int a) {
    fprintf(stdout, "Value of a is %d\n", a);
}

int main() {
    int num = 2, index;

    void (*fptr)(int) = &fun;

    (*fptr)(10);

    return 0;
}
