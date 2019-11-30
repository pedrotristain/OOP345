// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			10-04-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {

  class Reservation {

    char res_id[7]; // The ID of the reservation

    std::string res_name; // The name of the guest responsible for the reservation
    std::string res_email; // The email of the guest responsible for the reservation

    int res_guests; // The number of guests in the reservation
    int res_day; // The day of the reservation
    int res_hour; // The hour of the reservation

  public:

    Reservation(); // Default no-parameter constructor

    Reservation(const std::string&); // One parameter constructor
  
  private:

    friend std::ostream & operator<<(std::ostream &, const Reservation &); // Friend helper that inserts the content of a reservation into the output stream

  }; // class Reservation/   

  // Free Helpers

  // Trim all white spaces from the beginning and end of a string.
  std::string & trim(std::string &, const std::string & = " "); 

} // namespace sdds

#endif
