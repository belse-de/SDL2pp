//
// Created by belse on 15.03.18.
//

#include "Window.hpp"

using namespace Widget;

Widget::Window::Window(SDL2pp::Window &w) : _window{w}{

}

void Widget::Window::render(SDL2pp::Renderer &renderer) {
    //Initialize renderer color
    renderer.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    //Clear screen
    renderer.clear();
    int w,h;
    _window.getSize(&w,&h);
    SDL_Rect frame = {5,5,w-10,h-10};
    renderer.setDrawColor(0x00, 0x00, 0x00, 0xFF);
    renderer.drawRect(&frame);
}
