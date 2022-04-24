#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

#include <drogon/HttpAppFramework.h>
#include <drogon/orm/Mapper.h>
#include "../models/models.hpp"

#include "../main.hpp"

namespace quiz {
class Option {
public:
  int id;
  std::string text;

  Option(drogon_model::sqlite3::Option &ormOption) {
    id = ormOption.getValueOfId();
    text = ormOption.getValueOfText();
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

  Question(drogon_model::sqlite3::Question &ormQuestion) {
    id = ormQuestion.getValueOfId();
    text = ormQuestion.getValueOfText();

    const uint64_t optionIds[4] = {
        ormQuestion.getValueOfAnswerid(), ormQuestion.getValueOfOption2id(),
        ormQuestion.getValueOfOption3id(), ormQuestion.getValueOfOption4id()};

    for (auto val : optionIds) {
      auto ormOption = drogon::orm::Mapper<drogon_model::sqlite3::Option>(
                           drogon::app().getDbClient())
                           .findByPrimaryKey(val);

      options.push_back(Option(ormOption));
    }

    std::shuffle(options.begin(), options.end(), randomEngine);
  }
};

/** An object that represents an answer to a question.*/
class Answer {
public:
  int id;
  int questionId;
  std::string questionText;
  std::string text;

  Answer(drogon_model::sqlite3::Question &ormQuestion) {
    id = ormQuestion.getValueOfAnswerid();
    questionId = ormQuestion.getValueOfId();
    questionText = ormQuestion.getValueOfText();

    // the Option object that represents "Answer"
    auto tempOption = drogon::orm::Mapper<drogon_model::sqlite3::Option>(drogon::app().getDbClient()).findByPrimaryKey(id);
    text = tempOption.getValueOfText();
  }
};
} // namespace quiz