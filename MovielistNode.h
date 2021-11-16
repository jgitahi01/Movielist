#ifndef POLYLIST_H
#define POLYLIST_H
#include <iostream>
#include <string>
using namespace std;

/****** MovielistNode class specifications ******/
class MovielistNode
{
public:
   MovielistNode();
   MovielistNode(string id, string moviename, string actor, int length);
   void InsertAfter(MovielistNode *ptr);
   void SetNext(MovielistNode *ptr);
   string GetID();
   string GetMovieName();
   string GetActorName();
   int GetMovieLength();
   MovielistNode *GetNext();
   void PrintMovielistNode();

private:
   string uniqueID;
   string movieName;
   string actorName;
   int movieLength;
   MovielistNode *nextNodePtr;
};

/****** Movielist class specifications ******/
class Movielist
{
private:
   MovielistNode *head;
   MovielistNode *tail;

public:
   Movielist();
   void AddMovie(string id, string moviename, string actorname, int length);
   bool RemoveMovie(string id);
   void PrintList();
   bool ChangePosition(int oldPos, int newPos);
   void MoviesByActor(string actor);
   int TotalTime();
};
#endif
