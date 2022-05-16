#include <iostream>
#include <string>
#include <vector>

using namespace std;


namespace ariel {
    
    class OrgChart {
        public:
            class Node {
                public:
                    string _val;
                    vector<Node*> _sub;
                    Node *_next;
                    Node(string str) 
                        :_val(str), _sub(), _next(nullptr) {}
            };
            
            struct Node *_root;
        public:
            OrgChart();
            ~OrgChart();

            OrgChart& add_root(const string r);
            OrgChart& add_sub(string sup, string sub);

            friend ostream& operator<< (ostream& output, const OrgChart& orgChart);

            class level_order_iterator {
                private:
                    struct Node *current;
                
                public:
                    level_order_iterator(struct Node *ptr = nullptr)
                        : current(ptr) {

                    }

                    string& operator*() const {
                        return current->_val;
                    }

                    string* operator->() const {
                        return &(current->_val);
                    }

                    // ++i;
                    level_order_iterator& operator++() {
                        //++pointer_to_current_node;
                        current = current->_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    level_order_iterator operator++(int) {
                        level_order_iterator tmp= *this;
                        current = current->_next;
                        return tmp;
                    }

                    bool operator==(const level_order_iterator& rhs) const {
                        return current == rhs.current;
                    }

                    bool operator!=(const level_order_iterator& rhs) const {
                        return current != rhs.current;
                    }

            };  // END OF CLASS LEVEL_ORDER_ITERATOR

            class reverse_level_order_iterator {
                private:
                    struct Node *current;
                
                public:
                    reverse_level_order_iterator(struct Node *ptr = nullptr)
                        : current(ptr) {

                    }

                    string& operator*() const {
                        return current->_val;
                    }

                    string* operator->() const {
                        return &(current->_val);
                    }

                    // ++i;
                    reverse_level_order_iterator& operator++() {
                        //++pointer_to_current_node;
                        current = current->_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    reverse_level_order_iterator operator++(int) {
                        reverse_level_order_iterator tmp= *this;
                        current = current->_next;
                        return tmp;
                    }

                    bool operator==(const reverse_level_order_iterator& rhs) const {
                        return current == rhs.current;
                    }

                    bool operator!=(const reverse_level_order_iterator& rhs) const {
                        return current != rhs.current;
                    }

            };  // END OF CLASS reverse_level_order_iterator

            class preorder_iterator {
                private:
                    struct Node *current;
                
                public:
                    preorder_iterator(struct Node *ptr = nullptr)
                        : current(ptr) {

                    }

                    string& operator*() const {
                        return current->_val;
                    }

                    string* operator->() const {
                        return &(current->_val);
                    }

                    // ++i;
                    preorder_iterator& operator++() {
                        //++pointer_to_current_node;
                        current = current->_next;
                        return *this;
                    }

                    // i++;
                    // Usually iterators are passed by value and not by const& as they are small.
                    preorder_iterator operator++(int) {
                        preorder_iterator tmp= *this;
                        current = current->_next;
                        return tmp;
                    }

                    bool operator==(const preorder_iterator& rhs) const {
                        return current == rhs.current;
                    }

                    bool operator!=(const preorder_iterator& rhs) const {
                        return current != rhs.current;
                    }

            };  // END OF CLASS preorder_iterator


            level_order_iterator begin() {
                // begin(0)
                return level_order_iterator{nullptr};
            }
            level_order_iterator end() {
                return level_order_iterator{nullptr};
            }

            level_order_iterator begin_level_order() {
                return level_order_iterator{nullptr};
            }
            level_order_iterator end_level_order() {
                return level_order_iterator{nullptr};
            }


            reverse_level_order_iterator begin_reverse_order() {
                return reverse_level_order_iterator{nullptr};
            }
            reverse_level_order_iterator reverse_order() {
                return reverse_level_order_iterator{nullptr};
            }


            preorder_iterator begin_preorder() {
                return preorder_iterator{nullptr};
            }
            preorder_iterator end_preorder() {
                return preorder_iterator{nullptr};
            }


    };

    // ostream& operator<< (ostream& output, const OrgChart& orgChart) {
    //     return output;
    // }
   
}