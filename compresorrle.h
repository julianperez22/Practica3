#ifndef COMPRESORRLE_H
#define COMPRESORRLE_H

#include <string>
#include <stdexcept>


class CompresorRLE {
public:
    CompresorRLE(); //


    std::string comprimir(const std::string& texto);
    std::string descomprimir(const std::string& comprimido);
};

#endif // COMPRESORRLE_H
