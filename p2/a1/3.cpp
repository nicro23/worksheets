    #include<iostream>
    using namespace std;

    void main()
    {
        int i, j, k, z, select_row = 0, select_col = 0, sort = 0, region, dir, left, right;
        char direction;
        int x[3][3] = { 8,7,2,1,4,6,5,3,9 };
        while (sort == 0)
        {
            cout<<"select region (1/2/3/4): ";
            cin >> region;
            cout<<"select direction(r/l): ";
            cin >> direction;
            //set region
            select_row = 0;
            select_col = 0;
            if (region <= 2)
            {
                select_row = 1;
            }
            if (region % 2 != 0)
            {
                select_col = 1;
            }
            //set direction
            if (direction == 'r')
            {
                right = 1;
                left = 0;
            }
            if (direction == 'l')
            {
                left = 1;
                right = 0;
            }
            //rotate
            i = 0 + select_row;
            for (j = 0 + select_col; j < 2 + select_col; j += 1)
            {
                z = x[i][j];
                x[i][j] = x[i + 1][j];
                x[i + 1][j] = z;
            }
            j--;
            z = x[i][j - left];
            x[i][j - left] = x[i + 1][j - right];
            x[i + 1][j - right] = z;
            //check if sorted
            k = 1;
            sort = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (x[i][j] != k++)
                    {
                        sort = 0;
                        break;
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << x[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
        
