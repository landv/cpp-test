//
// Created by landv on 2019/11/29.
//

#include <stdio.h>
#include <xcb/xcb.h>
/**
clang++ main.cpp -o main `pkg-config --cflags --libs xcb` -lxcb-randr

landv@win7-pc:~/Desktop$ ./main

Informations of screen 416:
  width.........: 1920
  height........: 1080
  white pixel...: 16777215
  black pixel...: 0


*/
int  main (){
    /* Open the connection to the X server. Use the DISPLAY environment variable */

    int i, screenNum;
    xcb_connection_t *connection = xcb_connect (NULL, &screenNum);

    /* Get the screen whose number is screenNum */
    const xcb_setup_t *setup = xcb_get_setup (connection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator (setup);

    // we want the screen at index screenNum of the iterator
    for (i = 0; i < screenNum; ++i) {
        xcb_screen_next (&iter);
    }

    xcb_screen_t *screen = iter.data;

    /* report */
    printf ("\n");
    printf ("Informations of screen %u:\n", screen->root);
    printf ("  width.........: %d\n", screen->width_in_pixels);
    printf ("  height........: %d\n", screen->height_in_pixels);
    printf ("  white pixel...: %u\n", screen->white_pixel);
    printf ("  black pixel...: %u\n", screen->black_pixel);
    printf ("\n");

    return 0;
}
