#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 11;
int corX, corY, winValue;
int fieldPlayer[N + 2][N + 2];
int fieldShootFrPlayer[N][N];
int fieldComp[N][N];

// Checks
bool inField(int x, int y){
    if (x >= 0 && x < N && y >= 0 && y < N){
        return true;
    }
    else{
        return false;
    }
}

// Render functions
void renderSelf()
{
    // Output of player's field
    cout << "\t";
    for(int i = 1; i < N; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    for(int i = 0; i < N -1; i++){
        cout << i + 1 << "\t";

        for(int j = 0; j < N -1; j++){
            if(fieldPlayer[i][j] == 1){
                cout << "⬛";
            }
            else if(fieldPlayer[i][j] == 3){
                cout << "0~";
            }
            else if (fieldPlayer[i][j] == 2){
                cout << "🔲";
            }
            else{
                cout << "~~";
            }
        }
        cout << "\n";
    }
}

void renderShooted()
{
    // Output of bot's field in player's pov
    cout << "\t";
    for(int i = 1; i < N; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    for(int i = 0; i < N -1; i++){
        cout << i + 1 << "\t";

        for(int j = 0; j < N -1; j++){
            if(fieldShootFrPlayer[i][j] == 1){
                cout << "⬛";
            }
            else if(fieldShootFrPlayer[i][j] == 3){
                cout << "0~";
            }
            else if (fieldShootFrPlayer[i][j] == 2){
                cout << "🔲";
            }
            else{
                cout << "~~";
            }
        }
        cout << "\n";
    }
}

void renderBot()
{
    // Debug only feature!!!!
    // TODO: Delete ASAP
    cout << "\t";
    for(int i = 1; i < N; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    for(int i = 0; i < N -1; i++){
        cout << i + 1 << "\t";

        for(int j = 0; j < N -1; j++){
            if(fieldComp[i][j] == 1){
                cout << "⬛";
            }
            else if(fieldComp[i][j] == 3){
                cout << "0~";
            }
            else if (fieldComp[i][j] == 2){
                cout << "🔲";
            }
            else{
                cout << "~~";
            }
        }
        cout << "\n";
    }
}

// Setting up PC's ships
void setupOnePC()
{
    // Adding solo ship to field with random
            corX = rand() % N;
            corY = rand() % N;
            if ((fieldComp[corX][corY] == 0 ||
                fieldComp[corX][corY + 1] == 0 ||
                fieldComp[corX][corY - 1] == 0 ||
                fieldComp[corX + 1][corY] == 0 ||
                fieldComp[corX + 1][corY + 1] == 0 ||
                fieldComp[corX + 1][corY - 1] == 0 ||
                fieldComp[corX - 1][corY] == 0 ||
                fieldComp[corX - 1][corY + 1] == 0 ||
                fieldComp[corX - 1][corY - 1] == 0))
            {
                fieldComp[corX][corY] = 1;
            }
}

void setupTwoPC()
{
    // Adding two-bases ship to field to computer
    int x, y, x1, y1;

    x = 1 + rand() % N;
    y = 1 + rand() % N;
    cout << x << y;

    if (!(fieldComp[x][y] == 1 ||
          fieldComp[x][y + 1] == 1 ||
          fieldComp[x][y - 1] == 1 ||
          fieldComp[x + 1][y] == 1 ||
          fieldComp[x + 1][y + 1] == 1 ||
          fieldComp[x + 1][y - 1] == 1 ||
          fieldComp[x - 1][y] == 1 ||
          fieldComp[x - 1][y + 1] == 1 ||
          fieldComp[x - 1][y - 1] == 1))
    {

        x1 = rand() % N;
        y1 = rand() % N;
        if (!(fieldComp[x1][y1] == 1
              || (x1+1 == x && y1+1 == 1)
              || (x1-1 == x && y1+1 == 1)
              || (x1-1 == x && y1-1 == 1)
              || (x1+1 == x && y1-1 == 1))
            &&
            ((x1 == x && y1+1 == y) ||
             (x1+1 == x && y1 == y) ||
             (x1-1 == x && y1 == y) ||
             (x1 == x && y1-1 == y)))
        {
            fieldComp[x1 - 1][y1 - 1] = 1;
            fieldComp[x - 1][y - 1] = 1;
        }
        else{
            setupTwoPC();
        }
    }
    else{
        setupTwoPC();
    }
}

// Setting up Player's ships
void setupOnePlayer()
{
    // Adding solo ship to field by player
    cout << "Введи координату однопалубника: ";
    int x, y;
    cin >> y;
    cin >> x;
    x--;
    y--;
    if ((x + 1 < N && y + 1 < N) &&
                !(fieldPlayer[x][y] == 1 ||
                fieldPlayer[x][y + 1] == 1 ||
                fieldPlayer[x][y - 1] == 1 ||
                fieldPlayer[x + 1][y] == 1 ||
                fieldPlayer[x - 1][y] == 1 ||
                fieldPlayer[x + 1][y + 1] == 1 ||
                fieldPlayer[x - 1][y + 1] == 1 ||
                fieldPlayer[x + 1][y - 1] == 1 ||
                fieldPlayer[x - 1][y - 1] == 1))
            {
                fieldPlayer[x][y] = 1;
            }
    else{
        cout << "Так нельзя\n";
        setupOnePlayer();
    }
}

void setupTwoPlayer()
{
    // Adding two-bases ship to field by player
    cout << "Введи координату двухпалубника (первой палубы): ";
    int x, y, x1, y1;
    cin >> y;
    cin >> x;
    x--;
    y--;
    if ((x + 1 < N && y + 1 < N) &&
        !(fieldPlayer[x][y] == 1 ||
        fieldPlayer[x][y + 1] == 1 ||
        fieldPlayer[x][y - 1] == 1 ||
        fieldPlayer[x + 1][y] == 1 ||
        fieldPlayer[x - 1][y] == 1 ||
        fieldPlayer[x + 1][y + 1] == 1 ||
        fieldPlayer[x - 1][y + 1] == 1 ||
        fieldPlayer[x + 1][y - 1] == 1 ||
        fieldPlayer[x - 1][y - 1] == 1) &&
        !(fieldPlayer[x][y] == 1 ||
        fieldPlayer[x][y + 2] == 1 ||
        fieldPlayer[x][y - 2] == 1 ||
        fieldPlayer[x + 2][y] == 1 ||
        fieldPlayer[x - 2][y] == 1 ||
        fieldPlayer[x + 2][y + 2] == 1 ||
        fieldPlayer[x - 2][y + 2] == 1 ||
        fieldPlayer[x + 2][y - 2] == 1 ||
        fieldPlayer[x - 2][y - 2] == 1))
            {
                cout << "Введи координату двухпалубника (второй палубы): ";
                cin >> y1;
                cin >> x1;
                y1--;
                x1--;
                if (fieldPlayer[x1][y1] != 1 and
                    (x + 1 == x1 and y == y1 ||
                     x - 1 == x1 and y == y1||
                     x == x1 and y + 1 == y1||
                     x == x1 and y - 1 == y1) and
                    inField(x1, y1)){
                    fieldPlayer[x][y] = 1;
                    fieldPlayer[x1][y1] = 1;
                }
                else {
                    cout << "Так нельзя, введи другие координаты палуб\n";
                    setupTwoPlayer();
                }
            }
    else{
        cout << "Так нельзя, введи другую координату\n";
        setupTwoPlayer();
    }
}

// Initialization of fields
void fields()
{
    // Creating player's field 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
                fieldPlayer[i][j] = 0;
            }
    }
    
    // Creating computer's field 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
                fieldComp[i][j] = 0;
            }
    }
}

// Shooting functions
void shoot()
{
    int xt, yt;
    int scorePlayer;
    cout << "В какую клетку вести огонь, капитан? ";
    cin >> yt;
    cin >> xt;
    xt--;
    yt--;
    if (fieldComp[xt][yt] == 1 && inField(xt, yt)){
        fieldShootFrPlayer[xt][yt] = 2;
        fieldComp[xt][yt] = 2;
        cout << "Попадание! Можно и еще один выстрел сделать.\n";
        scorePlayer++;
        renderShooted();
        shoot();
    }
    else if (fieldComp[xt][yt] == 0 && inField(xt, yt)) {
        fieldShootFrPlayer[xt][yt] = 3;
        fieldComp[xt][yt] = 3;
        cout << "Эх, мимо(\n";
        renderShooted();
    }
    else{
        cout << "Ты сюда уже стрелял. Попробуй другую клетку)";
        shoot();
    }
}

// TODO: PC's shooting system


// Game itself
int main()
{
    int temp = 0;
    int buff = 0;
    int scorePlayer = 0;
    int scorePC = 0;
    fields();
    // magick
     for(int i = 0; i < 4; i++){
         setupOnePlayer();
         renderSelf();
         setupOnePC();
     }
    for(int i = 0; i < 3; i++){
        setupTwoPlayer();
        renderSelf();
        setupTwoPC();
    }

     renderBot();
     while (scorePC < 20  or scorePlayer < 20){
         shoot();
         renderBot();
         system("cls");
         system("clear");
     }
    return 0;
}
