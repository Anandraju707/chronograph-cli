#include "HistoryGraph.hpp"
#include <iostream>

// constructor
HistoryGraph::HistoryGraph() {
    root_ = std::make_unique<Node>(TextState("<ROOT>"), nullptr);
    current_ = root_.get();
    front_ = root_.get();
}

// adds a new state as a child of the current node 
// whether it's a new branch or a continued path
void HistoryGraph::addState(const TextState& state) {
    auto newNode = std::make_unique<Node>(state, current_);
    current_->children.push_back(std::move(newNode));
    current_->activeChildIndex = static_cast<int>(current_->children.size()) - 1;
    current_ = current_->children.back().get();
    front_ = current_;

}

// moves to the parent state, preserving active branch information
bool HistoryGraph::undo() {
    if (current_->parent == nullptr) {
        return false;
    }
    Node* child = current_;
    current_ = current_->parent;

    for (size_t i = 0; i < current_->children.size(); ++i) {
        if (current_->children[i].get() == child) {
            current_->activeChildIndex = static_cast<int>(i);
            break;
        }
    }

    return true;
}

// moves forward along the active branch 
bool HistoryGraph::redo() {
    if (current_->children.empty()) {
        return false;
    }
    current_ = current_->children[current_->activeChildIndex].get();
    return true;
}

// returns current 'snapshot' to be able to print out if needed
const TextState& HistoryGraph::getCurrentState() const {
    return current_->state;
}

// jumps directly to the root regardless of position
bool HistoryGraph::backToRoot(){
    if (current_->parent == nullptr){
        return false;
    }
    while(current_->parent != nullptr){
        current_ = current_->parent;
    }
    return true;
}

// jumps directly back to the front regardless of current postition
bool HistoryGraph::backToFront(){
    while(current_ != front_){
        if (!redo()) {
            return false; 
        }
    }
    return true;
}

// prints out the full path that the current pointer is pointing to
void HistoryGraph::printHistory(){
    Node* temp_current = current_;
    while(temp_current->parent != nullptr){
        temp_current = temp_current->parent;
    }
    while(true){
        std::cout << temp_current->state.getText() << std::endl;

        if (temp_current == front_) {
            break;
        }

        if (temp_current->activeChildIndex < 0) {
            break; 
        }
        temp_current = temp_current->children[temp_current->activeChildIndex].get();
    }
}