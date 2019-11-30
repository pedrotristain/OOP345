// Name:                                Pedro Zelada Souza
// Seneca Student ID:                   116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:                  30-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include "CustomerOrder.h"
#include "Task.h"
#include "Utilities.h"
#include "LineManager.h"

// 3 parameter constructor.
// Receives: 
// - A string with the filename specified by the user to be used for linking the assembly line objects
// - A vector that contains the addresses of all the 'Task' objects created for the assembly line
// - A vector that contains all the 'CustomerOrder' objects to be filled
LineManager::LineManager(const std::string & _fn, std::vector<Task *> & _tasks, std::vector<CustomerOrder> & _orders){

    // Number of orders the assembly line will begin with
    m_cntCustomerOrder = _orders.size();

    // Open the file '_fn' in reading mode
    std::fstream file(_fn, std::fstream::in);

    // If there was an error opening the file, throw an error
	if (!file)
		throw std::string("Unable to open [") + _fn + "] file.";

    // Control variable that will hold the string with the tokens
	std::string _tokens_str;

    // Iterate through the file extracting all lines
	while (!file.eof()) {
		
        // Extract current line of tokens
        std::getline(file, _tokens_str);

        // Control variables to extract tokens from the received string
        Utilities util;
        std::vector<std::string> tokens;
        size_t x = 0, start_pos = 0;
        bool more = false;

        util.setDelimiter('|');

        // Extract all tokens from the string
        do {

            tokens.push_back( util.extractToken(_tokens_str, start_pos, more) );
            x++;

        } while(more);

        // Pointer variables to form the assembly line chains
        Task * left_chain = nullptr;
        Task * right_chain = nullptr;

        // Iterate through the tasks vector forming the assembly line chain
        for(Task * task : _tasks){

            if(task->getName() == tokens[0]){

                left_chain = task; // Set the left chain

            } else if(tokens.size() > 1){
                
                if(task->getName() == tokens[1]) {

                    right_chain = task; // Set the right chain
                
                } // if*

            } // else if

        } // for

        if(right_chain != nullptr){

            // Set the next task of the left chain to be the task of the right chain
            left_chain->setNextTask(* right_chain);
            
        }

	} // while()

    for(Task * task : _tasks)
        AssemblyLine.push_back(task);
    
    // Move the _orders vector to the LineManager ToBeFilled member
    for(size_t i = 0; i < _orders.size(); i++)
        ToBeFilled.push_front(std::move(_orders[i]));

    // Get the first and last elements of the assembly
    std::vector<Task *> sorted;

    for(auto task : AssemblyLine)
        if(task->getNext() == nullptr)
            sorted.push_back(task);
    
    for(size_t i = 0; i < AssemblyLine.size(); i++)
        for(auto task : AssemblyLine)
            if(task->getNext() != nullptr)
                if(task->getNext() == sorted.back())
                    sorted.push_back(task);
    
    std::reverse(sorted.begin(), sorted.end());

    First = sorted.front();
    Last = sorted.back();

    // Close the file
	file.close();

} // LineManager::LineManager(const std::string &, std::vector<Task *> &, std::vecontr<CustomerOrder> &)

// A function that performs one cycle of operations on the assembly line
bool LineManager::run(std::ostream & os){

    // Control variable
    bool finished = true;

    // If there is queue, move the last 'CustomerOrder' to the front of the 'AssemblyLine'
    if(!ToBeFilled.empty()){

        * First += std::move(ToBeFilled.back());
        // * AssemblyLine.front() += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
        
    } // if()

    // Run the process on every line once
    for(Task * task : AssemblyLine)
        task->runProcess(os);

    // Control variable to hold complete orders
    CustomerOrder filled_order;

    // Check if the order at the end of the line is completed. If TRUE, move it to the complete queue
    if(Last->getCompleted(filled_order))
    // if(AssemblyLine.back()->getCompleted(filled_order))
        Completed.push_back(std::move(filled_order));

    // Move all orders that have finished their business in each line
    for(Task * task : AssemblyLine){

        // If the lines moved, repeat
        if(task->moveTask())
            finished = false;

    } // for()

    // If there is nothing else to assemble, finish the process
    return finished;

} // bool LineManager::run(std::ostream &)

// Query function that displays all the orders that were completed
void LineManager::displayCompleted(std::ostream & os) const{

    // for(size_t i = 0; i < Completed.size(); i++)
        // Completed[i].display(os);
    
    for(auto & order : Completed)
        order.display(os);

} // void LineManager::displayCompleted(std::ostream &) const

// Query function that validates each task on the assembly line
void LineManager::validateTasks() const {

    for(Task * task : AssemblyLine)
        task->validate(std::cout);

} // void LineManager::validateTasks() const
