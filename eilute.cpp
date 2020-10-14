#include "eilute.h"
int eilute(){
  std::ifstream file("kursiokai.txt");
  int count = 0;
  string line;
    while (getline(file, line))
        count++;
    return count;
}
