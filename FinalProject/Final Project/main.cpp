//Aidan Smagh
//Final Project

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include "player.h"

int main(int argc, char **argv)
{
    const int WIDTH = 1600;
    const int HEIGHT = 1100;
    enum KEYS{UP, DOWN, SPACE};
    bool keys[3] = {false, false, false};
    
    bool beginning = false;
    bool done = false;
    bool redraw = false;
    const int FPS = 60;
    
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_BITMAP *background = NULL;
    
    //initialize the works
    al_init();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);
    al_init_ttf_addon();
    al_init_font_addon();
    al_install_keyboard();
    al_init_image_addon();
    
    //background music and image
    sample = al_load_sample("background.wav");
    background = al_load_bitmap("background.png");
    display = al_create_display(WIDTH, HEIGHT);
    
    //object variables
    player myPlayer;
    myPlayer.initSprite();
    
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0/FPS);
    
    //init randomness
    srand(time(0));
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    
    al_start_timer(timer);
    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    
    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
            if (keys[UP]) {
                //move up
            }
            if (keys[DOWN]) {
                //move down
            }
            if (keys[SPACE]) {
                //do a flip
            }
            //start the ghosts with the for loops
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_UP:
                    keys[UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = true;
                    break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    done = true;
                    break;
                case ALLEGRO_KEY_UP:
                    keys[UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = false;
                    break;
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = false;
                    break;
            }
        }
        if (redraw && al_is_event_queue_empty(event_queue))
        {
            while (!beginning) {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(5.0);
                beginning = true;
                
            }
            
            redraw = false;
            al_draw_bitmap(background, 0, 0, 0);
            myPlayer.drawPlayer();
            
            
            
            al_flip_display();
            al_rest(10.0);
            
        }
    }
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(background);
    al_destroy_timer(timer);
    al_destroy_display(display);
    return 0;
}
