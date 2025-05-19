#include <iostream>

using namespace std;

void show_board(char casas[3][3]) {

    cout << casas[0][0] << " | " << casas[0][1] << " | " << casas[0][2] << endl;
    cout << "-----------" << endl;
    cout << casas[1][0] << " | " << casas[1][1] << " | " << casas[1][2] << endl;
    cout << "-----------" << endl;
    cout << casas[2][0] << " | " << casas[2][1] << " | " << casas[2][2] << endl;
}

void start(char casas[3][3], char* pointer) {
    char counter = '1';
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            pointer = &casas[i][j];
            *pointer = counter;
            counter += 1;
        }
    }
}

int mark_on(char casas[3][3], char casa, int jogador, char* pointer) {
    char jogada = (jogador == 1) ? 'X' : 'O';
    int number = (casa - '0') - 1;
    
    if (number / 3 == 0) {
        pointer = &casas[0][number];
        if (*pointer == 'X' || *pointer == 'O') {
            return 0;
        } else {
            *pointer = jogada;
            return 1;
        }
        
    } else if (number / 3 == 1) {
        number -= 3;
        pointer = &casas[1][number];
        if (*pointer == 'X' || *pointer == 'O') {
            return 0;
        } else {
            *pointer = jogada;
            return 1;
        }
    } else if (number / 3 == 2) {
        number -= 6;
        pointer = &casas[2][number];
        if (*pointer == 'X' || *pointer == 'O') {
            return 0;
        } else {
            *pointer = jogada;
            return 1;
        }
    }

    return 0;

}

int vencedor(char casas[3][3], char choice, int jogador){
    char jogada = (jogador == 1) ? 'X' : 'O';
    int number = choice - '0';
    int linha = (number - 1) / 3, coluna = (number - 1) % 3;
    
    // colunas
    if (casas[0][coluna] == jogada && casas[1][coluna] == jogada && casas[2][coluna] == jogada) {
        return jogador;
    }

    // linhas
    if (casas[linha][0] == jogada && casas[linha][1] == jogada && casas[linha][2] == jogada) {
        return jogador;
    }

    // diagonais

    if (casas[0][0] == jogada && casas[1][1] == jogada && casas[2][2] == jogada){
        return jogador;
    }
    if (casas[0][2] == jogada && casas[1][1] == jogada && casas[2][0] == jogada) {
        return jogador;
    }

    return 0;
    
}

int main()
{
    // priting the board
    char* pstart;
    char game[3][3];
    start(game, pstart);


    // making plays

    string linha;
    char escolha;
    char *making_changes = &game[0][0];
    int player = 1;
    char symbol = 'X';
    int is_running = 9;
    int printcase = 1;
    
    // loop

    while (is_running) {
        if (is_running == 9 && printcase == 1) show_board(game);
        bool keep_playing = false;
        int winner = -1;

        if (printcase) {
            cout << endl;
            cout << "Player " << player << " (" << symbol <<")" << ", choose your position: ";
            cout << endl;
        }
        // resolver isso (erro quando a entrada tem mais de 2 dígitos)
        getline(cin, linha);
        if(!linha.empty() && linha.size() == 1){
            escolha = linha[0];
        } else {
            escolha = '+';
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (!(escolha - '0' >= 1 && escolha - '0' <= 9)) {
            cout << "Invalid or already used position! Please, choose another position. ";
            printcase = 0;
            continue;
        } else if (mark_on(game, escolha, player, making_changes) == 0) {
            cout << "Invalid or already used position! Please, choose another position. ";
            printcase = 0;
            continue;
        } else {
            winner = vencedor(game, escolha, player);
            printcase = 1;
        }

        show_board(game);

        if (winner == 1) {
            cout << "Congratulations! Player 1 won!" << endl;
            keep_playing = true;
        } else if (winner == 2) {
            cout << "Congratulations! Player 2 won!" << endl;
            keep_playing = true;
        } else if (winner == 0 && is_running == 1) {
            cout << "It's a tie! No one wins." << endl;
            keep_playing = true;
        } else {
            player = (player == 1) ? 2 : 1;
            symbol = (symbol == 'X') ? 'O' : 'X';
            is_running--;
        }

        if (keep_playing) {
            cout << "Do you want to play again (y/s) ";
            char resposta;
            cin >> resposta;
            if (toupper(resposta) == 'Y'){
                is_running = 9;
                player = 1;
                symbol = 'X';
                start(game, pstart);
            } else {
                break;
            }
        }
        
    }

    cout << "Thank you so much for playing!";

    return 0;
}