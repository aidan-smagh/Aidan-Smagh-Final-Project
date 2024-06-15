#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "player.h"

player::~player()
{
    al_destroy_bitmap(image);
}
player::player()
{
    image = NULL;
}
void player::initSprite()
{
    x = 200;
    y = 550;
    
    maxFrame = 10;
    curFrame = 0;
    frameCount = 0;
    frameDelay = 6;
    frameWidth = 216;
    frameHeight = 180;
    animationColumns = 5;
    animationRows = 2;
    animationDirection = 1;
    
    image = al_load_bitmap("bird.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));
    
}
void player::updatePlayer(int width, int height, int dir)
{
    int oldx = x;
    int oldy = y;
    
    
}
void player::drawPlayer()
{
    
}
