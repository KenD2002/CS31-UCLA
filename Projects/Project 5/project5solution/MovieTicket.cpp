//
//  MovieTicket.cpp
//

#include "MovieTicket.h"

MovieTicket::MovieTicket( std::string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type ) : mMovie( movie ), mDay( day ), mTime( time ), mKind( kind ), mType( type )
{
    
}

std::string MovieTicket::getMovie( ) const
{
    return( mMovie );
}

MovieTicket::Day MovieTicket::getDay( )   const
{
    return( mDay );
}

MovieTicket::Time MovieTicket::getTime( )  const
{
    return( mTime );
}

MovieTicket::Kind MovieTicket::getKind( ) const
{
    return( mKind );
}

MovieTicket::Type MovieTicket::getType( ) const
{
    return( mType );
}

bool MovieTicket::isWeekendTicket( ) const
{
    bool result( false );
    switch( mDay )
    {
        case FRIDAY:
        case SATURDAY:
        case SUNDAY:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    return( result );
}

bool MovieTicket::isWeekdayTicket( ) const
{
    bool result( false );
    switch( mDay )
    {
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    return( result );
}

bool MovieTicket::isMatineeTicket( ) const
{
    bool result( false );
    switch( mTime )
    {
        case NOON:
        case TWOPM:
        case FOURPM:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    return( result );
}

bool MovieTicket::isEveningTicket( ) const
{
    bool result( false );
    switch( mTime )
    {
        case SIXPM:
        case EIGHTPM:
        case TENPM:
        case MIDNIGHT:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    return( result );
}

double MovieTicket::getCost( ) const
{
    double cost = 0;
    
    switch( mType )
    {
        case CHILD:
            cost = 3.50;
            break;

        case ADULT:
            cost = 7.50;
            break;

        case SENIOR:
            cost = 4.50;
            break;
    }
    
    switch( mTime )
    {
        case NOON:
        case TWOPM:
        case FOURPM:
            cost -= 2.00;
            break;
        default:
            break;
    }
    
    switch( mKind )
    {
        case GRANDOPENING:
            cost += 2.00;
            break;
        case BOMB:
            cost -= 1.00;
            break;
        default:
            break;
    }
    
    if (mKind == BLOCKBUSTER)
        cost += 1.00;
    
    return( cost );
}
