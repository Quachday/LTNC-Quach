#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX 100

// Hàm thay đổi kích cỡ khung cmd
/*void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console,&r);
    Movewindow(console,r.left,r.top,width,height,TRUE);
}*/
// Hàm dịch chuyển con trỏ đến tọa độ x,y.
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x-1,y-1};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,Cursor_an_Pos);
}
// Hàm xóa màn hình
/*void XoaManHinh()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X= 0;
    Position.Y=0;
    SetConsoleCursorPosition(hOut, Position);
}*/
// Hàm tô màu
void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau,x);
}
void VeBanCo_NangCao(int sodong,int socot, int dorong, char a[MAX][MAX] )
{

    // In viền khung trên đầu tiên
    cout << setw(dorong+3) << 1;
    for ( int i = 0; i < socot-1; i++)
    {
        cout << setw(dorong+1) << i+2;
    }


    cout << "\n   ";
    cout << (char)218;
    for ( int j = 0; j < socot; j++)
    {


        for ( int l = 0; l < dorong; l++ ) cout << (char)196; // 196 ─
        if ( j < socot-1) cout << (char)194; //194 ┬
        else cout << (char)191; // 191 ┐
    }
    cout << endl;
    //cout << str[0] << endl;

    cout << setw(4-1) << 1 << (char)179;
    for ( int k = 0; k < socot; k++)
    {
        for ( int l = 0; l < dorong; l++ )
        {
            if(l==dorong/2 & a[0][k] != ' ')
            {
                if(a[0][k]=='x') textcolor(12);
                else textcolor(14);
                cout << a[0][k];
                textcolor(7);
            }
            else cout << " ";
        }
        cout << (char)179; // 179 │
    }

    cout << "\n";

    int KhoangCachVoiLe= 3;
    // In những ô bên trong bàn cờ
    for ( int i = 0; i < sodong-1 ; i++)
    {
        cout << setw(4) << (char)195; // 195 ├
        for ( int j = 0; j < socot; j++)
        {
            for ( int l = 0; l < dorong; l++ ) cout << (char)196; // 196 ─
            if ( j < socot-1) cout << (char)197; // 197 ┼
            else cout << (char)180; // 180 ┤
        }




        for (int l = 0; l< 1; l++ )
        {
            cout << "\n" << setw(KhoangCachVoiLe)  << i+2 << (char)179; // 179 │
            for ( int k = 0; k < socot; k++)
            {
                for ( int l = 0; l < dorong; l++ )
                {
                    if(l==dorong/2 & a[i+1][k] != ' ')
                    {
                        if(a[i+1][k]=='x') textcolor(12);
                        else textcolor(14);
                        cout << a[i+1][k];
                        textcolor(7);
                    }
                    else cout << " ";
                }
                cout << (char)179;// 179 │

            }
        }
        //cout << str[i+1] << endl;
        cout << "\n";



    }
    // In viền khung dưới
    cout << "   " << (char)192; // 192 └
    for ( int j = 0; j < socot; j++)
    {
        for ( int l = 0; l < dorong; l++ ) cout << (char)196; // 196 ─
        if (j< socot-1) cout << (char)193; // 193 ┴
        else cout << (char)217; // 217 ┘
    }

}
void KhoiTaoMangLuuBanCo(char a[MAX][MAX], int sodong,int socot)
{
    for ( int i = 0; i <sodong; i++)
    {
        for (int j = 0; j<socot; j++)
        {
            a[i][j] = ' ';
        }
    }
}
void XuLyNuocCo(char a[MAX][MAX], int sodong,int socot, int dorong,int toadohang,int toadocot)
{
    VeBanCo_NangCao(sodong,socot,dorong,a);
    int i = 1;
    char quanco;


    //VeBanCo_NangCao(sodong,socot,dorong,a);

    //cout << "\nNhap toa do muon danh (toadohang-toadocot): ";
    cout << "\n";

    while (true)
    {

        static int j = 1;
        static int k = 1;
        if ( i%2 == 1)
        {
            cout << "Day la luot cua : X" ;
            quanco = 'x';
        }
        else
        {
            cout << "Day la luot cua : O" ;
            quanco = 'o';
        }
        /*gotoxy(45,3+ sodong*2);
        cout << "            ";
        gotoxy(45,3+sodong*2);
        cin >> toadohang >> toadocot;
        a[toadohang-1][toadocot-1] = quanco;
        gotoxy(5+dorong/2+(toadocot-1)*(dorong+1),toadohang*2+1); // con tro chuyen ve vi tri can danh
        if(quanco =='x')
        {
            textcolor(12);
            cout << quanco;
            textcolor(7);
        }
        else
        {
            textcolor(14);
            cout << quanco;
            textcolor(7);
        }
        gotoxy(1,4+sodong*2); // con tro chi den cho de in ra NHAP TOA DO


        */
        gotoxy(j,k);

        while(true) // bắt key = getch() // làm game console dùng getch tiện hơn
        {


        if(kbhit()) // ham nhận một phím từ bàn phím
        {char c = getch();

        if ( c == 75 || c=='a' || c == 'A' ) // ngoài việc so sánh với a thương và a hoa thì ta có thể so sách với 97 và 65 : các số trong mã ASCII => Các phím không phải kí tự thì ta tra số ASCII của phím đó
            // ở đây ta có cách biết tất cả mã ascii của các phím trên bàn phím = cách
            // cout << mã ascii của phím vừa bấm là : << (int)c << endl; left = 75 = K;  right=77=M ;up= 72 =H; down=80=P
        {
            gotoxy(j-1,k);
            j--;
        }
        if ( c == 72|| c=='W' || c == 'w')
        {
            gotoxy(j,k-1);
            k--;
        }
        if ( c == 77|| c=='d' || c == 'D')
        {
            gotoxy(j+1,k);
            j++;
        }
        if ( c == 80|| c=='s' || c == 'S')
        {
            gotoxy(j,k+1);
            k++;
        }
        if ( c == 32 ) // space = 32
        {
            if (quanco =='x') {textcolor(14) ; cout << quanco ; textcolor(7); break;}
            else {textcolor(12) ; cout << quanco ; textcolor(7); break;}
        }
        }
        }

       /* while(true) // bắt key = virtual key
        {
        //char c = getch();
        if ( GetAsyncKeyState(VK_LEFT))
        {
            gotoxy(j-1,k);
            j--;
            continue;
        }
        else if ( GetAsyncKeyState(VK_UP))
        {
            gotoxy(j,k-1);
            k--;
        }
        else if ( GetAsyncKeyState(VK_RIGHT))
        {
            gotoxy(j+1,k);
            j++;
        }
        else if ( GetAsyncKeyState(VK_DOWN))
        {
            gotoxy(j,k+1);
            k++;
        }
        else if ( GetAsyncKeyState(VK_SPACE))
        {
            if (quanco =='x') {textcolor(14) ; cout << quanco ; textcolor(7); Sleep(500); break;}
            else {textcolor(12) ; cout << quanco ; textcolor(7); Sleep(500); break;}
        }
        Sleep(100); // GOOGLE search mã Key code virtual hàm getasync trong lib window.h
        }
        */
        gotoxy(1,3+sodong*2);
        i++;



    }
}

int main()
{
    int sodong =5;
    int socot = 5;

    int dorong = 3 ;
    int toadohang = -1;
    int toadocot = -1;
    char a[MAX][MAX] = {{' '}};

    KhoiTaoMangLuuBanCo(a,sodong,socot);
    XuLyNuocCo(a,sodong,socot,dorong,toadohang,toadocot);








    return 0;
}
