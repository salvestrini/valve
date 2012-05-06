//
// This file is part of the valve package
//
// (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
//

#ifndef VALVE_UTILS_HH
#define VALVE_UTILS_HH

#include <ctime>

void bug();
void bug(const std::string & message);

class timedelta {
public:
        timedelta(const std::string & prefix) :
                prefix_(prefix) {
                time(&start_);
        }

        ~timedelta() {
                time(&end_);
                std::cout << prefix_ << ": "
                          << "elapsed " << difftime(end_, start_) << " seconds"
                          << std::endl;
        }

private:
        std::string prefix_;
        time_t      start_;
        time_t      end_;
};

#endif
