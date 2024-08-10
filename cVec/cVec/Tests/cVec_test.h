#include <assert.h>
#include <stdio.h>
#include "..\cVec.h" 

void test_create_cVec() {
    cVec* vec = create_cVec();
    assert(vec != NULL);
    assert(vec->DATA == NULL);
    assert(vec->size == 0);
    cVec_destroy(vec);
}

void test_cVec_add() {
    cVec* vec = create_cVec();
    int a = 5;
    cVec_add(vec, &a);
    assert(vec->size == 1);
    assert(vec->DATA[0] == &a);
    cVec_destroy(vec);
}

void test_cVec_remove_last() {
    cVec* vec = create_cVec();
    int a = 5;
    cVec_add(vec, &a);
    cVec_remove_last(vec);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);
    cVec_destroy(vec);
}

void test_cVec_remove_object_by_index() {
    cVec* vec = create_cVec();
    int a = 5, b = 10;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_remove_object_by_index(vec, 0);
    assert(vec->size == 1);
    assert(vec->DATA[0] == &b);
    cVec_destroy(vec);
}

void test_cVec_remove_object_by_argument() {
    cVec* vec = create_cVec();
    int a = 5, b = 10;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_remove_object_by_argument(vec, &a);
    assert(vec->size == 1);
    assert(vec->DATA[0] == &b);
    cVec_destroy(vec);
}

void cVec_run_test() {
    test_create_cVec();
    test_cVec_add();
    test_cVec_remove_last();
    test_cVec_remove_object_by_index();
    test_cVec_remove_object_by_argument();
    printf("%s", "all test passed");
}
