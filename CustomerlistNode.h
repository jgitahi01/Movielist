#ifndef POLYLIST_H
#define POLYLIST_H
#include <iostream>
#include <string>
using namespace std;

/****** CustomerlistNode class specifications ******/
class CustomerlistNode
{
public:
   CustomerlistNode();
   CustomerlistNode(int customerid, int creditCardNumber, string customerName, date creditCardExpirationDate,
   int creditCardValidationKey, int numberOfMoviesActive);
   void InsertAfter(CustomerlistNode *ptr);
   void SetNext(CustomerlistNode *ptr);
   int GetCustomerID();
   int GetCreditCardNumber();
   string GetCustomerName();
   int GetCreditCardValidationKey();
   int GetNumberOfMoviesActive();
   date GetCreditCardExpirationDate();
   
  
   CustomerlistNode *GetNext();
   void PrintCustomerlistNode();

private:
   int customerid; int creditCardNumber; string customerName; date creditCardExpirationDate;
   int creditCardValidationKey; int numberOfMoviesActive;
   CustomerlistNode *nextNodePtr;
};

/****** Customerlist class specifications ******/
class Customerlist
{
private:
   CustomerlistNode *head;
   CustomerlistNode *tail;

public:
   Customerlist();
   void AddCustomer(int customerid, int creditCardNumber, string customerName, date creditCardExpirationDate,
   int creditCardValidationKey, int numberOfMoviesActive);
   bool RemoveCustomer(int customerid);
   void PrintCustomerList();
   
  
};
#endif
