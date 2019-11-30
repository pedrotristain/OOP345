// Name:                                Pedro Zelada Souza
// Seneca Student ID:                   116427188
// Seneca email:                        pzelada-souza@myseneca.ca
// Date of completion:                  30-11-2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <deque>
#include "CustomerOrder.h"


class Task : public Item {

  // Double ended queue with new 'CustomerOrders' coming in one side and exiting out the other once filled.
  std::deque<CustomerOrder> m_orders;

  // Pointer to the next task in the line
  Task * m_pNextTask;

public:

  // 1 parameter constructor. Receives an string with tokens with the items data to be extracted.
  Task(const std::string);

  // Disable copy and move constructors 
  Task(Task &) = delete;
  Task(Task &&) = delete;

  // Disable move and copy operators
  Task & operator=(Task &) = delete;
  Task & operator=(Task &&) = delete;

  // Function that runs a single cycle of the assembly line
  void runProcess(std::ostream &);

  // Move the last 'CustomerOrder' in the queue if the current one is filled. Return FALSE if the queue is empty
  bool moveTask();

  //  Stores the provided Task object's reference into the m_pNextTask pointer
  void setNextTask(Task &);

  // Removes the last 'CustomerOrder' from the queue, places it in the parameter and returns TRUE. If the 'CustomerOrder' queue is empty, return FALSE.
  bool getCompleted(CustomerOrder &);

  // Writes the name of the Item this Task is responsible for into the output stream
  void validate(std::ostream &);

  // Return the next task in the line
  Task * getNext();

  // Moves the received 'CustomerOrder' onto the front of the queue
  Task & operator+=(CustomerOrder &&);

}; // class Task

#endif
