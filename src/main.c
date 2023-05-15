#include "visualMemory.h"


int main() {

    ///Assert
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    al_init_font_addon();
    assert(al_install_mouse());
    assert(al_install_keyboard());
    srand(time(NULL));

    /// Bitmap
    ALLEGRO_BITMAP *icon;
    icon = al_create_bitmap(0,0);
    icon = al_load_bitmap("img/iconDisplay1.png");
    //al_draw_scaled_bitmap(icon,0,0,1024,1024,0,0,32,32,0);

    /// Display
    ALLEGRO_DISPLAY *display;
    display=al_create_display(WIDTH,HEIGHT);
    al_set_window_title(display,"Visual Memory");
    al_set_window_position(display,0,0);
    //al_set_display_icon(display,icon);

    /// Timer
    ALLEGRO_TIMER *timer;
    timer = al_create_timer(1.0/60);
    al_start_timer(timer);

    /// Queue
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event;
    queue = al_create_event_queue();
    al_register_event_source(queue,al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue,al_get_keyboard_event_source());


    /// Declaration
    int end=0;
    ELEMENT elements[NB_ELEMENTS][NB_ELEMENTS]={0};

    /// Initialisation
    initElements(elements);
    al_clear_to_color(DARK_GREY);

    /// Boucle
    while (!end) {
        al_wait_for_event(queue,&event);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE :
                end=1;
                break;
            case ALLEGRO_EVENT_KEY_DOWN :
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE :
                        end=1;
                        break;
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :
                initElements(elements);
                randomElements(elements,NB_ACTIF);
                break;
            case ALLEGRO_EVENT_TIMER :
                gridCheckActivation(elements);
                al_flip_display();
                break;
        }
    }




    /// Destroy
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
