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

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unit_test, test_cin_cout, .init = redirect_all_stdout)
{
    /* fprintf(stdout, "cin output"); */
    /* fprintf(stderr, "crr output"); */
    /* cr_assert_stdout_eq_str("cin output", "cin:"); */
    /* cr_assert_stderr_eq_str("cerr", "cerr:"); */
}
