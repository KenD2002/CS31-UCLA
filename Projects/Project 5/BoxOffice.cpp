// IMPLEMENTATION FILE: BoxOffice.cpp
// IMPLEMENT 1. class BoxOffice member functions
#include "BoxOffice.h"
#include <string>
#include <iostream>

//constructor
BoxOffice::BoxOffice(std::string address, std::string whatsPlaying)
{
    mAddress = address;
    mMovie = whatsPlaying;
    mTicketCount = 0;
    mMatineeTickets = 0;
    mEveningTickets = 0;
    mWeekdayTickets = 0;
    mWeekendTickets = 0;
    mEarnedRevenue = 0.0;
}

//buyTicket function
MovieTicket BoxOffice::buyTicket(std::string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type)
{
    if(movie != mMovie)
    {
        std::logic_error le("Requested movie string does not match mMovie string.");
        throw(le);
    }
    
    //declare a MovieTicket type with arguments input
    MovieTicket mt(movie, day, time, kind, type);
    
    //increment for private values
    mTicketCount ++;
    
    if(mt.isMatineeTicket())
    {
        mMatineeTickets ++;
    }
    else
    {
        mEveningTickets ++;
    }
    
    if(mt.isWeekdayTicket())
    {
        mWeekdayTickets ++;
    }
    else
    {
        mWeekendTickets ++;
    }
    
    mEarnedRevenue += mt.getCost();
    
    return mt;
}

//getters
std::string BoxOffice::getAddress()
{
    return mAddress;
}

std::string BoxOffice::whatsPlaying()
{
    return mMovie;
}

//trackers
int BoxOffice::getWeekendTickets()
{
    return mWeekendTickets;
}

int BoxOffice::getWeekdayTickets()
{
    return mWeekdayTickets;
}

int BoxOffice::getMatineeTickets()
{
    return mMatineeTickets;
}

int BoxOffice::getEveningTickets()
{
    return mEveningTickets;
}

//total revenue
double BoxOffice::getRevenue()
{
    return mEarnedRevenue;
}
