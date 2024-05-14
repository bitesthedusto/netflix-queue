// File Name: MovieList.h
//
// Author: Vladyslav Prokopenko, Jill Seaman
// Date: 3/17/2024
// Assignment Number: 5
// CS 2308 spring 2024
// Instructor: Jill Seaman

#include <string>
#include <iostream>
using namespace std;

struct MovieNode {
    string title;
    int rating;
    MovieNode *next;
};

class MovieList {
public:
    MovieList();
    ~MovieList();
    void display(ostream& out);
    void lookupByRating(ostream& out, int rating);
    void addToTop(string title, int rating);
    void addToBottom(string title, int rating);
    bool remove(int n);
    bool moveToTop(string title);
    string nextLarger(string t);
    void displaySorted(ostream& out);
private:
    MovieNode* top;
};


