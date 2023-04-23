#include "dumb_date.h"

#include <map>
#include <stdexcept>
#include <regex>

namespace dumbdate {

    int GetDatePlus3DaysStr(const std::string &date, std::string &date_str) {

        // TODO: add other delimiters
        std::regex regex(R"((\d\d.\d\d))");

        if (!std::regex_match(date, regex)) {
            return NOT_DATE;
        }

        // TODO: add delimiter check

        std::string dayString = date.substr(0, 2);
        std::string monthString = date.substr(3, 2);

        std::size_t pos{};
        int day = std::stoi(dayString, &pos, 10);
        int month = std::stoi(monthString, &pos, 10);

        // TODO: Make list/vector instead map
        std::map<int, int> numbersOfDaysInMonth{
                {1,  31},
                {2,  29},
                {3,  31},
                {4,  30},
                {5,  31},
                {6,  30},
                {7,  31},
                {8,  31},
                {9,  30},
                {10, 31},
                {11, 30},
                {12, 31}
        };

        // Validate day and month
        if (month <= 0 || month > 12) {
            return INCORRECT_MONTH;
        }
        if (day <= 0 || day > numbersOfDaysInMonth.at(month)) {
            return INCORRECT_DAY;
        }

        // TODO: Make list/vector instead map
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

        // TODO: Make list/vector instead map
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
