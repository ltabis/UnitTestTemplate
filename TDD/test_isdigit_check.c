#include <criterion/criterion.h>

TEST(isdigit_test, isdigit)
{
    cr_assert_eq(is_digit("42"), 1);
    cr_assert_eq(is_digit("42+42"), 0);
    cr_assert_eq(is_digit("abc"), 0);
}
