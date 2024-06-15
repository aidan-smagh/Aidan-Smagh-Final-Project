
#ifndef player_h
#define player_h
class player
{
public:
    player();
    ~player();
    void initSprite();
    void updatePlayer(int width, int height, int dir);
    void drawPlayer();
    void moveUp();
    void moveDown();
    void rotate();
    int getWidth() {return frameWidth;}
    int getHeight() {return frameHeight;}
    int getX() {return x;}
    int getY() {return y;}
    void removeLife() {lives--;}
private:
    int x;
    int y;
    int speed;
    int score;
    int lives;
    int maxFrame;
    int curFrame;
    int frameCount;
    int frameDelay;
    int frameWidth;
    int frameHeight;
    int animationColumns;
    int animationRows;
    int animationDirection;
    
    ALLEGRO_BITMAP *image;
};
#endif
