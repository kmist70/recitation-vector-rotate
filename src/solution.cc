#include "solution.hpp"

std::vector<int> RotateRight(const std::vector<int>& vect, unsigned int no_rotations) {
  std::vector<int> result = vect;
  for (unsigned int i = 0; i < no_rotations; ++i) {
    int last_element = result.back();
    result.pop_back();
    result.insert(result.begin(), last_element);
  }
  return result;
}

std::vector<int> RotateChunks(const std::vector<int>& vect, unsigned int chunk_size, unsigned int no_rotations) {
  std::vector<int> result = vect;

  // handles unique cases
  if (chunk_size == 0) {
    return result;
  }
  unsigned int next_chunk = result.size() / chunk_size;
  unsigned int actual_rotations = no_rotations % next_chunk;
  if (actual_rotations == 0) {
    return result;
  }

  // standard solution algorithm
    // find a way to split chunks
    // go through it
  for (unsigned int i = 0; i < result.size(); i += chunk_size) {
    
    // result = RotateRight(result, actual_rotations);
  }


  return result;
}