#include "Filesaver.h"

FileSaver::FileSaver(string path) {
  // TODO: otworzyc Fstream ze sciezka path lub go stworzyc lub rzucic wyjatek
}

void FileSaver::update(Subject* const x) {
  file << x->getVal() << endl;
}
