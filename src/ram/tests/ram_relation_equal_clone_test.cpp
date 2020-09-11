/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2020, The Souffle Developers. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file ram_relation_equal_clone_test.cpp
 *
 * Tests equal and clone function of Relation class.
 *
 ***********************************************************************/

#include "tests/test.h"

#include "RelationTag.h"
#include "ram/Relation.h"
#include <string>

namespace souffle::ram {

namespace test {

TEST(Relation, CloneAndEquals) {
    Relation a("A", 4, 1, {"a", "b", "c", "d"}, {"i", "i", "i", "i"}, RelationRepresentation::DEFAULT);
    Relation b("A", 4, 1, {"a", "b", "c", "d"}, {"i", "i", "i", "i"}, RelationRepresentation::DEFAULT);
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    Relation* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}

TEST(RelationRepresentation, CloneAndEquals) {
    Relation A("A", 1, 1, {"a"}, {"i"}, RelationRepresentation::DEFAULT);
    RelationReference a(&A);
    RelationReference b(&A);
    EXPECT_EQ(a, b);
    EXPECT_NE(&a, &b);

    RelationReference* c = a.clone();
    EXPECT_EQ(a, *c);
    EXPECT_NE(&a, c);
    delete c;
}
}  // end namespace test
}  // namespace souffle::ram
