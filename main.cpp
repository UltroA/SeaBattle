#include <iostream>
using namespace std;

const int N = 10;
int corX, corY, winValue;
int fieldPlayer[N][N];
int fieldComp[N][N];


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

void setupTwoPlayer()
{
    // Adding two-bases ship to field
    cout << "Добавь двухпалобник\n";
    cout << "Введи координату первой палубы корабля: ";
    int x, y, x1, y1;
    cin >> x;
    cin >> y;
    if (!(fieldPlayer[x][y] == 1 ||
                fieldPlayer[x][y + 1] == 1 ||
                fieldPlayer[x][y - 1] == 1 ||
                fieldPlayer[x + 1][y] == 1 ||
                fieldPlayer[x + 1][y + 1] == 1 ||
                fieldPlayer[x + 1][y - 1] == 1 ||
                fieldPlayer[x - 1][y] == 1 ||
                fieldPlayer[x - 1][y + 1] == 1 ||
                fieldPlayer[x - 1][y - 1] == 1))
            {
                cout << "Введи координату второй палубы корабля: ";
                cin >> x1;
                cin >> y1;
                if (!(fieldPlayer[x1][y1] == 1 
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
                            fieldPlayer[x1 - 1][y1 - 1] = 1;
                            fieldPlayer[x - 1][y - 1] = 1;
                        }
                else{
                    cout << "Так нельзя\n";
                    setupTwoPlayer();
                }
            }
    else{
        cout << "Так нельзя";
        setupTwoPlayer();
    }
}

void setupOnePlayer()
{
    // Adding solo ship to field
    cout << "Введи координату однопалубника: ";
    int x, y;
    cin >> x;
    cin >> y;
    if (!(fieldPlayer[x][y] == 1 ||
                fieldPlayer[x][y + 1] == 1 ||
                fieldPlayer[x][y - 1] == 1 ||
                fieldPlayer[x + 1][y] == 1 ||
                fieldPlayer[x + 1][y + 1] == 1 ||
                fieldPlayer[x + 1][y - 1] == 1 ||
                fieldPlayer[x - 1][y] == 1 ||
                fieldPlayer[x - 1][y + 1] == 1 ||
                fieldPlayer[x - 1][y - 1] == 1))
            {
                fieldPlayer[x - 1][y - 1] = 1;
            }
    else{
        cout << "Так нельзя\n";
        setupOnePlayer();
    }
}

void fields(){
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

void outFieldPlayer(){
    // Output of player's field
    cout << "\t";
    for(int i = 1; i < N + 1; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    for(int i = 0; i < N; i++){
        cout << i + 1 << "\t";
        for(int j = 0; j < N; j++){
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

void outFieldPC(){ //Only for debug!!!
    // Output of player's field
    cout << "\t";
    for(int i = 1; i < N + 1; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";

    for(int i = 0; i < N; i++){
        cout << i + 1 << "\t";
        for(int j = 0; j < N; j++){
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

int main()
{
    int temp = 0;
    int buff = 0;
    
    fields();
    for(int i = 0; i < 4; i++){ 
        setupOnePC();  
        setupOnePlayer();
    }
    for(int i = 0; i < 2; i++){
        setupTwoPlayer();
        setupTwoPC();
    }
    outFieldPC();
    outFieldPlayer();
    return 0;
}
