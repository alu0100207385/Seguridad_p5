// #include "mias.hpp"
#include <bitset>
#include <iostream>

using namespace std;

const unsigned BITS = 8;

class DH
{
  private:
    unsigned p_, alfa_ , xa_, xb_;
    bool comprobar_primo (unsigned n);
    unsigned exp_rap2 (unsigned base, unsigned exp, unsigned m);
    
  public:
    DH (void);
    inline ~DH(){};
    void pedir_datos (void);
    unsigned get_p (void);
    unsigned get_alfa (void);
    unsigned get_xa (void);
    unsigned get_xb (void);
    void intercambio_claves (void);
};