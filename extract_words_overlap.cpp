#include <iostream>
#include <fstream>
#include <string>

#include "../word2vec/trunk/distance_lib.h"

int main(int argc, char* argv[]) {
  if (argc <= 6) {
    printf("Usage: ./extract_words_overlap <file> <output_file> <num_words> <upper|lower> <overlap_file> <overlap_extent>");
    return 0;
  }
  char filename[100];
  strcpy(filename, argv[1]);
  std::ofstream out(std::string(argv[2]) + ".txt");
  int fibSize = atoi(argv[3]);
  // std::cerr << "Fibsize: " << fibSize << std::endl;
  char random_words[fibSize][100];
  char overlap_filename[100];
  strcpy(overlap_filename, argv[5]);
  float overlap_extent = atof(argv[6]);
  int overlap_words = fibSize * overlap_extent;
  std::string line;
  std::ifstream in(std::string(argv[5]) + ".txt");
  if (!in.is_open()) {
    std::cerr << "Unable to open the input file\n";
    return -1;
  }
  for (int i = 0; i < overlap_words; i++) {
    std::getline(in, line);
    out << line << "\n";
  }
  if (std::string(argv[4]) == "upper")
    get_random_words_disjoint(filename, fibSize - overlap_words, random_words, true);
  else if (std::string(argv[4]) == "lower")
    get_random_words_disjoint(filename, fibSize - overlap_words, random_words, false);
  else if (std::string(argv[4]) == "any")
    get_random_words(filename, fibSize - overlap_words, random_words);
  else {
    std::cerr << "3rd argument invalid. Select upper or lower half of dictionary" << std::endl;
    return 1;
  }
  for (int i = 0; i < fibSize - overlap_words; i++)
    out << random_words[i] << "\n";
  out.close();
  in.close();
  return 0;
}
