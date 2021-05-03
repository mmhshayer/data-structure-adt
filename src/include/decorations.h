#ifndef decorations_h
#define decorations_h
#include <iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "termcolor.hpp"

using namespace std;

int main();
void clear();
void returnToMenu();
void titleScreen();
void mainMenuText();

void clear()
{
    #ifdef _WIN32
    system("cls");
    #elif __APPLE__
    system("clear");
    #elif __linux
    system("clear");
    #endif
}

void returnToMenu()
{
    cout << "\n";
    system("pause");
    main();
}

void titleScreen(){
   ifstream f("files/Logo.txt"); //taking file as inputstream
   string str;
   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
   }
   cout << termcolor::red << str << termcolor::white;
}

void mainMenuText(){
    std::cout << termcolor::green << "    1. Insert\n";
    std::cout << termcolor::red << "    2. Remove\n";
    std::cout << termcolor::blue << "    3. Update Info\n";
    std::cout << termcolor::yellow << "    4. Inquire\n";
    std::cout << termcolor::magenta << "    5. Sort Lists\n";
    std::cout << termcolor::white << "    6. Exit\n";
}

void line()
{
    printf("|");
    for (int i=0;i<42;i++)
        printf("-");
    printf("|\n");
}

#endif