using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Cards.cpp"
#include <fstream>
#include <string>
#include <time.h>
string playerName;
int score = 0, randomNumber = 0;
void get_userInfo(){
    playerName = u.get_name();
}

void show_Menu(){
    cout<<"\t1. I want to play (Press 1)."<<endl;
    cout<<"\t2. I want to exit (Press 2)."<<endl;
    cout<<"\t3. I want to know the last score (Press 3)."<<endl;
}

void instructions(){
    
    cout<<"\n\nHere are the general instructions to play the game:"<<endl<<endl;;
    cout<<"\n1. You will be shown 3 cards."<<endl;
    cout<<"\n2. Each card will have it's own identifier."<<endl;
    cout<<"\n3. You have to see and memorise the identifier."<<endl;
    cout<<"\n4. You, then will be shown some data that may or may not be used in the final answer\n"<<
             "(It's totally upon your decision whether you have to memorise it or not👀)."<<endl;
    cout<<"\n5. You then will be given the identifier and you have to name the card."<<endl;
    cout<<"\n6. If guessed correct then Congratulation🥳 your recalling power is OK but if not‼️"<<
             "then it's the correct time to think about it!!!\n\n"<<endl;
    cout<<"\n7. If you think that that particular word is not in any card, then press any number except 1, 2, 3"<<endl;
}

void show_tables(){
    int max = 100, min = 20;
    srand(time(NULL));                              //rand() = produce pseudo-random numbers.
                                                    //srand(seed) = choose the starting point of the sequence.
                                                    //srand(time(NULL)); = make the sequence different on each run.
    randomNumber = rand() % (max - min + 1) + min;
    int i = 1;
    
    cout<<"Do you know the remainder when "<<randomNumber<<" is divided by first 20 natural numbers?"<<"‼️";
    cout<<"\nHere we go, take a look at it:"<<endl<<endl;
    while(i<=9){
        cout<<"\t\t"<<randomNumber<<"\t % \t "<<i<<"    =      "<<(randomNumber%i)<<endl;
        i++;
    }
    while(i<=20){
        cout<<"\t\t"<<randomNumber<<"\t % \t"<<i<<"    =      "<<(randomNumber%i)<<endl;
        i++;
    }
    
}
// int main(){
//     show_tables();
//     cout<<randomNumber;
// }

void showCard(){
    cout<<"  ---------------------------- \t\t\t ---------------------------- \t\t\t ---------------------------- "<<endl;
    cout<<" |           Card 1           |\t\t\t|           Card 2           |\t\t\t|           Card 3           |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" | Hey I'm card 1.            |\t\t\t| Hey I'm card 2.            |\t\t\t| Hey I'm card 3.            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" | Remember my identifier...  |\t\t\t| Remember my identifier...  |\t\t\t| Remember my identifier...  |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |         "<<"\""<<c1.showString()<<"\""<<"           |\t\t\t|       "<<"\""<<c2.showString()<<"\""<<"          |\t\t\t|        "<<" \""<<c3.showString()<<"\""<<"         |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<" |                            |\t\t\t|                            |\t\t\t|                            |"<<endl;
    cout<<"  ---------------------------- \t\t\t ---------------------------- \t\t\t ---------------------------- "<<endl;
}

void storeScore(){
    ofstream file("score.txt", ios::app);
    if (!file){
        cout<<"\nError opening the file";
    }
    file<<playerName<<" "<<score<<"\n";
    file.close();
}

void readScore(){
    ifstream file("score.txt", ios::in);
    if (!file) {
        cerr << "File not found!\n";
    }

    file.seekg(0, ios::end);       // go to EOF
    int pos = file.tellg();        // get position at end
    string lastLine = "";
    char ch;

    // Read backwards until newline or start of file
    for (int i = pos - 1; i >= 0; i--) {
        file.seekg(i);
        file.get(ch);
        if (ch == '\n') break;     // stop at newline
        lastLine = ch + lastLine;  // prepend char to build line
    }
    cout<<lastLine;

    file.close();
}
string getLastLine(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file\n";
        return "";
    }

    string line;
    string lastLine;
    while (getline(file, line)) {
        lastLine = line; // overwrite lastLine each time
    }
    file.close();
    return lastLine;
}
string generate_randomWords(){
    random_device rd;
    mt19937 g(rd());
    shuffle(words.begin(), words.end(), g);
    return words[0];
}

void check_Answer(int n){
    switch(n){
        case 1:
            if(c1.is_word_in_card1(words[0])){
                cout<<"Whooaaaa!!!! You guessed it right🥳🥳🤩.\nWell Done\n";
                score++;
                cout<<"\nYour current score is "<<score;
                cout<<"\n\n";
            }else{
                cout<<"\nOoops! Wrong answer\n Better luck next time\n";
                score --;
            }
            storeScore();
            break;
        case 2:
            if(c2.is_word_in_card2(words[0])){
                cout<<"Whooaaaa!!!! You guessed it right🥳🥳🤩.\nWell Done\n";
                score++;
                cout<<"Your current score is "<<score;
                cout<<"\n\n";
            }else{
                cout<<"\nOoops! Wrong answer\n Better luck next time\n\n";
                score --;
            }
            storeScore();
            break;
        case 3:
            if(c3.is_word_in_card3(words[0])){
                cout<<"Whooaaaa!!!! You guessed it right🥳🥳🤩.\nWell Done";
                score++;
                cout<<"\nYour current score is "<<score;
                cout<<"\n\n";
            }else{
                cout<<"\nOoops! Wrong answer\n Better luck next time\n\n";
                score --;
            }
            storeScore();
            break;
        default:
            cout<<"Whooaaaa!!!! You guessed it right🥳🥳🤩.\nWell Done\n";
            score++;
            cout<<"\nYour current score is "<<score;
            cout<<"\n\n";
            storeScore();
            break;
    }
}

