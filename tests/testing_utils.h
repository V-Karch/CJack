#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    const char* name;
    bool (*test)(void);
} Test;

void run_test(Test* test) {
    if (test->test()) {
        printf("\033[38;2;116;211;255m[%s] Passed!\033[0m\n", test->name);
    } else {
        printf("\033[38;2;255;116;116m[%s] Failed!\033[0m\n", test->name);
    }
}