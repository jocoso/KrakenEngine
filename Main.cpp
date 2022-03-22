#include <iostream>
#include <string>

typedef std::string(*add_verd)(std::string);

class Controller {
    std::string(*func)(const char *);
    public:
        void add_input_map(std::string (*func)(const char *));
        std::string get_response(const char *input);
        void render(const char *input);
};

void Controller::add_input_map(std::string(*func)(const char *)) {
    this->func = func;
}

std::string Controller::get_response(const char *input) {
    puts("Get Response");
    return " ";
}

void Controller::render(const char *input) {
    puts(func(input).c_str());
}

std::string function1(const char *input) {
    if (input == "HI") {
        return "HELLO";
    }
}

int main(void) {

    Controller c;
    c.add_input_map(&function1);
    c.render("HI");

    return 0;
}