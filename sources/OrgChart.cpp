// #include <vector>
#include "OrgChart.hpp"


namespace ariel {
    
    OrgChart::OrgChart() {
        this->_root = nullptr;
    }
    
    OrgChart::~OrgChart() {
        // delete this->_root;
    }

    OrgChart& OrgChart::add_root(const string r) {
        if (this->_root == nullptr) {
            this->_root = new Node(r);
        } else {
            this->_root->_val = r;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(string sup, string sub) {
        this->_root->_sub.push_back(new Node(sub));
        this->_root->_sub.push_back(new Node(sub));
        this->_root->_sub.push_back(new Node(sub));

        return *this;
    }

    // Oriterator OrgChart::begin() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::end() {
    //     return iterator{nullptr};
    // }

    // iterator OrgChart::begin_level_order() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::end_level_order() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::begin_reverse_order() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::reverse_order() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::begin_preorder() {
    //     return iterator{nullptr};
    // }
    // iterator OrgChart::end_preorder() {
    //     return iterator{nullptr};
    // }

    
    ostream& operator<< (ostream& output, const OrgChart& orgChart) {
        return output;
    }
}