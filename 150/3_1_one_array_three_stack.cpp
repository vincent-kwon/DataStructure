/*
 * =====================================================================================
 *
 *       Filename:  3_1_one_array_three_stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/29/2014 09:33:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>

typedef struct _stack_info {
  int start_index;
  int end_index;
  int top_index;
} stack_info;

using namespace std;

template < typename T >
class NStack
{
public:
  NStack(int num_of_stack, int array_size);
  ~NStack();
  void push(int i, T t);
  int getArraySize();
  int getNumOfStacks();
  T* getWholeArray();
  T pop(int i);
private: 
  int num_of_stack_; //size of each stacks
  int whole_array_size_;  //size of whole array
  T* whole_array_; //whole array
  stack_info* st_array_; //array of stack_info
};

template < typename T >
NStack<T>::NStack(int num_stack, int array_size) : num_of_stack_(num_stack),
                                                   whole_array_size_(array_size), 
                                                   whole_array_(NULL), 
                                                   st_array_(NULL)
{

}

template < typename T >
NStack<T>::~NStack()
{

}

template < typename T >
void NStack<T>::push(int i, T t)
{

}

template <typename T>
T NStack<T>::pop(int i)
{
  T t;
  return t;
}

template <typename T>
int NStack<T>::getArraySize()
{
  return whole_array_size_;
}

template <typename T>
int NStack<T>::getNumOfStacks()
{
  return num_of_stack_;
}

template <typename T>
T* NStack<T>::getWholeArray()
{
  if (whole_array_ == NULL) {
    whole_array_ = new(nothrow) T[whole_array_size_];
  }
  return whole_array_;
}

int main()
{
  NStack<int> nst(3, 9);
  cout<<nst.getArraySize()<<endl;
  cout<<nst.getNumOfStacks()<<endl; 
}
