// filename: MovieList.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.9 PA#5 Netflix DVD queue
// 03/27/24
// CS2308 Spring 2024
// MovieList Function Definions

#include <iostream>
using namespace std;

#include "MovieList.h"

// creates an empty list, and deallocates all the nodes in the list
MovieList::MovieList() {
   
   top = nullptr;
   
}

// deallocates all the nodes in list
MovieList::~MovieList() {
   
   MovieNode *p;
   p = top;
   while (p != nullptr)  {
      
      MovieNode *temp = p;
      p = p->next;
      delete temp;
   }
   
   top = nullptr;
}
   
// print movie tites and ratings from top to bottom, with positions numbered
// (put a colon and a space between the number and movie title, followed by
// rating in parenthesis) one movie per line. use out << instead of cout <<
// uses out instead of cout to display
void MovieList::display(ostream& out) {
   
   int position = 0;
   
   MovieNode *p = top;
   while (p != nullptr) {
      
      out << position << ": " << p->title << " (" << p->rating << ")" << endl;
      p = p->next;
      position++;
   }
}
   
// print movie titles (from top to bottom) with the given rating
// out to display
// rating for rating of each movie
void MovieList::lookupByRating(ostream& out, int rating) {
   
   MovieNode *p = top;
   
   while (p != nullptr) {
      
      if (p->rating == rating) {
         
         out << p->title << endl;
      }
      
      p = p->next;
   }
   
}
   
// add a movie to the top of the list
// title for movie title
// rating for movie rating
void MovieList::addToTop(string title, int rating) {
    
   MovieNode *newTop = new MovieNode;
   newTop->title = title;
   newTop->rating = rating;
   
   newTop->next = top;
   top = newTop;
}

// add a movie to the bottom of the list
// title for movie title
// rating for movie rating
void MovieList::addToBottom(string title, int rating) {
   
   MovieNode *newNode = new MovieNode;
   newNode->title = title;
   newNode->rating = rating;
   newNode->next = nullptr;
   
   if (top == nullptr) {
      
      top = newNode;
   }
   else {
      MovieNode *p = top;
      while (p->next != nullptr) {
         
         p = p->next;
      }
      p->next = newNode;
      
   }
}
   
// Remove a movie at the given position. Return true successful, false if
// there is no movie at position n
// n for movie position in list
bool MovieList::remove(int n) {
   
   if (top == nullptr || n < 0) {
      
      return false;
   }
   
   if (n == 0) {
      
      MovieNode *temp = top;
      top = top->next;
      delete temp;
      return true;
   }
   
   MovieNode *p = top;
   for (int i = 0; p != nullptr && i < n - 1; ++i) {
      
      p = p->next;
   }
   
   if (p == nullptr || p->next == nullptr) {
      
      return false;
   }
   
   MovieNode *temp = p->next;
   p->next = temp->next;
   delete temp;
   return true;
   
}

// move a movie with given title to position 0 (top)
// title for title of movie
bool MovieList::moveToTop(string title) {
   
   if (top == nullptr) {
      
      return false;
   }
   
   if (top->title == title) {
      
      return true;
   }
   
   MovieNode *previous = nullptr;
   MovieNode *p = top;
   
   while (p != nullptr && p->title != title) {
      
      previous = p;
      p = p->next;
   }
   
   if (p == nullptr) {
      
      return false;
   }
   
   previous->next = p->next;
   p->next = top;
   top = p;
   return true;
   
}
   
// nextLarger returns the movie title (string t) that would come next after
// the title t in alphabetical order. Hint: use the algo to find the minimum
// string in a list, but ignore any movie with title t, and any that come
// before it in alphabetical order
// t for given title to compare to
string MovieList::nextLarger(string t) {
   
   string nextLargerTitle = "";
   MovieNode *p = top;
   
   while (p != nullptr) {
      
      if (p->title > t && (nextLargerTitle == "" || p->title < nextLargerTitle))
      {
         
         nextLargerTitle = p->title;
         
      }
      
      p = p->next;
   }
   
   return nextLargerTitle;
}
   
// Use (i.c. call) netLarger(string) to output the titles in sorted order with
// positions numbered. Do NOT sort the linked list, it shoud remain in
// the same order. Call nextLarger on the empty string to find the first one
// out to display
void MovieList::displaySorted(ostream& out) {
   
   string nextTitle = nextLarger("");
   int position = 0;
   
   while (!nextTitle.empty()) {

      out << position++ << ": " << nextTitle << endl;
      nextTitle = nextLarger(nextTitle);
      
   }
}

