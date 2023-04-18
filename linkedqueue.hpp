//
// Created by Jakob Ferguson on 4/15/23.
//

#ifndef INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_HPP
#define INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_HPP

template <typename T>
bool LinkedQueue<T>::isEmpty() const{
    return (m_size == 0);
};


// PURPOSE: looks at the front of the queue
// RETURNS: a reference to the element currently in front of the queue
// EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
//   message!!!         throw (Oops)
template <typename T>
const T& LinkedQueue<T>::front() const{
    if(m_front==NULL)throw Oops("Queue is empty!");
    return m_front->data;
};


// PURPOSE: looks at the back of the queue
// RETURNS: a reference to the element currently in the back of the queue
// EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
//   message!!!         throw (Oops)
template <typename T>
const T& LinkedQueue<T>::back() const{
    if(m_back==NULL)throw Oops("Queue is empty!");
    return m_back->data;
};


// PURPOSE: enqueue an element into the queue
// PARAMETERS: x is the item to add to the queue
// POSTCONDITIONS: x is now the element at the end of the queue,
template <typename T>
void LinkedQueue<T>::enqueue(const T& x){
    QNode<T>* temp = new QNode<T>; //create new node
    temp->data=x; //insert data into new node
    (m_size==0) ? m_front=temp : m_back->next=temp; //set m_front to temp unless !first element in q
    temp->next=NULL;
    m_back = temp; //set back of q to temp
    m_size++;
};


// PURPOSE: dequeues an elemet from the queue
// POSTCONDITIONS: the element formerly at the front of the queue has
//     been removed.
// NOTE: Dequeueing an empty queue results in an empty queue.
template <typename T>
void LinkedQueue<T>::dequeue(){
    if(m_size==0) return;
    QNode<T>* temp = m_front;
    m_front = m_front->next;
    delete temp;
    m_size--;
};


// PURPOSE: clears the queue
// POSTCONDITIONS: the queue is now empty
template <typename T>
void LinkedQueue<T>::clear(){
    for(int i=m_size;i>0;i--){
        dequeue();
    }
    m_front = NULL;
    m_back = NULL;
};


// PURPOSE: Base destructor
template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

#endif //INC_2023_SP_2_HW4_JBFMNF_LINKEDQUEUE_HPP
