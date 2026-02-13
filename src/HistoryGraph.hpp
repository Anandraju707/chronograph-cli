#pragma once
#ifndef Historygraph_H
#define Historygraph_H

#include <memory>
#include <vector>
#include "TextState.hpp"

// HistoryGraph owns and manages the document that operates on
// non-linear memory using a tree structure
class HistoryGraph {
public:
    HistoryGraph();

    //core operations
    void addState(const TextState& state);
    bool undo();
    bool redo();
    //inspection tools
    bool backToRoot();
    bool backToFront();
    void printHistory();

    const TextState& getCurrentState() const;

private:
    // object used to own and traverse between TextStates allowing for branching timelines
    struct Node {
        TextState state;
        Node* parent;
        std::vector<std::unique_ptr<Node>> children;
        int activeChildIndex = -1;

        
        Node(const TextState& s, Node* p)
            : state(s), parent(p) {}
    };

    std::unique_ptr<Node> root_;
    Node* current_;
    Node* front_;
};

#endif