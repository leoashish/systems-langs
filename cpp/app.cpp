// Simple CLI app: todo list
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> todos;
    std::string cmd;
    std::cout << "Commands: add <text>, list, quit\n";
    while (std::cin >> cmd) {
        if (cmd == "add") {
            std::string text;
            std::getline(std::cin, text);
            if (!text.empty() && text[0] == ' ') text.erase(0, 1);
            todos.push_back(text);
            std::cout << "added\n";
        } else if (cmd == "list") {
            for (size_t i = 0; i < todos.size(); ++i)
                std::cout << i + 1 << ". " << todos[i] << "\n";
        } else if (cmd == "quit") {
            break;
        } else {
            std::cout << "unknown\n";
        }
    }
    return 0;
}
