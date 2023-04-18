//
// Created by Jakob Ferguson on 4/12/23.
//

#ifndef INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_H
#define INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_H

#include "abstractqueue.h"

template <class T>
class QNode
{
public:
    T data;              // Data to be stored
    QNode<T>* next;     // Pointer to the next element in the list

    // Purpose: Default constructor
    // Postconditions: next pointer set to NULL
    // --- PREDEFINED HERE ---
    QNode() : next(NULL) {}

    // Purpose: Auxiliaty constructor, construct from parameters
    // Postconditions: data and next pointer set to parameters
    // --- PREDEFINED HERE ---
    QNode(const T& x, QNode<T>* p) : data(x), next(p) {}
};

template < typename T >
class  LinkedQueue : public AbstractQueue<T>
{
    private:

        int m_size;
        QNode<T>* m_front;
        QNode<T>* m_back;
    public:
        LinkedQueue() : m_size(0), m_front(NULL), m_back(NULL) {};

        // PURPOSE: Checks if a queue is empty
        // RETURNS: 'true' if the queue is empty
        //   'false' otherwise
        bool isEmpty() const;

        // PURPOSE: looks at the front of the queue
        // RETURNS: a reference to the element currently in front of the queue
        // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
        //   message!!!         throw (Oops)
        const T& front() const;


        // PURPOSE: looks at the back of the queue
        // RETURNS: a reference to the element currently in the back of the queue
        // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
        //   message!!!         throw (Oops)
        const T& back() const;


        // PURPOSE: enqueue an element into the queue
        // PARAMETERS: x is the item to add to the queue
        // POSTCONDITIONS: x is now the element at the end of the queue,
        void enqueue(const T& x);

        // PURPOSE: dequeues an elemet from the queue
        // POSTCONDITIONS: the element formerly at the front of the queue has
        //     been removed.
        // NOTE: Dequeueing an empty queue results in an empty queue.
        void dequeue();


        // PURPOSE: clears the queue
        // POSTCONDITIONS: the queue is now empty
        void clear();

        // PURPOSE: Base destructor
        ~LinkedQueue();
};

#include "linkedqueue.hpp"

#endif //INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_H
