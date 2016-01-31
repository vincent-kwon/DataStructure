/*
 * =====================================================================================
 *
 *       Filename:  ultimate_nway_merge.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/2015 08:19:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

//Assume 4 byte of data
template < typename T >
class MemoryManager {
public:
  MemoryManager(int totalSize, int chunkNum); //totalIntSize, chunkIntSize
  ~MemoryManager();
  int findByMerging(int k);
//  void operator=(MemoryManager& lhs) = delete;
//  MemoryManager(MemoryManager& c) = delete;
private:
  int totalSize_;
  int chunkSize_;
  int chunkNum_;
  int *startAddrPtr_;
  int *endAddrPtr_;
  int *currentIndexPtr_;
  string *inputFileName_;
  bool *isDone_;
  ifstream *fileStream_;
  int intNumInChunk_;
};

template < typename T >
MemoryManager<T>::MemoryManager(int totalSize, int chunkNum) : totalSize_(totalSize), chunkNum_(chunkNum) {
  cout<<"MemoryManager:"<<totalSize_<<" MB ,"<<chunkNum_<<" count"<<endl;
  
  chunkSize_ = totalSize_ / chunkNum_;
  intNumInChunk_ = chunkSize_ / 4;

  cout<<" chunkSize: "<<chunkNum_<<" so each chunk has "<< intNumInChunk_ << endl;
 
  startAddrPtr_ = (int *) malloc (sizeof(int) * chunkNum_);
  endAddrPtr_ = (int *) malloc (sizeof(int) * chunkNum_ );
  currentIndexPtr_ = (int *) malloc (sizeof(int) * chunkNum_);
  isDone_ = (bool *) malloc(sizeof(bool) * chunkNum_);

  if ( !startAddrPtr_ || !endAddrPtr_ || !currentIndexPtr_ || !isDone_) 
    exit(1);
 
  int currentStartIndex = 0;
  int currentEndIndex = 0;

  inputFileName_ = new string[chunkNum_];
  fileStream_ = new ifstream[chunkNum_];

  for (int i = 0 ; i < chunkNum_ ; i++, currentStartIndex += intNumInChunk_) {
    *(startAddrPtr_ + i) = currentStartIndex;
    currentEndIndex = currentStartIndex + intNumInChunk_ - 1;
    *(endAddrPtr_ + i)  = currentEndIndex;
    *(currentIndexPtr_ + i)= -1;
    *(isDone_ + i) = false;
    stringstream ss;
    ss << "_file_name_" << i ;
    inputFileName_[i] = ss.str(); //"_file_"+i;
    //(fileStream_ + i) = new ifstream(inputFileName_[i].c_str, ios_base::in);
    cout<<"s["<<i<<"]: " <<*(startAddrPtr_ + i)<<endl;
    cout<<"e["<<i<<"]: " <<*(endAddrPtr_ + i)<<endl;
    cout<<"c["<<i<<"]: " <<*(currentIndexPtr_ + i)<<endl;
    cout<<"f["<<i<<"]: " <<inputFileName_[i]<<endl;
  }
}

template < typename T >
int MemoryManager<T>::findByMerging(int kth) {
}

template < typename T >
MemoryManager<T>::~MemoryManager() {
  cout<<"MemoryManage destructor:"<<endl;
  free(startAddrPtr_);
  free(endAddrPtr_);
  free(currentIndexPtr_);
}

int main (int argc, char** argv) {
  shared_ptr< MemoryManager<int> >  mm ( new MemoryManager<int>(1024 * 1024, 1024) );
}

