/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2017, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file LogSize.h
 *
 ***********************************************************************/

#pragma once

#include "ram/Node.h"
#include "ram/Relation.h"
#include "ram/RelationStatement.h"
#include "souffle/utility/MiscUtil.h"
#include "souffle/utility/StreamUtil.h"
#include "souffle/utility/StringUtil.h"
#include <memory>
#include <ostream>
#include <string>
#include <utility>

namespace souffle::ram {

/**
 * @class LogSize
 * @brief Log relation size and a logging message.
 */
class LogSize : public RelationStatement {
public:
    LogSize(Own<RelationReference> relRef, std::string message)
            : RelationStatement(std::move(relRef)), message(std::move(message)) {}

    /** @brief Get logging message */
    const std::string& getMessage() const {
        return message;
    }

    LogSize* clone() const override {
        return new LogSize(souffle::clone(relationRef), message);
    }

protected:
    void print(std::ostream& os, int tabpos) const override {
        os << times(" ", tabpos) << "LOGSIZE " << getRelation().getName();
        os << " TEXT "
           << "\"" << stringify(message) << "\"";
        os << std::endl;
    }

    bool equal(const Node& node) const override {
        const auto& other = static_cast<const LogSize&>(node);
        return RelationStatement::equal(other) && message == other.message;
    }

    /** logging message */
    std::string message;
};

}  // namespace souffle::ram
