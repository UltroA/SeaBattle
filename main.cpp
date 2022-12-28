#include <iostream>
using namespace std;

const int N = 10;
int corX, corY, winValue;
int fieldPlayer[N][N];
int fieldComp[N][N];


void setupPC()
{
    // Adding solo ship to field
    for (int i = 0; i < 4; i++)
        {
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
}

void setupPlayer()
{
    // Adding solo ship to field
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
        cout << "Not today!)";
        setupPlayer();
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
        cout << ""<< i << " ";
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
                cout << "0";
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

int main()
{
    int temp = 0;
    int buff = 0;
    
    fields();
    setupPC();
    for(int i = 0; i < 3; i++){
        setupPlayer();
    }
    outFieldPlayer();

    return 0;
}
