#ifndef DUMBDATELIB_DUMB_DATE_H
#define DUMBDATELIB_DUMB_DATE_H

#include <string>

namespace dumbdate {

    const unsigned int OK = 0x00000000; // 0
    const unsigned int NOT_DATE = 0x00000001; // 1
    const unsigned int INCORRECT_DELIMITER = 0x00000010; // 16
    const unsigned int INCORRECT_DAY = 0x00000100; // 256
    const unsigned int INCORRECT_MONTH = 0x00001000; // 4096

    /**
     * Simple function that transforms a date into a text representation, adding three days to it.
     *
     * @param[in] date any date in the dd.mm format
     * @param[out] date_str adds three days to the `date` and returns a string representation of the new date
     * @return Execution error code.
     */
    int GetDatePlus3DaysStr(const std::string &date, std::string &date_str);
}

#endif //DUMBDATELIB_DUMB_DATE_H
