//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_DUSTBIN_H
#define WASTE_DUSTBIN_H

#include <string>
#include <vector>

#include "../../src/garbage/Garbage.hpp"
#include "../../src/garbage/PaperGarbage.hpp"
#include "../../src/garbage/PlasticGarbage.hpp"

#include "DustbinContentError.hpp"

class Dustbin {

public:
    Dustbin();
    explicit Dustbin(std::string);

    void throwOutGarbage(Garbage&);
    void throwOutPaperGarbage(PaperGarbage&);
    void throwOutPlasticGarbage(PlasticGarbage&);
    void emptyContents();

    const std::string &getColor() const;
    unsigned long getPaperGarbageAmount() const;
    unsigned long getPlasticGarbageAmount() const;
    unsigned long getHouseWasteAmount() const;

    virtual ~Dustbin();

private:
    const std::string color;
    std::vector<PaperGarbage> paperContent;
    std::vector<PlasticGarbage> plasticContent;
    std::vector<Garbage> houseWasteContent;

};


#endif //WASTE_DUSTBIN_H
