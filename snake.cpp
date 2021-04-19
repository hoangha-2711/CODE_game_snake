#include "snake.h"
#include <iostream>
#include <string>

snake::snake()
{

}

snake::~snake()
{

}

snake::init(int x, int y,SDl_Renderer* _renderer)
{
    cur_length = 1;
    body[0] = point(x,y);
    renderer = _renderer;
    fruits_count = 0;
}

snake::loop()
{


}

snake::render()
{
    texture =
}

snake::dead()
{

}
