#include <gtest/gtest.h>
#include "dumb_date.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// NotDate
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(NotDate, EmptyString) {
    std::string date;
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(NotDate, OnlyDilimiter) {
    std::string date = ".";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(NotDate, LettersInstreadNumbers) {
    std::string date = "aa.bb";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(NotDate, AllLetters) {
    std::string date = "abc";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(NotDate, DateBetweenRandomText) {
    std::string date = "abc12.01cbd";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

TEST(NotDate, TwoOrMoreSpacesInDate) {
    std::string date = "27    04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::NOT_DATE);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OK
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(OK, CorrectDate1) {
    std::string date = "04.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, u8"седьмое апреля");
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(OK, CorrectDate2) {
    std::string date = "27.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, u8"тридцатое апреля");
    EXPECT_EQ(code, dumbdate::OK);
}

TEST(OK, CorrectDate3) {
    std::string date = "29.02";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(date_str, u8"третье марта");
    EXPECT_EQ(code, dumbdate::OK);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INCORRECT_DELIMITER
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(INCORRECT_DELIMITER, BackslashDelimiter) {
    std::string date = "27/04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DELIMITER);
}

TEST(INCORRECT_DELIMITER, DashDelimiter) {
    std::string date = "27-04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DELIMITER);
}

TEST(INCORRECT_DELIMITER, EmptyDelimiter) {
    std::string date = "27 04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DELIMITER);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INCORRECT_DAY
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(INCORRECT_DAY, DayNotExisting) {
    std::string date = "63.04";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_DAY);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// INCORRECT_MONTH
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(INCORRECT_MONTH, MonthNotExisting) {
    std::string date = "27.23";
    std::string date_str;
    int code = dumbdate::GetDatePlus3DaysStr(date, date_str);
    EXPECT_EQ(code, dumbdate::INCORRECT_MONTH);
}
