#include "dumb_date.h"

#include <map>
#include <vector>
#include <stdexcept>
#include <regex>

namespace dumbdate {

    int GetDatePlus3DaysStr(const std::string &date, std::string &date_str) {

        // TODO: add other delimiters
        std::regex regex(R"((\d\d[\s\./-]\d\d))");

        if (!std::regex_match(date, regex)) {
            return NOT_DATE;
        }

        if (date.at(2) == '/' || date.at(2) == '-' || date.at(2) == ' ') {
            return INCORRECT_DELIMITER;
        }

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
                {1,  u8"первое"},
                {2,  u8"второе"},
                {3,  u8"третье"},
                {4,  u8"четвертое"},
                {5,  u8"пятое"},
                {6,  u8"шестое"},
                {7,  u8"седьмое"},
                {8,  u8"восьмое"},
                {9,  u8"девятое"},
                {10, u8"десятое"},
                {11, u8"одиннадцатое"},
                {12, u8"двенадцатое"},
                {13, u8"тринадцатое"},
                {14, u8"четырнадцатое"},
                {15, u8"пятнадцатое"},
                {16, u8"шестнадцатое"},
                {17, u8"семнадцатое"},
                {18, u8"восемнадцатое"},
                {19, u8"девятнадцатое"},
                {20, u8"двадцатое"},
                {21, u8"двадцать первое"},
                {22, u8"двадцать второе"},
                {23, u8"двадцать третье"},
                {24, u8"двадцать четвертое"},
                {25, u8"двадцать пятое"},
                {26, u8"двадцать шестое"},
                {27, u8"двадцать седьмое"},
                {28, u8"двадцать восьмое"},
                {29, u8"двадцать девятое"},
                {30, u8"тридцатое"},
                {31, u8"тридцать первое"}
        };

        // TODO: Make list/vector instead map
        std::map<int, std::string> monthMapping{
                {1, u8"января"},
                {2, u8"февраля"},
                {3, u8"марта"},
                {4, u8"апреля"},
                {5, u8"мая"},
                {6, u8"июня"},
                {7, u8"июля"},
                {8, u8"августа"},
                {9, u8"сентября"},
                {10,u8"октября"},
                {11,u8"ноября"},
                {12,u8"декабря"},
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
