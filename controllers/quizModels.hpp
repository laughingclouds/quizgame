#include <iostream>
#include <vector>

namespace quiz {
class Option {
public:
  int id;
  std::string text;

  Option(int _id, std::string _text) {
    id = _id;
    text = _text;
  }
};

/** Custom Question Class that holds a question and its relevant information*/
class Question {
public:
  int id;
  std::string text;
  // Find a way to randomly arrange the elements
  // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
  std::vector<Option> options;

  Question(int _id, std::string _text, std::vector<Option> _options) {
    id = _id;
    text = _text;
    options = _options;
  }
};
} // namespace quiz