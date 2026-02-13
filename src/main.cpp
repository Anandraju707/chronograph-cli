#include <iostream>
#include <string>
#include "HistoryGraph.hpp"

int main() {
    HistoryGraph history;
    std::string line;

    std::cout << "Text Editor CLI (type 'exit' to quit)\n";

    while(true){
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "exit") {
            break;
        } else if (line == "undo") {
            if (!history.undo())
                std::cout << "Nothing to undo\n";
        } else if (line == "redo") {
            if (!history.redo())
                std::cout << "Nothing to redo\n";
        } else if (line == "root") {
            history.backToRoot();
        } else if (line == "front") {
            history.backToFront();
        } else if (line == "current") {
            std::cout << history.getCurrentState().getText() << "\n";
        } else if (line == "history") {
            history.printHistory();
        } else if (line.size() >= 4 && line.substr(0, 4) == "add ") {
            std::string text = line.substr(4);
            history.addState(TextState(text));
        } else {
            std::cout << "Command does not exist\n";
        }
    }
    

    return 0;
}
