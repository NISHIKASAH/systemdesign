#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

class Symbol
{
    char mark;

public:
    Symbol(char elem)
    {
        mark = elem;
    }
    char getMark()
    {
        return mark;
    }
};

class Board
{
public:
    vector<vector<Symbol *>> grid;
    Symbol *markedempty;
    int size;
    Board(int boardsize)
    {
        markedempty = new Symbol('-');
        size = boardsize;
        grid = vector<vector<Symbol *>>(size, vector<Symbol *>(size, markedempty));
    }

    bool placeMark(int r, int c, Symbol *s)
    {
        if (r < 0 || r >= size || c < 0 || c >= size)
            return false;

        if (!isEmptycell(r, c))
        {
            return false;
        }

        grid[r][c] = s;
        return true;
    }
    Symbol *getEmptyCell()
    {
        return markedempty;
    }
    bool isEmptycell(int r, int c)
    {

        if (r < 0 || r >= size || c < 0 || c >= size)
            return false;
        return grid[r][c] == markedempty;
    }
    Symbol *getCellMark(int r, int c)
    {
        if (r < 0 || r >= size || c < 0 || c >= size)
            return markedempty;
        return grid[r][c];
    }
    int getSize()
    {
        return size;
    }

    void display()
    {
        cout << "\n";
        cout<<" ";
        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
        }
        cout<<endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
            for (int j = 0; j < size; j++)
            {
                cout << grid[i][j]->getMark() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

class GameRule
{

public:
    virtual bool checkValidCell(Board *board, int r, int c) = 0;
    virtual bool checkWin(Board *board, Symbol *s) = 0;
    virtual bool checkDraw(Board *board) = 0;
    virtual ~GameRule() {};
};

class StandardRule : public GameRule
{
public:
    bool checkValidCell(Board *board, int r, int c) override
    {
        board->isEmptycell(r, c);
    }
    bool checkWin(Board *board, Symbol *s) override
    {
        int size = board->getSize();
        bool win;
        for (int i = 0; i < size; i++)
        {
            win = true;
            for (int j = 0; j < size; j++)
            {
                if (board->getCellMark(i, j) != s)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                return true;
        }
        for (int j = 0; j < size; j++)
        {
            win = true;
            for (int i = 0; i < size; i++)
            {
                if (board->getCellMark(i, j) != s)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                return true;
        }

        for (int i = 0; i < size; i++)
        {
            if (board->getCellMark(i, i) != s)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;

        for (int i = 0; i < size; i++)
        {
            if (board->getCellMark(i, size - i - 1) != s)
            {
                win = false;
                break;
            }
        }
        return win;
    }
    bool checkDraw(Board *board) override
    {
        int size = board->getSize();
        bool draw = true;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board->isEmptycell(i, j))
                {
                    draw = false;
                    break;
                }
            }
        }
        return draw;
    }
};

class Player
{
private:
    int id;
    string name;
    int score;
    Symbol *symbol;

public:
    Player(int ids, string nam, Symbol *marker)
    {
        id = ids;
        name = nam;
        symbol = marker;
        score = 0;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getScore()
    {
        return score;
    }
    int incrementScore()
    {
        score = score + 1;
    }
    Symbol *getSymbol()
    {
        return symbol;
    }
    ~Player()
    {
        delete symbol;
    }
};

class Iobservable
{
public:
    virtual void update(string msg) = 0;
};
class ConsoleNotifier : public Iobservable
{
public:
    void update(string msg) override
    {
        cout << "[Notification] " << msg << endl;
    }
};

enum class Ruletype
{
    STANDDARD

};

class TicTacGame
{
    GameRule *rulestrategy;
    Board *board;
    vector<Iobservable*>observer;
    deque<Player*>players;
    bool gameover;

public:
    TicTacGame(int boardsize)
    {
        rulestrategy = new StandardRule();
        board = new Board(boardsize);
        gameover= false;
    }
    void addObserver(Iobservable * ob){
        observer.push_back(ob);

    }
    void notify(string msg){
        for(auto it : observer){
            it->update(msg);
        }
    }

    void addPlayer( Player * player){
        players.push_back(player);
    }
    void playGame(){
        while(!gameover){
            Player * currentplayer = players.front();
            cout<<currentplayer->getName()<<"("<<currentplayer->getSymbol()->getMark()<<")"<<endl;
            cout<<"enter row and column"<<endl;
            int row; int col ;
            cin>>row>>col;

            if(rulestrategy->checkValidCell( board , row,col)){
                board->placeMark(row,col , currentplayer->getSymbol() );
                string msg = currentplayer->getName() + "(" + to_string(row) +  "," + to_string(col) + ")" ;
                notify(msg);
                if(rulestrategy->checkWin(board , currentplayer->getSymbol())){
                     currentplayer->incrementScore();
                     cout<<currentplayer->getName() <<"Win! \n";
                    string msg = currentplayer->getName() + "win the game \n" ;
                    board->display();
                    notify(msg);
                    gameover = true;
                   

                
                }
                else if(rulestrategy->checkDraw(board)){
                    cout<<"its a draw !!\n";
                    board->display();
                    string msg = "Its a draw \n" ;
                    notify(msg);
                    gameover = true;
                }
                else{
                    players.pop_front();
                    players.push_back(currentplayer);
                }

            }
            else{
                cout<<"Invalid move , try again !"<<endl;
                
            }
            
        }
    }

    ~TicTacGame(){
        delete board ; 
        delete rulestrategy;
    }


};
class GameFactory
{
public:
static TicTacGame * createGame(Ruletype type , int boardsize)
    {
        if (type == Ruletype ::STANDDARD)
        {
            return new TicTacGame( boardsize);
        }
        else
        {
            cout << "Custom rule has not been created yet " << endl;
        }
    }
}; 

int main(){
   
   TicTacGame * game =  GameFactory ::createGame(Ruletype ::STANDDARD , 3);
   Iobservable * notifier = new ConsoleNotifier();
   game->addObserver(notifier);

   Player* player1 = new Player(1, "nishika" , new Symbol('X'));
   Player *player2 = new Player(2, "nitesh" , new Symbol('O'));



   game->addPlayer(player1);
   game->addPlayer(player2);

   game->playGame();

   delete game;
   delete player1;
   delete player2;
   delete notifier;
   return 0;

}