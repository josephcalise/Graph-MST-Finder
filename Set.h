/*
Joseph Calise
ID#: 2380565
calise@chapman.edu
CPSC-350 Section 03
PA6: Spanning The Gamut
*/
#ifndef SET_H
#define SET_H

template <typename T>
class Set{
  public:
    int m_size;
    Set();
    virtual ~Set();
    int add(T data);
    int* arr;
    bool contains(T data);
    bool isEmpty(){ return m_size==0;};
    void printSet();
};

template<typename T>
Set<T>::Set(){
    this->m_size = 0;
    this->arr = new int[50];
}

template<typename T>
Set<T>::~Set(){
    this->m_size = 0;
}



template<typename T>
int Set<T>::add(T data){
    if (contains(data) == false){
        arr[m_size++] = data;
        return 1;
    }else{
        return 0;
    } 
}

template<typename T>
bool Set<T>::contains(T data){
    int i;
    for (i = 0; i < this->m_size; i++){
        if (arr[i] == data){
            return true;
        }
    }
    return false;
}

template<typename T>
void Set<T>::printSet(){
    int i;
    for (i = 0; i < this->m_size; i++){
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}



#endif