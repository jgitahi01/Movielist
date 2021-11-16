#include "MovielistNode.h"

/****** Movielist class implementation ******/

// Default constructor implementation
MovielistNode::MovielistNode()
{
    uniqueID = "none";
    movieName = "none";
    actorName = "none";
    movieLength = 0;
    nextNodePtr = 0;
}

// Parameterized constructor implementation
MovielistNode::MovielistNode(string id, string moviename, string actor, int length)
{
    uniqueID = id;
    movieName = moviename;
    actorName = actor;
    movieLength = length;
    nextNodePtr = 0;
}

// InsertAfter function implementation
void MovielistNode::InsertAfter(MovielistNode *ptr)
{
    this->SetNext(ptr->GetNext());
    ptr->SetNext(this);
}

// SetNext function implementation
void MovielistNode::SetNext(MovielistNode *ptr)
{
    nextNodePtr = ptr;
}

// GetID function implementation
string MovielistNode::GetID()
{
    return uniqueID;
}

// GetmovieName function implementation
string MovielistNode::GetMovieName()
{
    return movieName;
}

// GetactorName function implementation
string MovielistNode::GetActorName()
{
    return actorName;
}

// GetmovieLength function implementation
int MovielistNode::GetMovieLength()
{
    return movieLength;
}

// GetNext function implementation
MovielistNode *MovielistNode::GetNext()
{
    return nextNodePtr;
}

// PrintMovielistNode function implementation
void MovielistNode::PrintMovielistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "movie Name: " << movieName << endl;
    cout << "actor Name: " << actorName << endl;
    cout << "movie Length (in hours/mins): " << movieLength << endl;
}

/****** Movielist class implementation ******/

// Default constructor implementation
Movielist::Movielist()
{
    head = tail = 0;
}

// Addmovie function implementation
void Movielist::AddMovie(string id, string moviename, string actorname, int length)
{
    MovielistNode *n = new MovielistNode(id, moviename, actorname, length);
    if (head == 0)
        head = tail = n;
    else
    {
        n->InsertAfter(tail);
        tail = n;
    }
}

// Removemovie function implementation
bool Movielist::RemoveMovie(string id)
{
    if (head == NULL)
    {
        cout << "Movielist is empty" << endl;
        return false;
    }

    MovielistNode *curr = head;
    MovielistNode *prev = NULL;
    while (curr != NULL)
    {
        if (curr->GetID() == id)
        {
            break;
        }
        prev = curr;
        curr = curr->GetNext();
    }

    if (curr == NULL) //not found
    {
        cout << "\"" << curr->GetMovieName() << "\" is not found" << endl;
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
        cout << "\"" << curr->GetMovieName() << "\" removed." << endl;
        delete curr;
        return true;
    }
}

// ChangePosition function implementation
bool Movielist::ChangePosition(int oldPos, int newPos)
{
    if (head == NULL)
    {
        cout << "Movielist is empty" << endl;
        return false;
    }

    MovielistNode *prev = NULL;
    MovielistNode *curr = head;

    int pos;
    if (head == NULL || head == tail)
        return false;

    //first locate the node that is to be move
    for (pos = 1; curr != NULL && pos < oldPos; pos++)
    {
        prev = curr;
        curr = curr->GetNext();
    }
    if (curr != NULL) //found a node at given position
    {
        string currentmovie = curr->GetMovieName();

        // delete it from the current list and later insert it
        // into the list at specified new poistion
        // after removing it from the curretn list, we don't
        // deallocate it but simply insert it in new position
        if (prev == NULL)
            head = curr->GetNext();
        else
        {
            prev->SetNext(curr->GetNext());
        }

        if (curr == tail) //if we removed the tail node
            tail = prev;

        MovielistNode *curr1 = curr;
        prev = NULL;
        curr = head;
        //now locate the new position
        for (pos = 1; curr != NULL && pos < newPos; pos++)
        {
            prev = curr;
            curr = curr->GetNext();
        }

        //insert in located position

        if (prev == NULL)
        {
            curr1->SetNext(head);
            head = curr1;
        }
        else
            curr1->InsertAfter(prev);

        if (curr == NULL)
            tail = curr1;

        cout << "\"" << currentmovie << "\" moved to position " << newPos << endl;
        return true;
    }
    else
    {
        cout << "Movie's current position is invalid" << endl;
        return false;
    }
}

// moviesByactor function implementation
void Movielist::MoviesByActor(string actor)
{
    if (head == NULL)
        cout << "Movielist is empty" << endl;
    else
    {
        MovielistNode *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (curr->GetActorName() == actor)
            {
                cout << endl
                     << i << "." << endl;
                curr->PrintMovielistNode();
            }
            curr = curr->GetNext();
            i++;
        }
    }
}

// TotalTime function implementation
int Movielist::TotalTime()
{
    int total = 0;
    MovielistNode *curr = head;

    while (curr != NULL)
    {
        total += curr->GetMovieLength();
        curr = curr->GetNext();
    }

    return total;
}

// PrintList function implementation
void Movielist::PrintList()
{
    if (head == NULL)
        cout << "Movielist is empty" << endl;
    else
    {
        MovielistNode *curr = head;
        int i = 1;
        while (curr != NULL)
        {
            cout << endl
                 << i++ << "." << endl;
            curr->PrintMovielistNode();
            curr = curr->GetNext();
        }
    }
}
