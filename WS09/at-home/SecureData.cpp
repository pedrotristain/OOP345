// Name:							Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:					pzelada-souza@myseneca.ca
// Date of completion:				26-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <thread>
#include <functional>
#include <algorithm>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	int add(int x, int z){ return x + z; }

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		auto cv = std::bind(converter, text, key, nbytes, Cryptor());

		thread t1(cv);
		thread t2(cv);

		t1.join();
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			fstream fs(file, std::ios::out|std::ios::binary);

			// TODO: write data into the binary file
			//         and close the file
			fs.write(text, nbytes - 1);

			fs.close();

		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		fstream fs(file, std::ios::in|std::ios::binary);

		// TODO: - allocate memory here for the file content
		delete [] text;

		fs.seekg(0, std::ios::end);
		nbytes = (int)fs.tellg() + 1;

		text = new char[nbytes];

		fs.seekg(ios::beg);

		// TODO: - read the content of the binary file
		fs.read(text, nbytes);
		text[nbytes] = '\0';

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";

		fs.close();
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
