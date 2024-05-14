#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct user 
{
    int r;
    int c;
};
void clear(char x[][498], int mat_r, int mat_c)
{
    //clear the matrix
    int i, j;
    for (i = 0; i < mat_r; i++)
    {
        for (j = 0; j < mat_c; j++)
        {
            x[i][j] = ' ';
        }
    }
}
void map(char x[][498], int mat_r, int mat_c)
{
    //screen the matrix
    int i, j;
    system("cls");
    for (i = 0; i < mat_r; i++)
    {
        for (j = 0; j < mat_c; j++)
        {
            cout << x[i][j];
        }
    }
    cout.flush();

}
void draw_hero(char x[][498], user usr)
{
    //draw hero ["center of gravity" = mouth]
    /*
    hero properties/dimensions:
        6 rows
        8 cols
    */
    //draw head
    x[usr.r][usr.c] = '-';
    x[usr.r][usr.c + 1] = '*';
    x[usr.r][usr.c - 1] = '*';
    x[usr.r][usr.c + 2] = ']';
    x[usr.r][usr.c - 2] = '[';
    //draw torso
    x[usr.r + 1][usr.c] = 208;//╨
    x[usr.r + 1][usr.c + 1] = 196;//─
    x[usr.r + 1][usr.c - 1] = 196;//─
    x[usr.r + 1][usr.c + 2] = 209;//╤
    x[usr.r + 2][usr.c + 2] = 179;//│
    x[usr.r + 1][usr.c - 2] = 209;//╤
    x[usr.r + 2][usr.c - 2] = 179;//│
    x[usr.r + 2][usr.c - 1] = ' ';
    x[usr.r + 2][usr.c] = ' ';
    x[usr.r + 2][usr.c + 1] = ' ';
    x[usr.r + 3][usr.c] = 196;//─
    x[usr.r + 3][usr.c + 1] = 196;//─
    x[usr.r + 3][usr.c - 1] = 196;//─
    x[usr.r + 3][usr.c + 2] = 180;//┤
    x[usr.r + 3][usr.c - 2] = 195;//├
    //draw right hand("free hand")
    x[usr.r + 1][usr.c - 3] = 218;//┌
    x[usr.r + 2][usr.c - 3] = 179;//│
    x[usr.r + 3][usr.c - 3] = 179;//│
    //draw left hand("gun hand")
    x[usr.r + 1][usr.c + 3] = 191;//┐
    x[usr.r + 2][usr.c + 3] = 192;//└
    x[usr.r + 2][usr.c + 4] = 216;//╪
    //draw left leg("kowsa")
    x[usr.r + 4][usr.c + 2] = 179;//│
    x[usr.r + 5][usr.c + 2] = 179;//│
    //draw right leg("bsl")
    x[usr.r + 4][usr.c - 2] = 179;//│
    x[usr.r + 5][usr.c - 2] = 179;//│
    //-------//
    //prototype moving objects
    /* proto frame 1
    //draw hero ["center of gravity" = mouth]
    //draw head
    x[usr.r][usr.c] = '-';
    x[usr.r][usr.c + 1] = '*';
    x[usr.r][usr.c - 1] = '*';
    x[usr.r][usr.c + 2] = ']';
    x[usr.r][usr.c - 2] = '[';
    //draw torso
    x[usr.r + 1][usr.c] = 208;//╨
    x[usr.r + 1][usr.c + 1] = 196;//─
    x[usr.r + 1][usr.c - 1] = 196;//─
    x[usr.r + 1][usr.c + 2] = 209;//╤
    x[usr.r + 2][usr.c + 2] = 179;//│
    x[usr.r + 1][usr.c - 2] = 209;//╤
    x[usr.r + 2][usr.c - 2] = 179;//│
    x[usr.r + 3][usr.c] = 196;//─
    x[usr.r + 3][usr.c + 1] = 196;//─
    x[usr.r + 3][usr.c - 1] = 196;//─
    x[usr.r + 3][usr.c + 2] = 180;//┤
    x[usr.r + 3][usr.c - 2] = 92;//
    //draw right hand("free hand")
    x[usr.r + 1][usr.c - 3] = 218;//┌
    x[usr.r + 2][usr.c - 3] = 92;//
    //x[usr.r + 3][usr.c - 3] = 179;//│
    //draw left hand("gun hand")
    x[usr.r + 1][usr.c + 3] = 191;//┐
    x[usr.r + 2][usr.c + 3] = 192;//└
    x[usr.r + 2][usr.c + 4] = 216;//╪
    //draw left leg("kowsa")
    x[usr.r + 4][usr.c + 2] = 92;//
    //x[usr.r + 5][usr.c + 2] = 179;//
    x[usr.r + 5][usr.c + 3] = 92;//
    //draw right leg("bsl")
    x[usr.r + 4][usr.c - 2] = 179;//│
    x[usr.r + 5][usr.c - 2] = 179;//│
    */
}
void draw_fixed(char x[][498], int mat_r, int mat_c, int ladder_r, int ladder_c, int ladder_length, int ladder_width)
{
    int i, j, k;

    for (i = 0; i < mat_c; i++)
    {
        x[0][i] = '-';
        x[44][i] = '-';
    }
    //draw borders
    for (j = 1; j + 1 < mat_r; j++)
    {
        x[j][0] = '|';
        x[j][165] = '|';
    }
    //draw first hill
    for (i = 0; i < 14; i++)
    {
        x[30 + i][38] = 179;
    }
    x[29][38] = 218;//┌
    for (j = 0; j < 126; j++)
    {
        x[29][39 + j] = 196;
    }
    //draw ladder
    int ladder_c_tmp = ladder_c;
    for (int i = 0; i < ladder_length; i++)
    {
        x[ladder_r][ladder_c_tmp++] = '|';
        for (int j = 0; j < (ladder_width - 2); j++)
        {
            x[ladder_r][ladder_c_tmp++] = '=';
        }
        x[ladder_r][ladder_c_tmp++] = '|';
        ladder_r++;
        ladder_c_tmp = ladder_c;
    }
}
void draw_platform(char x[][498], int platform_r, int platform_c, int platform_width)
{
    int i;
    //stair change place to variables
    x[platform_r][platform_c] = 232;
    for (i = 1; i < platform_width - 1; i++)
    {
        x[platform_r][platform_c + i] = 240;
    }
    x[platform_r][platform_c + i] = 232;
}
void draw_enemy1(char x[][498], int enemy1_r, int enemy1_c)
{
    x[enemy1_r][enemy1_c] = 2;
}
void draw_bullets(char x[][498], int bullets_pos[][2], int ct_bullet)
{
    //loop over number of bullets
    while (ct_bullet)
    {
        //draw bullet in the x & y contained in bullets_pos array
        x[(bullets_pos[ct_bullet][0])][(bullets_pos[ct_bullet][1])] = '>';
        //if infront of bullet is space

        //go to previous bullet
        ct_bullet--;
    }
}
void move_bullets(char x[][498], int bullets_pos[][2], int& ct_bullet)
{
    //reload bullet algoritihim
    // write code here
    //infinite bullets
    // make dummy count
    int ct_bullet_tmp = ct_bullet;
    //loop over number of bullets
    while (ct_bullet_tmp)
    {
        //if infront of bullet is space
        if ((x[bullets_pos[ct_bullet_tmp][0]][bullets_pos[ct_bullet_tmp][1] + 1]) == ' ')
        {
            //move bullet position to the next col
            bullets_pos[ct_bullet_tmp][1]++;
        }
        else
        {
            //shift backwards
            for (int i = ct_bullet_tmp; i < ct_bullet; i++)
            {
                //shift row
                bullets_pos[i][0] = bullets_pos[i + 1][0];
                //shift col
                bullets_pos[i][1] = bullets_pos[i + 1][1];
            }
            //minus actual count of bullet
            ct_bullet--;
            /*
            //shift backwards
            for (int i = ct_bullet_tmp; i < ct_bullet; i++)
            {
                bullets_pos[i][1] = bullets_pos[i + 1][1];
            }
            ct_bullet--;
            */
        }
        //move to the previous bullet
        ct_bullet_tmp--;
    }
    /*
    turret?
    while (ct_bullet--)
    {
        //if infront of bullet is space
        if ((bullets_pos[ct_bullet][0] + 1) == ' ')
        {
            //move bullet position to the next col
            bullets_pos[ct_bullet][0]++;
        }
        else
        {
            //make bullet col = -1
            bullets_pos[ct_bullet][0] = -1;
        }
    }*/
}
//contains all the draw and moves functions
void animation(char x[][498], int mat_r, int mat_c, user usr, int enemy1_r, int enemy1_c, int platform_r, int platform_c, int platform_width, int bullets_pos[][2], int& ct_bullet, int ladder_r, int ladder_c, int ladder_length, int ladder_width)
{
    //clear the matrix
    clear(x, mat_r, mat_c);
    //draw fixed background [current: roof, floor]
    draw_fixed(x, mat_r, mat_c, ladder_r, ladder_c, ladder_length, ladder_width);
    //draw combo1 [platform,enemy1,hero]
    //draw platform
    draw_platform(x, platform_r, platform_c, platform_width);
    //draw enemy 1
    draw_enemy1(x, enemy1_r, enemy1_c);
    //move then draw bullet
    move_bullets(x, bullets_pos, ct_bullet);
    draw_bullets(x, bullets_pos, ct_bullet);
    //draw hero
    draw_hero(x, usr);
    //screen the matrix
}
//gravity,trampoline(no more trampoline :<)
void gravity(char x[][498], int mat_r, int mat_c, user& usr, int enemy1_r, int enemy1_c, int platform_r, int platform_c, int platform_width, int bullets_pos[][2], int ct_bullet, int ladder_r, int ladder_c, int ladder_length, int ladder_width) {
    // bynzl kam cell
    int gravity = 1;
    // Check lw fy hga ta7tyh
    if (usr.r + 6 < mat_r && x[usr.r + 6][usr.c - 2] == ' ' && x[usr.r + 6][usr.c + 2] == ' ') 
    {
        usr.r += gravity;
    }
    //******** Trampoline??
    animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
}
//checks if hero is standing on the elevator
void check_and_move_elevator(char x[][498], int mat_r, int mat_c, user& usr, int enemy1_r, int enemy1_c, int& platform_r, int platform_c, int platform_width, int bullets_pos[][2], int& ct_bullet, int ladder_r, int ladder_c, int ladder_length, int ladder_width, int& is_platform_on_floor, int& platform_cd, int& is_hero_on_platform)
{
    int i, is_left_on_platform = 0;
    if (is_platform_on_floor == 0)
    {
        //minus from the cd
        platform_cd--;
        //when cd is less than 1
        if (platform_cd < 1)
        {
            //doc howa gowa el asansir nfso momken n5li g3fr yt7rk wla la2
            //checks if user's position is on the platform
            for (i = platform_c; i < platform_width + platform_c; i++)
            {
                if (usr.c - 3 == i)
                {
                    is_left_on_platform = 1;
                }
                if (usr.r + 6 == platform_r && usr.c + 3 == i && is_left_on_platform == 1)
                {
                    //sets hero to standing on a platform
                    is_hero_on_platform = 1;
                }
            }
            if (is_hero_on_platform == 1)
            {
                //is_hero_on_platform = 1;
                usr.r--;
                platform_r--;
                //10 equal to the height the platform will move(should be variable)
                if (platform_r == 44 - 10)
                {
                    //flag platform to be not on floor
                    is_platform_on_floor = 1;
                    //set a cd to make platform stay in place
                    platform_cd = 20;
                }
            }
        }
    }
    //when platform not on ground
    if (is_platform_on_floor == 1)
    {
        //some cd to make the transition smoother
        if (platform_cd == 19)
        {
        //set hero to not standing on the platform
        is_hero_on_platform = 0;
        }
        //minus from the cd
        platform_cd--;
        //when cd is less than
        if (platform_cd < 1)
        {
            //check if hero is standing on platform
            for (i = platform_c; i < platform_width + platform_c; i++)
            {
                if (usr.c - 3 == i)
                {
                    is_left_on_platform = 1;
                }
                if (usr.r + 6 == platform_r && usr.c + 3 == i && is_left_on_platform == 1)
                {
                    //sets hero to standing on a platform
                    is_hero_on_platform = 1;
                }
            }
            //start moving platform to the floor
            platform_r++;
            //when platform is at floor
            if (platform_r == 44)
            {
                //reset flag
                is_platform_on_floor = 0;
                //reset cooldown
                platform_cd = 20;
                //sets hero to not standing on platform
                is_hero_on_platform = 0;
            }
        }
    }
}
void user_action(char x[][498], char dir, user& usr, int mat_r, int mat_c, int& enemy1_r, int& enemy1_c, int platform_r, int platform_c, int platform_width, int& is_hero_on_platform, int bullets_pos[][2], int& ct_bullet, int ladder_r, int ladder_c, int ladder_flag, int ladder_length, int ladder_width)
{
    ladder_flag = 0;
    for (int i = 0; i < ladder_length; i++)
    {
        if ((usr.r + 5) == (ladder_r + i))
        {
            for (int j = 0; j < ladder_width; j++)
            {
                if (usr.c == (ladder_c + j))
                {
                    ladder_flag = 1;
                }
            }
        }
    }
    /*if ((x[usr.r+ 5][usr.c-1] == '|'&& x[usr.r + 5][usr.c + 1] == '=')||(x[usr.r + 5][usr.c - 1] == '=' && x[usr.r + 5][usr.c + 1] == '|'))
    {

        ladder_flag = 1;
        break;
    }
    else
    {
        break;
    }*/
    if (ladder_flag == 1)
    {
        if (dir == 'w')
        {
            usr.r--;
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
        }
    }
    //move up if user pressed w
    /*if (dir == 'w')
    {
        usr.r--;
        animation(x, mat_r, mat_c, usr.r, usr.c, enemy1_r, enemy1_c, platform_r, platform_c, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
    }*/
    //move down if user pressed s while on a ladder
    if (ladder_flag == 1)
    {
        if (dir == 's' && usr.r < 38)
        {
            usr.r++;
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
        }
    }
    //move left if user pressed a
    if (dir == 'a')
    {
        if (is_hero_on_platform == 0 || (usr.c - 3) != platform_c)
        {
            usr.c--;
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
        }
    }
    //move right if user pressed d check char as a bound
    if (dir == 'd' && x[usr.r][usr.c + 4] != '|')
    {
        if (is_hero_on_platform == 0 || (usr.c + 4) != (platform_c + platform_width))
        {
            usr.c++;
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
        }
    }
    //gets the gun's row {subject to change}
    int gun_r = usr.r + 2;
    //gets the gun's col {subject to change}
    int gun_c = usr.c + 4;
    //shoot an arrow if user pressed e
    if (dir == 'e')
    {
        ct_bullet++;
        bullets_pos[ct_bullet][0] = gun_r;
        bullets_pos[ct_bullet][1] = gun_c + 1;
    }
    //shoot grapple hook
    if (dir == 'f')
    {
        int i;
        //loop from gun col to obstacle (not space) or 5
        for (i = 1; x[gun_r][gun_c + i] == ' ' && i < 5; i++)
        {
            //make things move while inside loop
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            //checks collision [currently checks with enemy1 only]

            //throws grapple
            //draw grapple tip
            x[gun_r][gun_c + i] = '>';
            if ((i - 1) > 0)
            {
                //loop from after gun col to before grapple tip
                for (int j = 1; j < i; j++)
                {
                    //draw grapple rope
                    x[gun_r][gun_c + j] = '-';
                }
            }
            map(x, mat_r, mat_c);
        }
        //enemy detection
        if (x[gun_r][gun_c + i] == 2)
        {
            //if you catched enemy
            //(sudden >:) animation)
            //move&display hero to infront of enemy
            usr.c += i - 1;
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            map(x, mat_r, mat_c);
            //draw hero behind enemy*needs to be changed to dynamic*
            usr.c += 11;
            //redraw map
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            //draw hit animation
            x[gun_r - 2][usr.c - 8] = 92;
            x[gun_r - 1][usr.c - 7] = 92;
            x[gun_r][usr.c - 6] = 92;
            x[gun_r + 1][usr.c - 5] = 92;
            x[gun_r + 2][usr.c - 4] = 92;
            //kill enemy
            enemy1_r = -1;
            //display
            map(x, mat_r, mat_c);

            //animation
            //for(k=1;k<i;k++)
            // usr.c++;
            // clear(x, mat_r, mat_c);
            //
            //
            //x[r][c + i] = '>';
            //	map(x, mat_r, mat_c);
        }
    }
    //fire laser if you press r
    if (dir == 'r')
    {
        int i;
        //loop from gun col to something that's not space
        for (i = 1; x[gun_r][gun_c + i] == ' '; i++)
        {
            x[gun_r][gun_c + i] = 205;
        }
        map(x, mat_r, mat_c);
        //enemy detection
        if (x[gun_r][gun_c + i] == 2)
        {
            //touched enemy
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            map(x, mat_r, mat_c);
            animation(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            x[enemy1_r][enemy1_c] = 248;
            x[enemy1_r][enemy1_c - 2] = 248;
            x[enemy1_r + 1][enemy1_c - 1] = 248;
            x[enemy1_r + 1][enemy1_c + 1] = 248;
            enemy1_r = -1;
            map(x, mat_r, mat_c);
        }
    }
    //dodge button
    if (dir == 'z')
    {
        usr.c += 10;
    }


}
int main()
{
    //combo 1 para: (char x[][498], char dir, int& usr.r, int& usr.c, int mat_r, int mat_c, int& enemy1_r, int& enemy1_c,int platform_r, int platform_c, int bullets_pos[][2],int &ct_bullet,int ladder_r, int ladder_c, int ladder_length)
    int mat_r, mat_c;
    user usr;
    int enemy1_r, enemy1_c;
    int platform_r, platform_c, platform_width, is_platform_on_floor, platform_cd, is_hero_on_platform;
    int bullets_pos[100][2], ct_bullet = 0;
    int ladder_r, ladder_c, ladder_flag, ladder_length, ladder_width;
    char x[45][498];
    //size of mat
    mat_r = 45;
    mat_c = 166;
    //usr position
    usr.r = 38;
    //usr.c = 80;
    usr.c = 20;
    //enemy1 position
    enemy1_r = 38;
    enemy1_c = 150;
    //platform position
    platform_r = 44;
    platform_c = 196;
    platform_width = 15;
    is_platform_on_floor = 0;
    platform_cd = 0;
    is_hero_on_platform = 0;
    //ladder position and flag
    //top left cell of the ladder
    ladder_r = 29;
    ladder_c = 30;
    ladder_flag = 0;
    ladder_length = 15;
    ladder_width = 8;
    //infinite loop
    while (true)
    {
        //loop till keyboard is hit
        while (!_kbhit())
        {
            //clear matrix to redraw
            clear(x, mat_r, mat_c);
            //draw fixed background [current: roof, floor]
            draw_fixed(x, mat_r, mat_c, ladder_r, ladder_c, ladder_length, ladder_width);
            //draw combo1 [platform,enemy1,hero]
            //draw platform
            draw_platform(x, platform_r, platform_c, platform_width);
            //draw enemy 1
            draw_enemy1(x, enemy1_r, enemy1_c);
            //move then draw bullet
            move_bullets(x, bullets_pos, ct_bullet);
            draw_bullets(x, bullets_pos, ct_bullet);
            //draw hero
            draw_hero(x, usr);
            //gravity
            gravity(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);
            check_and_move_elevator(x, mat_r, mat_c, usr, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width, is_platform_on_floor, platform_cd, is_hero_on_platform);
            //screen the matrix
            map(x, mat_r, mat_c);
        }
        //save user input
        char move = _getch();
        //take action based on input
        user_action(x, move, usr, mat_r, mat_c, enemy1_r, enemy1_c, platform_r, platform_c, platform_width, is_hero_on_platform, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_flag, ladder_length, ladder_width);
        //*betsara3 el gravity lma ad5al input bas bt7el moshkelet lazer spamming wna tayer
        //gravity(x, mat_r, mat_c, usr.r, usr.c, enemy1_r, enemy1_c, platform_r, platform_c, bullets_pos, ct_bullet, ladder_r, ladder_c, ladder_length, ladder_width);

    }
}
/*
void MoveHero(int& usr.r, int& usr.c, char dir, int& ladder_flag, char X[][80])
{
    ladder_flag = 0;
    while (true)
    {
        if ((X[usr.r+1][usr.c-1] == '|'&& X[usr.r+1][usr.c + 1] == '=')||(X[usr.r + 1][usr.c - 1] == '=' && X[usr.r + 1][usr.c + 1] == '|'))
        {

            ladder_flag = 1;
            break;
        }
        else
        {
            break;
        }

    }
    if (ladder_flag == 1)
    {
        if (dir == 'w') {
            usr.r--;
        }
    }
    if (dir == 's') {
        usr.r++;
    }
    if (dir == 'a') {
        usr.c--;
    }
    if (dir == 'd')
    {
        usr.c++;
    }

}
*/