//ALUMNO: Aaron Socas Gaspar
//Seguridad curso 2013-2014
//Practica 5: Diffie-Hellman

#include "dh.hpp"

int main (void)
{
  DH n;
  n.pedir_datos();
  n.intercambio_claves();
  return 0;
}
