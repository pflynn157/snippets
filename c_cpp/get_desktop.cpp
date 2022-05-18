//Used for getting current desktop with X11
//===========================================================
#include <limits.h>
#include <X11/Xlib.h>

int getCurrentDesktop() {
    Display *dsp = XOpenDisplay(NULL);
    Window root = XRootWindow(dsp, 0);
    
    Atom type;
    int format;
    unsigned long nitems, bytes_after;
    int *current_desktop;
    
    XGetWindowProperty(dsp, root, XInternAtom(dsp, "_NET_CURRENT_DESKTOP", 1),
        0L, LONG_MAX, 0, AnyPropertyType, &type, &format, &nitems, &bytes_after,
        (unsigned char **)&current_desktop);
    
    XCloseDisplay(dsp);

    if (current_desktop == nullptr)
    	return 0;
    return current_desktop[0];
}
