#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

class Entities
{
public:
    int start;
    int end;

    Entities(int s, int e)
    {
        start = s;
        end = e;
    }
    int getStart()
    {
        return start;
    }
    int getEnd()
    {
        return end;
    }
    virtual void display() = 0;
    virtual string getName() = 0;
    ~Entities() {};
};

class Snake : public Entities
{
public:
    Snake(int start, int end) : Entities(start, end) {};
    string getName() override
    {
        return "SNAKE";
    }
    void display() override
    {
        cout << "Snake position : " << "[" <<start << "," << end << "]" <<endl;
    }
};

class Ladder : public Entities
{
public:
    Ladder(int start, int end) : Entities(start, end) {};
    string getName() override
    {
        return "LADDER";
    }
    void display() override
    {
        cout << "Ladder position " << "[" <<start << ","  << end << "]" <<endl;
    }
};

class Dice
{
    int face;

public:
    Dice(int size)
    {
        face = size;
        srand(time(0));
    }
    int roll()
    {
        return (rand() % face + 1);
    }
};

class EntitySetupStrategy;
class Board
{
    int size;
    map<int, Entities *> boardEntities;
    vector<Entities *> entitiesList;

public:
    Board(int boardsize)
    {
        size = boardsize * boardsize;
    }
    int getBoardsize()
    {
        return size;
    }

    bool CanAddEntities(int pos)
    {
        if (boardEntities.find(pos) != boardEntities.end())
        {
            return false;
        }
        else
            return true;
    }
    void addBoardEntity(Entities *entities)
    {
        if (CanAddEntities(entities->getStart()))
        {
            entitiesList.push_back(entities);
            boardEntities[entities->getStart()] = entities;
        }
    }
    Entities *getEntities(int pos)
    {
        if (boardEntities.find(pos) != boardEntities.end())
        {
            return boardEntities[pos];
        }
        else
            return nullptr;
    }
    void setUpEntities(EntitySetupStrategy *strategy);
    void displayBoard()
    {
        cout << "------Board configuration --------";

        int snakecount = 0;
        int laddercount = 0;
        for (auto it : entitiesList)
        {
            if (it->getName() == "SNAKE")
            {
                snakecount++;
            }
            else
            {
                laddercount++;
            }
        }
        cout << "\nSnake count : " << snakecount << endl;
        for (auto it : entitiesList)
        {
            if (it->getName() == "SNAKE")
            {
                it->display();
            }
        }

        cout << "Ladder count : " << laddercount << endl;
        for (auto it : entitiesList)
        {
            if (it->getName() == "LADDER")
            {
                it->display();
            }
        }
    }

    ~Board()
    {
        for (auto entities : entitiesList)
        {
            delete entities;
        }
    }
};
class GameRule
{
public:
    virtual bool checkValidPos(int pos, int diceVal, int boardsize) = 0;
    virtual int checkNextPos(int pos, int diceVal, Board *board) = 0;
    virtual bool checkWin(int pos, int boardsize) = 0;
};

class StandardRule : public GameRule
{
public:
    bool checkValidPos(int pos, int diceVal, int boardsize) override
    {
        int newpos = pos + diceVal;
        return newpos <= boardsize;
    }

    int checkNextPos(int pos, int diceVal, Board *board)
    {
       return pos + diceVal;
    }
    bool checkWin(int pos, int boardsize)
    {
        return pos == boardsize;
    }
};

class EntitySetupStrategy
{
public:
    virtual void setUpEntities(Board *board) = 0;
};
class StandardSetupStrategy : public EntitySetupStrategy
{
public:
    void setUpEntities(Board *board)
    {
        int size = board->getBoardsize();
        if (size != 100)
        {
            cout << "This setUp can be perform only in 100 size board" << endl;
        }
        // Standard snake positions
        board->addBoardEntity(new Snake(99, 54));
        board->addBoardEntity(new Snake(95, 75));
        board->addBoardEntity(new Snake(92, 88));
        board->addBoardEntity(new Snake(89, 68));
        board->addBoardEntity(new Snake(74, 53));
        board->addBoardEntity(new Snake(64, 60));
        board->addBoardEntity(new Snake(62, 19));
        board->addBoardEntity(new Snake(49, 11));
        board->addBoardEntity(new Snake(46, 25));
        board->addBoardEntity(new Snake(16, 6));

        // Standard ladder positions
        board->addBoardEntity(new Ladder(2, 38));
        board->addBoardEntity(new Ladder(7, 14));
        board->addBoardEntity(new Ladder(8, 31));
        board->addBoardEntity(new Ladder(15, 26));
        board->addBoardEntity(new Ladder(21, 42));
        board->addBoardEntity(new Ladder(28, 84));
        board->addBoardEntity(new Ladder(36, 44));
        board->addBoardEntity(new Ladder(51, 67));
        board->addBoardEntity(new Ladder(71, 91));
        board->addBoardEntity(new Ladder(78, 98));
        board->addBoardEntity(new Ladder(87, 94));
    }
};

class Iobserver
{
public:
    virtual void update(string msg) = 0;
};

class ConsoleNotifier : public Iobserver
{
public:
    void update(string msg) override
    {
        cout << "[Notification :] " << msg << endl;
    }
};

class Player
{
private:
    int id;
    string name;
    int pos;
    int score;

public:
    Player(int ids, string nam)
    {
        id = ids;
        name = nam;
        score = 0;
        pos = 0;
    }
    int getScore()
    {
        return score;
    }
    void IncrementScore()
    {
        score = score + 1;
    }
    string getName()
    {
        return name;
    }
    int getPos()
    {
        return pos;
    }
    void setPos(int position)
    {
        pos = position;
    }
};

void Board ::setUpEntities(EntitySetupStrategy *strategy)
{
    strategy->setUpEntities(this);
};
class SnakeAndLadder
{
    Board *board;
    GameRule *rule;
    Dice *dice;
    vector<Iobserver *> observerlist;
    deque<Player *> players;
    bool gameover;

public:
    SnakeAndLadder(Board *bd, Dice *di)
    {
        board = bd;
        dice = di;
        gameover = false;
        rule = new StandardRule();
        
    }
    void addObserver(Iobserver *obs)
    {
        observerlist.push_back(obs);
    }
    void addPlayer(Player *player)
    {
        players.push_back(player);
    }
      void displayPlayerPositions() {
        cout << "\n=== Current Positions ===" << endl;
        for(auto player : players) {
            cout << player->getName() << ": " << player->getPos() << endl;
        }
        cout << "======================" << endl;
    }

    void notify(string msg)
    {
        for (auto observer : observerlist)
        {
            observer->update(msg);
        }
    }

    void play()
    {

         if(players.size() < 2) {
            cout << "Need at least 2 players!" << endl;
            return;
        }
        
        notify("Game Started");
        board->displayBoard();
        while (!gameover)
        {
            Player *currentplayer = players.front();
            string msg = "player: " + currentplayer->getName() + " to start game at position " + to_string(currentplayer->getPos());
            notify(msg);

            cout << "Please Enter to roll a dice" << endl;
            cin.get();
            int diceval = dice->roll();
            if (rule->checkValidPos(currentplayer->getPos(), diceval, board->getBoardsize()))
            {

                int newpos = rule->checkNextPos(currentplayer->getPos(), diceval, board);
                
                currentplayer->setPos(newpos);

                Entities *entity = board->getEntities(newpos);
                if (entity != nullptr)
                {
                    if (entity->getName() == "SNAKE")
                    {
                        string msg = "snake at position " + to_string(entity->getStart()) + " "+  currentplayer->getName() +
                                     " move  downward from " + to_string(entity->getStart()) + "to" +
                                     to_string(entity->getEnd()) + "\n";
                        notify(msg);
                        currentplayer->setPos(entity->getEnd());
                    }
                    else if (entity->getName() == "LADDER")
                    {
                        msg = "Ladder at position " + to_string(entity->getStart()) + " "+  currentplayer->getName() +
                              " move upperward from " + to_string(entity->getStart()) + "to" +
                              to_string(entity->getEnd()) + "\n";
                        notify(msg);
                        currentplayer->setPos(entity->getEnd());
                    }
                    
                }
                notify(currentplayer->getName() + " New Position " + to_string(currentplayer->getPos()));
                    displayPlayerPositions();

                if (rule->checkWin(currentplayer->getPos(), board->getBoardsize()))
                {
                    string msg = currentplayer->getName() + " win the game !\n";
                    notify(msg);
                   
                    currentplayer->IncrementScore();
                    gameover = true;
                }
                else
                {
                    players.pop_front();
                    players.push_back(currentplayer);
                }
            }
            else
            {
                players.pop_front();
                players.push_back(currentplayer);
            }
        }
    }
    ~SnakeAndLadder() {};
};

class GameFactory
{
public:
    static SnakeAndLadder *createSnakeLadderGame(Board *board, Dice *dice)
    {
        return new SnakeAndLadder(board, dice);
    }
};

int main()
{
    Board *board = new Board(10);
    Dice *dice = new Dice(6);
   board->setUpEntities(new StandardSetupStrategy());
    SnakeAndLadder *game = GameFactory ::createSnakeLadderGame(board, dice);
    Iobserver *observer1 = new ConsoleNotifier();
    game->addObserver(observer1);
    Player *player1 = new Player(1, "nishika");
    Player *player2 = new Player(2, "nitesh");
    game->addPlayer(player1);
    game->addPlayer(player2);
    game->play();

    delete game ;
    delete board;
    
}