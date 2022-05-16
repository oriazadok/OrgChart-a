
#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <sstream>
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Illegal Input") {

    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO")
        .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI"));     // Now the VP_BI is subordinate to the COO

    CHECK_THROWS(organization.add_sub("QQQ", "CTO"));
    CHECK(organization._root->_val == "CEO");
    CHECK_NE(organization._root->_val,  "ceo");

    CHECK(organization._root->_sub[0]->_val == "CTO");
    CHECK(organization._root->_sub[1]->_val == "CFO");
    CHECK(organization._root->_sub[2]->_val == "COO");

    // CHECK(organization._root->_sub[0]->_sub[0]->_val == "VP_SW");
    // CHECK(organization._root->_sub[2]->_sub[0]->_val == "VP_SW");


    
   
}

TEST_CASE("BUILD TREE") {
    OrgChart a;
    
    CHECK_NOTHROW(a.add_root("CEO"));
    string s1 = a._root->_val;
    CHECK_EQ(s1, "CEO");

    CHECK_NOTHROW(a.add_root("ORIA"));
    string s2 = a._root->_val;
    CHECK_EQ(s2, "ORIA");

    
    CHECK_NOTHROW(a.add_sub("ORIA", "ZADOK"));
    CHECK_NOTHROW(a.add_sub("ORIA", "ROI"));
    CHECK_NOTHROW(a.add_sub("ORIA", "CAPARA"));
    CHECK_EQ(a._root->_sub[0]->_val, "ZADOK");
    CHECK_EQ(a._root->_sub[1]->_val, "ROI");
    CHECK_EQ(a._root->_sub[2]->_val, "CAPARA");

    CHECK_THROWS(a._root->_sub[0]->_sub.at(4));
    OrgChart::Node n1("BAR");
    CHECK_NOTHROW(a._root->_sub[0]->_sub.push_back(&n1));
    CHECK_EQ(a._root->_sub[0]->_sub[0]->_val, "BAR");
    CHECK_NE(a._root->_sub[0]->_sub[0]->_val, "ssss");

    CHECK_THROWS(a._root->_sub[0]->_sub.at(4));
    OrgChart::Node n2("ANTON");
    CHECK_NOTHROW(a._root->_sub[0]->_sub.push_back(&n2));
    CHECK_EQ(a._root->_sub[0]->_sub[1]->_val, "ANTON");
    CHECK_EQ(a._root->_sub[0]->_sub[1]->_val, "ANTON");

    CHECK_THROWS(a._root->_sub[1]->_sub.at(4));
    OrgChart::Node n3("ITAMAR");
    CHECK_NOTHROW(a._root->_sub[1]->_sub.push_back(&n3));
    CHECK_EQ(a._root->_sub[1]->_sub[0]->_val, "ITAMAR");
    CHECK_EQ(a._root->_sub[1]->_sub[0]->_val, "ITAMAR");

    CHECK_THROWS(a._root->_sub[2]->_sub.at(4));
    OrgChart::Node n4("SUB");
    CHECK_NOTHROW(a._root->_sub[2]->_sub.push_back(&n4));
    CHECK_EQ(a._root->_sub[2]->_sub[0]->_val, "SUB");
    CHECK_EQ(a._root->_sub[2]->_sub[0]->_val, "SUB");
    
}


