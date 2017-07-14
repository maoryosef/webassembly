#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

int main(int argc, char ** argv) {
    printf("WebAssembly module loaded\n");
}

int EMSCRIPTEN_KEEPALIVE roll_dice() {
    srand ( time(NULL) );
    return rand() % 6 + 1;
}

int EMSCRIPTEN_KEEPALIVE add(int a, int b) {
    return a + b;
}

void EMSCRIPTEN_KEEPALIVE fillArray(int* a, int len) {
    for (int i = 0; i < len; i++) {
        a[i] = i * i;
    }

    for (int j = 0; j < len; ++j) {
        printf("a[%d] = %d\n", j, a[j]);
    }
}

void EMSCRIPTEN_KEEPALIVE echoArray(int* a, int len) {
    for (int j = 0; j < len; ++j) {
        printf("a[%d] = %d\n", j, a[j]);
    }
}