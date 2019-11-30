// Name:                                Pedro Zelada Souza
// Seneca Student ID:                   116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:                  30-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"


class LineManager {

    // A container containing all the references of the 'Task' objects on the assembly line
    std::vector<Task *> AssemblyLine;

    // A queue of 'CustomerOrder' to be filled
    std::deque<CustomerOrder> ToBeFilled;

    // A queue of 'CustomerOrder' completed
    std::deque<CustomerOrder> Completed;

    // The number of 'CustomerOrder' objects the assembly line started with
    unsigned int m_cntCustomerOrder;

    // Set the first and last element of the assembly line
    Task * First;
    Task * Last;

public:

    // 3 parameter constructor.
    // Receives: 
    // - A string with the filename specified by the user to be used for linking the assembly line objects
    // - A vector that contains the addresses of all the 'Task' objects created for the assembly line
    // - A vector that contains all the 'CustomerOrder' objects to be filled
    LineManager(const std::string &, std::vector<Task *> &, std::vector<CustomerOrder> &);

    // A function that performs one cycle of operations on the assembly line
    bool run(std::ostream &);

    // Query function that displays all the orders that were completed
    void displayCompleted(std::ostream&) const;

    // Query function that validates each task on the assembly line
    void validateTasks() const;

}; // class LineManager

#endif
