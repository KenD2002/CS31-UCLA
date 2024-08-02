// INTERFACE FILE: MovieTicket.h
// Defines class MovieTicket
#ifndef MovieTicket_h
#define MovieTicket_h

#include <string>
#include <iostream>

class MovieTicket
{
public:
    enum Time {NOON, TWOPM, FOURPM, SIXPM, EIGHTPM, TENPM, MIDNIGHT};
    enum Day  {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
    enum Type {CHILD, ADULT, SENIOR};
    enum Kind {GRANDOPENING, BLOCKBUSTER, REGULAR, BOMB};
    
private:
    std::string mMovie;
    Day         mDay;
    Time        mTime;
    Kind        mKind;
    Type        mType;

public:
    //constructor
    MovieTicket(std::string movie, Day day, Time time, Kind kind, Type type);
    
    //getters
    std::string getMovie();
    Day         getDay();
    Time        getTime();
    Kind        getKind();
    Type        getType();
    
    //ticket trackers
    bool isWeekendTicket();
    bool isWeekdayTicket();
    bool isMatineeTicket();
    bool isEveningTicket();
    
    //ticket price
    double getCost();
};

#endif /* MovieTicket_h */
