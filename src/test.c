#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_calculation.h"
#include "s21_stack.h"

START_TEST(calc_test) {
    {
        char src[100] = "4^acos(x/4)/tan(2*x)";
        char x_text[100] = "1.2";
        double result = readStr(src, x_text);
        double real_result = -6.31492;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-1 failed");
    }
    {
        char src[100] = "x+x";
        char x_text[100] = "2";
        double result = readStr(src, x_text);
        double real_result = 4;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-2 failed");
    }
    {
        char src[100] = "123+0.456";
        double result = readStr(src, NULL);
        double real_result = 123.456;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-3 failed");
    }
    {
        char src[100] = "log(x)";
        char x_text[100] = "-2";
        double result = readStr(src, x_text);
        double real_result = NAN;
        ck_assert_msg(result != result && real_result != real_result, "test-4 failed");
    }
    {
        char src[100] = "-(-1)";
        double result = readStr(src, NULL);
        double real_result = 1;
        ck_assert_msg(result == real_result, "test-5 failed");
    }
    {
        char src[100] = "cos(10mod2.2)";
        double result = readStr(src, NULL);
        double real_result = 0.362358;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-6 failed");
    }
    {
        char src[100] = "sqrt(ln(10))";
        double result = readStr(src, NULL);
        double real_result = 1.517427;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-7 failed");
    }
    {
        char src[100] = "atan(10)+sin(10)";
        double result = readStr(src, NULL);
        double real_result = 1.644775;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-8 failed");
    }
    {
        char src[100] = "asin(1)";
        double result = readStr(src, NULL);
        double real_result = 1.570796;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-9 failed");
    }
    {
        char src[100] = "10-20*(-10)";
        double result = readStr(src, NULL);
        double real_result = -210;
        ck_assert_msg(fabs(result) - fabs(real_result) <= 0.00001, "test-10 failed");
    }
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, calc_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
