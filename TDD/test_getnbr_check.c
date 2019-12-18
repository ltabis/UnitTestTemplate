/*
** Test for a function, you have to implement the function
** according to the tests.
**
** getnbr avec un boundary check
*/

#include <criterion/criterion.h>

TEST(getnbr_check_test, test_normal)
{
    cr_assert_eq(getnbr_check("12345"), 12345);
    cr_assert_eq(getnbr_check("000"), 0);
}

TEST(getnbr_check_test, test_crash)
{
    cr_assert_eq(getnbr_check(NULL), 0);
}

TEST(getnbr_check_test, test_boundary)
{
    cr_assert_eq(getnbr_check("4294967296"), 0);
    cr_assert_eq(getnbr_check("-42"), 0);
}

TEST(getnbr_check_test, test_bad_formatting)
{
    cr_assert_eq(getnbr_check("abc"), 0);
    cr_assert_eq(getnbr_check("-+-+-42"), 0);
    cr_assert_eq(getnbr_check("42abc"), 0);
}
