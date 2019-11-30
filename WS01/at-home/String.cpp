// Name:							Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:					pzelada-souza@myseneca.ca
// Date of completion:				09-16-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <iostream>
#include <string.h>
#include "String.h"

namespace sdds{

	unsigned int g_maxSize = 3; // Definition of the externally linked variable.

  String::String(const char * str_) {

		text = new char[g_maxSize + 1]; // Dynamically assign memory to to the member.

		if (str_) { // Checks for the null address. If not null, copy the string up to the maxSize.
			strncpy(text, str_, g_maxSize);
		} else {
			text[0] = '\0';
		}

		text[g_maxSize] = '\0'; // Add the null terminator.

  } // String::String(const char *)

	const void String::display(std::ostream &os) {

		os << text;

		return void();

	} // String::display(std::ostream)

	std::ostream& operator<<(std::ostream& os, String &str_) {

		static int counter = 0;
		counter++;

		os << counter << ": ";
		str_.display(os);

		return os;

	} // std::ostream& operator<<()

}
