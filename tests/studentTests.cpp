#include <string>
#include <sstream>
#include <fstream>

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "ITPDoubleList.hpp"
#include "movie.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Student list tests", "[student]")
{
    
	SECTION("Default constructor, size, and destructor")
	{

        {
            ITPDoubleList<int> myList;
            REQUIRE(myList.size() == 0);
        }
        REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
        {
            ITPDoubleList<int> myList;
            //push an element into the list
            
            
            for(int i = 0; i < 10; i++)
            {
                myList.push_front(i+10);
                //if there's only 1 element, front should equal to back
                if(i == 0)
                {
                    REQUIRE(myList.front() == myList.back());
                    //check value in front
                    REQUIRE(myList.front() == i+10);
                    //check value in back
                    REQUIRE(myList.back() == i+10);
                }
                //if there's more than 1 element, back should always equal to 10 and front will increment by 10
                else
                {
                //check value in back (constantly = 10)
                REQUIRE(myList.back() == 10);
                //check value in front
                REQUIRE(myList.front() == i+10);
                }
            }
            //check the number of elements is correct or not
            REQUIRE(myList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{19,18,17,16,15,14,13,12,11,10}");
            REQUIRE(myList.toReverseString() == "{10,11,12,13,14,15,16,17,18,19}");
        }
        REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
        {
            ITPDoubleList<int> myList;
            //push 10 elements into the list
            for(int i = 0; i < 10; i++)
            {
                myList.push_front(i+10);
                //if there's only 1 element, front should equal to back
                if(i == 0)
                {
                    REQUIRE(myList.front() == myList.back());
                    //check value in front
                    REQUIRE(myList.front() == i+10);
                    //check value in back
                    REQUIRE(myList.back() == i+10);
                }
                //if there's more than 1 element, back should always equal to 10 and front will increment by 10
                else
                {
                //check value in back (constantly = 10)
                REQUIRE(myList.back() == 10);
                //check value in front
                REQUIRE(myList.front() == i+10);
                }
            }
            //check the number of elements is correct or not
            REQUIRE(myList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{19,18,17,16,15,14,13,12,11,10}");
            REQUIRE(myList.toReverseString() == "{10,11,12,13,14,15,16,17,18,19}");
            
            //start poping back
            for(int i = 0; i < 10; i++)
            {
                //check if each element is correctly poped off
                REQUIRE(myList.front() == (9 - i) + 10);
                myList.pop_front();
                //check if the size is correctly decremented
                REQUIRE(myList.size() == 10-(i+1));
            }
            //check if the list is empty and has a size of 0
            REQUIRE(myList.size() == 0);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{}");
            REQUIRE(myList.toReverseString() == "{}");
        }
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{
        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
                //if there's only 1 element, front should equal to back
                if(i == 0)
                {
                    REQUIRE(myList.front() == myList.back());
                    //check value in front
                    REQUIRE(myList.front() == i+10);
                    //check value in back
                    REQUIRE(myList.back() == i+10);
                }
                //if there's more than 1 element, back should always equal to 10 and front will increment by 10
                else
                {
                    //check value in front (constantly = 10)
                    REQUIRE(myList.front() == 10);
                    //check value in back
                    REQUIRE(myList.back() == i+10);
                }
            }
            //check the number of elements is correct or not
            REQUIRE(myList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(myList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
        }
        // Leave this at the end
        REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
        {
            ITPDoubleList<int> myList;
            //push 10 elements into the list
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
                //if there's only 1 element, front should equal to back
                if(i == 0)
                {
                    REQUIRE(myList.front() == myList.back());
                    //check value in front
                    REQUIRE(myList.front() == i+10);
                    //check value in back
                    REQUIRE(myList.back() == i+10);
                }
                //if there's more than 1 element, back should always equal to 10 and front will increment by 10
                else
                {
                //check value in front (constantly = 10)
                REQUIRE(myList.front() == 10);
                //check value in back
                REQUIRE(myList.back() == i+10);
                }
            }
            //check the number of elements is correct or not
            REQUIRE(myList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(myList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
            
            //start poping back
            for(int i = 0; i < 10; i++)
            {
                //check if each element is correctly poped off
                REQUIRE(myList.back() == (9 - i) + 10);
                myList.pop_back();
                //check if the size is correctly decremented
                REQUIRE(myList.size() == 10-(i+1));
            }
            //check if the list is empty and has a size of 0
            REQUIRE(myList.size() == 0);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{}");
            REQUIRE(myList.toReverseString() == "{}");
        }

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
        {
            //create a list and put 10 elements in it
           ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            //check if the size is correcly == 10
            REQUIRE(myList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(myList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
            //call clear on the list
            myList.clear();
            //check if the size is restored to 0
            REQUIRE(myList.size() == 0);
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{}");
            REQUIRE(myList.toReverseString() == "{}");
        }

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
        {
            //create a list and put 10 elements in it
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(myList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
            //invoke copy constructor to create a deep copy list
            ITPDoubleList<int> copyList = myList;
            //check if the copied list is identical to the original list
            for(int i = 0; i < 10; i++)
            {
                REQUIRE(myList.front() == copyList.front());
                REQUIRE(myList.back() == copyList.back());
            }
            //check if the list is correct using toString and toReverseString
            REQUIRE(copyList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(copyList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
            //clear the original list one by one and check if each element is successfully removed
            for(int i = 0; i < 10; i++)
            {
                myList.pop_back();
                //size should be decremented by one each time
                REQUIRE(myList.size() == 10-(i+1));
                //when poping back the original list, copied list's back should remain unchanged and always equals to 19
                REQUIRE(copyList.back() == 19);
            }
            //check if original list is emptied
            REQUIRE(myList.size() == 0);
            REQUIRE(myList.toString() == "{}");
            REQUIRE(myList.toReverseString() == "{}");
            //copied list should not be emptied
            REQUIRE(copyList.size() != 0);
            //copied list's size should remain unchanged and equal to 10
            REQUIRE(copyList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(copyList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(copyList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
        }

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            //check if the list is correct using toString and toReverseString
            REQUIRE(myList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(myList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
            //invoke copy constructor to create a deep copy list
            ITPDoubleList<int> copyList;
            //put 5 elements into the copy list
            for(int i = 0; i < 5; i++)
            {
                copyList.push_back(i+5);
            }
            //check if copy list's size is 5
            REQUIRE(copyList.size() == 5);
            //check if the list is correct using toString and toReverseString
            REQUIRE(copyList.toString() == "{5,6,7,8,9}");
            REQUIRE(copyList.toReverseString() == "{9,8,7,6,5}");
            //two lists should be different
            REQUIRE(copyList.size() != myList.size());
            //equite copyList and myList;
            copyList = myList;
            //both list should have 10 as size
            REQUIRE(copyList.size() == myList.size());
            REQUIRE(copyList.size() == 10);
            //check if the copied list is identical to the original list
            for(int i = 0; i < 10; i++)
            {
                REQUIRE(myList.front() == copyList.front());
                REQUIRE(myList.back() == copyList.back());
            }
            //clear the original list one by one and check if each element is successfully removed
            for(int i = 0; i < 10; i++)
            {
                myList.pop_back();
                //size should be decremented by one each time
                REQUIRE(myList.size() == 10-(i+1));
                //when poping back the original list, copied list's back should remain unchanged and always equals to 19
                REQUIRE(copyList.back() == 19);
            }
            //check if original list is emptied
            REQUIRE(myList.size() == 0);
            //copied list should not be emptied
            REQUIRE(copyList.size() != 0);
            //copied list's size should remain unchanged and equal to 10
            REQUIRE(copyList.size() == 10);
            //check if the list is correct using toString and toReverseString
            REQUIRE(copyList.toString() == "{10,11,12,13,14,15,16,17,18,19}");
            REQUIRE(copyList.toReverseString() == "{19,18,17,16,15,14,13,12,11,10}");
        }

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
        {
            //create a empty list
            ITPDoubleList<int> myList;
            //push five elements into the list to see if the list is working normally
            for(int i = 0; i < 5; i++)
            {
                myList.push_back(i+5);
            }
            //check if the list is correct
            REQUIRE(myList.size() == 5);
            REQUIRE(myList.toString() == "{5,6,7,8,9}");
            REQUIRE(myList.toReverseString() == "{9,8,7,6,5}");
            
            //back, front, pop_front, pop_back should not yield any exceptions at this point
            //test back and front
            REQUIRE(myList.back() == 9);
            REQUIRE(myList.front() == 5);
            //test pop back
            myList.pop_back();
            REQUIRE(myList.toString() == "{5,6,7,8}");
            //test pop front
            myList.pop_front();
            REQUIRE(myList.toString() == "{6,7,8}");
            
            //clear the LList
            myList.clear();
            REQUIRE(myList.size() == 0);
            
            /*
             *  back, front, pop_back, push_back should yield exceptions NOW
             */
            
            //testing back
            try
            {
                myList.back();
                //if doesn't throw an exception: false
                REQUIRE(false);
            }
            catch (std::out_of_range& e)
            {
                //only pass if we catch the out_of_range exception
                REQUIRE(true);
            }
            catch (std::exception& e)
            {
                //catching anyother kind of exceptions are wrong
                REQUIRE(false);
            }
            //testing front
            try
            {
                myList.front();
                //if doesn't throw an exception: false
                REQUIRE(false);
            }
            catch (std::out_of_range& e)
            {
                //only pass if we catch the out_of_range exception
                REQUIRE(true);
            }
            catch (std::exception& e)
            {
                //catching anyother kind of exceptions are wrong
                REQUIRE(false);
            }
            //test pop_back()
            try
            {
                myList.pop_back();
                //if doesn't throw an exception: false
                REQUIRE(false);
            }
            catch (std::out_of_range& e)
            {
                //only pass if we catch the out_of_range exception
                REQUIRE(true);
            }
            catch (std::exception& e)
            {
                //catching anyother kind of exceptions are wrong
                REQUIRE(false);
            }
            //testing pop_front()
            try
            {
                myList.pop_front();
                //if doesn't throw an exception: false
                REQUIRE(false);
            }
            catch (std::out_of_range& e)
            {
                //only pass if we catch the out_of_range exception
                REQUIRE(true);
            }
            catch (std::exception& e)
            {
                //catching anyother kind of exceptions are wrong
                REQUIRE(false);
            }
            
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{

        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_front(i+10);
            }
            ITPDoubleList<int>::Iterator itr = myList.begin();
            //begaining should be 10
            REQUIRE(*itr == 19);
            //begaining should == front
            REQUIRE(*itr == myList.front());
            //itr should not == back;
            REQUIRE(!(*itr == myList.back()));
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{

        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            ITPDoubleList<int>::Iterator itr;
            itr = myList.begin();
            //iterator's value should be the value of the first element
            REQUIRE(*itr == myList.front());
            //iterator should point to the front node
            REQUIRE(itr == myList.begin());
            //iterator should not point to the end()
            REQUIRE(itr != myList.end());
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
        {
            //create a 10 element list
           ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            //point iterator at the first node
            ITPDoubleList<int>::Iterator itr = myList.begin();
            //loop through the list
            for(int i = 0; i < 10; i++)
            {
                //check iterator's value at each position
                REQUIRE(*itr == i+10);
                //increment iterator by 1
                itr++;
            }
            //iterator should point to end at this point
            REQUIRE(itr == myList.end());
            //iterator should not equal to begin
            REQUIRE(itr != myList.begin());
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
        {
            //create a 10 element list
            ITPDoubleList<int> myList;
            for(int i = 0; i < 10; i++)
            {
                myList.push_back(i+10);
            }
            //point iterator at the first node
            ITPDoubleList<int>::Iterator itr = myList.begin();
            //loop through the list
            for(int i = 1; i < 10; i++)
            {
                itr++;
            }
            //iterator should NOT point to end at this point
            REQUIRE(itr != myList.end());
            //iterator should NOT equal to begin
            REQUIRE(itr != myList.begin());
            
            //we are at the last node at this point, start backtracking
            for(int i = 9; i > 0; i--)
            {
                //check if iterator point to the correct value
                REQUIRE(*itr == i+10);
                //decrement iterator by 1
                itr--;
            }
            //we should point to begin() at this point
            REQUIRE(itr == myList.begin());
            REQUIRE(itr != myList.end());
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
     
	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 5; i++)
            {
                myList.push_back(i+10);
            }
            //get the iterator
            ITPDoubleList<int>::Iterator itr = myList.begin();
            //ensure iterator is correctly point to the first value
            REQUIRE(*itr == 10);
            //insert at front
            myList.insert(itr, 999);
            REQUIRE(myList.front() == 999);
            //iterator should still point to 10
            REQUIRE(*itr == 10);
            
            //move iterator to the middle
            itr++;
            itr++;
            //check if iterator is pointing to the middle value
            REQUIRE(*itr == 12);
            //insert a value left to the itr
            myList.insert(itr, 1222);
            //check if itr is still point to 12
            REQUIRE(*itr == 12);
            
            //move iterator to the last node
            itr++;
            itr++;
            //check if iterator points correctly to the last value
            REQUIRE(*itr == 14);
            //insert a value left to the end of the list
            myList.insert(itr, 1444);
            //check if iterator is still correctly points to 14
            REQUIRE(*itr == 14);
            //move iterator to point at end(), insertion should yield an exception
            itr++;
            try
            {
                myList.insert(itr, 999);
                REQUIRE(false);
            }
            catch(std::out_of_range& e)
            {
                REQUIRE(true);
            }
            catch(std::exception& e)
            {
                REQUIRE(false);
            }
        }
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
        {
            ITPDoubleList<int> myList;
            for(int i = 0; i < 5; i++)
            {
                myList.push_back(i+10);
            }
            //point iterator to the begining
            ITPDoubleList<int>::Iterator itr = myList.begin();
            REQUIRE(*itr == 10);
            //delete the front node
            itr = myList.erase(itr);
            //check if the the first node is deleted successfully
            REQUIRE(myList.front() == 11);
            //iterator should point to the new front now
            REQUIRE(*itr == 11);
            
            //move the iterator to the middle (1 node before the last node)
            itr++;
            itr++;
            //check if iterator is correctly moved
            REQUIRE(*itr == 13);
            //delete 13
            itr = myList.erase(itr);
            //iterator should be poitning to the last node at this point
            REQUIRE(*itr == 14);
            //delete the last node
            myList.erase(itr);
            //the last node now should be 12 instead of 14
            REQUIRE(myList.back() == 12);
            
            //move the iterator to point to end
            itr++;
            //erase should cuase exceptiosn now
            try
            {
                myList.erase(itr);
                REQUIRE(false);
            }
            catch (std::out_of_range& e)
            {
                REQUIRE(true);
            }
            catch (std::exception& e)
            {
                REQUIRE(false);
            }
        }
        
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]")
{
	SECTION("Bad constructor")
	{
        {
            //create a bad file name
            std::string badFile = "asdfasdf";
            try
            {
                //try to create a momvie player, should throw an exception
                MoviePlayer movPlay (badFile);
                //if no exceptions are thrown, fail
                REQUIRE(false);
            }
            //ecveption should be invalid_argument
            catch(std::invalid_argument& e)
            {
                REQUIRE(true);
            }
            //catching any other kind of exceptions should be false
            catch(std::exception& e)
            {
                REQUIRE(false);
            }

        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
        {
            //file name for scene 2
            std::string fileName = "input/scene2.ani";
            //create a movie player with scene 2
            MoviePlayer movPly(fileName);
            //check if these three varaibles are correct, if so the entire scene is loaded correctly
            REQUIRE(movPly.getCurrFrameNum() == 1);
            REQUIRE(movPly.getNumFrames() == 69);
            REQUIRE(movPly.getFrameSize() == 13);
        }
	}

	SECTION("Checking frames, scene 2")
	{
        {
            //variable store the number of \n found in a frame
            int counter = 0;
            //variable we use to loop through a entire frame string
            int idx = 0;
            //file name for scene 2
            std::string fileName = "input/scene2.ani";
            //create a movie player with scene 2
            MoviePlayer movPly(fileName);
            
            //get the first frame
            std::string firstFrame = movPly.getCurrFrame();
            //we loop until find() return string::npos which either means we do not find the \n substring or already parsed all chars
            while ((idx = firstFrame.find("\n", idx)) != std::string::npos) {
                //we only enter in the loop when we found a \n, thus we increment counter by 1
                counter++;
                //since we found a \n, we will start our next search pass the found \n by moving idx 2 indexs forward
                idx += 2;
               }
            //the size of a frame should equal to the frame size stated by us
            REQUIRE(counter == movPly.getFrameSize());
            //reset counter and idx
            counter = 0;
            idx = 0;
            
            //arrive at second frame
            movPly.goFwrd();
            
            //get the second frame
            std::string secondFrame = movPly.getCurrFrame();
            //we loop until find() return string::npos which either means we do not find the \n substring or already parsed all chars
            while ((idx = firstFrame.find("\n", idx)) != std::string::npos) {
                //we only enter in the loop when we found a \n, thus we increment counter by 1
                counter++;
                //since we found a \n, we will start our next search pass the found \n by moving idx 2 indexs forward
                idx += 2;
               }
            //the size of a frame should equal to the frame size stated by us
            REQUIRE(counter == movPly.getFrameSize());
            //reset counter and idx
            counter = 0;
            idx = 0;
            //since we place the first frame three times, second frame should equal to first frame too
            REQUIRE(firstFrame.compare(secondFrame) == 0);
            
            //arrive at the fourth frame
            movPly.goFwrd();
            movPly.goFwrd();
            
            //get the fourth frame
            std::string fourthFrame = movPly.getCurrFrame();
            //we loop until find() return string::npos which either means we do not find the \n substring or already parsed all chars
            while ((idx = firstFrame.find("\n", idx)) != std::string::npos) {
                //we only enter in the loop when we found a \n, thus we increment counter by 1
                counter++;
                //since we found a \n, we will start our next search pass the found \n by moving idx 2 indexs forward
                idx += 2;
               }
            //the size of a frame should equal to the frame size stated by us
            REQUIRE(counter == movPly.getFrameSize());
            //reset counter and idx
            counter = 0;
            idx = 0;
            //the fourth frame should be different, so it should not equal to the previous frame (1-3)
            REQUIRE(fourthFrame.compare(firstFrame) != 0);
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}
