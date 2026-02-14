#include <stdio.h>
#include <math.h>
#include <unistd.h>

#include <ncurses.h>

int height,width;

typedef struct {
  float x;
  float y;
}V2;

V2 screen(V2 vector){
    V2 screen_cordinates =
    {
        (vector.x + 3.0)/6 * width,
        (1 - (vector.y + 3.0)/6) * height ,
        // (((1.0 - (vector.y) + 3.0) * height) /6.0)
    };
    return screen_cordinates;
}

float heart_formula(float x,float k){
    if(x == 0){
        return 0;
    } else if (x < 0){
        x = x * -1;
        return (powf(x,2.0/3.0) + 0.9 *  sinf(k*x) * sqrtf(3.0 - powf(x,2.0)) * -1);
    } else {
        return powf(x,2.0/3.0) + 0.9 *  sinf(k*x) * sqrtf(3.0 - powf(x,2.0));
    }

}

int main(int argc, char ** argv)
{
    float k = 0.0;
    // V2 test[] ={
    //  {0,0},
    //  {-3,3},
    //  {3,3},
    //  {3,-3},
    //  {-3,-3}
    // };
    // char test_chars[] = "12345";
    initscr();
    getmaxyx(stdscr,height,width);
    const double FPS = 10.0;
    height--;
    width--;
    V2 point;
    float y;
    while (1) {
        refresh();
        clear();
        for (float x = -2.0 ; x < 2.0; x += 0.01){
            y = heart_formula(x,k);
            if ( y != NAN){
                point = screen((V2){x,y});
                mvaddch((int)point.y,(int)point.x,'@');
            }
        }
        // for (int i = 0; i < 5; ++i){
        //     point = screen(test[i]);
        //     mvaddch((int)point.y,(int)point.x,test_chars[i]);
        // }
        move(height,width);
        usleep(1e6/FPS);
        k++;
    }
    endwin();
}
