//
//  BoxOffice.h
//

#ifndef BoxOfficeH
#define BoxOfficeH

#include <iostream>
#include <string>
#include "MovieTicket.h"

class BoxOffice
{
public:
    BoxOffice( std::string address, std::string whatsPlaying );
    
    MovieTicket buyTicket( std::string movie, MovieTicket::Day day, MovieTicket::Time time,
        MovieTicket::Kind kind, MovieTicket::Type type );
    
    std::string getAddress() const;
    std::string whatsPlaying() const;
    
    int getWeekendTickets( ) const;
    int getWeekdayTickets( ) const;
    int getMatineeTickets( ) const;
    int getEveningTickets( ) const;
    double getRevenue() const;
    
private:
    std::string mAddress, mMovie;
    
    int         mTicketCount;
    int         mWeekendTickets;
    int         mMatineeTickets;
    int         mWeekdayTickets;
    int         mEveningTickets;
    
    double      mEarnedRevenue;
};

#endif /* BoxOffice_h */
