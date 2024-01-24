/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <typename T>
class MinHeap{
  public:
    MinHeap(int c);
    virtual ~MinHeap();
    void insert(T k);
    T getMin();
    void deleteMin();
    bool isEmpty(){ return m_size==0;}
    T dequeue();
    int m_size;
  private:
    T* m_Heap;
    //how many things in heap
    //what's max size of heap
    int m_cap;
    void fixHeap(int startIdx);
    int getLeftIdx(int i);
    int getRightIdx(int i);
    int getParentIdx(int i);
};

template <typename T>
MinHeap<T>::MinHeap(int c){
  m_Heap = new T[c];
  m_size = 0;
  m_cap = c;
}

template <typename T>
MinHeap<T>::~MinHeap(){
  delete[] m_Heap;
}

template <typename T>
T MinHeap<T>::getMin(){
  //TODO: check for empty heap
  return m_Heap[0];
}

template <typename T>
int MinHeap<T>::getLeftIdx(int i){
  return (2*i)+1;
}

template <typename T>
int MinHeap<T>::getRightIdx(int i){
  return (2*i)+2;
}

template <typename T>
int MinHeap<T>::getParentIdx(int i){
  return (i-1)/2;
}

template <typename T>
void MinHeap<T>::insert(T k){
  //TODO: make sure array isn't full
  m_Heap[m_size++] = k;
  int currIdx = m_size - 1;
  //make sure thing is still a heap
  while((currIdx!=0) && (m_Heap[currIdx] < m_Heap[getParentIdx(currIdx)])){
    T temp = m_Heap[currIdx];
    m_Heap[currIdx] = m_Heap[getParentIdx(currIdx)];
    m_Heap[getParentIdx(currIdx)] = temp;
    currIdx = getParentIdx(currIdx);
  }
}

template <typename T>
void MinHeap<T>::deleteMin(){
  //TODO: check for empty heap
  if(m_size==1){
    --m_size;
    //return;
  }else{
    m_Heap[0] = m_Heap[m_size-1];
    --m_size;
    fixHeap(0); //fix heap starting at root
  }
}

template <typename T>
void MinHeap<T>::fixHeap(int startIdx){
  int left = getLeftIdx(startIdx);
  int right = getRightIdx(startIdx);
  int smallest = startIdx;
  if(left < m_size && m_Heap[left] < m_Heap[startIdx]){
    smallest = left;
  }
  if(right < m_size && m_Heap[right] < m_Heap[smallest]){
    smallest = right;
  }
  if(smallest != startIdx){//have to swap with child
    T temp = m_Heap[startIdx];
    m_Heap[startIdx] = m_Heap[smallest];
    m_Heap[smallest] = temp;
    fixHeap(smallest);
  }
}

template <typename T>
T MinHeap<T>::dequeue(){
    T min = getMin();
    deleteMin();
    return min;
}


#endif