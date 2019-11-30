// Name:                            Pedro Zelada Souza
// Seneca Student ID:               116427188
// Seneca email:                    pzelada-souza@myseneca.ca
// Date of completion:              17-10-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>
#include <iostream>
#include <exception>

namespace sdds {

  template<class T>
  class Collection {

    std::string c_name;

    T * c_objects; // Dinamically allocated array of objects of type T.

    size_t c_size;

    void (*c_observer)(const Collection &, const T &);

  public:

    // 1 parameter constructor. Sets the collection name to the received parameter.
    // Sets other members to default value.
    Collection(std::string name) {

      c_name = name;
      c_objects = nullptr;
      c_size = 0;

      c_observer = nullptr;

    } // Collecction(std::string)

    // Disable copy operations
    Collection(const Collection &) = delete;
    Collection & operator=(const Collection &) = delete;

    // Destructor. Releases dynamic allocated memory (c_objects)
    ~Collection() {

      delete [] c_objects;

    } // ~Collection()

    // Query that returns the name of the collection
    const std::string & name() const{ return c_name; }

    // Query that returns how many items are currently in the collection
    size_t size() const{ return c_size; }

    /* --------------------------------------------------------------------- */

    // No ideia how this works
    void setObserver(void (*observer)(const Collection<T> & col, const T & item)){

      // Set the observer function
      c_observer = observer;

    } // void setObserver(void (*)(const Collection<T>&, const T&))

    /* --------------------------------------------------------------------- */

    // If 'item' is already in the collection, this function does nothing [check by title].
    // Otherwise, it  resizes the 'c_objects' array, add a copy of 'item' to the collection and calls the observer (if it exists).
    Collection<T> & operator+=(const T & item){

      bool exists = false; // Control variable that will tell if the new item already exists in the collection.

      // Check if the new item is in the collection already
      for(size_t x = 0; x < c_size; x++ ){

        // If it is, change the control variable to 'true' and exit the loop.
        if( c_objects[x].title() == item.title() ){

          exists = true;
          x = c_size;

        } // if()

      } // for()

      // If the new item is not in the collection, add it up. Otherwise, do nothing.
      if(!exists) {

        T * temp = new T[c_size]; // Create a temporary collection to hold all objects.

        // Iterate through the objects and move them to the new array.
        for(size_t x = 0; x < c_size; x++){

          temp[x] = std::move(c_objects[x]);

        } // for()

        // Reset the objects array and increase its size by 1
        delete [] c_objects;
        c_objects = new T[c_size + 1];

        // Iterate through the objects and move them back.
        for(size_t x = 0; x < c_size; x++){

          c_objects[x] = std::move(temp[x]);

        } // for()

        // Add the new item
        c_objects[c_size] = item;

        // Increment the attribute that holds the size of the array
        c_size += 1;

        // Delete the temp array
        delete [] temp;

        // If the observer function is set up, call it. 
        if(c_observer != NULL)
          c_observer(*this, item);

      } // if(!is_in)

      return *this;

    } // Collection<T> & operator+=(const T &)

    // Returns the item at the index 'idx'
    // Throws an error if index is out of range
    T & operator[](size_t idx) const{

      if(idx > c_size - 1)
        throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");

      return c_objects[idx];

    } // T & operator[](size_t) const

    // Returns the address of the item with title matching the received title.
    // Returns 'nullptr' in case of no match
    T * operator[](std::string title) const {

      T * match = nullptr; // Control variable to hold address of the matched object.

      // iterate through the collection
      for(size_t x = 0; x < c_size; x++) {
        T temp = c_objects[x];

        if(c_objects[x].title() == title){ // If there is a match, get the address of the object

          match = &c_objects[x];

        } // if()

      } // for()

      return match; // Return the address of the found object or nullptr

    } // T * operator[](std::string) const

  private:

    // Friend helper that inserts the content of the collection into the output stream
    friend std::ostream & operator<<(std::ostream & os, const Collection & col){

      for(size_t x = 0; x < col.size(); x++ ){

        os << col[x];

      } // for()

      return os;

    } // friend std::ostream & operator<<(std::ostream &, const Collection &

  }; // class Collection

} // namespace sdds

#endif
