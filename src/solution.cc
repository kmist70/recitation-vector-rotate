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

  // handles case where chunk size is 0
  if (chunk_size == 0) {
    result.clear();
    return result;
  }

  unsigned int num_chunk = result.size() / chunk_size;
  unsigned int actual_rotations = no_rotations % num_chunk;

  if (actual_rotations == 0) {
    return result;
  }

  for (unsigned int i = 0; i < result.size(); i += chunk_size) {
    // for tail cases where chunk size is not the chunk size given at the beginning
    if((i * chunk_size) + chunk_size > result.size() && result.size() % chunk_size != 0) {
      chunk_size = result.size % chunk_size;
    }
    
    // standard procedure to rotate chunks
    std::vector<int> current_chunk(chunk_size);
    for (unsigned int j = 0; j < chunk_size; ++j) {
      current_chunk[j] = result[(i+1) * j];
    }
    current_chunk = RotateRight(current_chunk, actual_rotations);

    for (unsigned int j = 0; j < chunk_size; ++j) {
      result[(i+1) * j] = current_chunk[j];
    }
  }

  return result;
}