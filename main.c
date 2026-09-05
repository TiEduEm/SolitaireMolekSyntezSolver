#include "utils.h"
int main() {
  struct gameState orig;
  read(&orig);
  print_current_state(orig);
  return 0;
}
