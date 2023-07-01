#include "Window.h"

int main(void)
{
    srand(time(nullptr));
    Window window(1080, 720);
    window.loop();
    return 0;
}