#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    const char* name;
    bool (*test)(void);
} Test;

void run_test(Test test) {
    if (test.test()) {
        printf("\033[38;2;116;211;255m[%s] Passed!\033[0m\n", test.name);
    } else {
        printf("\033[38;2;255;116;116m[%s] Failed!\033[0m\n", test.name);
    }
}

void run_tests(Test* tests, int length) {
    for (int i = 0; i < length; i++) {
        if (tests[i].test()) {
            printf("\033[38;2;116;211;255m[%d/%d][%s] Passed!\033[0m\n", i + 1, length, tests[i].name);
        } else {
            printf("\033[38;2;255;116;116m[%d/%d][%s] Failed!\033[0m\n", i + 1, length, tests[i].name);
        }
    }
}