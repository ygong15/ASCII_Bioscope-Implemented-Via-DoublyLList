#include <fstream>
#include <iostream>
#include <sstream>

#include "movie.h"

MoviePlayer::MoviePlayer(std::string filmName)
{
    //update mFilmName to user input
    mFilmName = filmName;
    //load mFilm
    loadTape();
    //set the pos iterator to the begaining of the list
    rewind();
    //set currFrameNum to 1 since we are at the begaining of the movie right now
}

MoviePlayer::~MoviePlayer()
{
    //make sure mFilm is empty
    mFilm.clear();
}

void MoviePlayer::goFwrd()
{
    //we stop whenever currFrameNum == size of the list. This means that we are already at the last node so we cannot advance the iterator anymore
    if(currFrameNum < getNumFrames())
    {
        pos++;
        currFrameNum++;
    }
}

void MoviePlayer::goBack()
{
    //only move backward when we are not at the begaining of the list
    if(pos != mFilm.begin())
    {
        //decrement current frame by one
        currFrameNum--;
        //decrement iterator by one
        pos--;
    }
}

void MoviePlayer::rewind()
{
    //point the iterator to the begaining frae
    pos = mFilm.begin();
    //set the currFrameNum to 1 -> the first frame
    currFrameNum = 1;
}

std::string MoviePlayer::getCurrFrame()
{
    //dereference the iterator to return the string it points to
    return *pos;
}

void MoviePlayer::delCurrFrame()
{
    //delete the current pos and point pos to the next node
    pos = mFilm.erase(pos);
    //no need to change currFrameNum
}

void MoviePlayer::copyCurrFrame()
{
    //copy pos and insert it before pos. pos will then point to the newly copied pos right before it.
    pos = mFilm.insert(pos, *pos);
    //no need to change currFrameNum since we already go back by one
}


unsigned MoviePlayer::getCurrFrameNum() const
{
    return currFrameNum;
}

unsigned int MoviePlayer::getNumFrames() const
{
    return mFilm.size();
}

unsigned int MoviePlayer::getFrameSize() const
{
    return FRAMESIZE;
}

void MoviePlayer::loadTape()
{
    //create a in file stream -> inFile
    std::ifstream inFile(mFilmName);
    //throw file not open exception when inFile is not opened
    if(!inFile.is_open())
    {
        throw std::invalid_argument("File cannot be opened");
    }
    //create a temp string variable to temperaraly hold the stirng
    std::string temp;
    //create a string that will hold a frame worth of strings
    std::string frameString = "";
    //seperator temp string
    std::string sepStr;
    //numFrame will hold the seperator and determines how many times the frame will be added into the list
    int numFrame;
    //keep reading until the end of the file
    while(!inFile.eof())
    {
        //get the seperator line
        getline(inFile, sepStr);
        //check if we have a good seperator. If we do, the frame we about to read is complete. If not, we do nothing but keep finidng a good seperator
        if(!sepStr.empty() && std::isdigit(sepStr[0]))
        {
            numFrame = std::stoi(sepStr);
            //read in the next 13 lines
            for(int i = 0; i < FRAMESIZE; i++)
            {
                //only read in a line if it's not at the end of the file
                if(!inFile.eof())
                {
                    getline(inFile,temp);
                    //two special circumstances where we need to add in a space to hold place
                    if(temp.empty() || temp.at(temp.size()-1) == '\\')
                    {
                        temp += " ";
                    }
                    //since getline() stripped \n, we have to add it back in
                    temp += "\n";
                    //push the line into the frameString
                    frameString += temp;
                }
            }
            //after finished reading 13 lines, we push the constructed frameString into the tape
            //we push the frame the number of time that is specified by the seperator (stored in numFrame)
            for(int i = 0; i < numFrame; i++)
            {
                mFilm.push_back(frameString);
            }
            //clear the frameString before reading in the next frame
            frameString.clear();
        }
    }
}

