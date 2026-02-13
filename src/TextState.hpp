#pragma once

#ifndef TextState_H
#define TextState_H

#include <string>

// immutable value object representing a 'snapshot' of the text document
// each HistoryGraph node owns one TextState 
class TextState {
public:
    // Construct a text state from full document text
    explicit TextState(const std::string& text);

    // Access the document text
    const std::string& getText() const;

private:
    std::string text_;
};

#endif