#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20

void InBanCo( char Banco[MAX][MAX], int n)
{
    cout << n << endl;
    for ( int i = 0; i < n;i++)
        {
            for ( int j = 0; j < n; j++)
            {
                cout << Banco[i][j] << ' ';
            }
            cout << endl;
        }

}
char kiemTraNgang(char Banco[MAX][MAX], int n, int i, int j)
{
        int countt = 1;
      for (int k = j; k >0 ; k--)
        {if ( Banco[i][k-1] == Banco[i][j]) countt++;
                else break ; }

        for (int l = j; l < n-1 ; l++)
                {
                    {if ( Banco[i][l+1] == Banco[i][j]) countt++;
                    else break ; }
                }


                if (countt >=5 ) {return Banco[i][j];}
        return '.' ;
}
char KiemTraDoc(char Banco[MAX][MAX], int n, int i, int j)
{
     int countt = 1;
      for (int k = i; k >0 ; k--)
        {if ( Banco[k-1][j] == Banco[i][j]) countt++;
                else break ; }

        for (int l = i; l < n-1 ; l++)
                {
                    {if ( Banco[l+1][j] == Banco[i][j]) countt++;
                    else break ; }
                }


                if (countt >=5 ) {return Banco[i][j];}
        return '.' ;
}
char KiemTraCheoChinh(char Banco[MAX][MAX], int n, int i, int j)
{
 int countt = 1;
    int l = i, k=j;
      while(l>0 & k>0 & Banco[l-1][k-1]== Banco[i][j] )
        {
            countt++;
            l-=1;
            k-=1;
            if (countt ==5 ) {return Banco[i][j];}
        }
        l = i;
        k=j;
      while(l<0 & k<0 & Banco[l+1][k+1]== Banco[i][j])
        {
            countt++;
            l+=1;
            k+=1;
            if (countt ==5 ) {return Banco[i][j];}
        }



        return '.' ;
}
char KiemTraCheoPhu(char Banco[MAX][MAX], int n, int i, int j)
{
 int countt = 1;
    int l = i, k=j;
      while(l>0 & k<n & Banco[l-1][k+1]== Banco[i][j] )
        {
            countt++;
            l-=1;
            k+=1;
            if (countt ==5 ) {return Banco[i][j];}
        }
        l = i;
        k=j;
      while(l<n & k>0 & Banco[l+1][k-1]== Banco[i][j] )
        {
            countt++;
            l+=1;
            k-=1;
            if (countt ==5 ) {return Banco[i][j];}
        }



        return '.' ;
}
string ketqua(char kiemtra)
{

    if (kiemtra == 'x') return "Ti wins";
    if (kiemtra =='o') return "Teo wins";
    return ".";
}

int main()
{
    char Banco[MAX][MAX];

    ifstream file("C:\\Users\\AnhQT\\Desktop\\Caroo\\input1.txt");  // '\' là 1 kí tự đặc biệt không được dùng, ta sử dụng '\\'
    if (!file)
        cout << "Khong mo duoc";
    else
    {
        int n;
        file >> n;
        string line;
        getline(file,line); // cú pháp lấy cả dòng, xuống dòng
        for ( int i = 0; i < n;i++)
        {
            for ( int j = 0; j < n; j++)
            {
                Banco[i][j] = '.';

                file >> Banco[i][j];

            if (Banco[i][j] != '.' )
            {
                // Xử lý thắng thua;

                // Xet hang ngang suy ra cung so i khac so j
                /*char ktngang = kiemTraNgang(Banco,n,i,j);
                if ( ktngang != '.')
                {

                    if ( ktngang == 'x') { cout << "Ti wins" << endl ; file.close(); return 0;}
                    else {cout << "Teo wins" << endl;    file.close(); return 0;}

                }


                 char ktdoc = KiemTraDoc(Banco,n,i,j);
                if ( ktdoc != '.')
                {

                    if ( ktdoc == 'x') { cout << "Ti wins" << endl ; file.close(); return 0;}
                    else {cout << "Teo wins" << endl;    file.close(); return 0;}

                }
                char ktcheochinh = KiemTraCheoChinh(Banco,n,i,j);
                if ( ktcheochinh != '.')
                {

                    if ( ktcheochinh == 'x') { cout << "Ti wins" << endl ; file.close(); return 0;}
                    else {cout << "Teo wins" << endl;    file.close(); return 0;}

                }
                 char ktcheophu = KiemTraCheoPhu(Banco,n,i,j);

                if ( ktcheophu != '.')
                {

                    if ( ktcheophu == 'x') { cout << "Ti wins" << endl ; file.close(); return 0;}
                    else {cout << "Teo wins" << endl;    file.close(); return 0;}

                }*/
                string s = ketqua(kiemTraNgang(Banco,n,i,j));
                string t = ketqua(KiemTraDoc(Banco,n,i,j));
                string v = ketqua(KiemTraCheoChinh(Banco,n,i,j));
                string u = ketqua(KiemTraCheoPhu(Banco,n,i,j));
                if ( s != ".") { cout << s; return 0;}
                if ( t != ".") { cout << t; return 0;}
                if ( v != ".") { cout << v; return 0;}
                if ( u != ".") { cout << u; return 0;}






            }
            }
            getline(file,line);
        }

        file.close();

    }

    cout << "Not yet";

    return 0;
}


