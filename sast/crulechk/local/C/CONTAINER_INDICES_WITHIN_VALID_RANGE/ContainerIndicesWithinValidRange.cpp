//@checker CONTAINER_INDICES_WITHIN_VALID_RANGE
#include <cstddef>
  
void insert_in_table(int *table, std::size_t tableSize, int pos, int value) {
  if (pos >= tableSize) {
    // Handle error
    return;
  }
  table[pos] = value;
}