// Name:                                Pedro Zelada Souza
// Seneca Student ID:                   116427188
// Seneca email:						pzelada-souza@myseneca.ca
// Date of completion:                  30-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <string>
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Task.h"


// 1 parameter constructor. Receives an string with tokens with the items data to be extracted.
// Sets 'm_pNextTask' in a safe empty state.
Task::Task(const std::string str_tokens) : Task::Item(str_tokens){

    m_pNextTask = nullptr;

} // Task(const std::string)

// Function that runs a single cycle of the assembly line
void Task::runProcess(std::ostream & os){

    // If there are any 'CustomerOrder' in the queue:
    if(!m_orders.empty()) {
        
        // Verify fill status of the LAST 'CustomerOrder' 
        // Fill it if the order contains the 'Item' specified by the current 'Task'
        if(!m_orders.back().getOrderFillState())
            m_orders.back().fillItem(* this, os);   

    } // if()

} // Task::runProcess(std::ostream &)

// Move the last 'CustomerOrder' in the queue if the current one is filled. Return FALSE if the queue is empty
bool Task::moveTask(){

    // Flag that tells if the item was moved
    bool is_moved = false;

    // Check if there is another task to move the last 'CustomerOrder'
    if(m_pNextTask != nullptr){

        // If TRUE, move the last order in the queue ONLY if it is filled
        // if the orders fill state for the current Item is true
        if(!m_orders.empty()){

            if(m_orders.back().getItemFillState(getName())){

                // moves the last CustomerOrder in the queue to the next task on the assembly line 
                * m_pNextTask += std::move(m_orders.back());
                
                // Remove from the queue
                m_orders.pop_back();

                // Change the flag to TRUE
                is_moved = true;

            } // if()

        } // if()
        
    } // if()

    // Return TRUE if the queue is not empty. FALSE otherwise
    return is_moved;

} // Task::moveTask()

//  Stores the provided Task object's reference into the m_pNextTask pointer
void Task::setNextTask(Task & next_task){

    m_pNextTask = & next_task;

} // Task::setNextTask(Task &)

// Removes the last 'CustomerOrder' from the queue, places it in the parameter and returns TRUE.
// If the 'CustomerOrder' queue is empty, return FALSE.
bool Task::getCompleted(CustomerOrder & _co){

    // Flag variable that will tell if the order is complete
    bool is_completed = false;

    // If the queue is not empty, remove the last item and place it in the received parameter
    if(!m_orders.empty()){

        // Place it in the parameters
        _co = std::move(m_orders.back());

        // Remove from the queue
        m_orders.pop_back();

        // Set the flag to true
        is_completed = true;

    } // if()

    // Return TRUE if not empty, FALSE otherwise
    return is_completed;

} // Task::getCompleted(CustomerOrder &)

// Writes the name of the 'Item' this 'Task' is responsible for into the output stream
void Task::validate(std::ostream & os){

    // Insert the 'Item' name in the output stream
    os << getName() << " --> ";

    // If there are more tasks, insert the next tasks' name in the output stream
    if(m_pNextTask != nullptr)
        os << m_pNextTask->getName();
    
    // Otherwise display a message stating there are no more tasks
    else
        os << "END OF LINE";
    
    // Insert an line break
    os << std::endl;

} // Task::validate(std::ostream &)

// Return the address of the next task in the line
Task * Task::getNext() {

    return m_pNextTask;

} // Task * Task::getNext()

// Moves the received 'CustomerOrder' onto the front of the queue
Task & Task::operator+=(CustomerOrder && _co){

    // Push the received order to the front of the queue
    m_orders.push_front( std::move(_co) );

    // Return this object
    return * this;

} // Task::operator+=(CustomerOrder &&)
