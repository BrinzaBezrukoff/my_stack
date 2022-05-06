#include <iostream>

#include "stack/Stack.h"


int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.pop();
    s.push(30);

    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;

    return 0;
}
