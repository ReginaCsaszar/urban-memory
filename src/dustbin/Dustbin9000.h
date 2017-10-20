//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_DUSTBIN9000_H
#define WASTE_DUSTBIN9000_H


#include "Dustbin.h"
#include "../../src/garbage/BottleCap.hpp"
#include "BottleCapException.hpp"

class Dustbin9000 : public Dustbin {

public:
    Dustbin9000(std::string);
    Dustbin9000();

    virtual ~Dustbin9000();

    void throwOutMetalGarbage(Garbage);
    void throwOutBottlecap(BottleCap);

    void emptyContents();

    unsigned long getMetalGarbageAmount() const;
    unsigned long getBottlecapAmount() const;

private:
    std::vector<Garbage> metalContent;
    std::vector<BottleCap> pinkBottleCaps;
};

#endif //WASTE_DUSTBIN9000_H
