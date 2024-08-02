//
//  BoxOffice.cpp
//

#include "BoxOffice.h"
#include <stdexcept>


BoxOffice::BoxOffice( std::string address, std::string whatsPlaying ) : mAddress( address ), mMovie( whatsPlaying ), mTicketCount(0), mWeekendTickets(0), mMatineeTickets(0), mWeekdayTickets(0), mEveningTickets(0), mEarnedRevenue(0)
{
    
}

MovieTicket BoxOffice::buyTicket( std::string movie, MovieTicket::Day day, MovieTicket::Time time,
    MovieTicket::Kind kind, MovieTicket::Type type )
{
    if (movie == whatsPlaying())
    {
        MovieTicket m( movie, day, time, kind, type );
    
        mTicketCount++;
        if (m.isEveningTicket())
        {
            mEveningTickets++;
        }
        if (m.isMatineeTicket())
        {
            mMatineeTickets++;
        }
        if (m.isWeekdayTicket())
        {
            mWeekdayTickets++;
        }
        if (m.isWeekendTicket())
        {
            mWeekendTickets++;
        }
        mEarnedRevenue += m.getCost();
    
        return( m );
    }
    else
    {
        std::logic_error e( "movie not showing here" );
        throw( e );
    }
}

std::string BoxOffice::getAddress() const
{
    return( mAddress );
}

std::string BoxOffice::whatsPlaying() const
{
    return( mMovie );
}

int BoxOffice::getWeekendTickets( ) const
{
    return( mWeekendTickets );
}

int BoxOffice::getWeekdayTickets( ) const
{
    return( mWeekdayTickets );
}

int BoxOffice::getMatineeTickets( ) const
{
    return( mMatineeTickets );
}

int BoxOffice::getEveningTickets( ) const
{
    return( mEveningTickets );
}

double BoxOffice::getRevenue() const
{
    return( mEarnedRevenue );
}
