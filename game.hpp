#include <vector>

class Space{
    public:
        int adj_bombs;
        bool isBomb;
        bool isClicked;
        bool isFlagged;

};
class Game{
    public:
        Game(int height, int width, int bombs);
        ~Game();
        void restart();
        void reveal(int x, int y);
        void check();

    private:
        int height, width, bombs;
        std::vector< std::vector<Space> > board;
        bool gameover;
};