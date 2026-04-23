#ifndef COMPRESORRLE_H
#define COMPRESORRLE_H

#include <string>

class CompresorRLE {
public:
    CompresorRLE();
    std::string comprimir(std::string texto);
    std::string descomprimir(std::string texto);
};

#endif
