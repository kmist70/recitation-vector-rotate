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
  std::vector<std::vector<int>> chunk_list;

  int c = 0;  //variable tracking index of 1D vector
  for (unsigned int a = 0; a < next_chunk; ++a) {
    for (unsigned int b = 0; b < chunk_size; ++b) {
      chunk_list[a][b] = result[c];
      ++c;
    }
  }
  //handles extra values that dont divide evenly
  if (c < result.size()) {
    while (c < result.size()) {
      int b = 0;
      chunk_list[next_chunk][b] = result[c];
      ++b;
      ++c;
    }
  }

  result.clear();
  //by this point, all values should be in chunks assigned to their own subvectors and result is cleared
  //rotates each subvector in the 2D vector
  for (unsigned int i = 0; i < chunk_list.size(); ++i) {
    chunk_list[i] = RotateRight(chunk_list[i], actual_rotations);
  }

  //populates result again with the rotated chunks
  for (unsigned int a = 0; a < chunk_list.size(); ++a) {
    for (unsigned int b = 0; b < chunk_list[a].size(); ++b) {
      result.push_back(chunk_list[a][b]);
    }
  }

  return result;
}