// INTERFACE FILE: BoxOffice.h
// Defines class BoxOffice
#ifndef BoxOffice_h
#define BoxOffice_h

#include <string>
#include <iostream>
#include "MovieTicket.h"

class BoxOffice
{
private:
    std::string mAddress, mMovie;
    int         mTicketCount, mMatineeTickets, mEveningTickets, mWeekdayTickets, mWeekendTickets;
    double      mEarnedRevenue;

public:
    //constructor
    BoxOffice(std::string address, std::string whatsPlaying);
    
    //getters
    MovieTicket buyTicket(std::string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type);
    std::string getAddress();
    std::string whatsPlaying();
    
    //trackers
    int getWeekendTickets();
    int getWeekdayTickets();
    int getMatineeTickets();
    int getEveningTickets();
    
    //total revenue
    double getRevenue();

};

#endif /* BoxOffice_h */
