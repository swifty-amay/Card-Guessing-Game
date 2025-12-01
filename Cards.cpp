using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>

class Card1{
    private:
        vector<string> s1= {"Honest", "Alloys", "Beasts", "Duffer"};
    public:
        string showString(){
            random_device rd;
            mt19937 g(rd());
            shuffle(s1.begin(), s1.end(), g);
            return s1[0];
        }
        bool is_word_in_card1(string cd){
            for(string c: s1){
                if (cd == showString()){
                    return true;
                }
            }
            return false;
        }
    
}c1;

class Card2{
    private:
        vector<string> s2 = {"Knowledge", "Acceptive", "Dejection", "Carbonize", "Delicious"};
    public:
        string showString(){
            random_device rd;
            mt19937 g(rd());
            shuffle(s2.begin(), s2.end(), g);
            return s2[0];
        }
        bool is_word_in_card2(string cd){
            for(string c: s2){
                if (cd == showString()){
                    return true;
                }
            }
            return false;
        }    
    
}c2;

class Card3{
    private:
        vector<string> s3 = {"Punctual", "Elephant", "Bloggers", "Mountain"};
    public:
        string showString(){
            random_device rd;
            mt19937 g(rd());
            shuffle(s3.begin(), s3.end(), g);
            return s3[0];
        }
        bool is_word_in_card3(string cd){
            for(string c: s3){
                if (cd == showString()){
                    return true;
                }
            }
            return false;
        }
    
}c3;

class User{
    private:
        string name;
    public:
        string get_name(){
            string name;
            cout<<"Enter your name: ";
            getline(cin,this->name);
            name = this->name;
            return name;
        }
}u;

vector<string> words = {c1.showString(), c2.showString(), c3.showString()};