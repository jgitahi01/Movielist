#include "CustomerlistNode.h"

/****** Customerlist class implementation ******/

// Default constructor implementation
CustomerlistNode::CustomerlistNode()
{
    customerid = 0; 
    creditCardNumber = 0;
    customerName = "";
    creditCardExpirationDate; 
    creditCardValidationKey = 0;
    numberOfMoviesActive = 0; 
    
}

// Parameterized constructor implementation
CustomerlistNode::CustomerlistNode(int customerid, int creditCardNumber, string customerName, date creditCardExpirationDate,
   int creditCardValidationKey, int numberOfMoviesActive)
{
    customerid= customerid;
    creditCardNumber = creditCardNumber;
    customerName = customerName;
    creditCardExpirationDate = creditCardExpirationDate;
    creditCardValidationKey = creditCardValidationKey;
    numberOfMoviesActive = numberOfMoviesActive;
}

// InsertAfter function implementation
void CustomerlistNode::InsertAfter(CustomerlistNode *ptr)
{
    this->SetNext(ptr->GetNext());
    ptr->SetNext(this);
}

// SetNext function implementation
void CustomerlistNode::SetNext(CustomerlistNode *ptr)
{
    nextNodePtr = ptr;
}


// Get Customer ID function implementation
int CustomerlistNode::GetCreditCardNumber()
{
    return creditCardNumber;
}


int CustomerlistNode::GetCreditCardValidationKey()
{
    return creditCardValidationKey;
}
// Get Customer ID function implementation
int CustomerlistNode::GetCustomerID()
{
    return customerid;
}

int CustomerlistNode::GetNumberOfMoviesActive()
{
    return numberOfMoviesActive;
}


// Get customerName function implementation
string CustomerlistNode::GetCustomerName()
{
    return customerName;
}


date CustomerlistNode::GetCreditCardExpirationDate()
{
    return creditCardExpirationDate;
}




// GetNext function implementation
CustomerlistNode *CustomerlistNode::GetNext()
{
    return nextNodePtr;
}

// PrintCustomerlistNode function implementation
void CustomerlistNode::PrintCustomerlistNode()
{
    cout << "Customer ID: " << Customerid << endl;
    cout << "creditCardNumber: " << creditCardNumber << endl;
    cout << "customerName: " << customerName << endl;
    cout << "creditCardExpirationDate: " << creditCardExpirationDate << endl;
    cout << "creditCardValidationKey: " << creditCardValidationKey << endl;
    cout << "numberOfMoviesActive: " << numberOfMoviesActive << endl;
   
}

/****** Customerlist class implementation ******/

// Default constructor implementation
Customerlist::Customerlist()
{
    head = tail = 0;
}

// AddCustomer function implementation
void Customerlist::AddCustomer(int customerid, int creditCardNumber, string customerName, date creditCardExpirationDate,
   int creditCardValidationKey, int numberOfMoviesActive)
{
    CustomerlistNode *n = new CustomerlistNode(customerid,creditCardNumber,customerName,creditCardExpirationDate
        ,creditCardValidationKey ,numberOfMoviesActive);
    if (head == 0)
        head = tail = n;
    else
    {
        n->InsertAfter(tail);
        tail = n;
    }
}

// RemoveCustomer function implementation
bool Customerlist::RemoveCustomer(int customerid)
{
    if (head == NULL)
    {
        cout << "Customerlist is empty" << endl;
        return false;
    }

    CustomerlistNode *curr = head;
    CustomerlistNode *prev = NULL;
    while (curr != NULL)
    {
        if (curr->GetCustomerID() == customerid)
        {
            break;
        }
        prev = curr;
        curr = curr->GetNext();
    }

    if (curr == NULL) //not found
    {
        cout << "\"" << curr->GetCustomerID() << "\" is not found" << endl;
        return false;
    }
    else
    {
        if (prev != NULL)
            prev->SetNext(curr->GetNext());
        else
            head = curr->GetNext();

        if (tail == curr)
            tail = prev;
        cout << "\"" << curr->GetCustomerID() << "\" removed." << endl;
        delete curr;
        return true;
    }
}






// PrintList function implementation
void Customerlist::PrintCustomerList()
{
    if (head == NULL)
        cout << "Customerlist is empty" << endl;
    else
    {
        CustomerlistNode *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            cout << endl
                 << i++ << "." << endl;
            curr->PrintCustomerlistNode();
            curr = curr->GetNext();
        }
    }
}
