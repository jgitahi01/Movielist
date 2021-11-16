#include "LoanlistNode.h"

/****** Loanlist class implementation ******/

// Default constructor implementation
LoanlistNode::LoanlistNode()
{
     loanid = 0; 
    movieid = 0 ; 
    customerid = 0;
    status ="null";
    dueDate; 
    dueTime;
}

// Parameterized constructor implementation
LoanlistNode::LoanlistNode(int loanid, int movieid, int customerid, string status ,date dueDate, time dueTime)
{
    loanid= loanid;
    movieid = movieid;
    customerid = customerid;
    status = status;
    dueDate = dueDate;
    dueTime = dueTime;
}

// InsertAfter function implementation
void LoanlistNode::InsertAfter(LoanlistNode *ptr)
{
    this->SetNext(ptr->GetNext());
    ptr->SetNext(this);
}

// SetNext function implementation
void LoanlistNode::SetNext(LoanlistNode *ptr)
{
    nextNodePtr = ptr;
}

// Get Loan ID function implementation
int LoanlistNode::GetLoanID()
{
    return loanid;
}

// Get movie ID function implementation
int LoanlistNode::GetMovieID()
{
    return movieid;
}

// Get status function implementation
string LoanlistNode::GetStatus()
{
    return status;
}



// GetNext function implementation
LoanlistNode *LoanlistNode::GetNext()
{
    return nextNodePtr;
}

// PrintLoanlistNode function implementation
void LoanlistNode::PrintLoanlistNode()
{
    cout << "Loan ID: " << loanid << endl;
    cout << "Movie ID: " << movieid << endl;
    cout << "Customer ID: " << customerid << endl;
    cout << "Status: " << status << endl;
   
}

/****** Loanlist class implementation ******/

// Default constructor implementation
Loanlist::Loanlist()
{
    head = tail = 0;
}

// AddLoan function implementation
void Loanlist::AddLoan(int loanid, int movieid, int customerid, string status ,date dueDate, time dueTime)
{
    LoanlistNode *n = new LoanlistNode(loanid, movieid, customerid,status, dueDate,dueTime);
    if (head == 0)
        head = tail = n;
    else
    {
        n->InsertAfter(tail);
        tail = n;
    }
}

// RemoveLoan function implementation
bool Loanlist::RemoveLoan(int loanid)
{
    if (head == NULL)
    {
        cout << "Loanlist is empty" << endl;
        return false;
    }

    LoanlistNode *curr = head;
    LoanlistNode *prev = NULL;
    while (curr != NULL)
    {
        if (curr->GetLoanID() == loanid)
        {
            break;
        }
        prev = curr;
        curr = curr->GetNext();
    }

    if (curr == NULL) //not found
    {
        cout << "\"" << curr->GetLoanID() << "\" is not found" << endl;
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
        cout << "\"" << curr->GetLoanID() << "\" removed." << endl;
        delete curr;
        return true;
    }
}






// PrintList function implementation
void Loanlist::PrintList()
{
    if (head == NULL)
        cout << "Loanlist is empty" << endl;
    else
    {
        LoanlistNode *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            cout << endl
                 << i++ << "." << endl;
            curr->PrintLoanlistNode();
            curr = curr->GetNext();
        }
    }
}
