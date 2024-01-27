#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // if there's no more room in the back
  if(empty()){
    Item* item = new Item;
    head_ = item;
    tail_ = item;
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
    size_ = 1;
  }
  else if(tail_->last == ARRSIZE){
    Item* item = new Item;
    item->prev = tail_;
    tail_->next = item;
    tail_ = item;
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
    size_++;
  }
  else {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::pop_back()
{
  // if nothing in list
  if(empty()){
    return;
  }
  // if one thing in list
  if(size() == 1){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
  }
  // if one thing in node but other items exist
  else if(tail_->last - tail_->first == 1){
    // delete this item
    // change the other items pointers
    Item* temp = tail_;
    tail_ = temp->prev;
    tail_->next = NULL;
    delete temp;
    size_--;
  }
  else {
    tail_->last--;
    size_--;
  }

}

void ULListStr::push_front(const std::string& val)
{
  // if list is empty
  if(empty()){
    Item* item = new Item;
    head_ = item;
    tail_ = item;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    size_ = 1;
  }
  // if there's no more room in the front
  else if(head_->first == 0){
    // make new Item
    Item* item = new Item;
    // new item points to curr item
    item->next = head_;
    // curr item points to new item
    head_->prev = item;
    head_ = item;
    head_->first = ARRSIZE -1;
    head_->val[head_->first] = val;
    head_->last = ARRSIZE;
    size_++;
  }
  else {
    // curr item is not full, don't need to make new item
    head_->val[head_->first - 1] = val;
    // update first
    head_->first--;
    size_++;
  }
}

void ULListStr::pop_front()
{
  // if list is empty
  if(empty()){
    return;
  }
  // if there's only one element in list
  if(size() == 1){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
  }
  // if there's one element in item but other items exist
  else if(head_->last - head_->first == 1){
    Item* temp = head_;
    head_ = temp->next;
    head_->prev = NULL;
    delete temp;
    size_--;
  }
  // normal case
  else {
    head_->first++;
    size_--;
  }
  
}

std::string const & ULListStr::back() const
{
  // don't need to consider empty list case
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc < size()){
    Item* temp = head_;
    while(temp){
      size_t itemsize = temp->last-temp->first;
      if(loc < itemsize){
        return &(temp->val[temp->first + loc]);
      }
      else {
        loc -= itemsize;
        temp = temp->next;
      }
    }
  }
  return NULL;
  
  
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
