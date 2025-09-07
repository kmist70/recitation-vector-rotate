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
  std::vector<int> result;

  // handles case where chunk size is 0 (returns empty vector)
  if (chunk_size == 0 || vect.empty()) {
    return result;
  }

  // true number of rotations (for runtime purposes)
  unsigned int actual_rotations = no_rotations % chunk_size;

  // return vect if there is no rotating to be done
  if (actual_rotations == 0) {
    return vect;
  }

  // standard procedure after special cases are handled
  for (unsigned int i = 0; i < vect.size(); i += chunk_size) {
    unsigned int current_chunk_size = chunk_size;

    // for tail cases where current chunk size is not the chunk size given at the beginning
    if(i + current_chunk_size > vect.size()) {
      current_chunk_size = vect.size() - i;
    }
    
    // process for rotating chunks
    std::vector<int> current_chunk;
    for (unsigned int j = 0; j < current_chunk_size; ++j) {
      current_chunk.push_back(vect[i+j]);
    }

    // new vector for the rotated chunk
    std::vector<int> rotated_chunk = RotateRight(current_chunk, actual_rotations);

    // adds to the vector assigned to result, which holds all the rotated chunks
    for (unsigned int j = 0; j < rotated_chunk.size(); ++j) {
      result.push_back(rotated_chunk[j]);
    }
  }

  return result;
}