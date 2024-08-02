// IMPLEMENTATION FILE: MovieTicket.cpp
// IMPLEMENT 1. class MovieTicket member functions
#include "MovieTicket.h"
#include <iostream>
#include <string>

//constructor
MovieTicket::MovieTicket(std::string movie, Day day, Time time, Kind kind, Type type)
{
    mMovie = movie;
    mDay   = day;
    mTime  = time;
    mKind  = kind;
    mType  = type;
}

//getters
std::string MovieTicket::getMovie()
{
    return mMovie;
}

MovieTicket::Day MovieTicket::getDay()
{
    return mDay;
}

MovieTicket::Time MovieTicket::getTime()
{
    return mTime;
}

MovieTicket::Kind MovieTicket::getKind()
{
    return mKind;
}

MovieTicket::Type MovieTicket::getType()
{
    return mType;
}

//ticket trackers
bool MovieTicket::isWeekendTicket()
{
    if(mDay == FRIDAY || mDay == SATURDAY || mDay == SUNDAY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MovieTicket::isWeekdayTicket()
{
    if(!isWeekendTicket())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MovieTicket::isMatineeTicket()
{
    if(mTime == NOON || mTime == TWOPM || mTime == FOURPM)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MovieTicket::isEveningTicket()
{
    if(!isMatineeTicket())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//ticket price
double MovieTicket::getCost()
{
    double price(0.0);
    
    //Base price
    if(mType == CHILD)
    {
        price += 3.5;
    }
    else if(mType == ADULT)
    {
        price += 7.5;
    }
    else if(mType == SENIOR)
    {
        price += 4.5;
    }
    
    //Matinee discount
    if(isMatineeTicket())
    {
        price -= 2;
    }
    
    //Blockbuster upgrade
    if(mKind == BLOCKBUSTER)
    {
        price += 1;
    }
    
    //GrandOpening upgrade
    if(mKind == GRANDOPENING)
    {
        price += 2;
    }
    
    //Bomb disount
    if(mKind == BOMB)
    {
        price -= 1;
    }
    
    return price;
}
