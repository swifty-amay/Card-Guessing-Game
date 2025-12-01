using namespace std;
#include <iostream>
#include "Functions.cpp"
#include <thread>
#include <chrono>
#include <cstdlib>

int main(){
    int option, cardNumber;
    char ch;
    get_userInfo();
    cout<<"\n";
    while(1){
    show_Menu();
    cout<<"\nEnter your option: ";
    cin>>option;
    this_thread::sleep_for(chrono::seconds(1));
    switch (option){
        case 1:
            instructions();
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"\nAre you ready?(Press Y)";
            cin>>ch;
            cout<<"\nHere we go!!!";
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"\nHere are the cards:\n";
            this_thread::sleep_for(chrono::seconds(1));
            showCard();
            this_thread::sleep_for(chrono::seconds(5));
            cout<<"\nShowing the clue👽\n";
            this_thread::sleep_for(chrono::seconds(1));
            show_tables();
            cout<<"\nYou have 5 seconds to go through this!\n\n\n";
            this_thread::sleep_for(chrono::seconds(5));
            system("clear");
            cout<<"OK, so here is your question -> I am a card which belongs to a category, my keyword is "<<generate_randomWords()<<".\nI am Card Number???\n\n";
            cin>>cardNumber;
            cout<<"\nThinking.....\n\n";
            this_thread::sleep_for(chrono::seconds(3));
            check_Answer(cardNumber);
            break;
        case 2:
            storeScore();
            return 0;
        case 3:
            string scoreShow;
            scoreShow = getLastLine("score.txt");
            if (scoreShow == ""){
                cout<<"\n Sorry, no last score to show\n\n";
            }else{
                cout<<"Player  Score ->";
                cout<<scoreShow<<"\n\n\n";
            }
            
            break;
        }
    }
    return 0;
}

