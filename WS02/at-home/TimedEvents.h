// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			09-20-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace sdds {

  class TimedEvents {

    int rec_num;

    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point end_time;

    struct {
      std::string event_name;
      std::string time_units;
      std::chrono::steady_clock::duration event_duration;
    } records[7];

  public:

    TimedEvents();

    void startClock();
    void stopClock();
    void recordEvent(std::string);

private:
    friend std::ostream & operator<<(std::ostream &, const TimedEvents &);

  };


}

#endif
