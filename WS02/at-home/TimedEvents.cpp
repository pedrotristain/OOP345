// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			09-20-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "TimedEvents.h"

namespace sdds {

  // Default constructor
  TimedEvents::TimedEvents() {

    rec_num = 0;

    start_time = std::chrono::steady_clock::now();
    end_time = std::chrono::steady_clock::now();

  } // TimedEvents::TimedEvents()

  void TimedEvents::startClock() {

    start_time = std::chrono::steady_clock::now();

  } // TimedEvents::startClock()

  void TimedEvents::stopClock() {

    end_time = std::chrono::steady_clock::now();

  } // TimedEvents::stopClock()

  void TimedEvents::recordEvent(std::string _evt_name) {

    records[rec_num].event_name = _evt_name;

    records[rec_num].time_units = "nanoseconds";

    std::chrono::duration<long, std::nano> dur = end_time - start_time;
    records[rec_num].event_duration = dur;

    rec_num++;

  } // TimedEvents::recordEvent()

  std::ostream & operator<<(std::ostream & os, const TimedEvents & right) {

    os << "--------------------------" << std::endl;
    os << "Execution Times:" << std::endl;
    os << "--------------------------" << std::endl;

    for(int i = 0; i < right.rec_num; i++) {

      os << std::setw(20) << std::left << right.records[i].event_name;
      os << std::setw(12) << std::right << right.records[i].event_duration.count() << " " << right.records[i].time_units;
      os << std::endl;

    }

    os << "--------------------------" << std::endl;

    return os;

  } // std::ostream & operator<<()

}
