#include "dumb_date.h"

#include <map>
#include <stdexcept>

namespace dumbdate {

    int GetDatePlus3DaysStr(const std::string& date, std::string &date_str) {

        if (date.empty() || date.length() > 5) {
            return NOT_DATE;
        }

        size_t separatorIndex = date.find('.');

        if (separatorIndex == -1) {
            bool isSlash = date.find('/') != -1;
            bool isDash = date.find('-') != -1;
            bool isPeriod = date.find('.') != -1;
            bool isComma = date.find(',') != -1;
            if (isSlash || isDash || isPeriod || isComma) {
                return INCORRECT_DELIMITER;
            }
            return NOT_DATE;
        }

        std::string dayString = date.substr(0, separatorIndex);
        std::string monthString = date.substr(separatorIndex + 1, 2);

        if (dayString.find('+') != dayString.find('-')) {
            return NOT_DATE;
        }

        if (monthString.find('+') != monthString.find('-')) {
            return NOT_DATE;
        }

        std::size_t pos{};
        int day;
        int month;
        try {
            day = std::stoi(dayString, &pos, 10);
            if (pos != 2) {
                return INCORRECT_FORMAT;
            }
            month = std::stoi(monthString, &pos, 10);
            if (pos != 2) {
                return INCORRECT_FORMAT;
            }
        } catch (std::invalid_argument const& ex) {
            return NOT_DATE;
        }

        std::map<int, int> numbersOfDaysInMonth {
                {1, 31},
                {2, 29},
                {3, 31},
                {4, 30},
                {5, 31},
                {6, 30},
                {7, 31},
                {8, 31},
                {9, 30},
                {10, 31},
                {11, 30},
                {12, 31}
        };

        if (month <= 0 || month > 12) {
            return INCORRECT_MONTH;
        }

        if (day <= 0 || day > numbersOfDaysInMonth.at(month)) {
            return INCORRECT_DAY;
        }

        std::map<int, std::string> dayMapping{
                {1,  "первое"},
                {2,  "второе"},
                {3,  "третье"},
                {4,  "четвертое"},
                {5,  "пятое"},
                {6,  "шестое"},
                {7,  "седьмое"},
                {8,  "восьмое"},
                {9,  "девятое"},
                {10, "десятое"},
                {11, "одиннадцатое"},
                {12, "двенадцатое"},
                {13, "тринадцатое"},
                {14, "четырнадцатое"},
                {15, "пятнадцатое"},
                {16, "шестнадцатое"},
                {17, "семнадцатое"},
                {18, "восемнадцатое"},
                {19, "девятнадцатое"},
                {20, "двадцатое"},
                {21, "двадцать первое"},
                {22, "двадцать второе"},
                {23, "двадцать третье"},
                {24, "двадцать четвертое"},
                {25, "двадцать пятое"},
                {26, "двадцать шестое"},
                {27, "двадцать седьмое"},
                {28, "двадцать восьмое"},
                {29, "двадцать девятое"},
                {30, "тридцатое"},
                {31, "тридцать первое"}
        };

        std::map<int, std::string> monthMapping{
                {1,  "января"},
                {2,  "февраля"},
                {3,  "марта"},
                {4,  "апреля"},
                {5,  "мая"},
                {6,  "июня"},
                {7,  "июля"},
                {8,  "августа"},
                {9,  "сентября"},
                {10, "октября"},
                {11, "ноября"},
                {12, "декабря"},
        };

        int dayPlusThree = day + 3;
        int daysInMonth = numbersOfDaysInMonth.at(month);

        if (dayPlusThree > daysInMonth) {
            day = dayPlusThree - daysInMonth;
            month++;
            month %= 12;
        } else {
            day += 3;
        }

        date_str = dayMapping.at(day) + ' ' + monthMapping.at(month);

        return OK;
    }
}
