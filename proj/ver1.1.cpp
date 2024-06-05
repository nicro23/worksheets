#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
using namespace std;
struct matrix
{
    int r;
    int c;
    int forward_boundary;
    int backward_boundary;
    int scroll_speed;
    int do_scroll;
    int level;

};
struct user
{
    int r;
    int c;
    int speed;
    int is_jumping;
    int jump_height;
    int jump_cd;
    int jump_cd_reset;
    int gravity_speed;
    int can_left;
    int can_right;
    int can_ladder_up;
    int can_ladder_down;
    int can_fall;
    int can_fly;
    int is_falling;
    int is_facing_right;
    int cur_frame;
    int die;

};
struct platfrm
{
    int r;
    int r_const;
    int c;
    int width;
    int top;
    int is_platform_on_floor;
    int cd;
    int cd_reset;
    int is_hero_on_platform;
    int is_moving;
};
struct ldder
{
    int r;
    int c;
    int length;
    int width;
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
};
struct cest
{
    int r;
    int c;
    int cur_frame;
};
struct katio
{
    int r;
    int c;
    int is_looking_right;
    //range for vision
    int c_min;
    int c_max;
    int cur_frame;
    int hp;
    int alive;
    int cd;
    int cd_reset;

};
struct bullts
{
    int ct;
    int pos[100][2];
    int cd;
    int cd_reset;
};
struct mahmod
{
    int r;
    int c;
};
struct ofu
{
    int r;
    int c;
    int cur_frame;
    int cd;
    int cd_reset;
};
void clear(char x[][350])
{
    //clear the matrix
    int i, j;
    for (i = 0; i < 30; i++)
    {
        for (j = 0; j < 350; j++)
        {
            x[i][j] = ' ';
        }
    }
}
void map(char x[][350], matrix mat)
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
void draw_hero(char x[][350], user& usr)
{
    //draw hero ["center of gravity" = mouth]
    /*
    hero properties/dimensions:
        6 rows
        8 cols
        hitbox is 6 row and 7 cols
    */
    //draw looking right
    if (usr.cur_frame == 0 || usr.cur_frame == 1)
    {
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
    }
    //draw looking left
    if (usr.cur_frame == 4 || usr.cur_frame == 5)
    {
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
        x[usr.r + 2][usr.c - 3] = 217;//│
        x[usr.r + 2][usr.c - 4] = 216;//│
        //draw left hand("gun hand")
        x[usr.r + 1][usr.c + 3] = 191;//┐
        x[usr.r + 2][usr.c + 3] = 179;//└
        x[usr.r + 3][usr.c + 3] = 179;//╪
        //draw left leg("kowsa")
        x[usr.r + 4][usr.c + 2] = 179;//│
        x[usr.r + 5][usr.c + 2] = 179;//│
        //draw right leg("bsl")
        x[usr.r + 4][usr.c - 2] = 179;//│
        x[usr.r + 5][usr.c - 2] = 179;//│
    }
    //draw turning left
    if (usr.cur_frame == 2 || usr.cur_frame == 3)
    {
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
        x[usr.r + 2][usr.c - 3] = '/';//│
        x[usr.r + 3][usr.c - 4] = '/';//│
        //draw left hand("gun hand")
        x[usr.r + 1][usr.c + 3] = 191;//┐
        x[usr.r + 2][usr.c + 3] = 192;//└
        x[usr.r + 2][usr.c + 4] = 216;//╪
        //draw left leg("kowsa")
        x[usr.r + 4][usr.c + 2] = 179;//│
        x[usr.r + 5][usr.c + 2] = 179;//│
        //draw right leg("bsl")
        x[usr.r + 4][usr.c - 2] = 179;//│
        x[usr.r + 5][usr.c - 3] = '/';//│
        if (usr.cur_frame == 3)
        {
            usr.cur_frame--;
        }
        else
        {
            usr.cur_frame = 5;
        }
    }
    //draw turning right
    if (usr.cur_frame == 6 || usr.cur_frame == 7)
    {
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
        //draw right hand("gun hand")
        x[usr.r + 1][usr.c - 3] = 218;//┌
        x[usr.r + 2][usr.c - 3] = 217;//│
        x[usr.r + 2][usr.c - 4] = 216;//│
        //draw left hand("free hand")
        x[usr.r + 1][usr.c + 3] = 191;//┐
        x[usr.r + 2][usr.c + 3] = 92;//└
        x[usr.r + 3][usr.c + 4] = 92;//╪
        //draw left leg("kowsa")
        x[usr.r + 4][usr.c + 2] = 179;//│
        x[usr.r + 5][usr.c + 3] = 92;
        //draw right leg("bsl")
        x[usr.r + 4][usr.c - 2] = 179;//│
        x[usr.r + 5][usr.c - 2] = 179;//│
        if (usr.cur_frame == 7)
        {
            usr.cur_frame--;
        }
        else
        {
            usr.cur_frame = 1;
        }
    }
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
void draw_fixed(char x[][350], matrix mat, ldder ladder, hill hills[], int ct_hills, lva lava)
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
    //draw clouds
    //draw clouds
    //cloud 1
    x[2][7] = 218;
    x[2][8] = 196;
    x[2][9] = 196;
    x[2][10] = 196;
    x[2][11] = 196;
    x[2][12] = 191;
    x[3][7] = 179;
    x[3][12] = 193;
    x[3][13] = 196;
    x[3][14] = 191;
    x[4][5] = 218;
    x[4][6] = 196;
    x[4][7] = 217;
    x[4][14] = 193;
    x[4][15] = 196;
    x[4][16] = 191;
    x[5][5] = 192;
    x[5][6] = 196;
    x[5][7] = 196;
    x[5][8] = 196;
    x[5][9] = 196;
    x[5][10] = 196;
    x[5][11] = 196;
    x[5][12] = 196;
    x[5][13] = 196;
    x[5][14] = 196;
    x[5][15] = 196;
    x[5][16] = 217;

    //stars
    x[5][22] = '*';
    x[3][70] = '*';
    x[2][37] = '*';
    x[2][29] = '*';
    x[4][28] = '*';
    x[5][37] = '*';
    x[5][65] = '*';
    x[2][74] = '*';
    x[3][22] = '*';
    x[4][76] = '*';
    x[2][80] = '*';
    x[2][105] = '*';
    x[4][108] = '*';

    //cloud 2
    x[2][51] = 218;
    x[2][52] = 196;
    x[2][53] = 196;
    x[2][54] = 196;
    x[2][55] = 196;
    x[2][56] = 191;
    x[3][51] = 217;
    x[3][50] = 196;
    x[3][50] = 218;
    x[3][51] = 180;
    x[3][56] = 192;
    x[4][51] = 196;
    x[4][50] = 192;
    x[4][52] = 196;
    x[4][53] = 196;
    x[4][54] = 196;
    x[4][55] = 196;
    x[4][56] = 196;
    x[4][57] = 217;
    x[3][57] = 191;
    //cloud 3
    x[2][93] = 218;
    x[2][94] = 196;
    x[2][95] = 196;
    x[2][96] = 196;
    x[2][97] = 194;
    x[2][98] = 191;
    x[3][98] = 193;
    x[3][97] = 192;
    x[3][99] = 191;
    x[4][99] = 179;
    x[5][99] = 217;
    x[5][98] = 196;
    x[5][97] = 196;
    x[5][96] = 196;
    x[5][95] = 196;
    x[5][94] = 196;
    x[5][93] = 196;
    x[5][92] = 196;
    x[5][91] = 196;
    x[4][90] = 180;
    x[5][90] = 193;
    x[5][89] = 192;
    x[4][89] = 218;
    x[3][90] = 218;
    x[3][91] = 196;
    x[3][93] = 217;
    x[3][92] = 196;
    x[4][57] = 217;
    x[3][57] = 191;

    //cloud 4
    x[3][122] = 218;
    x[3][123] = 196;
    x[3][124] = 196;
    x[3][125] = 196;
    x[3][126] = 191;
    x[4][126] = 197;
    x[4][127] = 191;
    x[5][127] = 217;
    x[5][126] = 196;
    x[5][125] = 196;
    x[5][124] = 196;
    x[5][123] = 196;
    x[5][122] = 196;
    x[4][122] = 217;
    x[5][121] = 192;
    x[4][121] = 218;

    //cloud 5

    x[3][214] = 218;
    x[3][215] = 196;
    x[3][216] = 196;
    x[3][217] = 196;
    x[3][218] = 196;
    x[3][219] = 191;
    x[4][219] = 193;
    x[4][220] = 191;
    x[5][220] = 192;
    x[5][221] = 196;
    x[5][222] = 191;
    x[6][222] = 217;
    x[6][221] = 196;
    x[6][220] = 196;
    x[6][219] = 196;
    x[6][218] = 196;
    x[6][217] = 196;
    x[6][216] = 196;
    x[6][215] = 196;
    x[6][214] = 196;
    x[6][213] = 196;
    x[6][212] = 196;
    x[6][211] = 196;
    x[6][210] = 196;
    x[6][209] = 192;
    x[5][209] = 218;
    x[5][210] = 196;
    x[5][211] = 217;
    x[4][211] = 218;
    x[4][212] = 196;
    x[4][213] = 196;
    x[4][214] = 217;

    //more stars

    x[1][135] = '*';
    x[1][145] = '*';
    x[3][145] = '*';
    x[3][165] = '*';
    x[2][150] = '*';
    x[2][175] = '*';
    x[3][160] = '*';
    x[3][180] = '*';
    x[4][200] = '*';
    x[4][190] = '*';
    x[2][132] = '*';
    x[3][155] = '*';
    x[4][170] = '*';
    x[1][180] = '*';
    x[2][195] = '*';
    x[3][205] = '*';
    x[4][185] = '*';
    x[1][140] = '*';
    x[3][199] = '*';
    x[2][220] = '*';
    x[4][223] = '*';
    x[1][120] = '*';
    x[3][118] = '*';
    x[2][125] = '*';
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
    for (i = 0; i < lava.width; i++)
    {
        x[lava.r][lava.c + i] = 165; //≈
    }
}
void draw_platform(char x[][350], platfrm platform)
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
void draw_and_open_chest(char x[][350], cest& chest, user usr)
{
    //draw key
    if (usr.r > 5 && usr.r < 14 && usr.c > 334 && usr.c < 337)
    {
        chest.cur_frame = 1;
    }
    if (chest.cur_frame == 0)
    {
        x[12][339] = 201;
        x[12][340] = 205;
        x[12][341] = 201;
        x[12][342] = 205;
        x[12][343] = '+';
        x[13][344] = 192;
        x[13][345] = 217;
        x[12][346] = '+';
        x[13][343] = 92;
        x[13][346] = '/';
        x[11][344] = 218;
        x[11][345] = 191;
        x[11][343] = '/';
        x[11][346] = 92;
        x[12][344] = 179;
        x[12][345] = 179;
    }
    if (chest.cur_frame == 0) {
        x[chest.r][chest.c] = '+';
        x[chest.r][chest.c + 1] = 196;
        x[chest.r][chest.c + 2] = 196;
        x[chest.r][chest.c + 3] = 196;
        x[chest.r][chest.c + 4] = 194;
        x[chest.r][chest.c + 5] = 196;
        x[chest.r][chest.c + 6] = 196;
        x[chest.r][chest.c + 7] = 194;
        x[chest.r][chest.c + 8] = 196;
        x[chest.r][chest.c + 9] = 196;
        x[chest.r][chest.c + 10] = 196;
        x[chest.r][chest.c + 11] = '+';
        x[chest.r + 1][chest.c] = 179;
        x[chest.r + 1][chest.c + 1] = 95;
        x[chest.r + 1][chest.c + 2] = 95;
        x[chest.r + 1][chest.c + 3] = 95;
        x[chest.r + 1][chest.c + 4] = 179;
        x[chest.r + 1][chest.c + 5] = 91;
        x[chest.r + 1][chest.c + 6] = 93;
        x[chest.r + 1][chest.c + 7] = 179;
        x[chest.r + 1][chest.c + 8] = 95;
        x[chest.r + 1][chest.c + 9] = 95;
        x[chest.r + 1][chest.c + 10] = 95;
        x[chest.r + 1][chest.c + 11] = 179;
        x[chest.r + 2][chest.c] = 179;
        x[chest.r + 2][chest.c + 2] = 179;
        x[chest.r + 2][chest.c + 9] = 179;
        x[chest.r + 2][chest.c + 11] = 179;
        x[chest.r + 3][chest.c] = '+';
        x[chest.r + 3][chest.c + 1] = 196;
        x[chest.r + 3][chest.c + 2] = 196;
        x[chest.r + 3][chest.c + 3] = 196;
        x[chest.r + 3][chest.c + 4] = 196;
        x[chest.r + 3][chest.c + 5] = 196;
        x[chest.r + 3][chest.c + 6] = 196;
        x[chest.r + 3][chest.c + 7] = 196;
        x[chest.r + 3][chest.c + 8] = 196;
        x[chest.r + 3][chest.c + 9] = 196;
        x[chest.r + 3][chest.c + 10] = 196;
        x[chest.r + 3][chest.c + 11] = '+';
    }
    if (chest.cur_frame == 1) {
        x[chest.r - 2][chest.c + 2] = 196;
        x[chest.r - 2][chest.c + 3] = 196;
        x[chest.r - 2][chest.c + 4] = 196;
        x[chest.r - 2][chest.c + 5] = 194;
        x[chest.r - 2][chest.c + 6] = 194;
        x[chest.r - 2][chest.c + 7] = 196;
        x[chest.r - 2][chest.c + 8] = 196;
        x[chest.r - 2][chest.c + 9] = 196;
        x[chest.r - 1][chest.c + 1] = 47;
        x[chest.r - 1][chest.c + 5] = 192;
        x[chest.r - 1][chest.c + 6] = 217;
        x[chest.r - 1][chest.c + 10] = 92;
        x[chest.r][chest.c] = 47;
        x[chest.r][chest.c + 4] = 'W';
        x[chest.r][chest.c + 5] = 'I';
        x[chest.r][chest.c + 6] = 'N';
        x[chest.r][chest.c + 7] = '!';
        x[chest.r][chest.c + 11] = 92;
        x[chest.r + 1][chest.c] = 218;
        x[chest.r + 1][chest.c + 1] = 196;
        x[chest.r + 1][chest.c + 2] = 194;
        x[chest.r + 1][chest.c + 3] = 196;
        x[chest.r + 1][chest.c + 4] = 196;
        x[chest.r + 1][chest.c + 5] = 196;
        x[chest.r + 1][chest.c + 6] = 196;
        x[chest.r + 1][chest.c + 7] = 196;
        x[chest.r + 1][chest.c + 8] = 196;
        x[chest.r + 1][chest.c + 9] = 194;
        x[chest.r + 1][chest.c + 10] = 196;
        x[chest.r + 1][chest.c + 11] = 191;
        x[chest.r + 2][chest.c] = 179;
        x[chest.r + 2][chest.c + 2] = 179;
        x[chest.r + 2][chest.c + 9] = 179;
        x[chest.r + 2][chest.c + 11] = 179;
        x[chest.r + 3][chest.c] = '+';
        x[chest.r + 3][chest.c + 1] = 196;
        x[chest.r + 3][chest.c + 2] = 196;
        x[chest.r + 3][chest.c + 3] = 196;
        x[chest.r + 3][chest.c + 4] = 196;
        x[chest.r + 3][chest.c + 5] = 196;
        x[chest.r + 3][chest.c + 6] = 196;
        x[chest.r + 3][chest.c + 7] = 196;
        x[chest.r + 3][chest.c + 8] = 196;
        x[chest.r + 3][chest.c + 9] = 196;
        x[chest.r + 3][chest.c + 10] = 196;
        x[chest.r + 3][chest.c + 11] = '+';
    }
}
void draw_katio(char x[][350], katio& kat)
{
    if (kat.alive == 1) {
        if (kat.cd < 0) {
            kat.cur_frame = 0;
            if (kat.cur_frame == 0) {
                //draw sword
                x[kat.r - 1][kat.c - 7] = 196;
                x[kat.r - 1][kat.c - 6] = '#';
                x[kat.r - 1][kat.c - 5] = 240;
                x[kat.r - 1][kat.c - 4] = '+';
                x[kat.r - 1][kat.c - 3] = '=';
                x[kat.r - 1][kat.c - 2] = '=';
                x[kat.r - 1][kat.c - 1] = '=';
                x[kat.r - 1][kat.c] = '=';
                x[kat.r - 1][kat.c + 1] = '=';
                x[kat.r - 1][kat.c + 2] = '=';
                x[kat.r - 1][kat.c + 3] = '=';
                x[kat.r - 1][kat.c + 4] = '=';
                x[kat.r - 1][kat.c + 5] = 175;
                x[kat.r][kat.c - 5] = 92;
                x[kat.r][kat.c - 2] = 218;
                x[kat.r][kat.c - 1] = 196;
                x[kat.r][kat.c] = 194;
                x[kat.r][kat.c + 1] = 196;
                x[kat.r][kat.c + 2] = 191;
                x[kat.r + 1][kat.c - 4] = 92;
                x[kat.r + 1][kat.c - 2] = 179;
                x[kat.r + 1][kat.c - 1] = 95;
                x[kat.r + 1][kat.c] = 179;
                x[kat.r + 1][kat.c + 1] = 95;
                x[kat.r + 1][kat.c + 2] = 179;
                x[kat.r + 2][kat.c - 3] = 92;
                x[kat.r + 2][kat.c - 2] = 192;
                x[kat.r + 2][kat.c - 1] = 196;
                x[kat.r + 2][kat.c] = 197;
                x[kat.r + 2][kat.c + 1] = 196;
                x[kat.r + 2][kat.c + 2] = 217;
                x[kat.r + 3][kat.c] = 179;
                x[kat.r + 3][kat.c + 2] = 92;
                x[kat.r + 4][kat.c] = 127;
                x[kat.r + 4][kat.c + 3] = 92;
                x[kat.r + 5][kat.c - 1] = 179;
                x[kat.r + 5][kat.c + 1] = 179;
                x[kat.r + 5][kat.c + 4] = '#';
                if (kat.is_looking_right == 0) {
                    x[kat.r + 6][kat.c - 1] = 'a';
                    x[kat.r + 6][kat.c + 1] = '@';
                }
                else {
                    //draw looking right
                    x[kat.r + 6][kat.c - 1] = '@';
                    x[kat.r + 6][kat.c + 1] = 'a';
                }
            }
        }
        if (kat.cur_frame == 1) {
            //draw sword
            x[kat.r][kat.c - 2] = 218;
            x[kat.r][kat.c - 1] = 196;
            x[kat.r][kat.c] = 194;
            x[kat.r][kat.c + 1] = 196;
            x[kat.r][kat.c + 2] = 191;
            x[kat.r + 1][kat.c - 2] = 179;
            x[kat.r + 1][kat.c - 1] = 95;
            x[kat.r + 1][kat.c] = 179;
            x[kat.r + 1][kat.c + 1] = 95;
            x[kat.r + 1][kat.c + 2] = 179;
            x[kat.r + 2][kat.c - 2] = 192;
            x[kat.r + 2][kat.c - 1] = 196;
            x[kat.r + 2][kat.c] = 197;
            x[kat.r + 2][kat.c + 1] = 196;
            x[kat.r + 2][kat.c + 2] = 217;
            x[kat.r + 3][kat.c] = 179;
            x[kat.r + 3][kat.c + 2] = 92;
            x[kat.r + 3][kat.c - 2] = 47;

            x[kat.r + 4][kat.c] = 127;
            x[kat.r + 4][kat.c + 3] = 92;
            x[kat.r + 4][kat.c - 3] = 47;
            x[kat.r + 5][kat.c - 1] = 179;
            x[kat.r + 5][kat.c + 1] = 179;
            x[kat.r + 5][kat.c + 4] = '#';
            x[kat.r + 5][kat.c - 4] = '#';
            x[kat.r + 5][kat.c - 3] = 196;
            x[kat.r + 5][kat.c - 5] = 240;
            x[kat.r + 5][kat.c - 6] = '+';
            x[kat.r + 5][kat.c - 7] = '=';
            x[kat.r + 5][kat.c - 8] = '=';
            x[kat.r + 5][kat.c - 9] = '=';
            x[kat.r + 5][kat.c - 10] = '=';
            x[kat.r + 5][kat.c - 11] = '=';
            x[kat.r + 5][kat.c - 12] = '=';
            x[kat.r + 5][kat.c - 13] = '=';
            x[kat.r + 5][kat.c - 14] = '=';
            x[kat.r + 5][kat.c - 15] = 174;
            if (kat.is_looking_right == 0) {
                x[kat.r + 6][kat.c - 1] = 'a';
                x[kat.r + 6][kat.c + 1] = '@';
            }
            else {
                //draw looking right
                x[kat.r + 6][kat.c - 1] = '@';
                x[kat.r + 6][kat.c + 1] = 'a';
            }

        }
    }
}
void draw_mahmoud(char x[][350], mahmod mahmoud)
{
    x[mahmoud.r][mahmoud.c - 1] = '/';
    x[mahmoud.r][mahmoud.c + 1] = 92;
    x[mahmoud.r - 1][mahmoud.c] = 196;
    x[mahmoud.r + 1][mahmoud.c - 3] = 192;
    x[mahmoud.r + 1][mahmoud.c - 2] = '+';
    x[mahmoud.r + 1][mahmoud.c - 1] = 196;
    x[mahmoud.r + 1][mahmoud.c] = 196;
    x[mahmoud.r + 1][mahmoud.c + 1] = 196;
    x[mahmoud.r + 1][mahmoud.c + 2] = '+';
    x[mahmoud.r + 1][mahmoud.c + 3] = 217;
    x[mahmoud.r + 2][mahmoud.c - 2] = 179;
    x[mahmoud.r + 2][mahmoud.c - 1] = '@';
    x[mahmoud.r + 2][mahmoud.c + 1] = '+';
    x[mahmoud.r + 2][mahmoud.c + 2] = 179;
    x[mahmoud.r + 3][mahmoud.c - 2] = 192;
    x[mahmoud.r + 3][mahmoud.c - 1] = 194;
    x[mahmoud.r + 3][mahmoud.c] = 196;
    x[mahmoud.r + 3][mahmoud.c + 1] = 194;
    x[mahmoud.r + 3][mahmoud.c + 2] = 217;
    x[mahmoud.r + 4][mahmoud.c - 2] = '+';
    x[mahmoud.r + 4][mahmoud.c - 3] = '+';
    x[mahmoud.r + 4][mahmoud.c - 4] = 'q';
    x[mahmoud.r + 4][mahmoud.c - 5] = '=';
    x[mahmoud.r + 4][mahmoud.c - 6] = 174;
    x[mahmoud.r + 4][mahmoud.c - 1] = 179;
    x[mahmoud.r + 4][mahmoud.c] = 'M';//31
    x[mahmoud.r + 4][mahmoud.c + 1] = 179;
    x[mahmoud.r + 4][mahmoud.c + 2] = '+';
    x[mahmoud.r + 5][mahmoud.c - 1] = 195;
    x[mahmoud.r + 5][mahmoud.c] = 196;
    x[mahmoud.r + 5][mahmoud.c + 1] = 180;
    x[mahmoud.r + 6][mahmoud.c - 1] = 179;
    x[mahmoud.r + 6][mahmoud.c + 1] = 179;
    x[mahmoud.r + 7][mahmoud.c - 1] = 188;
    x[mahmoud.r + 7][mahmoud.c + 1] = 188;//179,179

}
void move_katio(katio& kat, user usr)
{
    if (kat.alive == 1 && kat.cd < 0) {
        //minus 9 to make range bigger but without him moving out of range
        if (usr.r == kat.r + 1 && usr.c > kat.c_min - 9 && usr.c < kat.c_max) {
            if (usr.c > kat.c_min - 9 && usr.c < kat.c_max) {
                if (usr.c > kat.c) {
                    kat.c++;
                }
                else {
                    kat.c--;
                }
            }
        }
        else {
            if (kat.c == kat.c_max) {
                kat.is_looking_right = 0;
            }
            if (kat.c == kat.c_min) {
                kat.is_looking_right = 1;
            }
            if (kat.is_looking_right == 1) {
                kat.c++;
            }
            if (kat.is_looking_right == 0) {
                kat.c--;
            }
        }
    }
}
void draw_ufo(char x[][350], ofu& ufo)
{
    if (ufo.cur_frame == 0)
    {
        x[ufo.r][ufo.c + 5] = 218;
        x[ufo.r][ufo.c + 6] = 196;
        x[ufo.r][ufo.c + 7] = 196;
        x[ufo.r][ufo.c + 8] = 196;
        x[ufo.r][ufo.c + 9] = 196;
        x[ufo.r][ufo.c + 10] = 196;
        x[ufo.r][ufo.c + 11] = 191;
        x[ufo.r + 1][ufo.c + 1] = 218;
        x[ufo.r + 1][ufo.c + 2] = 196;
        x[ufo.r + 1][ufo.c + 3] = 196;
        x[ufo.r + 1][ufo.c + 4] = 196;
        x[ufo.r + 1][ufo.c + 5] = 193;
        x[ufo.r + 1][ufo.c + 6] = 196;
        x[ufo.r + 1][ufo.c + 7] = 196;
        x[ufo.r + 1][ufo.c + 8] = 196;
        x[ufo.r + 1][ufo.c + 9] = 196;
        x[ufo.r + 1][ufo.c + 10] = 196;
        x[ufo.r + 1][ufo.c + 11] = 193;
        x[ufo.r + 1][ufo.c + 12] = 196;
        x[ufo.r + 1][ufo.c + 13] = 196;
        x[ufo.r + 1][ufo.c + 14] = 196;
        x[ufo.r + 1][ufo.c + 15] = 191;
        x[ufo.r + 2][ufo.c] = 218;
        x[ufo.r + 2][ufo.c + 1] = 180;
        x[ufo.r + 2][ufo.c + 5] = 'U';
        x[ufo.r + 2][ufo.c + 6] = 'F';
        x[ufo.r + 2][ufo.c + 7] = 'O';
        x[ufo.r + 2][ufo.c + 8] = '+';
        x[ufo.r + 2][ufo.c + 9] = '3';
        x[ufo.r + 2][ufo.c + 10] = '0';
        x[ufo.r + 2][ufo.c + 11] = '0';
        x[ufo.r + 2][ufo.c + 15] = 195;
        x[ufo.r + 2][ufo.c + 16] = 191;
        x[ufo.r + 3][ufo.c] = 192;
        x[ufo.r + 3][ufo.c + 1] = 193;
        x[ufo.r + 3][ufo.c + 2] = 196;
        x[ufo.r + 3][ufo.c + 3] = 194;
        x[ufo.r + 3][ufo.c + 4] = 196;
        x[ufo.r + 3][ufo.c + 5] = 196;
        x[ufo.r + 3][ufo.c + 6] = 196;
        x[ufo.r + 3][ufo.c + 7] = 196;
        x[ufo.r + 3][ufo.c + 8] = 194;
        x[ufo.r + 3][ufo.c + 9] = 196;
        x[ufo.r + 3][ufo.c + 10] = 196;
        x[ufo.r + 3][ufo.c + 11] = 196;
        x[ufo.r + 3][ufo.c + 12] = 196;
        x[ufo.r + 3][ufo.c + 13] = 194;
        x[ufo.r + 3][ufo.c + 14] = 196;
        x[ufo.r + 3][ufo.c + 15] = 193;
        x[ufo.r + 3][ufo.c + 16] = 217;
        x[ufo.r + 4][ufo.c + 3] = 179;
        x[ufo.r + 4][ufo.c + 8] = 179;
        x[ufo.r + 4][ufo.c + 13] = 179;
        x[ufo.r + 5][ufo.c + 3] = '@';
        x[ufo.r + 5][ufo.c + 8] = '@';
        x[ufo.r + 5][ufo.c + 13] = '@';
    }
    if (ufo.cur_frame == 1)
    {
        x[ufo.r][ufo.c + 5] = 218;
        x[ufo.r][ufo.c + 6] = 196;
        x[ufo.r][ufo.c + 7] = 196;
        x[ufo.r][ufo.c + 8] = 196;
        x[ufo.r][ufo.c + 9] = 196;
        x[ufo.r][ufo.c + 10] = 196;
        x[ufo.r][ufo.c + 11] = 191;
        x[ufo.r + 1][ufo.c + 1] = 218;
        x[ufo.r + 1][ufo.c + 2] = 196;
        x[ufo.r + 1][ufo.c + 3] = 196;
        x[ufo.r + 1][ufo.c + 4] = 196;
        x[ufo.r + 1][ufo.c + 5] = 193;
        x[ufo.r + 1][ufo.c + 6] = 196;
        x[ufo.r + 1][ufo.c + 7] = 196;
        x[ufo.r + 1][ufo.c + 8] = 196;
        x[ufo.r + 1][ufo.c + 9] = 196;
        x[ufo.r + 1][ufo.c + 10] = 196;
        x[ufo.r + 1][ufo.c + 11] = 193;
        x[ufo.r + 1][ufo.c + 12] = 196;
        x[ufo.r + 1][ufo.c + 13] = 196;
        x[ufo.r + 1][ufo.c + 14] = 196;
        x[ufo.r + 1][ufo.c + 15] = 191;
        x[ufo.r + 2][ufo.c] = 218;
        x[ufo.r + 2][ufo.c + 1] = 180;
        x[ufo.r + 2][ufo.c + 5] = 'U';
        x[ufo.r + 2][ufo.c + 6] = 'F';
        x[ufo.r + 2][ufo.c + 7] = 'O';
        x[ufo.r + 2][ufo.c + 8] = '+';
        x[ufo.r + 2][ufo.c + 9] = '3';
        x[ufo.r + 2][ufo.c + 10] = '0';
        x[ufo.r + 2][ufo.c + 11] = '0';
        x[ufo.r + 2][ufo.c + 15] = 195;
        x[ufo.r + 2][ufo.c + 16] = 191;
        x[ufo.r + 3][ufo.c] = 192;
        x[ufo.r + 3][ufo.c + 1] = 193;
        x[ufo.r + 3][ufo.c + 2] = 196;
        x[ufo.r + 3][ufo.c + 3] = 194;
        x[ufo.r + 3][ufo.c + 4] = 196;
        x[ufo.r + 3][ufo.c + 5] = 196;
        x[ufo.r + 3][ufo.c + 6] = 196;
        x[ufo.r + 3][ufo.c + 7] = 196;
        x[ufo.r + 3][ufo.c + 8] = 194;
        x[ufo.r + 3][ufo.c + 9] = 196;
        x[ufo.r + 3][ufo.c + 10] = 196;
        x[ufo.r + 3][ufo.c + 11] = 196;
        x[ufo.r + 3][ufo.c + 12] = 196;
        x[ufo.r + 3][ufo.c + 13] = 194;
        x[ufo.r + 3][ufo.c + 14] = 196;
        x[ufo.r + 3][ufo.c + 15] = 193;
        x[ufo.r + 3][ufo.c + 16] = 217;
        x[ufo.r + 4][ufo.c + 3] = 179;
        x[ufo.r + 4][ufo.c + 8] = 179;
        x[ufo.r + 4][ufo.c + 13] = 179;
        x[ufo.r + 5][ufo.c + 3] = '@';
        x[ufo.r + 5][ufo.c + 8] = '@';
        x[ufo.r + 5][ufo.c + 13] = '@';
        for (int i = 6; i < 30; i++)
        {
            x[ufo.r + i][ufo.c + 8] = 179;
        }
    }
    if (ufo.cur_frame == 2)
    {
        x[ufo.r][ufo.c + 5] = 218;
        x[ufo.r][ufo.c + 6] = 196;
        x[ufo.r][ufo.c + 7] = 196;
        x[ufo.r][ufo.c + 8] = 196;
        x[ufo.r][ufo.c + 9] = 196;
        x[ufo.r][ufo.c + 10] = 196;
        x[ufo.r][ufo.c + 11] = 191;
        x[ufo.r + 1][ufo.c + 1] = 218;
        x[ufo.r + 1][ufo.c + 2] = 196;
        x[ufo.r + 1][ufo.c + 3] = 196;
        x[ufo.r + 1][ufo.c + 4] = 196;
        x[ufo.r + 1][ufo.c + 5] = 193;
        x[ufo.r + 1][ufo.c + 6] = 196;
        x[ufo.r + 1][ufo.c + 7] = 196;
        x[ufo.r + 1][ufo.c + 8] = 196;
        x[ufo.r + 1][ufo.c + 9] = 196;
        x[ufo.r + 1][ufo.c + 10] = 196;
        x[ufo.r + 1][ufo.c + 11] = 193;
        x[ufo.r + 1][ufo.c + 12] = 196;
        x[ufo.r + 1][ufo.c + 13] = 196;
        x[ufo.r + 1][ufo.c + 14] = 196;
        x[ufo.r + 1][ufo.c + 15] = 191;
        x[ufo.r + 2][ufo.c] = 218;
        x[ufo.r + 2][ufo.c + 1] = 180;
        x[ufo.r + 2][ufo.c + 5] = 'U';
        x[ufo.r + 2][ufo.c + 6] = 'F';
        x[ufo.r + 2][ufo.c + 7] = 'O';
        x[ufo.r + 2][ufo.c + 8] = '+';
        x[ufo.r + 2][ufo.c + 9] = '3';
        x[ufo.r + 2][ufo.c + 10] = '0';
        x[ufo.r + 2][ufo.c + 11] = '0';
        x[ufo.r + 2][ufo.c + 15] = 195;
        x[ufo.r + 2][ufo.c + 16] = 191;
        x[ufo.r + 3][ufo.c] = 192;
        x[ufo.r + 3][ufo.c + 1] = 193;
        x[ufo.r + 3][ufo.c + 2] = 196;
        x[ufo.r + 3][ufo.c + 3] = 194;
        x[ufo.r + 3][ufo.c + 4] = 196;
        x[ufo.r + 3][ufo.c + 5] = 196;
        x[ufo.r + 3][ufo.c + 6] = 196;
        x[ufo.r + 3][ufo.c + 7] = 196;
        x[ufo.r + 3][ufo.c + 8] = 194;
        x[ufo.r + 3][ufo.c + 9] = 196;
        x[ufo.r + 3][ufo.c + 10] = 196;
        x[ufo.r + 3][ufo.c + 11] = 196;
        x[ufo.r + 3][ufo.c + 12] = 196;
        x[ufo.r + 3][ufo.c + 13] = 194;
        x[ufo.r + 3][ufo.c + 14] = 196;
        x[ufo.r + 3][ufo.c + 15] = 193;
        x[ufo.r + 3][ufo.c + 16] = 217;
        x[ufo.r + 4][ufo.c + 3] = 179;
        x[ufo.r + 4][ufo.c + 8] = 179;
        x[ufo.r + 4][ufo.c + 13] = 179;
        x[ufo.r + 5][ufo.c + 3] = '@';
        x[ufo.r + 5][ufo.c + 8] = '@';
        x[ufo.r + 5][ufo.c + 13] = '@';
        for (int i = 6; i < 30; i++)
        {
            x[ufo.r + i][ufo.c + 5] = 179;
            x[ufo.r + i][ufo.c + 6] = 177;
            x[ufo.r + i][ufo.c + 7] = 177;
            x[ufo.r + i][ufo.c + 8] = 178;
            x[ufo.r + i][ufo.c + 9] = 177;
            x[ufo.r + i][ufo.c + 10] = 176;
            x[ufo.r + i][ufo.c + 11] = 179;
        }
    }

}
void ufo_fire(char x[][350], ofu& ufo)
{
    if (ufo.cd > 28)
    {
        ufo.cur_frame = 0;
    }
    if (ufo.cd < 28 && ufo.cd > 10)
    {
        ufo.cur_frame = 1;
    }
    if (ufo.cd < 13)
    {
        ufo.cur_frame = 2;
    }
    if (ufo.cd < 0)
    {
        ufo.cd = ufo.cd_reset;
    }

}
void draw_bullets(char x[][350], bullts bullet)
{
    //loop over number of bullets
    while (bullet.ct)
    {
        //draw bullet in the x & y contained in bullets_pos array
        x[(bullet.pos[bullet.ct][0])][(bullet.pos[bullet.ct][1] - 1)] = '-';
        x[(bullet.pos[bullet.ct][0])][(bullet.pos[bullet.ct][1])] = '>';
        //if infront of bullet is space

        //go to previous bullet
        bullet.ct--;
    }
}
void move_bullets(char x[][350], bullts& bullet, katio& kat, matrix mat)
{
    //reload bullet algoritihim
    // write code here
    //infinite bullets
    // make dummy count
    int ct_bullet_tmp = bullet.ct;
    //loop over number of bullets
    while (ct_bullet_tmp)
    {
        //if infront of bullet is space
            //move bullet position to the next col
        bullet.pos[ct_bullet_tmp][1]++;
        for (int i = kat.c - 2; i < kat.c + 2; i++)
        {
            if ((bullet.pos[ct_bullet_tmp][1]) == i && ((bullet.pos[ct_bullet_tmp][0] + 1) == kat.r + 4))
            {
                kat.hp--;
                if (kat.hp <= 0)
                {
                    kat.alive = 0;
                    kat.r = 20;
                }
                for (int i = ct_bullet_tmp; i < bullet.ct; i++)
                {
                    //shift row
                    bullet.pos[i][0] = bullet.pos[i + 1][0];
                    //shift col
                    bullet.pos[i][1] = bullet.pos[i + 1][1];
                }
                bullet.ct--;
            }
        }
        if ((bullet.pos[ct_bullet_tmp][1]) > mat.c)
        {
            for (int i = ct_bullet_tmp; i < bullet.ct; i++)
            {
                //shift row
                bullet.pos[i][0] = bullet.pos[i + 1][0];
                //shift col
                bullet.pos[i][1] = bullet.pos[i + 1][1];
            }
            bullet.ct--;
        }
        //shift backwards

        //minus actual count of bullet

        /*
        //shift backwards
        for (int i = ct_bullet_tmp; i < ct_bullet; i++)
        {
            bullets_pos[i][1] = bullets_pos[i + 1][1];
        }
        ct_bullet--;
        */

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
void move_elevator(char x[][350], user& usr, platfrm& platform)
{
    if (platform.is_platform_on_floor == 0)
    {
        //when cd is less than 1
        if (platform.cd < 1)
        {
            //doc howa gowa el asansir nfso momken n5li g3fr yt7rk wla la2
            //checks if user's position is on the platform
            platform.is_moving = 1;
            if (platform.is_hero_on_platform == 1)
            {
                usr.r--;
            }
            platform.r--;
            if (platform.r == platform.r_const - platform.top)
            {
                platform.is_moving = 0;
                //flag platform to be not on floor
                platform.is_platform_on_floor = 1;
                //set a cd to make platform stay in place
                platform.cd = platform.cd_reset;
            }
        }
    }
    //when platform not on ground
    if (platform.is_platform_on_floor == 1)
    {
        //when cd is less than
        if (platform.cd < 1)
        {
            //start moving platform to the floor
            platform.is_moving = 1;
            platform.r++;
            //when platform is at floor
            if (platform.r_const == platform.r)
            {
                platform.is_moving = 0;
                //reset flag
                platform.is_platform_on_floor = 0;
                //reset cooldown
                platform.cd = platform.cd_reset;
            }
        }
    }
}
void check_next_level_and_scroll(char x[][350], matrix& mat, user& usr)
{
    if (mat.level == 0)
    {
        mat.do_scroll = 0;
    }
    if (mat.do_scroll == 0)
    {
        if (usr.c == 115)
        {
            //tp usr to next scene and allow scrolling
            mat.c += 115;
            usr.r = 23;
            usr.c = 116;
            mat.level = 1;
        }
    }
    if (mat.level == 1)
    {
        mat.do_scroll = 1;
    }
    if (mat.do_scroll == 1)
    {
        if (usr.c > (mat.c - mat.forward_boundary) && mat.c < 350)
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
            mat.level = 0;
        }
    }
}
void object_detection(user& usr, platfrm& platform, ldder ladder, hill hills[], int ct_hills)
{
    int is_left_on_platform = 0, is_right_on_platform = 0, can_right = 1, can_left = 1, can_ladder_up = 0, can_ladder_down = 0, can_fall = 1, can_fly = 1;
    platform.is_hero_on_platform = 0;
    /*for (int i = usr.r; i < usr.r + 6; i++)
    {
        for (int j = usr.c - 2; j < usr.c + 3; j++)
        {
            if ()
            {
                return 1;
            }
        }
    }*/
    //check platforms
    for (int i = platform.c - 1; i < platform.width + platform.c + 1; i++)
    {
        if (usr.c - 2 == i)
        {
            is_left_on_platform = 1;
        }
        if (usr.c + 2 == i)
        {
            is_right_on_platform = 1;
        }
        if (usr.r + 6 == platform.r && is_left_on_platform == 1 && is_right_on_platform == 1)
        {
            //sets hero to standing on a platform
            platform.is_hero_on_platform = 1;
            can_fall = 0;
        }
    }
    if (platform.is_moving == 1 && platform.is_hero_on_platform == 1 && (usr.c - 4) == platform.c)
    {
        can_left = 0;
        can_fall = 0;
    }
    if (platform.is_moving == 1 && platform.is_hero_on_platform == 1 && (usr.c + 4) == (platform.c + platform.width))
    {
        can_right = 0;
        can_fall = 0;
    }
    //checking hills
    while (ct_hills)
    {
        //draw verticals
        if (hills[ct_hills].is_left_wall == 1 || hills[ct_hills].is_right_wall == 1)
        {
            for (int i = hills[ct_hills].start_r; i < hills[ct_hills].end_r; i++)
            {
                if (hills[ct_hills].is_left_wall == 1)
                {
                    if (((i == usr.r) || (i == usr.r + 5)) && (hills[ct_hills].start_c == (usr.c + 3)))
                    {
                        can_right = 0;
                        //redundant
                    }
                    if (((i == usr.r) || (i == usr.r + 5)) && (hills[ct_hills].start_c == (usr.c - 3)))
                    {
                        can_left = 0;
                        //redundant
                    }
                }
                if (hills[ct_hills].is_right_wall == 1)
                {
                    if (((i == usr.r) || (i == usr.r + 5)) && (hills[ct_hills].end_c == (usr.c + 3)))
                    {
                        can_right = 0;
                        //redundant
                    }
                    if (((i == usr.r) || (i == usr.r + 5)) && (hills[ct_hills].end_c == (usr.c - 3)))
                    {
                        can_left = 0;
                        //redundant
                    }
                }
            }
        }
        //can be used to check corners
        /*if (hills[ct_hills].is_left_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            if ((hills[ct_hills].start_r == usr.r) && (hills[ct_hills].end_c == (usr.c + 3)))
            {
                can_right = 0;
                //redundant
                animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest,ufo);
                map(x, mat);
            }
        }
        if (hills[ct_hills].is_right_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].end_c];
        }*/
        //draw horizontal( - and + to remove corners
        if (hills[ct_hills].is_horizontal_wall = 1)
        {
            for (int i = (hills[ct_hills].start_c + 1); i < (hills[ct_hills].end_c); i++)
            {
                if (hills[ct_hills].start_r == (usr.r + 6) && (i == (usr.c - 2) || (i == (usr.c + 2))))
                {
                    can_fall = 0;
                    //redundant
                }
                if (hills[ct_hills].start_r == (usr.r - 1) && (i == (usr.c - 2) || (i == (usr.c + 2))))
                {
                    can_fly = 0;
                    //redundant
                }
            }
        }
        ct_hills--;
    }
    //check floor
    if (usr.r == 23)
    {
        can_fall = 0;
    }
    //check ladder
    for (int i = 0; i < ladder.length; i++)
    {
        //idk checks if you stand on ladder somehow
        if ((usr.r + 5) == (ladder.r + i))
        {
            for (int j = 0; j < ladder.width; j++)
            {
                if (usr.c == (ladder.c + j))
                {
                    can_ladder_up = 1;
                    can_fly = 0;
                }
            }
        }
        if ((usr.r + 6) == (ladder.r + i))
        {
            for (int j = 0; j < ladder.width; j++)
            {
                if (usr.c == (ladder.c + j))
                {
                    can_ladder_down = 1;
                    can_fall = 0;
                }
            }
        }
    }
    if (can_right == 0)
    {
        usr.can_right = 0;
    }
    else
    {
        usr.can_right = 1;
    }
    if (can_left == 0)
    {
        usr.can_left = 0;
    }
    else
    {
        usr.can_left = 1;
    }
    if (can_ladder_up == 1)
    {
        usr.can_ladder_up = 1;
    }
    else
    {
        usr.can_ladder_up = 0;
    }
    if (can_ladder_down == 1)
    {
        usr.can_ladder_down = 1;
    }
    else
    {
        usr.can_ladder_down = 0;
    }
    if (can_fly == 1)
    {
        usr.can_fly = 1;
    }
    else
    {
        usr.can_fly = 0;
    }
    if (can_fall == 0)
    {
        usr.can_fall = 0;
    }
    else
    {
        usr.can_fall = 1;
    }
}
void bullet_detection(bullts& bullet, katio& kat)
{
    //reload bullet algoritihim
    // write code here
    //infinite bullets
    // make dummy count
    int ct_bullet_tmp = bullet.ct;
    //loop over number of bullets
    while (ct_bullet_tmp)
    {
        for (int i = kat.c - 10; i < kat.c + 10; i++)
        {
            for (int j = kat.r; j < kat.r + 5; j++)
                if (((bullet.pos[ct_bullet_tmp][0]) == j && (bullet.pos[ct_bullet_tmp][1] + 1)) == i)
                {
                    kat.r = -10;
                    //shift backwards
                    for (int i = ct_bullet_tmp; i < bullet.ct; i++)
                    {
                        //shift row
                        bullet.pos[i][0] = bullet.pos[i + 1][0];
                        //shift col
                        bullet.pos[i][1] = bullet.pos[i + 1][1];
                    }
                    //minus actual count of bullet
                    bullet.ct--;
                }
        }
        //move to the previous bullet
        ct_bullet_tmp--;
    }
}
void cd(user& usr, bullts& bullet, platfrm& platform, katio& kat, ofu& ufo)
{
    usr.jump_cd--;
    bullet.cd--;
    platform.cd--;
    kat.cd--;
    ufo.cd--;
}
void check_death(user& usr, lva lava, katio& kat, ofu ufo)
{
    //checking lava
    for (int i = lava.c; i < (lava.c + lava.width); i++)
    {
        if (lava.r == (usr.r + 6) && i == usr.c)
        {
            usr.die = 1;
        }
    }
    for (int i = kat.c - 10; i < kat.c + 10; i++)
    {
        if (usr.c == i && usr.r == kat.r + 1)
        {
            kat.cur_frame = 1;
            kat.cd = kat.cd_reset;
            usr.die = 1;
        }
    }
    if (ufo.cur_frame == 2 && usr.c > ufo.c && usr.c < ufo.c + 15)
    {
        usr.die = 1;
    }
    //
}
void animation(char x[][350], matrix& mat, user& usr, platfrm& platform, bullts& bullet, ldder ladder, hill hills[], int ct_hills, lva lava, katio& kat, cest& chest, ofu& ufo, mahmod mahmoud)
{
    //clear the matrix
    clear(x);
    check_next_level_and_scroll(x, mat, usr);
    //draw fixed background [current: roof, floor]
    draw_fixed(x, mat, ladder, hills, ct_hills, lava);
    //draw combo1 [platform,enemy1,hero]
    //draw platform
    draw_platform(x, platform);
    draw_and_open_chest(x, chest, usr);
    draw_ufo(x, ufo);
    ufo_fire(x, ufo);
    //draw katio
    draw_katio(x, kat);
    draw_mahmoud(x, mahmoud);
    move_katio(kat, usr);
    //move then draw bullet
    move_bullets(x, bullet, kat, mat);
    draw_bullets(x, bullet);
    //draw hero
    draw_hero(x, usr);
    move_elevator(x, usr, platform);
    object_detection(usr, platform, ladder, hills, ct_hills);
    cd(usr, bullet, platform, kat, ufo);
    check_death(usr, lava, kat, ufo);
}
//must copy animation refrences[contains animation]
void die(char x[][350], matrix& mat, user& usr, platfrm& platform, bullts& bullet, ldder ladder, hill hills[], int ct_hills, lva lava, katio& kat, cest& chest, ofu& ufo, mahmod mahmoud)
{
    if (mat.level == 0)
    {
        usr.r = 23;
        usr.c = 20;
        mat.c = 115;
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        map(x, mat);
    }
    if (mat.level == 1)
    {
        usr.r = 23;
        usr.c = 118;
        mat.c = 230;
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        map(x, mat);
    }
    usr.die = 0;
}
//gravity,trampoline(no more trampoline :< )
/*int object_detection_alg(char x[][350], user usr, hill hills[], int ct_hills)
{

    for (int i = usr.r; i < usr.r + 6; i++)
    {
        for (int j = usr.c - 2; j < usr.c + 3; j++)
        {

            if (1)
            {
                return 1;
            }
        }
    }
    while (ct_hills)
    {
        //draw verticals
        if (hills[ct_hills].is_left_wall == 1 || hills[ct_hills].is_right_wall == 1)
        {
            for (int i = hills[ct_hills].start_r; i < hills[ct_hills].end_r; i++)
            {
                if (hills[ct_hills].is_left_wall == 1)
                {
                    x[i][hills[ct_hills].start_c];
                }
                if (hills[ct_hills].is_right_wall == 1)
                {
                    x[i][hills[ct_hills].end_c];
                }

            }
        }
        //draw corners
        if (hills[ct_hills].is_left_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].start_c];
        }
        if (hills[ct_hills].is_right_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].end_c];
        }
        //draw horizontal( - and + to remove corners
        if (hills[ct_hills].is_horizontal_wall = 1)
        {
            for (int i = (hills[ct_hills].start_c + 1); i < (hills[ct_hills].end_c); i++)
            {
                x[hills[ct_hills].start_r][i];
            }
        }
        ct_hills--;
    }

}
int object_detection_hero(char x[][350], char dir, user& usr, hill hills[], int ct_hills)
{
    int usr_r_bound, usr_c_bound;
    if (dir == 'w')
    {
        usr_c_bound = usr.c;
        usr_r_bound = usr.r - usr.speed;
    }
    if (dir == 'w')
    {
        usr_c_bound = usr.c;
        usr_r_bound = usr.r - usr.speed;
    }
    if (dir == 'a')
    {
        usr_c_bound = usr.c - usr.speed;
        usr_r_bound = usr.r;
    }
    if (dir == 'd')
    {
        usr_c_bound = usr.c + usr.speed;
        usr_r_bound = usr.r;
    }
    /*for (int i = usr.r; i < usr.r + 6; i++)
    {
        for (int j = usr.c - 2; j < usr.c + 3; j++)
        {
            if ()
            {
                return 1;
            }
        }
    }
    //checking hills
    while (ct_hills)
    {
        //draw verticals
        if (dir == 'd' || dir == 'a')
        {
            if (hills[ct_hills].is_left_wall == 1 || hills[ct_hills].is_right_wall == 1)
            {
                for (int i = hills[ct_hills].start_r; i < hills[ct_hills].end_r; i++)
                {
                    if (hills[ct_hills].is_left_wall == 1)
                    {
                        if ((i == usr_r_bound) && (hills[ct_hills].start_c == (usr_c_bound + 2)))
                        {
                            return 0;
                        }
                    }
                    if (hills[ct_hills].is_right_wall == 1)
                    {
                        if ((i == usr_r_bound) && hills[ct_hills].end_c == (usr_c_bound))
                        {
                            return 0;
                        }
                    }
                }
            }
        }
        //draw corners
        if (hills[ct_hills].is_left_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].start_c];
        }
        if (hills[ct_hills].is_right_wall == 1 && hills[ct_hills].is_horizontal_wall == 1)
        {
            x[hills[ct_hills].start_r][hills[ct_hills].end_c];
        }
        //draw horizontal( - and + to remove corners
        if (dir == 'w')
        {
            if (hills[ct_hills].is_horizontal_wall = 1)
            {
                for (int i = (hills[ct_hills].start_c + 1); i < (hills[ct_hills].end_c); i++)
                {
                    if (hills[ct_hills].start_r == usr_r_bound && i == usr_c_bound)
                    {
                        return 0;
                    }
                }
            }
        }
        ct_hills--;
    }
    return 1;
}*/
//must copy animation refrences[contains animation]
void gravity_and_jump(char x[][350], matrix& mat, user& usr, platfrm& platform, bullts& bullet, ldder ladder, hill hills[], int ct_hills, lva lava, katio& kat, cest& chest, ofu& ufo,mahmod mahmoud)
{
    // bynzl kam cell;
    // Check lw fy hga ta7tyh
    if (usr.is_jumping == 0)
    {
        if (usr.can_fall == 1)
        {
            usr.is_falling = 1;
            usr.r += usr.gravity_speed;
        }
        else
        {
            usr.is_falling = 0;
        }
        //m3rfsh kont m7tagha leh
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
    }
    if (usr.is_jumping == -1)
    {
        for (int i = 0; i < usr.jump_height && usr.is_jumping == -1 && usr.can_fly == 1; i++)
        {
            usr.r--;
            //m7tagha 3shan el nta tzhr
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
        }
        usr.is_jumping = 0;
        usr.jump_cd = usr.jump_cd_reset;

    }
    if (usr.is_jumping == -2)
    {
        for (int i = 0; i < usr.jump_height && usr.is_jumping == -2 && usr.can_right == 1 && usr.can_fly == 1; i++)
        {
            usr.r--;
            usr.c++;
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
        }
        for (int i = 0; i < usr.jump_height && usr.is_jumping == -2 && usr.can_right == 1 && usr.can_fall == 1; i++)
        {
            usr.r++;
            usr.c++;
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
        }
        usr.is_jumping = 0;
        usr.jump_cd = usr.jump_cd_reset;
    }
    if (usr.is_jumping == -3)
    {
        for (int i = 0; i < usr.jump_height && usr.is_jumping == -3 && usr.can_left == 1 && usr.can_fly == 1; i++)
        {
            usr.r--;
            usr.c--;
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
        }
        for (int i = 0; i < usr.jump_height && usr.is_jumping == -3 && usr.can_left == 1 && usr.can_fall == 1; i++)
        {
            usr.r++;
            usr.c--;
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
        }
        usr.is_jumping = 0;
        usr.jump_cd = usr.jump_cd_reset;
    }
    //******** Trampoline??
}
//checks if hero is standing on the elevator
//must copy animation refrences[contains animation]
void user_action(char x[][350], char dir, user& usr, matrix& mat, platfrm& platform, bullts& bullet, ldder ladder, hill hills[], int ct_hills, lva lava, katio& kat, cest& chest, ofu& ufo,mahmod mahmoud)
{
    if (dir == 'w' && usr.can_ladder_up == 1/* && object_detection_hero(x, dir, usr, hills, ct_hills)*/)
    {
        usr.r -= usr.speed;
        //3shan lw taneitk days myzhrsh
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
    }

    //move down if user pressed s while on a ladder
    if (dir == 's' && usr.can_ladder_down == 1 && usr.r + 5 < 45)
    {
        usr.r += usr.speed;
        //3shan lw taneitk days myzhrsh
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
    }
    //move left if user pressed a
    if (dir == 'a' && usr.can_left == 1/*&& object_detection_hero(x, dir, usr, hills, ct_hills) */)
    {
        if (usr.is_facing_right == 1)
        {
            usr.cur_frame = 3;
        }
        //smoother transition
       // animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest,ufo);
       // map(x,mat);
        usr.c -= usr.speed;
        //3shan lw taneitk days myzhrsh
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);



        usr.is_facing_right = 0;
    }
    //move right if user pressed d check char as a bound
    if (dir == 'd' && usr.can_right == 1/* && object_detection_hero(x, dir, usr, hills, ct_hills) */)
    {
        if (usr.is_facing_right == 0)
        {
            usr.cur_frame = 7;
        }
        //smoother transition
        //animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest,ufo);
        //map(x,mat);
        usr.c += usr.speed;
        //3shan lw taneitk days myzhrsh
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        usr.is_facing_right = 1;
    }
    //gets the gun's row {subject to change}
    int gun_r = usr.r + 2;
    //gets the gun's col {subject to change}
    int gun_c = usr.c + 4;
    //shoot an arrow if user pressed e
    if (dir == 'e')
    {
        if (bullet.cd < 1)
        {
            bullet.ct++;
            bullet.pos[bullet.ct][0] = gun_r;
            bullet.pos[bullet.ct][1] = gun_c + 1;
            bullet.cd = bullet.cd_reset;
        }
    }
    //shoot grapple hook
    if (dir == 'f' && usr.is_facing_right == 1)
    {
        int i;
        //loop from gun col to obstacle (not space) or 5
        for (i = 1; x[gun_r][gun_c + i] == ' ' && i < 10; i++)
        {
            //make things move while inside loop
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
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
            for (int k = kat.c - 2; k < kat.c + 2; k++)
            {
                if ((gun_r == k && gun_c == kat.r + 4))
                {
                    kat.hp -= 3;
                    //if you catched enemy
                    //(sudden >:) animation)
                    //move&display hero to infront of enemy
                    usr.c += i - 1;
                    animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
                    map(x, mat);
                    //draw hero behind enemy*needs to be changed to dynamic*
                    usr.c += 11;
                    //redraw map
                    animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
                    //draw hit animation
                    x[gun_r - 2][usr.c - 8] = 92;
                    x[gun_r - 1][usr.c - 7] = 92;
                    x[gun_r][usr.c - 6] = 92;
                    x[gun_r + 1][usr.c - 5] = 92;
                    x[gun_r + 2][usr.c - 4] = 92;
                    //kill enemy
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
        }
        //enemy detection
    }
    if (dir == 'f' && usr.is_facing_right == 0)
    {
        int i;
        //loop from gun col to obstacle (not space) or 5
        for (i = 1; x[gun_r][gun_c + i] == ' ' && i < 5; i++)
        {
            //make things move while inside loop
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
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
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            map(x, mat);
            //draw hero behind enemy*needs to be changed to dynamic*
            usr.c += 11;
            //redraw map
            animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            //draw hit animation
            x[gun_r - 2][usr.c - 8] = 92;
            x[gun_r - 1][usr.c - 7] = 92;
            x[gun_r][usr.c - 6] = 92;
            x[gun_r + 1][usr.c - 5] = 92;
            x[gun_r + 2][usr.c - 4] = 92;
            //kill enemy
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
    if (dir == 'r' && bullet.cd < 0)
    {
        int i;
        //loop from gun col to something that's not space
        for (i = 1; x[gun_r][gun_c + i] == ' '; i++)
        {
            x[gun_r][gun_c + i] = 205;
        }
        map(x, mat);
        //enemy detection
        if (gun_r == (kat.r + 3) && ((kat.c - 1) == (gun_c + i)))
        {
            kat.hp--;
            if (kat.hp <= 0)
            {
                kat.alive = 0;
            }
        }
        bullet.cd = bullet.cd_reset;
        /*
        * if (x[26][kat.c - 2] = 205)
            {
                kat.hp--;
                if (kat.hp <= 0)
                {
                    kat.alive = 0;
                }
            }
        */
    }
    //jump
    if (dir == 'i' && usr.is_jumping == 0 && usr.is_falling == 0 && usr.jump_cd < 0)
    {
        usr.is_jumping = -1;
    }
    if (dir == 'l' && usr.is_jumping == 0 && usr.is_falling == 0 && usr.jump_cd < 0)
    {
        usr.is_jumping = -2;
    }
    if (dir == 'j' && usr.is_jumping == 0 && usr.is_falling == 0 && usr.jump_cd < 0)
    {
        usr.is_jumping = -3;
    }
    //dodge button
    if (dir == 'x')
    {
        usr.c += 10;
        //avoid not displaying when spamming
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        map(x, mat);
    }
    if (dir == 'z')
    {
        usr.c -= 10;
        //avoid not displaying when spamming
        animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        map(x, mat);
    }
}
int main()
{
    //combo 1 para: (char x[][350], char dir, int& usr.r, int& usr.c, int mat_r, int mat_c, int& enemy1_r, int& enemy1_c,int platform.r, int platform.c, int bullets_pos[][2],int &ct_bullet,int ladder.r, int ladder.c, int ladder.length)
    char x[30][350];
    matrix mat;
    user usr;
    platfrm platform;
    platfrm falling[5];
    int falling_ct = 5;
    bullts bullet;
    ldder ladder;
    hill hills[12 + 1];
    int ct_hills = 12;
    lva lava;
    katio kat;
    mahmod mahmoud;
    cest chest;
    ofu ufo;
    //size of mat
    mat.r = 30;
    mat.c = 115;
    mat.forward_boundary = 35;
    mat.backward_boundary = 84;
    mat.scroll_speed = 1;
    mat.do_scroll = 0;
    mat.level = 0;
    //usr position
    //scene 1
    usr.r = 23;
    usr.c = 20;
    //scene 2
    //usr.r = 23;
    //usr.c = 115;

    usr.speed = 1;
    usr.is_jumping = 0;
    usr.jump_height = 5;
    usr.jump_cd = 0;
    usr.jump_cd_reset = 5;
    usr.gravity_speed = 1;
    usr.can_ladder_up = 0;
    usr.can_left = 1;
    usr.can_right = 1;
    usr.can_ladder_down = 0;
    usr.can_fly = 1;
    usr.can_fall = 0;
    usr.cur_frame = 0;
    usr.is_facing_right = 1;
    usr.die = 0;
    //katio
    kat.r = 7;
    kat.c = 74;
    kat.is_looking_right = 1;
    kat.c_min = 40;
    kat.c_max = 112;
    kat.cur_frame = 0;
    kat.hp = 3;
    kat.alive = 1;
    kat.cd = 0;
    kat.cd_reset = 5;
    //mahmoud
    mahmoud.r = 7;
    mahmoud.c = 215;
    //bullets initialization
    bullet.ct = 0;
    bullet.cd = 0;
    bullet.cd_reset = 8;
    //chest position
    chest.r = 25;
    chest.c = 2;
    chest.cur_frame = 0;
    ufo.r = 0;
    ufo.c = 284;
    ufo.cd = 0;
    ufo.cd_reset = 40;
    //hills positions
    hills[1].start_r = 14;
    hills[1].end_r = 14 + 15; //29
    hills[1].start_c = 38;
    hills[1].end_c = 38 + 76; //114
    hills[1].is_left_wall = 1;
    hills[1].is_horizontal_wall = 1;
    hills[1].is_right_wall = 0;

    /*//hill object detection test
    hills[1].start_r = 13;
    hills[1].end_r = 14 + 15; //29
    hills[1].start_c = 20;
    hills[1].end_c = 43; //114
    hills[1].is_left_wall = 1;
    hills[1].is_horizontal_wall = 1;
    hills[1].is_right_wall = 1;
    */
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
    hills[3].end_c = 197 + 51;//250
    hills[3].is_left_wall = 0;
    hills[3].is_horizontal_wall = 1;
    hills[3].is_right_wall = 0;
    //
    hills[4].start_r = 14;
    hills[4].end_r = 0;
    hills[4].start_c = 335;
    hills[4].end_c = 335 + 14;
    hills[4].is_left_wall = 0;
    hills[4].is_horizontal_wall = 1;
    hills[4].is_right_wall = 0;

    hills[5].start_r = 14;
    hills[5].end_r = 0;
    hills[5].start_c = 258;
    hills[5].end_c = 258 + 10;
    hills[5].is_left_wall = 0;
    hills[5].is_horizontal_wall = 1;
    hills[5].is_right_wall = 0;

    hills[6].start_r = 14;
    hills[6].end_r = 0;
    hills[6].start_c = 278;
    hills[6].end_c = 278 + 10;
    hills[6].is_left_wall = 0;
    hills[6].is_horizontal_wall = 1;
    hills[6].is_right_wall = 0;

    hills[7].start_r = 14;
    hills[7].end_r = 0;
    hills[7].start_c = 297;
    hills[7].end_c = 297 + 10;
    hills[7].is_left_wall = 0;
    hills[7].is_horizontal_wall = 1;
    hills[7].is_right_wall = 0;

    hills[8].start_r = 14;
    hills[8].end_r = 0;
    hills[8].start_c = 316;
    hills[8].end_c = 316 + 10;
    hills[8].is_left_wall = 0;
    hills[8].is_horizontal_wall = 1;
    hills[8].is_right_wall = 0;

    hills[9].start_r = 27;
    hills[9].end_r = 29;
    hills[9].start_c = 165;
    hills[9].end_c = 165 + 11;
    hills[9].is_left_wall = 1;
    hills[9].is_horizontal_wall = 1;
    hills[9].is_right_wall = 0;

    hills[10].start_r = 25;
    hills[10].end_r = 27;
    hills[10].start_c = 173;
    hills[10].end_c = 173 + 5;
    hills[10].is_left_wall = 1;
    hills[10].is_horizontal_wall = 1;
    hills[10].is_right_wall = 0;

    hills[11].start_r = 27;
    hills[11].end_r = 29;
    hills[11].start_c = 200;
    hills[11].end_c = 200 + 11;
    hills[11].is_left_wall = 0;
    hills[11].is_horizontal_wall = 1;
    hills[11].is_right_wall = 1;

    hills[12].start_r = 25;
    hills[12].end_r = 27;
    hills[12].start_c = 198;
    hills[12].end_c = 198 + 5;
    hills[12].is_left_wall = 0;
    hills[12].is_horizontal_wall = 1;
    hills[12].is_right_wall = 1;
    //platform position
    platform.r = 24;
    platform.r_const = platform.r;
    platform.c = 180 + 1;
    platform.width = 15;
    platform.top = 10;
    platform.is_platform_on_floor = 0;
    platform.cd = 0;
    platform.cd_reset = 30;
    platform.is_hero_on_platform = 0;
    //ladder position and flag
    //top left cell of the ladder
    ladder.r = 14;
    ladder.c = 30;
    ladder.length = 15;
    ladder.width = 8;
    //lava position
    lava.r = 29;
    lava.c = 245;
    lava.width = 115 - 30; //buffer of 10 blocks right and elft
    lava.top = 5;
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
            draw_and_open_chest(x, chest, usr);
            draw_ufo(x, ufo);
            ufo_fire(x, ufo);
            draw_katio(x, kat);
            move_katio(kat, usr);
            draw_mahmoud(x, mahmoud);
            //move then draw bullet
            move_bullets(x, bullet, kat, mat);
            draw_bullets(x, bullet);
            //draw hero
            draw_hero(x, usr);
            //gravity
            gravity_and_jump(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            move_elevator(x, usr, platform);
            object_detection(usr, platform, ladder, hills, ct_hills);
            check_death(usr, lava, kat, ufo);
            cd(usr, bullet, platform, kat, ufo);
            if (usr.die == 1)
            {
                animation(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
                map(x, mat);
                die(x, mat, usr, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
            }
            //screen the matrix
            map(x, mat);
        }
        //save user input
        char move = _getch();
        //take action based on input
        user_action(x, move, usr, mat, platform, bullet, ladder, hills, ct_hills, lava, kat, chest, ufo, mahmoud);
        //*betsara3 el gravity lma ad5al input bas bt7el moshkelet lazer spamming wna tayer
        //gravity(x, mat, usr, enemy1, platform, bullets_pos, ct_bullet, ladder, hills, ct_hills);

    }
}