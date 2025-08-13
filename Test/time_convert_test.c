#include "unity.h"
#include "time_convert.h"

void setUp(void) {
   
}

void tearDown(void) {
    
}

void test_midnight_should_return_AM(void) {
    TEST_ASSERT_EQUAL_STRING("AM", get_AM_or_PM(0));
}

void test_noon_should_return_PM(void) {
    TEST_ASSERT_EQUAL_STRING("PM", get_AM_or_PM(12));
}

void test_weekday_from_ymd_known_dates(void) {
    TEST_ASSERT_EQUAL_UINT8(2, weekday_from_ymd(2025, 8, 12));
    TEST_ASSERT_EQUAL_UINT8(6, weekday_from_ymd(2000, 1, 1));
    TEST_ASSERT_EQUAL_UINT8(5, weekday_from_ymd(1999, 12, 31));
}

void test_weekday_to_str_basic(void) {
    TEST_ASSERT_EQUAL_STRING("Mon", weekday_to_str(1));
    TEST_ASSERT_EQUAL_STRING("Sun", weekday_to_str(7));
    TEST_ASSERT_EQUAL_STRING("???", weekday_to_str(0)); 
}

void test_month_to_str_valid(void) {
    TEST_ASSERT_EQUAL(0, strncmp("Jan", month_to_str(1), 3));
    TEST_ASSERT_EQUAL(0, strncmp("Dec", month_to_str(12), 3));
}

void test_month_to_str_invalid(void) {
    TEST_ASSERT_EQUAL_STRING("???", month_to_str(0));
    TEST_ASSERT_EQUAL_STRING("???", month_to_str(13));
}

void test_month_from_str_valid(void) {
    TEST_ASSERT_EQUAL_UINT8(8, month_from_str("Aug"));
    TEST_ASSERT_EQUAL_UINT8(12, month_from_str("Dec"));
}

void test_month_from_str_not_found_defaults_to_jan(void) {
    TEST_ASSERT_EQUAL_UINT8(1, month_from_str("WTF"));
}



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_midnight_should_return_AM); 
    RUN_TEST(test_noon_should_return_PM);
    RUN_TEST(test_weekday_from_ymd_known_dates);
    RUN_TEST(test_weekday_to_str_basic);
    RUN_TEST(test_month_to_str_valid);
    RUN_TEST(test_month_to_str_invalid);
    RUN_TEST(test_month_from_str_valid);
    RUN_TEST(test_month_from_str_not_found_defaults_to_jan);
    return UNITY_END();
}
