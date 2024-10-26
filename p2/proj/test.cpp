#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct matrix
{
    int r;
    int c;
    int forward_boundary;
    int backward_boundary;
    int scroll_speed;
    int do_scroll = 0;

};
struct user
{
    int r;
    int c;
    int speed;
};
struct platfrm
{
    int r;
    int c;
    int width;
    int top;
    int is_platform_on_floor;
    int cd;
    int is_hero_on_platform;
    int is_passable;
};
struct ldder
{
    int r;
    int c;
    int flag_up;
    int flag_down;
    int length;
    int width;
    int is_passable;
};
struct enemy
{
    int r;
    int c;
    int is_passable;
};
struct hill
{
    int start_r;
    int start_c;
    int end_r;
    int end_c;
    int is_right_wall;
    int is_left_wall;
    int is_horizontal_wall;
};
struct lva
{
    int r;
    int c;
    int width;
    int top;
    int is_hero_on_lava;
    int is_passable;
};
void clear(char x[][498])
{
    //clear the matrix
    int i, j;
    for (i = 0; i < 30; i++)
    {
        for (j = 0; j < 498; j++)
        {
            x[i][j] = ' ';
        }
    }
}
void map(char x[][498], matrix mat)
{
    //screen the matrix
    int i, j;
    system("cls");
    for (i = (mat.r - 30); i < mat.r; i++)
    {
        for (j = (mat.c - 115); j < mat.c; j++)
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
void draw_fixed(char x[][498], matrix mat, ldder ladder, hill hills[], int ct_hills, lva lava)
{
    int i, j, k;

    //draw borders
    for (i = (mat.c - 115); i < mat.c; i++)
    {
        x[0][i] = '-';
        x[29][i] = '-';
    }
    for (j = 1; j + 1 < mat.r; j++)
    {
        x[j][(mat.c - 115)] = '|';
        x[j][(mat.c - 1)] = '|';
    }
    //draw walls
    //draw hill
    while (ct_hills)
    {
        //draw verticals
        if (hills[ct_hills].is_left_wall == 1 || hills[ct_hills].is_right_wall == 1)
        {
            for (i = hills[ct_hills].start_r; i < hills[ct_hills].end_r; i++)
            {
                if (hills[ct_hills].is_left_wall == 1)
                {
                    x[i][hills[ct_hills].start_c] = 179; //│
                }
                if (hills[ct_hills].is_right_wall == 1)
                {
                    x[i][hills[ct_hills].end_c] = 179; //│
                }

            }
        }
        //draw corners
        if (hills[ct_hills].is_left_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
          x[hills[ct_hills].start_r][hills[ct_hills].start_c] = 218; //┌
        }
        if (hills[ct_hills].is_right_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].end_c] = 191; //┐
        }
        //draw horizontal( - and + to remove corners
        if (hills[ct_hills].is_horizontal_wall = 1)
        {
            for (i = (hills[ct_hills].start_c + 1); i < (hills[ct_hills].end_c); i++)
            {
                x[hills[ct_hills].start_r][i] = 196; //─
            }
        }
        ct_hills--;
    }
    //draw ladder
    int ladder_c_tmp = ladder.c;
    for (int i = 0; i < ladder.length; i++)
    {
        x[ladder.r][ladder_c_tmp++] = '|';
        for (int j = 0; j < (ladder.width - 2); j++)
        {
            x[ladder.r][ladder_c_tmp++] = '=';
        }
        x[ladder.r][ladder_c_tmp++] = '|';
        ladder.r++;
        ladder_c_tmp = ladder.c;
    }
    //draw lava
    for (i = 0 ;i < lava.width; i++)
    {
        x[lava.r][lava.c + i] = 247; //≈
    }
}
void draw_platform(char x[][498], platfrm platform)
{
    int i;
    //stair change place to variables
    x[platform.r][platform.c] = 232;
    for (i = 1; i < platform.width - 1; i++)
    {
        x[platform.r][platform.c + i] = 240;
    }
    x[platform.r][platform.c + i] = 232;
}
void draw_enemy1(char x[][498], enemy enemy1)
{
    x[enemy1.r][enemy1.c] = 2;
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
void animation(char x[][498], matrix mat, user usr, enemy enemy1, platfrm platform, int bullets_pos[][2], int& ct_bullet, ldder ladder, hill hills[], int ct_hills, lva lava)
{
    //clear the matrix
    clear(x);
    //draw fixed background [current: roof, floor]
    draw_fixed(x, mat, ladder, hills, ct_hills, lava);
    //draw combo1 [platform,enemy1,hero]
    //draw platform
    draw_platform(x, platform);
    //draw enemy 1
    draw_enemy1(x, enemy1);
    //move then draw bullet
    move_bullets(x, bullets_pos, ct_bullet);
    draw_bullets(x, bullets_pos, ct_bullet);
    //draw hero
    draw_hero(x, usr);
    //screen the matrix
}
//gravity,trampoline(no more trampoline :<)
void gravity(char x[][498], matrix mat, user& usr, enemy enemy1, platfrm platform, int bullets_pos[][2], int ct_bullet, ldder ladder, hill hills[], int ct_hills,lva lava) 
{
    // bynzl kam cell
    int gravity = 1;
    // Check lw fy hga ta7tyh
    if (usr.r + 6 < mat.r && x[usr.r + 6][usr.c - 2] == ' ' && x[usr.r + 6][usr.c + 2] == ' ')
    {
        usr.r += gravity;
    }
    //******** Trampoline??
    animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
}
//checks if hero is standing on the elevator
void check_and_move_elevator(char x[][498], user& usr, platfrm &platform)
{
    int i, is_left_on_platform = 0;
    if (platform.is_platform_on_floor == 0)
    {
        //minus from the cd
        platform.cd--;
        //when cd is less than 1
        if (platform.cd < 1)
        {
            //doc howa gowa el asansir nfso momken n5li g3fr yt7rk wla la2
            //checks if user's position is on the platform
            for (i = platform.c; i < platform.width + platform.c; i++)
            {
                if (usr.c - 3 == i)
                {
                    is_left_on_platform = 1;
                }
                if (usr.r + 6 == platform.r && usr.c + 3 == i && is_left_on_platform == 1)
                {
                    //sets hero to standing on a platform
                    platform.is_hero_on_platform = 1;
                }
            }
            if (platform.is_hero_on_platform == 1)
            {
                usr.r--;
                platform.r--;
                if (platform.r == 29 - platform.top)
                {
                    //flag platform to be not on floor
                    platform.is_platform_on_floor = 1;
                    //set a cd to make platform stay in place
                    platform.cd = 20;
                }
            }
        }
    }
    //when platform not on ground
    if (platform.is_platform_on_floor == 1)
    {
        //some cd to make the transition smoother
        if (platform.cd == 19)
        {
            //set hero to not standing on the platform
            platform.is_hero_on_platform = 0;
        }
        //minus from the cd
        platform.cd--;
        //when cd is less than
        if (platform.cd < 1)
        {
            //check if hero is standing on platform
            for (i = platform.c; i < platform.width + platform.c; i++)
            {
                if (usr.c - 3 == i)
                {
                    is_left_on_platform = 1;
                }
                if (usr.r + 6 == platform.r && usr.c + 3 == i && is_left_on_platform == 1)
                {
                    //sets hero to standing on a platform
                    platform.is_hero_on_platform = 1;
                }
            }
            //start moving platform to the floor
            platform.r++;
            //when platform is at floor
            if (platform.r == 29)
            {
                //reset flag
                platform.is_platform_on_floor = 0;
                //reset cooldown
                platform.cd = 20;
                //sets hero to not standing on platform
                platform.is_hero_on_platform = 0;
            }
        }
    }
}
void check_next_level_and_scroll(char x[][498], matrix &mat, user &usr)
{
    if (mat.do_scroll == 0)
    {
        if (usr.c == 115)
        {
            //tp usr to next scene and allow scrolling
            mat.c += 115;
            usr.r = 23;
            usr.c = 116;
            mat.do_scroll = 1;
        }
    }
    if (mat.do_scroll == 1)
    {
        if (usr.c > (mat.c - mat.forward_boundary) && mat.c < 498)
        {
            mat.c += mat.scroll_speed;
        }
        //bounds
        if (usr.c < (mat.c - mat.backward_boundary) && mat.c > 115 * 2)
        {
            mat.c -= mat.scroll_speed;
        }
        if (usr.c == 114)
        {
            //tp usr to prev scene and stop scrolling
            mat.c -= 115;
            usr.r = 8;
            usr.c = 113;
            mat.do_scroll = 0;
        }
    }
}
void object_detection()
{

}
void user_action(char x[][498], char dir, user& usr, matrix mat, enemy &enemy1, platfrm platform, int bullets_pos[][2], int& ct_bullet, ldder ladder, hill hills[], int ct_hills,lva lava)
{
    ladder.flag_up = 0;
    ladder.flag_down = 0;
    for (int i = 0; i < ladder.length; i++)
    {
        //idk checks if you stand on ladder somehow
        if ((usr.r + 5) == (ladder.r + i))
        {
            for (int j = 0; j < ladder.width; j++)
            {
                if (usr.c == (ladder.c + j))
                {
                    ladder.flag_up = 1;
                }
            }
        }
        if ((usr.r + 6) == (ladder.r + i))
        {
            for (int j = 0; j < ladder.width; j++)
            {
                if (usr.c == (ladder.c + j))
                {
                    ladder.flag_down = 1;
                }
            }
        }

    }
    /*if ((x[usr.r+ 5][usr.c-1] == '|'&& x[usr.r + 5][usr.c + 1] == '=')||(x[usr.r + 5][usr.c - 1] == '=' && x[usr.r + 5][usr.c + 1] == '|'))
    {

        ladder.flag = 1;
        break;
    }
    else
    {
        break;
    }*/
    if (ladder.flag_up == 1)
    {
        if (dir == 'w')
        {
            usr.r-= usr.speed;
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
        }
    }
    //move up if user pressed w
    /*if (dir == 'w')
    {
        usr.r--;
        animation(x, mat_r, mat_c, usr.r, usr.c, enemy1, platform.r, platform.c, bullets_pos, ct_bullet, ldder ladder);
    }*/
    //move down if user pressed s while on a ladder
    if (ladder.flag_down == 1)
    {
        if (dir == 's' && usr.r + 5 < 45)
        {
            usr.r+= usr.speed;
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
        }
    }
    //move left if user pressed a
    if (dir == 'a')
    {
        if (platform.is_hero_on_platform == 0 || (usr.c - 3) != platform.c)
        {
            usr.c-= usr.speed;
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
        }
    }
    //move right if user pressed d check char as a bound
    if (dir == 'd')
    {
        if (platform.is_hero_on_platform == 0 || (usr.c + 4) != (platform.c + platform.width))
        {
            usr.c+= usr.speed;
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
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
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
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
            map(x, mat);
        }
        //enemy detection
        if (x[gun_r][gun_c + i] == 2)
        {
            //if you catched enemy
            //(sudden >:) animation)
            //move&display hero to infront of enemy
            usr.c += i - 1;
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
            map(x, mat);
            //draw hero behind enemy*needs to be changed to dynamic*
            usr.c += 11;
            //redraw map
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
            //draw hit animation
            x[gun_r - 2][usr.c - 8] = 92;
            x[gun_r - 1][usr.c - 7] = 92;
            x[gun_r][usr.c - 6] = 92;
            x[gun_r + 1][usr.c - 5] = 92;
            x[gun_r + 2][usr.c - 4] = 92;
            //kill enemy
            enemy1.r = -1;
            //display
            map(x, mat);

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
        map(x, mat);
        //enemy detection
        if (x[gun_r][gun_c + i] == 2)
        {
            //touched enemy
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
            map(x, mat);
            animation(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
            x[enemy1.r][enemy1.c] = 248;
            x[enemy1.r][enemy1.c - 2] = 248;
            x[enemy1.r + 1][enemy1.c - 1] = 248;
            x[enemy1.r + 1][enemy1.c + 1] = 248;
            enemy1.r = -1;
            map(x, mat);
        }
    }
    //dodge button
    if (dir == 'x')
    {
        usr.c += 10;
    }
    if (dir == 'z')
    {
        usr.c -= 10;
    }
}
int main()
{
    //combo 1 para: (char x[][498], char dir, int& usr.r, int& usr.c, int mat_r, int mat_c, int& enemy1_r, int& enemy1_c,int platform.r, int platform.c, int bullets_pos[][2],int &ct_bullet,int ladder.r, int ladder.c, int ladder.length)
    char x[30][498];
    matrix mat;
    user usr;
    enemy enemy1;
    platfrm platform;
    int bullets_pos[100][2], ct_bullet = 0;
    ldder ladder;
    hill hills[4 + 1];
    int ct_hills = 4;
    lva lava;
    //size of mat
    mat.r = 30;
    mat.c = 115;
    mat.forward_boundary = 35;
    mat.backward_boundary = 84;
    mat.scroll_speed = 1;
    mat.do_scroll = 0;
    //usr position
    //scene 1
   // usr.r = 23;
   // usr.c = 20;
    //scene 2
    usr.r = 23;
    usr.c = 115;
    usr.speed = 1;
    //enemy1 position
    enemy1.r = 10;
    enemy1.c = 99;
    //hills positions
    hills[1].start_r = 14;
    hills[1].end_r = 14 + 15; //29
    hills[1].start_c = 38;
    hills[1].end_c = 38 + 76; //114
    hills[1].is_left_wall = 1;
    hills[1].is_horizontal_wall = 1;
    hills[1].is_right_wall = 0;
    hills[2].start_r = 14;
    hills[2].end_r = 0;
    hills[2].start_c = 114 + 1; //115
    hills[2].end_c = 115 + 65;//180
    hills[2].is_left_wall = 0;
    hills[2].is_horizontal_wall = 1;
    hills[2].is_right_wall = 0;
    //
    hills[3].start_r = 14;
    hills[3].end_r = 0;
    hills[3].start_c = 195 + 1; //196
    hills[3].end_c = 197 + 48;//245
    hills[3].is_left_wall = 0;
    hills[3].is_horizontal_wall = 1;
    hills[3].is_right_wall = 0;
    //
    hills[4].start_r = 14;
    hills[4].end_r = 0;
    hills[4].start_c = 330; //196
    hills[4].end_c = 330 + 15;//345
    hills[4].is_left_wall = 0;
    hills[4].is_horizontal_wall = 1;
    hills[4].is_right_wall = 0;
    //platform position
    platform.r = 29;
    platform.c = 180 + 1;
    platform.width = 15;
    platform.top = 15;
    platform.is_platform_on_floor = 0;
    platform.cd = 0;
    platform.is_hero_on_platform = 0;
    //ladder position and flag
    //top left cell of the ladder
    ladder.r = 14;
    ladder.c = 30;
    ladder.flag_up = 0;
    ladder.flag_down = 0;
    ladder.length = 15;
    ladder.width = 8;
    //lava position
    lava.r = 29;
    lava.c = 245;
    lava.width = 115 - 30; //buffer of 10 blocks right and elft
    lava.top = 5;
    lava.is_hero_on_lava = 0;
    //infinite loop
    while (true)
    {
        //loop till keyboard is hit
        while (!_kbhit())
        {
            //clear matrix to redraw
            clear(x);
            //draw fixed background [current: roof, floor]
            check_next_level_and_scroll(x, mat, usr);
            draw_fixed(x, mat, ladder, hills, ct_hills, lava);
            //draw platform
            draw_platform(x, platform);
            //draw enemy 1
          // draw_enemy1(x, enemy1);
            //move then draw bullet
            move_bullets(x, bullets_pos, ct_bullet);
            draw_bullets(x, bullets_pos, ct_bullet);
            //draw hero
            draw_hero(x, usr);
            //gravity
            gravity(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
            check_and_move_elevator(x, usr, platform);
            //screen the matrix
            map(x, mat);
        }
        //save user input
        char move = _getch();
        //take action based on input
        user_action(x, move, usr, mat, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills, lava);
        //*betsara3 el gravity lma ad5al input bas bt7el moshkelet lazer spamming wna tayer
        //gravity(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills);

    }
}
/*
void MoveHero(int& usr.r, int& usr.c, char dir, int& ladder.flag, char X[][80])
{
    ladder.flag = 0;
    while (true)
    {
        if ((X[usr.r+1][usr.c-1] == '|'&& X[usr.r+1][usr.c + 1] == '=')||(X[usr.r + 1][usr.c - 1] == '=' && X[usr.r + 1][usr.c + 1] == '|'))
        {

            ladder.flag = 1;
            break;
        }
        else
        {
            break;
        }

    }
    if (ladder.flag == 1)
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