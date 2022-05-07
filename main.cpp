//
//  main.cpp
//  sodoku_c++
//
//  Created by Lydia Swanson on 5/4/22.
//

//Next do something to check the box positioning.
//Create class with new student
//Keep track of their scores
//Create another file with multiple puzzles or something. 

#include <iostream>
using namespace std;

void printPuzzle(int puzzle[9][9]){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout << puzzle[i][j];
            cout << " ";
            if ((j + 1) % 3 == 0 ) {
                cout<< " ";
            }
            if ((i + 1) % 3 == 0 & j == 8) {
                cout<< "\n";
            }
        }
        cout << "\n";
    }
}

bool checkVert(int puzzle[9][9], int position, int guess){
    
    for(int i = 0; i<9; i++){
        if(puzzle[i][position] == guess){
            return false;
        }
    }
    
    return true;
}

bool checkHoriz(int puzzle[9][9], int position, int guess){
    
    for(int i = 0; i<9; i++){
        if(puzzle[position][i] == guess){
            return false;
        }
    }
    
    return true;
}

bool checkBox(int puzzle[9][9], int horiz, int vert, int guess){
    
//    Out what horzontal box they are in.
//    Find out what horizontal box they are int.
//    Loop through for each box
    
    int horizBox;
    int vertBox;
    
    if(horiz < 3){horizBox = 1;}
    else if (horiz < 6){horizBox = 2;}
    else horizBox = 3;
    
    if(vert < 3){vertBox = 1;}
    else if (vert < 6){vertBox = 2;}
    else vertBox= 3;
    
    int startH;
    int endH;
    int startV;
    int endV;
    
    switch (horizBox) {
        case 1:
            startH = 0;
            endH = 3;
            break;
        case 2:
            startH = 3;
            endH = 6;
            break;
        case 3:
            startH = 6;
            endH = 9;
            break;
    }

    switch (vertBox) {
        case 1:
            startV = 0;
            endV = 3;
            break;
        case 2:
            startV = 3;
            endV = 6;
            break;
        case 3:
            startV = 6;
            endV = 9;
            break;
    }
    
    for(int i = startH; i < endH; i++){
        for(int j = startV; j < endV; j++){
            
            if(puzzle[j][i] == guess){
                return false;
            }
        }
    }
        
    return true;
}

void guess(int puzzle[9][9]){
//    Get input from the user
    
    int horiz;
    int vert;
    int guess;

    cout << "Please enter the horizontal placement: ";
    cin >> horiz;
    horiz--;
    cout << "Please enter the vertical placement: ";
    cin >> vert;
    vert--;
    cout << "Please enter your guess: ";
    cin >> guess;

    cout << "\n";
//    Loop through the lists and print them.
//    checkVert(puzzle, vert);
    
    bool horizR = checkHoriz(puzzle, vert, guess);
    bool vertR =checkVert(puzzle, horiz, guess);
    bool boxR = checkBox(puzzle, horiz, vert, guess);
    
    if(puzzle[vert][horiz] != 0){
        cout << "I'm sorry. But that position is taken\n";
    }
    
    else{
        if(horizR & vertR){
//            Enter update array with element and call the print function.
            puzzle[vert][horiz] = guess;
            printPuzzle(puzzle);
        }
        else {
            cout << "Incorrect\n";
    
        };
        
        
    }
    
    
//    printPuzzle(puzzle);
    
}

int main(int argc, const char * argv[]) {
    
//  Creating the variables
    
    int puzzle[9][9] = { {4 , 0, 9, 8, 3, 2, 1, 7, 5},
        {0 , 0, 1, 0, 4, 0, 3, 0, 9},
        {0 , 3, 5, 0, 0, 6, 0, 0, 0},
        {0 , 0, 0, 0, 0, 3, 0, 9, 0},
        {6 , 9, 0, 0, 5, 7, 0, 0, 3},
        {0 , 0, 0, 0, 0, 4, 6, 2, 7},
        {9 , 2, 6, 0, 0, 8, 4, 5, 1},
        {1 , 5, 0, 0, 2, 0, 0, 3, 0},
        {0 , 0, 0, 0, 0, 1, 9, 0, 2},
    };
    
//    int puzzle[9][9] = {
//        {1 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 1, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//        {0 , 0, 0, 0, 0, 0, 0, 0, 0},
//    };
    
    printPuzzle(puzzle);
    
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(puzzle[i][j] == 0){
                guess(puzzle);
            }
        }
    }
    
    cout << "Thank you for playing";
    
    
    return 0;
}
