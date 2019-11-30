// Name:										Pedro Zelada Souza
// Seneca Student ID:				116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:			09-20-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <fstream>

#include "Text.h"

namespace sdds {

  Text::Text() {

    records = nullptr;

    num_recs = 0;

  } // Text::Text()

  Text::Text(char * _file){


    std::ifstream f(_file);  // connects output.txt to fout for output

    if (f.is_open()) {

      int count = 0;

      std::string temp;

      while( std::getline( f, temp, ' ') ){
        count++;
      }

      num_recs = count - 1;

      records = new std::string[count];

      f.clear();
      f.seekg(0, std::ios::beg);

      count = 0;
      while(f){

        std::getline( f, records[count], ' ');
        count++;

      }

      f.clear();
      f.close();

    } else {

    }

  } // Text::Text(char * _str)

  Text::Text(const Text & src) {

    num_recs = src.num_recs;

    records = new std::string[num_recs];

    for( int x = 0; x < src.num_recs; x++ ){

      records[x] = src.records[x];

    }

  } // Text::Text(const Text &)

  Text& Text::operator=(const Text & src) {

    num_recs = src.num_recs;

    if (this != &src) {

      if (src.records != nullptr) {

        if(records != nullptr)
          delete [] records;

        records = new std::string[num_recs];

        for( int x = 0; x < src.num_recs; x++ ){

          records[x] = src.records[x];

        }

      } else {

        records = nullptr;

      }

    }

    return *this;

  } // Text::Text& operator=()

  Text::~Text() {

    if (records != nullptr)
      delete [] records;

  } // Text::~Text()

  std::size_t Text::size() const {

    return num_recs;

  } // Text::size_t size()

}
