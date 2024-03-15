#include <stdlib.h>
#include <check.h>
#include "operations.h"

START_TEST(addition_test)
{
    ck_assert_int_eq(opaddition(3,11),14);
}
END_TEST

START_TEST(subtraction_test)
{
    ck_assert_int_eq(opsubtraction(15,6),9);
}
END_TEST

START_TEST(multiplication_test)
{
    ck_assert_int_eq(opmultiplication(8,9),72);
}
END_TEST

START_TEST(division_test)
{
    ck_assert_int_eq(opdivision(20,5),4);
}
END_TEST

Suite* suite_operations(void)
{
    Suite* s;
    TCase* tca, *tcs, *tcm, *tcd;
    s = suite_create("suite_operations");
    tca = tcase_create("addition");
    tcs = tcase_create("subtraction");
    tcm = tcase_create("multiplication");
    tcd = tcase_create("division");
    tcase_add_test(tca, addition_test);
    tcase_add_test(tcs, subtraction_test);
    tcase_add_test(tcm, multiplication_test);
    tcase_add_test(tcd, division_test);

    suite_add_tcase(s, tca);
    suite_add_tcase(s, tcs);
    suite_add_tcase(s, tcm);
    suite_add_tcase(s, tcd);
    return s;
}

int main(void)
{
    int number_failed;
    SRunner* sr;

    Suite* s_op = suite_operations();

    sr = srunner_create(s_op);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}