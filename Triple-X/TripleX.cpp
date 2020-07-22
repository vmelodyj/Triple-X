#include <iostream>
#include <ctime>
using namespace std;
void PrintIntro(int Difficulty){
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room...\nEnter the correct code to continue...\n\n" << endl;

}

bool PlayGame(int Difficulty){

    PrintIntro(Difficulty);
    const int Level {};

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum {CodeA+CodeB+CodeC};
    const int CodeProduct {CodeA * CodeB * CodeC};

    cout << "+ There are 3 numbers in the code";
    cout << "\n+ The codes add-up to: " << CodeSum;
    cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int InA, InB, InC;
    cin >> InA >> InB >> InC;

    int InSum {InA + InB + InC};
    int InProduct {InA * InB * InC};

    if (CodeSum == InSum && CodeProduct == InProduct) {
        cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    } else {
        cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }


    cout << endl;


}

int main(){
    srand(time(nullptr));

    int LevelDiff {1};
    const int MaxDiff {5};

    while (LevelDiff <= MaxDiff){
        bool Complete = PlayGame(LevelDiff);
        cin.clear();
        cin.ignore();

        if (Complete) {
            LevelDiff++;
        }
    }
    cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
};