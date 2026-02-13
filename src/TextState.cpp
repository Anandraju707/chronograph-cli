#include "TextState.hpp"

TextState::TextState(const std::string& text)
    : text_(text) {}

const std::string& TextState::getText() const {
    return text_;
}
