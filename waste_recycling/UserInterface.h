//
// Created by jeannie on 2017.10.22..
//

#ifndef DUSTBIN_USERINTERFACE_H
#define DUSTBIN_USERINTERFACE_H

#include <bits/unique_ptr.h>
#include <iostream>
#include "dustbin/Dustbin9000.h"

class UserInterface {

public:
    UserInterface() = default;
    ~UserInterface() = default;

    void process();

private:

    std::unique_ptr<Dustbin> bin;

    int selectedMenu = 0;
    std::string givenString = "";

    void showCarret();
    void showBinOptions();
    void showGarbageOptions();
    void readInputString(std::string type);
    void readInputInt();

    void dustbinMenu();
    void garbageMenu();

    void handleGarbageMenu();
    void handlePaperGarbageMenu();
    void handlePlasticGarbageMenu();
    void handleMetalGarbageMenu();
    void handleBottleCapMenu();
};


#endif //DUSTBIN_USERINTERFACE_H
