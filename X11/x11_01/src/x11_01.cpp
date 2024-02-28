#include <X11/Xlib.h>
#include <iostream>
#include <string.h>

int main() {
    Display *display;
    Window window;
    XEvent event;
    char *msg = (char *)"Hello, World!";
    int screen;

    /* open connection with the server */
    display = XOpenDisplay(NULL);
    if(display == NULL) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    screen = DefaultScreen(display);

    /* create window */
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 500, 300, 1,
                           BlackPixel(display, screen), WhitePixel(display, screen));

    /* select kind of events we are interested in */
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    /* map (show) the window */
    XMapWindow(display, window);

    /* event loop */
    while(1) {
        XNextEvent(display, &event);

        /* draw or redraw the window */
        if(event.type == Expose) {
            XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 10, 10);
            XDrawString(display, window, DefaultGC(display, screen), 50, 50, msg, strlen(msg));
        }
        /* exit on key press */
        if(event.type == KeyPress)
            break;
    }

    /* close connection to server */
    XCloseDisplay(display);

    return 0;
}