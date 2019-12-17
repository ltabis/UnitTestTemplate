/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "test.h"

// setup function
void setup(void)
{
    printf("Runs before the test");
}

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite(My_test_suite);

Test(unit_test, test_cin_cout, .init = redirect_all_stdout)
{
    fprintf(stdout, "cin output");
    fflush(stdout);
    cr_assert_stdout_eq_str("cin output", "cin:");
}

Test(unit_test, test_cerr_cout, .init = redirect_all_stdout)
{
    fprintf(stderr, "cerr output");
    cr_assert_stderr_eq_str("cerr output", "cerr:");
}