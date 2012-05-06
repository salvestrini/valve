//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#ifndef VALVE_UTILS_HH
#define VALVE_UTILS_HH

#include <ctime>

void bug(const std::string & message);

class timedelta {
public:
        timedelta() {
                time(&start);
        }

        ~timedelta() {
                time(&end);
                std::cout << "elapsed " << difftime(end, start) << " seconds"
                          << std::endl;
        }

private:
        time_t start;
        time_t end;
};

#endif
