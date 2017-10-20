//
// Created by jeannie on 2017.10.20..
//

#include <string>


class Garbage {

public:
    explicit Garbage(std::string name) : name(name){}

    virtual ~Garbage() {
        std::cout << "You destroyed a Garbage." << std::endl;
    }

    const std::string& getName() const {
        return name;
    }

private:
    const std::string name;

};
