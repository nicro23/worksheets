    #include<iostream>
    using namespace std;

    void main()
    {
        int i, j, tot, row, right, left, k, max = -99999, top_row, top_col, pos_top_row,pos_top_col,pos_bot_row;
        int x[20][20];
        //input matrix
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                cin >> x[i][j];
            }
        }
        //loop around every cell
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                //prep variables
                top_row = i;
                top_col = j;
                row = i;
                left = j - 1;
                right = j + 1;
                tot = x[i][j];
                //search for all possible triangles with the head
                while (left >= 0 && right < 20 && ++row < 20)
                {
                    for (k = left; k <= right; k++)
                    {
                        tot += x[row][k];
                    }
                    //determine triangle with highest total
                    if (tot > max)
                    {
                        max = tot;
                        pos_top_row = top_row;
                        pos_top_col = top_col;
                        pos_bot_row = row;
                    }
                    left -= 1;
                    right += 1;
                }
            }
        }
        //display triangle
        left = pos_top_col;
        right = pos_top_col;
        for (i = pos_top_row; i <= pos_bot_row; i++)
        {
            for (j = left; j <= right; j++)
            {
                cout << x[i][j] << " ";
            }
            left--;
            right++;
            cout << endl;
        }
    }
        
