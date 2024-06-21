#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "player.h"
#include <iostream>

player::~player()
{
    al_destroy_bitmap(image);
}
player::player(int HEIGHT)
{
    
    image = al_load_bitmap("balloon.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));
    
    x = 300;
    y = 550;
    speed = 10;
    lives = 5;
    
    
    maxFrame = 3;
    curFrame = 0;
    frameCount = 0;
    frameDelay = 10;
    frameWidth = 140;
    frameHeight = 200;
    animationColumns = 3;
    animationRows = 1;
    animationDirection = 1;
    

}
void player::drawPlayer()
{
    int fx = (curFrame % animationColumns) * frameWidth;
    int fy = (curFrame / animationColumns) * frameHeight;
    
    std::cout << fx << " ";
    std::cout << fy;
    
    al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x, y, 0);
    
}
void player::updatePlayer(int width, int height)
{
    if (++curFrame >= frameDelay) {
        curFrame += animationDirection;
        if (curFrame >= maxFrame) {
            curFrame = 0;
        } else if (curFrame <= 0) {
            curFrame = maxFrame = 1;
        }
    }
}
void player::MoveUp()
{
    y -= speed;
    if (y < 0) {
        y = 0;
    }
}
void player::MoveDown()
{
    y += speed;
    if (y > 800) {
        y = 800;
    }
}
