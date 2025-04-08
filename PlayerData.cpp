#include <windows.h>
#include <iostream>

using namespace std;

void Gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


struct PlayerInfo
{
public:
    PlayerInfo(int InX, int InY)
        : X(InX)
        , Y(InY)
    {}
	int X, Y;

};

int main()
{
	PlayerInfo PlayerInfo(50, 50);

    while (true) {
        char Input;
        cin >> Input;
        
        getchar();

        switch (Input)
        {
        case 'w':
        {
            --PlayerInfo.Y;
            break;
        }
        case 's':
        {
            ++PlayerInfo.Y;
            break;
        }
        case 'a':
        {
            --PlayerInfo.X;
            break;
        }
        case 'd':
        {
            ++PlayerInfo.X;
            break;
        }
        default:
            break;
        }

        Gotoxy(PlayerInfo.X, PlayerInfo.Y);
    }
}