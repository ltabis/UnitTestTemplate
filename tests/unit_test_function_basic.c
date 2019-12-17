/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(tests, isneg_test)
{
    cr_assert_eq(isneg(3), 1);
    cr_assert_eq(isneg(-1), 0);
}
