#include <assert.h>
#include"../cVec.h"

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

    float b = 3.14;
    cVec_add(vec, &b);
    assert(vec->size == 2);
    assert(vec->DATA[1] == &b);

    cVec_destroy(vec);
}

void test_cVec_remove_last() {
    cVec* vec = create_cVec();
    int a = 5;
    cVec_add(vec, &a);
    cVec_remove_last(vec);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);

    cVec_add(vec, &a);
    cVec_remove_last(vec);
    cVec_remove_last(vec);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);

    cVec_destroy(vec);
}

void test_cVec_remove_object_by_index() {
    cVec* vec = create_cVec();
    int a = 5, b = 10, c = 15;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_add(vec, &c);

    cVec_remove_object_by_index(vec, 1);
    assert(vec->size == 2);
    assert(vec->DATA[0] == &a);
    assert(vec->DATA[1] == &c);

    cVec_remove_object_by_index(vec, 0);
    assert(vec->size == 1);
    assert(vec->DATA[0] == &c);

    cVec_remove_object_by_index(vec, 0);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);

    cVec_destroy(vec);
}

void test_cVec_remove_object_by_argument() {
    cVec* vec = create_cVec();
    int a = 5, b = 10, c = 15;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_add(vec, &c);

    cVec_remove_object_by_argument(vec, &b);
    assert(vec->size == 2);
    assert(vec->DATA[0] == &a);
    assert(vec->DATA[1] == &c);

    cVec_remove_object_by_argument(vec, &c);
    assert(vec->size == 1);
    assert(vec->DATA[0] == &a);

    cVec_remove_object_by_argument(vec, &a);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);

    cVec_destroy(vec);
}

void test_cVec_transfer() {
    cVec* vec1 = create_cVec();
    cVec* vec2 = create_cVec();
    int a = 5, b = 10, c = 15;
    cVec_add(vec1, &a);
    cVec_add(vec2, &b);
    cVec_add(vec2, &c);

    cVec_transfer(vec1, vec2);
    assert(vec1->size == 3);
    assert(vec1->DATA[0] == &a);
    assert(vec1->DATA[1] == &b);
    assert(vec1->DATA[2] == &c);

    cVec_destroy(vec1);
    cVec_destroy(vec2);
}

void test_cVec_erase_transfer() {
    cVec* vec1 = create_cVec();
    cVec* vec2 = create_cVec();
    int a = 5, b = 10, c = 15;
    cVec_add(vec1, &a);
    cVec_add(vec2, &b);
    cVec_add(vec2, &c);

    cVec_erase_transfer(vec1, vec2);
    assert(vec1->size == 2);
    assert(vec1->DATA[0] == &b);
    assert(vec1->DATA[1] == &c);

    cVec_destroy(vec1);
    cVec_destroy(vec2);
}

void test_cVec_clear() {
    cVec* vec = create_cVec();
    int a = 5, b = 10;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_clear(vec);
    assert(vec->size == 0);
    assert(vec->DATA == NULL);
    cVec_destroy(vec);
}

void test_cVec_resize() {
    cVec* vec = create_cVec();
    int a = 5, b = 10, c = 15;
    cVec_add(vec, &a);
    cVec_add(vec, &b);
    cVec_resize(vec, 5);
    assert(vec->size == 5);

    int* null = NULL;
    for (int i = 2; i < 5; ++i) {
        assert(vec->DATA[i] == null);
    }

    cVec_destroy(vec);
}
/*TODO: Write test for swap*/

void cVec_run_test() {
    test_create_cVec();
    test_cVec_add();
    test_cVec_remove_last();
    test_cVec_remove_object_by_index();
    test_cVec_remove_object_by_argument();
    test_cVec_transfer();
    test_cVec_erase_transfer();
    test_cVec_clear();
    test_cVec_resize();
    printf("%s", "All tests passed\n");
}
