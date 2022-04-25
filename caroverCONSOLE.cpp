i = y;
            j = x;
            while( i>0 & j<socot & a[i-1][j+1]== a[y][x])
            {
                gotoxy(6+(j+1)*4,3+(i-1)*2);
                textcolor(14+16);
                cout << quanco;
                i--;
                j++;
            }
            i=y;
            j=x;
            while( i<sodong & j>0 & a[i+1][j-1]== a[y][x])
            {

                gotoxy(6+(j-1)*4,3+(i+1)*2);
                textcolor(14+16);
                cout << quanco;
                i++;
                j--;
            }
            sleep(5);
            textcolor(7);
            system("cls");

            cout << quanco << " wins" ;
            exit(0);
