//
//  MovieTicket.h
//

#ifndef MovieTicketH
#define MovieTicketH

#include <iostream>
#include <string>

class MovieTicket
{
public:
    enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY,
               FRIDAY, SATURDAY, SUNDAY };
    enum Time { NOON, TWOPM, FOURPM, SIXPM, EIGHTPM, TENPM, MIDNIGHT };
    enum Kind { GRANDOPENING, BLOCKBUSTER, REGULAR, BOMB };
    enum Type { CHILD, ADULT, SENIOR };
    
    MovieTicket( std::string movie, MovieTicket::Day day, MovieTicket::Time time, MovieTicket::Kind kind, MovieTicket::Type type );
    
    std::string getMovie( ) const;
    MovieTicket::Day  getDay( )   const;
    MovieTicket::Time getTime( )  const;
    MovieTicket::Kind getKind( ) const;
    MovieTicket::Type getType( ) const;
    
    bool isWeekendTicket( ) const;
    bool isWeekdayTicket( ) const;
    bool isMatineeTicket( ) const;
    bool isEveningTicket( ) const;
    
    double getCost( ) const;
    
private:
    std::string       mMovie;
    MovieTicket::Day  mDay;
    MovieTicket::Time mTime;
    MovieTicket::Kind mKind;
    MovieTicket::Type mType;
};

#endif /* MovieTicket_h */
