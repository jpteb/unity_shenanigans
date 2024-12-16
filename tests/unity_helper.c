#include "unity_helper.h"
#include <stdio.h>

void CustomOutputChar(int c) { printf("HAHA Yeet: %c\n", (char)c); }

void CustomOutputFlush() {
    printf("Custom output flush called\n");
};
void CustomOutputStart() {
    printf("Custom output start called\n");
};
void CustomOutputComplete() {
    printf("Custom output complete called\n");
};
