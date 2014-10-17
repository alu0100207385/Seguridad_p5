**Autor: Aarón Socas Gaspar**

# INTERCAMBIO DE CLAVES DE DIFFIE-HELLMAN

##Objetivo

Implementar el algoritmo de intercambio de claves de Diffie-Hellman.

##Desarrollo

1. Implementa el generador el algoritmo de intercambio de claves de Diffie-Hellman según el diagrama que se incluye a continuación:

```
	  A								B
    escoge secreto xA					escoge secreto xB
    calcula yA =α^(xA) (mod p)			calcula y B =α^(xB) (mod p)
    genera k= yB^(xA) (mod p)			genera k= yA^(xB) (mod p)
```

2. El programa debe solicitar el número primo p, el número α<p, y los secretos x A y x B , y mostrar la traza completa del algoritmo, es decir, los números intermedios generados y A e y B , y la clave compartida k.

##Ejecución

Antes de nada debemos compilar:
`
    g++ main.cpp dh.cpp -o dh (o salida que deseen)
`

Para ejecutar en Linux:
`
    ./dh (o nombre de salida escogido)
`

##Ejemplo

p = 13, α = 4, xA = 5, xB = 2, yA = 10, y B = 3, k = 9

p = 43, α = 23 xA = 25, xB = 33, yA = 40, y B = 16, k = 4

p = 113, α = 43 xA = 54, xB = 71, yA = 11, y B = 29, k = 61

--------------------------------------------------------------------------
*Aarón Socas Gaspar- Seguridad de Sistemas Informáticos (Curso 2013-2014)*