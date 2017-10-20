//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_DUSTBINTEST_HPP
#define WASTE_DUSTBINTEST_HPP

#include "gtest/gtest.h"
#include "../src/dustbin/Dustbin.h"


TEST(DustbinTest, members) {
    Dustbin bin = Dustbin("black");
    EXPECT_EQ(bin.getColor(), "black");
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(),0);
}

TEST(DustbinTest, Garbage) {
    Dustbin bin = Dustbin();
    Garbage waste = Garbage("waste");
    EXPECT_EQ(waste.getName(), "waste");
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getHouseWasteAmount(), 1);
}

TEST(DustbinTest, PaperGarbage) {
    Dustbin bin = Dustbin();
    PaperGarbage paper = PaperGarbage("paper");
    EXPECT_EQ(paper.getName(), "paper");
    EXPECT_EQ(paper.squeezeState(), false);
    EXPECT_ANY_THROW(bin.throwOutPaperGarbage(paper));
    paper.squeeze();
    EXPECT_EQ(paper.squeezeState(), true);
    EXPECT_NO_THROW(bin.throwOutPaperGarbage(paper));
    EXPECT_EQ(bin.getPaperGarbageAmount(), 1);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
}

TEST(DustbinTest, PlasticGarbage) {
    Dustbin bin = Dustbin();
    PlasticGarbage plastic = PlasticGarbage("plastic");
    EXPECT_EQ(plastic.getName(), "plastic");
    EXPECT_EQ(plastic.cleanState(), false);
    EXPECT_ANY_THROW(bin.throwOutPlasticGarbage(plastic));
    plastic.clean();
    EXPECT_EQ(plastic.cleanState(), true);
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 1);
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
}

TEST(DustbinTest, emptyContent) {
    Dustbin bin = Dustbin();
    PlasticGarbage plastic = PlasticGarbage("plastic");
    PaperGarbage paper = PaperGarbage("paper");
    Garbage waste = Garbage("waste");
    paper.squeeze();
    plastic.clean();
    EXPECT_NO_THROW(bin.throwOutPaperGarbage(paper));
    EXPECT_NO_THROW(bin.throwOutPlasticGarbage(plastic));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    EXPECT_NO_THROW(bin.throwOutGarbage(waste));
    bin.emptyContents();
    EXPECT_EQ(bin.getPaperGarbageAmount(), 0);
    EXPECT_EQ(bin.getPlasticGarbageAmount(), 0);
    EXPECT_EQ(bin.getHouseWasteAmount(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


#endif //WASTE_DUSTBINTEST_HPP
