#include <iostream>
#include <string>
#include <vector>
#include <list>
 #include <functional>
 //problem1
int hash_string(const std::string& str, int n) {
    int hash = 0;
     for (char c : str) {
        int value;
        if (c >= '0' && c <= '9') {
             value = c - '0';
        }
        else if (c >= 'A' && c <= 'Z') {
             value = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'z') {
             value = c - 'a' + 36;
        }
        else {
             value = 0;
        }

        hash = (hash + value) % n;
    }

    return hash;
}
//problem2
int hash_block(const std::string& block) {
    int hash = 0;
    for (char c : block) {
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        }
        else if (c >= 'A' && c <= 'Z') {
            value = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'z') {
            value = c - 'a' + 36;
        }
        else {
            value = 0;
        }
        hash = (hash * 62 + value);   
    }
    return hash;
}

 int hash_string_folding(const std::string& str, int n) {
    int block_size = 4;
    int hash = 0;

    for (size_t i = 0; i < str.length(); i += block_size) {
        std::string block = str.substr(i, block_size);
        hash += hash_block(block);
    }

    return hash % n;
}
 //problem3
 int hash_block(const std::string& block) {
     int hash = 0;
     for (char c : block) {
         int value;
         if (c >= '0' && c <= '9') {
             value = c - '0';
         }
         else if (c >= 'A' && c <= 'Z') {
             value = c - 'A' + 10;
         }
         else if (c >= 'a' && c <= 'z') {
             value = c - 'a' + 36;
         }
         else {
             value = 0;
         }
         hash = (hash * 62 + value);   
     }
     return hash;
 }

  int hash_string_folding(const std::string& str, int n) {
     int block_size = 4;
     int hash = 0;

     for (size_t i = 0; i < str.length(); i += block_size) {
         std::string block = str.substr(i, block_size);
         hash += hash_block(block);
     }

     return hash % n;
 }

  class MyClass {
 public:
     std::string attr1;
     std::string attr2;
     std::string attr3;

     MyClass(const std::string& a1, const std::string& a2, const std::string& a3)
         : attr1(a1), attr2(a2), attr3(a3) {}

     int hash(int n) const {
          int hash1 = hash_string_folding(attr1, n);
         int hash2 = hash_string_folding(attr2, n);
         int hash3 = hash_string_folding(attr3, n);

          return (hash1 + hash2 + hash3) % n;
     }
 };
  //proble4
  class PhoneHashTable {
  public:
      PhoneHashTable(int table_size = 10, double limit_load_factor = 0.75)
          : table_size(table_size), limit_load_factor(limit_load_factor), num_elements(0) {
          table.resize(table_size);
      }

      void insert(const std::string& key, const std::string& value) {
          if (get_load_factor() > limit_load_factor) {
              rehash();
          }

          int hash_index = hash_function(key);
          table[hash_index].emplace_back(key, value);
          num_elements++;
      }

      bool find(const std::string& key) const {
          int hash_index = hash_function(key);
          for (const auto& pair : table[hash_index]) {
              if (pair.first == key) {
                  return true;
              }
          }
          return false;
      }

      void remove(const std::string& key) {
          int hash_index = hash_function(key);
          for (auto it = table[hash_index].begin(); it != table[hash_index].end(); ++it) {
              if (it->first == key) {
                  table[hash_index].erase(it);
                  num_elements--;
                  return;
              }
          }
      }

  private:
      std::vector<std::list<std::pair<std::string, std::string>>> table;
      int table_size;
      double limit_load_factor;
      int num_elements;

      double get_load_factor() const {
          return static_cast<double>(num_elements) / table_size;
      }

      int hash_function(const std::string& key) const {
          std::hash<std::string> hasher;
          return hasher(key) % table_size;
      }

      void rehash() {
          std::vector<std::list<std::pair<std::string, std::string>>> old_table = table;
          table_size *= 2;
          table.clear();
          table.resize(table_size);
          num_elements = 0;

          for (const auto& bucket : old_table) {
              for (const auto& pair : bucket) {
                  insert(pair.first, pair.second);
              }
          }
      }
  };
  //problem5
  struct PhoneEntry {
      std::string phone_number;
      std::string name;

      PhoneEntry(const std::string& phone, const std::string& n)
          : phone_number(phone), name(n) {}
  };

   struct Node {
      PhoneEntry entry;
      Node* next;

      Node(const PhoneEntry& e) : entry(e), next(nullptr) {}
  };

   class LinkedList {
  public:
      LinkedList() : head(nullptr) {}

      void put(const PhoneEntry& phone) {
          Node* current = head;
          Node* prev = nullptr;

           while (current != nullptr) {
              if (current->entry.phone_number == phone.phone_number) {
                  current->entry.name = phone.name;
                  return;
              }
              prev = current;
              current = current->next;
          }

           Node* new_node = new Node(phone);
          if (prev == nullptr) {
              head = new_node;
          }
          else {
              prev->next = new_node;
          }
      }

      void print_all() const {
          Node* current = head;
          while (current != nullptr) {
              std::cout << "Phone Number: " << current->entry.phone_number
                  << ", Name: " << current->entry.name << std::endl;
              current = current->next;
          }
      }

  private:
      Node* head;
  };

   class PhoneHashTable {
  public:
      PhoneHashTable(int table_size = 10) : table_size(table_size) {
          table = new LinkedList[table_size];
      }

      void put(const PhoneEntry& phone) {
          int hash_index = hash_function(phone.phone_number);
          table[hash_index].put(phone);
      }

      void print_all() const {
          for (int i = 0; i < table_size; ++i) {
              std::cout << "Bucket " << i << ":" << std::endl;
              table[i].print_all();
          }
      }

  private:
      int table_size;
      LinkedList* table;

      int hash_function(const std::string& key) const {
          std::hash<std::string> hasher;
          return hasher(key) % table_size;
      }
  };
int main() {
 

    return 0;
}
