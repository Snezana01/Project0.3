#include "creating.h"

int eilute(std::string a){
  std::ifstream file(a);
  int count = 0;
  string line;
    while (getline(file, line))
        count++;
    return count;
};

bool palyginimas(const duomuo &a, const duomuo &b)
{
    if (a.Vard != b.Vard )
        return a.Vard < b.Vard;
    return a.Pav < b.Pav;
};
