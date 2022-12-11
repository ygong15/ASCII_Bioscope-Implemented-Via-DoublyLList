// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection

#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        // Constructors
        Iterator()
        {
            // assign the node pointer to null
            mCurr = nullptr;
		}
        
        Iterator(Node* inCurr)
        {
            // equite mCurr to the input node pointer
            mCurr = inCurr;
        }
        
        Iterator(const Iterator& src)
        {
            // equite mCurr to src.mCurr;
            mCurr = src.mCurr;
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
            // equite mCurr to src.mCurr
            mCurr = src.mCurr;
            return *this; // FIX RETURN VALUE
		}
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            // point iterator to the next node
            mCurr = mCurr->mNext;
            return *this; // FIX RETURN VALUE
		}
        
        // i++
        Iterator operator++(int)
        {
            // copy-construct a identical iterator
            Iterator retval(*this);
            // point mCurr to the next node. Since retval is a shallow copy, retval's mCurr will also be moved forward
            mCurr = mCurr->mNext;
            // return retval
            return retval; // FIX RETURN VALUE
        }
        
        // --i
        Iterator& operator--()
        {
            // point mCurr to the prev node
            mCurr = mCurr->mPrev;
            // return this iterator
            return *this; // FIX RETURN VALUE
        }
        
        // i--
        Iterator operator--(int)
        {
            // copy construct a iterator
            Iterator retval(*this);
            mCurr = mCurr -> mPrev;
            // return the copy constructed iterator
            return retval; // FIX RETURN VALUE
        }
        
        // Dereference
        T& operator*() const
        {
            // return the value in the node pointed by mCurr
            return mCurr->mData; // FIX RETURN VALUE
        }
        
        Node* operator->() const
        {
            // return mCurr (node pointer)
            return mCurr; // FIX RETURN VALUE
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            // compare whether the two mCurr are pointing to the same node
            return mCurr == rhs.mCurr; // FIX RETURN VALUE
        }
        
        bool operator!=(const Iterator& rhs) const
        {
            // compare whether the two mCurr are pointing to the same node
            return mCurr != rhs.mCurr; // FIX RETURN VALUE
        }
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        // point head to null and tail to null
        mHead = nullptr;
        mTail = nullptr;
        // initialize size to 0
        mSize = 0;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
        // set size to 0
        mSize = 0;
        // set head and tail ptr to null
        mHead = nullptr;
        mTail = nullptr;
        // use a iterator to traverse the other list and push_back all its elements
        Iterator itr = other.begin();
        // traverse the other list and push_back each elements into this list
        while (itr != other.end()) {
            push_back(*itr);
            itr++;
        }
    }
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        // call the clear() function
        clear();
	}
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        // keep calling pop_front while mSize > 0
        while(mSize > 0)
        {
            pop_front();
        }
    }
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
        // call the clear() function to clear elements in the current list
        clear();
        // create an iterator temp to point at the beginign of the other list
        Iterator temp = other.begin();
        // push_back value points by temp into the current list
        while(temp != other.end())
        {
            push_back(*temp);
            temp++;
        }
        return *this;
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        // return mSize;
        return mSize;
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        //allocate a new node
        Node* newNode = new Node();
        newNode->mData = value;
        newNode->mPrev = nullptr;
        //new node's next should point to the current head
        newNode->mNext = mHead;
        //if the list is empty, the new node is also the tail
        if(mSize == 0)
        {
            mTail = newNode;
        }
        //if not empty
        else
        {
            //current head's previous needs to point to the new node
            mHead->mPrev = newNode;
        }
        //head should be the new node
        mHead = newNode;
        
        mSize++;
        
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        // return the value in the node points by mHead
        if(mHead == nullptr)
        {
            throw std::out_of_range("list is empty");
        }
        return mHead->mData;
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        if(mSize == 0)
        {
            throw std::out_of_range("cannot pop from an empty list");
        }
        else if(mSize == 1)
        {
            //delete the head node
            delete mHead;
            //set head and tail to null
            mHead = nullptr;
            mTail = nullptr;
            //decrement size by 1
            mSize--;
        }
        else
        {
            //set a temp point to the currently second node
            Node* temp = mHead->mNext;
            //delete the current head node
            delete mHead;
            //point the head to temp
            mHead = temp;
            //point temp's prev to null
            mHead->mPrev = nullptr;
            //decrement size by 1
            mSize--;
        }
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        //allocate the new node
        Node* newNode = new Node();
        newNode->mData = value;
        //set newNode's prev to the current tail
        newNode->mPrev = mTail;
        //set newNOde's next to null since this is the tail
        newNode->mNext = nullptr;
        //if the list is empty, the head is the newNode
        if(mSize == 0)
        {
            mHead = newNode;
        }
        //if the size is not empty, set the current tail's next to the new node
        else
        {
            mTail->mNext = newNode;
        }
        //set the tail to the new node
        mTail = newNode;
        //increment size by 1
        mSize++;
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& back()
    {
        // return the value in the node points by mTail
        if(mTail == nullptr)
        {
            throw std::out_of_range("tail is empty");
        }
        return mTail->mData;
        
    }

    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        // if the size is 0, throw an exception
        if(mSize == 0)
        {
            throw std::out_of_range("cannot pop since the list is empty");
        }
        // if the size is 1
        else if(mSize == 1)
        {
            //delete the tail node
            delete mTail;
            //point both mHead and mTail to null
            mTail = nullptr;
            mHead = nullptr;
            //decrement size by 1
            mSize--;
        }
        // if the list contains more than one node
        else
        {
            //create a temp points to the second to last node
            Node* temp = mTail->mPrev;
            //delete the tail node
            delete mTail;
            //point tail to temp
            mTail = temp;
            //set temp's next to null
            temp->mNext = nullptr;
            //decrement size by 1
            mSize--;
        }
    }
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
        // if the list is empty, return a iterator pointing to null
        if(mSize == 0)
        {
            return Iterator();
        }
        // return an iterator constructed with the head node if the list is not empty
        return Iterator(mHead);
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        // since end() will return a Iterator points to null, we can just return a default iterator
        return Iterator();
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
        //check if iterator is invalid by check if == end() or if mCurr is pointing to null
        if(i == end() || i.mCurr == nullptr)
        {
            throw std::out_of_range("cannot insert beyond the last node");
        }
        //pointing to the first node
        else if(i == begin())
        {
            pop_front();
            return begin();
        }
        //pointing to the last node
        else if(i->mNext == nullptr)
        {
            pop_back();
            return end();
        }
        //make three pointers point to the current node, the node before, and the node after
        Node* before = i->mPrev;
        Node* after = i->mNext;
        Node* toDel = i.mCurr;
        //delete the current node
        delete toDel;
        //point before's next to after
        before->mNext = after;
        //point after's prev to before
        after->mPrev = before;
        //decrement size by 1
        mSize--;
        return Iterator(after);
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        //check the validity of iterator by checking end() or pointing to null
        if(i == end())
        {
            //throw out of range exception
            throw std::out_of_range("can not insert pass the last node");
        }
        else if(i==begin())
        {
            //push front and return the first node if pointing to begin
            push_front(val);
            return begin();
        }
        //pointing to a middle node
        Node* before = i->mPrev;
        Node* after = i.mCurr;
        //allocate a new node
        Node* newNode = new Node();
        //set new node's val to passed in val
        newNode->mData = val;
        //new node prev to before
        newNode->mPrev = before;
        //new node next to after
        newNode->mNext = after;
        //set before's next to the new node
        before->mNext = newNode;
        //set after's prev to the new node
        after->mPrev = newNode;
        //increment size by 1
        mSize++;
        //return an iterator pointing to the new node
        return Iterator(newNode);
    }
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        //putting in the begining {
        os<<"{";
        //create an iterator pointing to the head
        Iterator temp = list.begin();
        //loop through the entire list
        while(temp != list.end())
        {
            //if we are at the last node, we do not add the ","
            if(temp.mCurr == list.mTail)
            {
                os<<*temp;
            }
            //if we are not at the last node, we add in the value, "," and a space
            else
            {
                os<<*temp<<",";
            }
            //increment iterator
            temp++;
        }
        //add in the back "}";
        os << "}";
        //return the stream
        return os;
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::ostringstream val;
        val << "{";
        Iterator temp = begin();
        //loop through the entire list
        while(temp != end())
        {
            //if we are at the last node, we do not add the ","
            if(temp.mCurr == mTail)
            {
                val<<*temp;
            }
            //if we are not at the last node, we add in the value, "," and a space
            else
            {
                val<<*temp<<",";
            }
            //increment iterator
            temp++;
        }
        //add in the back "}";
        val << "}";
        //return string
        return val.str();
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        //deal with an empty list
        if(mSize == 0)
        {
            return "{}";
        }
        //initialize a iterator pointing at end
        Iterator temp = begin();
        while(temp->mNext != nullptr)
        {
            temp++;
        }
        //initialize an empty string for return
        std::stringstream val;
        //add in the fornt {
        val << "{";
        //loop through the entire list
        while(temp != begin())
        {
            val << *temp;
            val << ",";
            temp--;
        }
        //we are at the first node, add it in
        val << *temp;
        //add in the back }
        val << "}";
        //return the string
        return val.str();
    }
};
