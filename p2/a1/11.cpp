    #include<iostream>
    using namespace std;

    void main()
    {
        int x[100][200];
        int i, j, value, ct, v_begin_row,v_begin_col,v_end_row,v_end_col,tot=0;
        //input matrix
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 200; j++)
            {
                cin >> x[i][j];
            }
        }
        //input value
        cin >> value;
        //check if value is repeated twice
        ct = 0;
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 200; j++)
            {
                if (x[i][j] == value)
                {
                    //catch position of first and second appearance 
                    v_end_row = i;
                    v_end_col = j;
                    if (++ct == 2)
                    {
                        break;
                    }
                    v_begin_row = i;
                    v_begin_col = j;
                }
            }
            if (ct == 2)
            {
                break;
            }
        }
        if (ct == 2)
        {
            //count the summation of the specified area
            for (i = v_begin_row; i <= v_end_row; i++)
            {
                for (j = v_begin_col; j <= v_end_col; j++)
                {
                    tot += x[i][j];
                }
            }
        }
        cout << tot;
    }
        
