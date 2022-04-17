/**
 *
 *  Solved.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Solved.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string Solved::Cols::_question_id = "question_id";
const std::string Solved::Cols::_user_id = "user_id";
const std::string Solved::primaryKeyName = "";
const bool Solved::hasPrimaryKey = false;
const std::string Solved::tableName = "solved";

const std::vector<typename Solved::MetaData> Solved::metaData_={
{"question_id","uint64_t","integer",8,0,0,1},
{"user_id","uint64_t","integer",8,0,0,1}
};
const std::string &Solved::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Solved::Solved(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["question_id"].isNull())
        {
            questionId_=std::make_shared<uint64_t>(r["question_id"].as<uint64_t>());
        }
        if(!r["user_id"].isNull())
        {
            userId_=std::make_shared<uint64_t>(r["user_id"].as<uint64_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            questionId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            userId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
    }

}

Solved::Solved(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            questionId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            userId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[1]].asUInt64());
        }
    }
}

Solved::Solved(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("question_id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["question_id"].isNull())
        {
            questionId_=std::make_shared<uint64_t>((uint64_t)pJson["question_id"].asUInt64());
        }
    }
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<uint64_t>((uint64_t)pJson["user_id"].asUInt64());
        }
    }
}

void Solved::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            questionId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            userId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[1]].asUInt64());
        }
    }
}

void Solved::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("question_id"))
    {
        dirtyFlag_[0] = true;
        if(!pJson["question_id"].isNull())
        {
            questionId_=std::make_shared<uint64_t>((uint64_t)pJson["question_id"].asUInt64());
        }
    }
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<uint64_t>((uint64_t)pJson["user_id"].asUInt64());
        }
    }
}

const uint64_t &Solved::getValueOfQuestionId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(questionId_)
        return *questionId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Solved::getQuestionId() const noexcept
{
    return questionId_;
}
void Solved::setQuestionId(const uint64_t &pQuestionId) noexcept
{
    questionId_ = std::make_shared<uint64_t>(pQuestionId);
    dirtyFlag_[0] = true;
}

const uint64_t &Solved::getValueOfUserId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(userId_)
        return *userId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Solved::getUserId() const noexcept
{
    return userId_;
}
void Solved::setUserId(const uint64_t &pUserId) noexcept
{
    userId_ = std::make_shared<uint64_t>(pUserId);
    dirtyFlag_[1] = true;
}

void Solved::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Solved::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "question_id",
        "user_id"
    };
    return inCols;
}

void Solved::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getQuestionId())
        {
            binder << getValueOfQuestionId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getUserId())
        {
            binder << getValueOfUserId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Solved::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    return ret;
}

void Solved::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getQuestionId())
        {
            binder << getValueOfQuestionId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getUserId())
        {
            binder << getValueOfUserId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Solved::toJson() const
{
    Json::Value ret;
    if(getQuestionId())
    {
        ret["question_id"]=(Json::UInt64)getValueOfQuestionId();
    }
    else
    {
        ret["question_id"]=Json::Value();
    }
    if(getUserId())
    {
        ret["user_id"]=(Json::UInt64)getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    return ret;
}

Json::Value Solved::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getQuestionId())
            {
                ret[pMasqueradingVector[0]]=(Json::UInt64)getValueOfQuestionId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getUserId())
            {
                ret[pMasqueradingVector[1]]=(Json::UInt64)getValueOfUserId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getQuestionId())
    {
        ret["question_id"]=(Json::UInt64)getValueOfQuestionId();
    }
    else
    {
        ret["question_id"]=Json::Value();
    }
    if(getUserId())
    {
        ret["user_id"]=(Json::UInt64)getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    return ret;
}

bool Solved::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("question_id"))
    {
        if(!validJsonOfField(0, "question_id", pJson["question_id"], err, true))
            return false;
    }
    else
    {
        err="The question_id column cannot be null";
        return false;
    }
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(1, "user_id", pJson["user_id"], err, true))
            return false;
    }
    else
    {
        err="The user_id column cannot be null";
        return false;
    }
    return true;
}
bool Solved::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Solved::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("question_id"))
    {
        if(!validJsonOfField(0, "question_id", pJson["question_id"], err, false))
            return false;
    }
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(1, "user_id", pJson["user_id"], err, false))
            return false;
    }
    return true;
}
bool Solved::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Solved::validJsonOfField(size_t index,
                              const std::string &fieldName,
                              const Json::Value &pJson,
                              std::string &err,
                              bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}