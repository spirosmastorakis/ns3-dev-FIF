#include <iostream>
#include <fstream>

#include "../word2vec/trunk/distance_lib.h"

int main(int argc, char* argv[]) {
  if (argc <= 4) {
    printf("Usage: ./extract_words <file> <output_file> <num_words> <upper|lower>");
    return 0;
  }
  char filename[100];
  strcpy(filename, argv[1]);
  std::ofstream out(std::string(argv[2]) + ".txt");
  int fibSize = atoi(argv[3]);
  // std::cerr << "Fibsize: " << fibSize << std::endl;
  char random_words[fibSize][100];
  if (std::string(argv[4]) == "upper")
    get_random_words_disjoint(filename, fibSize, random_words, true);
  else if (std::string(argv[4]) == "lower")
    get_random_words_disjoint(filename, fibSize, random_words, false);
  else if (std::string(argv[4]) == "any")
    get_random_words(filename, fibSize, random_words);
  else {
    std::cerr << "3rd argument invalid. Select upper or lower half of dictionary" << std::endl;
    return 1;
  }
  for (int i = 0; i < fibSize; i++)
    out << random_words[i] << "\n";
  out.close();
  return 0;
}
