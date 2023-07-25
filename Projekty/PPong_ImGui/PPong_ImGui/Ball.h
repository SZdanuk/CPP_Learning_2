#pragma once
class ppBall
{
public:

    int ball_pos_x, ball_pos_y, speed;
    enum ballDirs
    {
        NE,
        NW,
        SE,
        SW
    };
    ballDirs ball_direction;

    ppBall() //Konstruktor
    {

    }
    ppBall(int x, int y, int ball_speed) //Konstruktor
    {
        ball_pos_x = x;
        ball_pos_y = y;
        speed = ball_speed;
        ball_direction = NE;

    }
        
};

