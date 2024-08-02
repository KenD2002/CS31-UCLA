#include <iostream>
#include <string>
#include <cassert>
#include "MovieTicket.h"
#include "BoxOffice.h"

int main()
{
    // sample test code

    BoxOffice b("1900 Pico Boulevard", "Titanic");
    assert(b.getAddress() == "1900 Pico Boulevard");
    assert(b.whatsPlaying() == "Titanic");
    assert(b.getWeekendTickets() == 0);
    assert(b.getWeekdayTickets() == 0);
    assert(b.getMatineeTickets() == 0);
    assert(b.getEveningTickets() == 0);

    // use care when working with assert on doubles
    assert( std::to_string(b.getRevenue()) == "0.000000");


    MovieTicket t("The Lake House", MovieTicket::Day::MONDAY, MovieTicket::Time::TWOPM, MovieTicket::Kind::BOMB, MovieTicket::Type::ADULT);

    assert(t.getMovie() == "The Lake House");
    assert(t.getDay() == MovieTicket::Day::MONDAY);
    assert(t.getTime() == MovieTicket::Time::TWOPM);
    assert(t.getKind() == MovieTicket::Kind::BOMB);
    assert(t.getType() == MovieTicket::Type::ADULT);
    assert(t.isWeekendTicket() == false);
    assert(t.isWeekdayTicket() == true);
    assert(t.isMatineeTicket() == true);
    assert(t.isEveningTicket() == false);

    // use care when working with assert on doubles
    // since the BoxOffice b did not create the ticket...
    assert(std::to_string(b.getRevenue()) == "0.000000");

    try
    {
        MovieTicket m = b.buyTicket("The Wizard of Oz", MovieTicket::Day::MONDAY,
                                    MovieTicket::Time::NOON, MovieTicket::Kind::REGULAR,
                                    MovieTicket::Type::ADULT);
        assert( false );  // we are expecting the buyTicket to fail....
    }
    catch(std::logic_error)
    {
        assert(true);
    }

    try
    {
        MovieTicket m = b.buyTicket("Titanic", MovieTicket::Day::MONDAY,
                                    MovieTicket::Time::NOON, MovieTicket::Kind::REGULAR,
                                    MovieTicket::Type::ADULT);
        assert(true); // we are expecting the buyTicket to succeed....
    }
    catch(std::logic_error)
    {
        assert(false);
    }
    
    //test for constructors
    BoxOffice bo1("address1", "The Lake House");
    MovieTicket mt1("The Lake House", MovieTicket::Day::MONDAY, MovieTicket::Time::TWOPM, MovieTicket::Kind::BOMB, MovieTicket::Type::ADULT);
    MovieTicket mt2("The Mountain Mansion", MovieTicket::Day::SUNDAY, MovieTicket::Time::MIDNIGHT, MovieTicket::Kind::BLOCKBUSTER, MovieTicket::Type::SENIOR);
    

    //test for MovieTicket getters
    std::cout << "getMovie() = " << mt1.getMovie() << " getDay() = " << mt1.getDay() << " getTime() = " << mt1.getTime() << " getKind() = " << mt1.getKind() << " getType = " << mt1.getType() << std::endl;
    
    //test for MovieTicket trackers
    std::cout << "isWeekendTicket() = " << mt1.isWeekendTicket() << " isWeekdayTicket() = " << mt1.isWeekdayTicket() << " isMatineeTicket() = " << mt1.isMatineeTicket() << " isEveningTicket() = " << mt1.isEveningTicket() << std::endl;
    
    //test for MovieTicket ticket price
    std::cout << "mt1 ticket price = " << mt1.getCost() << " mt2 ticket price = " << mt2.getCost() << std::endl;
    
    //test for BoxOffice getters
    std::cout << "getAddress() = " << bo1.getAddress() << " whatsPlaying() = " << bo1.whatsPlaying() << std::endl;
    
    //test if buyTicket in class BoxOffice would produce correct increment for ticket trackers and total revenue
    bo1.buyTicket("The Lake House", MovieTicket::Day::MONDAY, MovieTicket::Time::TWOPM, MovieTicket::Kind::BOMB, MovieTicket::Type::ADULT);
    std::cout << std::to_string(bo1.getRevenue());
    std::cout << " getMatineeTickets() = " << bo1.getMatineeTickets() << " getEveningTickets() = " << bo1.getEveningTickets() << " getWeekdayTickets() = " << bo1.getWeekdayTickets() << " getWeekendTickets() = " << bo1.getWeekendTickets() << std::endl;
    bo1.buyTicket("The Lake House", MovieTicket::Day::SUNDAY, MovieTicket::Time::MIDNIGHT, MovieTicket::Kind::BLOCKBUSTER, MovieTicket::Type::SENIOR);
    std::cout << std::to_string(bo1.getRevenue());
    std::cout << " getMatineeTickets() = " << bo1.getMatineeTickets() << " getEveningTickets() = " << bo1.getEveningTickets() << " getWeekdayTickets() = " << bo1.getWeekdayTickets() << " getWeekendTickets() = " << bo1.getWeekendTickets() << std::endl;
    
    //test if buyTicket in class BoxOffice would catch any logic errors if movie != mMovie
    try
    {
        MovieTicket m = bo1.buyTicket("The Mountain Mansion", MovieTicket::Day::SUNDAY, MovieTicket::Time::MIDNIGHT, MovieTicket::Kind::BLOCKBUSTER, MovieTicket::Type::SENIOR);
        
        assert(false);
    }
    catch(std::logic_error)
    {
        assert(true);
    }

    try
    {
        MovieTicket m = bo1.buyTicket("The Lake House", MovieTicket::Day::MONDAY, MovieTicket::Time::TWOPM, MovieTicket::Kind::BOMB, MovieTicket::Type::ADULT);
        assert(true);
    }
    catch(std::logic_error)
    {
        assert(false);
    }
    
    std::cout << "all tests passed!" << std::endl;
    return 0;
}
