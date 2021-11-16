#ifndef POLYLIST_H
#define POLYLIST_H
#include <iostream>
#include <string>
using namespace std;

/****** MovielistNode class specifications ******/
class LoanlistNode
{
public:
   LoanlistNode();
   LoanlistNode(int loanid, int movieid, int customerid, string status ,date dueDate, time dueTime);
   void InsertAfter(LoanlistNode *ptr);
   void SetNext(LoanlistNode *ptr);
   int GetLoanID();
   int GetMovieID();
   string GetStatus();
  
   LoanlistNode *GetNext();
   void PrintLoanlistNode();

private:
   int loanid; int movieid; int customerid; string status; date dueDate; time dueTime;
   LoanlistNode *nextNodePtr;
};

/****** Loanlist class specifications ******/
class Loanlist
{
private:
   LoanlistNode *head;
   LoanlistNode *tail;

public:
   Loanlist();
   void AddLoan(int loanid, int movieid, int customerid, string status ,date dueDate, time dueTime);
   bool RemoveLoan(string id);
   void PrintList();
   bool ChangePosition(int oldPos, int newPos);
   int TotalLoans();
};
#endif
