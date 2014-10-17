#include "dh.hpp"

DH::DH (void)
{
  p_ = 0; alfa_ = 0; xa_ = 0; xb_ = 0;
}

void DH::pedir_datos (void)
{
    unsigned n;
    do
    {
      cout<<"Introduce el valor de p (debe ser un nº primo): ";
      cin>>n;
    }while (!comprobar_primo(n));   //comprobamos que el numero introducido es primo
    p_ = n;
    do
    {
	cout<<"Introduce el valor de alfa (alfa<p): ";
	cin>>n;
    } while (p_ < (n+1));   //alfa<p
    alfa_ = n;
    cout<<"Escoge el secreto Xa: ";
    cin>>xa_;
    cout<<"Escoge el secreto Xb: ";
    cin>>xb_;
}

bool DH::comprobar_primo (unsigned n)
{
  unsigned a=0;
  for (unsigned i=1; i<(n+1); i++) //empiezo en 2 pq por 1 son todos divisibles
  {
      if(n%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
      a++;
  }
  if (a==2) //solo tiene dos divisores: 1 y si mismo
    return true;
  else //tiene mas de un divisor, no es primo
    return false;
}

unsigned DH::get_p (void)
{
  return p_;
}

unsigned DH::get_alfa (void)
{
  return alfa_;
}

unsigned DH::get_xa (void)
{
  return xa_;
}

unsigned DH::get_xb (void)
{
  return xb_;
}


unsigned DH::exp_rap2 (unsigned base, unsigned exp, unsigned m)
{
  //P1
  bitset<BITS> b(exp);
  //P2
  unsigned r=1;
  //P3
  for (int i=(BITS-1); i>-1; i--)
  {
    r=(r*r)%m;
    if (b[i]==1)
      r=(r*base)%m;
  }
  return r;
}

void DH::intercambio_claves (void)
{
  unsigned ya, yb, ka, kb;
  ya = exp_rap2 (alfa_,xa_,p_);
  yb = exp_rap2 (alfa_,xb_,p_);
  ka = exp_rap2 (yb,xa_,p_);
  kb = exp_rap2 (ya,xb_,p_);
  cout<<"p= "<<p_<<", Xa= "<<xa_<<", Xb= "<<xb_<<", Ya= "<<ya<<", Yb= "<<yb<<", ";
  if (ka==kb)
    cout<<"k= "<<ka<<endl;
  else
    cout<<"Ka= "<<ka<<", Kb= "<<kb<<endl;
}
