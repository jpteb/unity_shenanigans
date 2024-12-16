#include <stdio.h>

#include "unity_helper.h"
#include "some_func.h"
#include "unity.h"

void setUp(void) {
  // Set up resources before each test
}

void tearDown(void) {
  // Clean up resources after each test
}

void add_test(void) {
    TEST_ASSERT_EQUAL(add(1, 2), 3);
}

int main(void) {
#ifdef UNITY_INCLUDE_CONFIG_H
    printf("unity include config.h activated!\n");
#endif
    UNITY_BEGIN();
    UNITY_OUTPUT_CHAR('x');
    
    RUN_TEST(add_test);

    return UNITY_END();
}
