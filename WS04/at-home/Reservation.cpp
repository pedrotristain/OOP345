// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			10-04-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include "Reservation.h"

namespace sdds {

  // Default no-parameter constructor
  // Sets the object in an empty safe state
  Reservation::Reservation(){

    res_id[0] = '\0';
    res_name = res_email = "";
    res_guests = res_day = res_hour = 0;

  } // Reservation::Reservation()

  // One parameter constructor
  Reservation::Reservation(const std::string & m_res){

    size_t count = 0, previous = 0, current = m_res.find(':'); // Temp variables to get the tokens.
    std::string tokens[6]; // Temporary variable to hold values from token string

    // Search the string for ',' characters
    if(current > 0){

      // Extract substrings from the tokens string until it reaches the last one
      while(count < 6){

        tokens[count] = m_res.substr(previous, current - previous); // Capture the token before the ',' delimiter

        tokens[count] = trim(tokens[count]); // Trim the white spaces from the token

        previous = current + 1; // Tells where to begin the next substr
        current = m_res.find(',', previous); // Tells where to end the next substr

        count++;

      } // while()

      // Populate the object
      strcpy(res_id, &tokens[0][0]);
      res_name = tokens[1];
      res_email = tokens[2];
      res_guests = std::stoi(tokens[3]);
      res_day = std::stoi(tokens[4]);
      res_hour = std::stoi(tokens[5]);

    } // if (current > 0)

  } // Reservation::Reservation(const std::string &)

  // Friend helper that inserts the content of a reservation into the output stream
  std::ostream & operator<<(std::ostream & os, const Reservation & res){

    os << "Reservation " << res.res_id << ":" << std::setw(11) << std::right << res.res_name << " ";

    std::string formatted_email = " <" + res.res_email + ">";
    os << std::left << std::setw(25) << formatted_email;

    // Breakfast time
    if(res.res_hour >= 6 && res.res_hour <= 9){

      os << "Breakfast on day";

    } else if (res.res_hour >= 11 && res.res_hour <= 15) { // Lunch time

      os << "Lunch on day";

    } else if (res.res_hour >= 17 && res.res_hour <= 21) { // Dinner time

      os << "Dinner on day";

    } else { // Open drink time

      os << "Drinks on day";

    } // if()

    os << " " << res.res_day << " @ " << res.res_hour << ":00 for " << res.res_guests << " people.";

    os << std::endl;

    return os;

  } // operator<<()

  // Trim all white spaces from the beginning and end of a string.
  std::string & trim(std::string & str_to_trim, const std::string & trim_chars) {

    str_to_trim.erase(0, str_to_trim.find_first_not_of(trim_chars)); // Remove all spaces from the beginning of the string.

    str_to_trim.erase(str_to_trim.find_last_not_of(trim_chars) + 1); // Remove all spaces from the end of the string.

    return str_to_trim; // Returns the trimmed string

  } // trim()

} // namespace sdds
