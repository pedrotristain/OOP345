// Name:							Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:					pzelada-souza@myseneca.ca
// Date of completion:				09-16-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <iostream>

namespace sdds{

	extern unsigned int g_maxSize;

  class String {

		char * text; // Dynamic size C-string

	public:

	      String(const char *); // 1 parameter constructor.

        const void display(std::ostream&);

	};

	std::ostream & operator<<(std::ostream& , String&);
}
