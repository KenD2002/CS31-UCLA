//
//  main.cpp
//  Wordle
//

#include <iostream>
#include "Wordle.h"
#include "Move.h"
#include "Score.h"

void clearScreen( );

// interactively play Wordle
int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    // by default, no cheating - pick a random word
    Wordle game;
    
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;
    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    // acquire the entered word
                    getline( cin, turn );
                    // if the word is valid, build a move
                    // for this round of play
                    if (game.isValid(turn))
                    {
                        Move m = game.play( turn );
                        game.endRound(m);
                    }
                    else
                    {
                        // turn was not a valid word and does not count
                        cout << turn << " was not a Dictionary word!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            // repetitively display the board
            cout << game.display( message ) << endl;
        }
        else
        {
            // once the game is over, finally display the board and
            // show the game outcome and the winning word
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning word was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );
    
    // destroy the in-memory database of five letter words managed by
    // the Dictionary object
    Singleton::destroySingleton();
    
    /*
    // test code 1
    
    Piece p;
    assert( p.getLetter() == NOTVALID );
    p = Piece( "M" );
    assert( p.getLetter() == M );
    assert( p.getLetterAsString() == "M" );

    Move m;
    p = m.getPiece( 0 );
    assert( p.getLetter() == NOTVALID );
    m.setPieces( "world" );
    p = m.getPiece( 2 );
    assert( p.getLetter() == R );
    m.setPiece( 2, 'j' );
    p = m.getPiece( 2 );
    assert( p.getLetter() == J );

    Score s;
    assert( s.isExactMatch()  == false );
    assert( s.getAnswer( 2 ) == WRONG );
    m.setPieces( "hello" );
    Move theAnswer;
    theAnswer.setPieces( "stank" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == false );
    assert( s.to_string() == "_____" );
    theAnswer.setPieces( "hello" );
    s = Score( m, theAnswer );
    assert( s.isExactMatch() == true );
    assert( s.to_string() == "RRRRR" );

    Board b;
    assert( b.getCurrentRound() == 0 );
    m.setPieces( "hello" );
    theAnswer.setPieces( "logic" );
    s = Score( m, theAnswer );
    b.endRound( m, s );
    assert( b.getCurrentRound() == 1 );
    assert( b.getMoveForRound( 0 ).to_string() == "HELLO" );
    assert( b.getScoreForRound( 0 ).to_string() == "__M_M" );

    
    //test code 2
    
    Wordle game1( "angel" );
    Score s1;
    Move m1;
    Board board;
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 1);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 2);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 3);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 4);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 5);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 6);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 7);
    assert(game1.gameIsOver() == false);
    m1 = game1.play( "acute" );
    s1 = game1.endRound( m1 );
    board = game1.getBoard();
    assert(board.getCurrentRound() == 8);
    assert(game1.gameIsOver() == true);
    assert(game1.determineGameOutcome() == GAMELOST);
    
     
    //test code 3
    
    Wordle game2( "start" );
    Score s2;
    Move m2;
    Board board2;
    m2 = game2.play( "hello" );
    s2 = game2.endRound( m2 );
    board2 = game2.getBoard();
    assert(board2.getCurrentRound() == 1);
    assert(game2.gameIsOver() == false);
    assert(s2.to_string() == "_____");
    m2 = game2.play( "other" );
    s2 = game2.endRound( m2 );
    board2 = game2.getBoard();
    assert(board2.getCurrentRound() == 2);
    assert(game2.gameIsOver() == false);
    assert(s2.to_string() == "_R__M");
    m2 = game2.play( "stair" );
    s2 = game2.endRound( m2 );
    board2 = game2.getBoard();
    assert(board2.getCurrentRound() == 3);
    assert(game2.gameIsOver() == false);
    assert(s2.to_string() == "RRR_M");
    m2 = game2.play( "stare" );
    s2 = game2.endRound( m2 );
    board2 = game2.getBoard();
    assert(board2.getCurrentRound() == 4);
    assert(game2.gameIsOver() == false);
    assert(s2.to_string() == "RRRR_");
    m2 = game2.play( "start" );
    s2 = game2.endRound( m2 );
    board2 = game2.getBoard();
    assert(board2.getCurrentRound() == 5);
    assert(game2.gameIsOver() == true);
    assert(s2.to_string() == "RRRRR");
    
    cout << "all tests passed!" << endl;
    */
    
    return( 0 );
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

