#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  T priority;
  Element<T> *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};
 
/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
bool isEmpty(Queue<T> &q){
  if(q.Head == nullptr && q.Tail == nullptr){
    return true;
  } else{
    return false;
  }
}  
  
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> newElement;
  newElement = new Element<T>;
  newElement->data = value;
  newElement->priority = priority;
  newElement->next = nullptr;
  
  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.Head;  
  
  if(isEmpty(q)){
    q.Head = newElement;
    q.Tail = newElement;
  } else{
    while(newElement->priority >= pHelp->priority){
      if(pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }
  }
  
  //Insert First
  if(pHelp == q.Head && newElement->priority > pHelp->priority){
    newElement->next = pHelp;
    q.Head = newElement;
  }
  //Insert Last
  else if(pHelp == q.Tail && newElement->priority < pHelp->priority){
    pHelp->next = newElement;
    q.Tail = newElement;
  }
  //Insert Middle
  else{
    pRev->next = newElement;
    newElement->next = pHelp;
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  Element<T> *delElement;
  if(isEmpty(q)){
    delElement = nullptr;
  } else if(q.Head->next == nullptr){
    delElement = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  } else{
    delElement = q.Head;
    q.Head = q.Head->next;
    delElement->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
