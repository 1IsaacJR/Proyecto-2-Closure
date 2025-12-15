#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
El siguiente trabajo presenta una simulacion de las cerraduras para funciones de orden superior
y como interactuan los ambientes en dichas funciones.

Bibliografia:

https://www.geeksforgeeks.org/cpp/c-mutable-keyword/     <- Funcionamiento de "mutable" 
https://cplusplus.com/forum/general/267408/         <- closure simulation
https://en.cppreference.com/w/cpp/utility/functional/function.html <- Lambda function
*/

/*
Se iniciliza una funcion con tipo int, la cual simula un L-closure para el incremento de numeros
*/
function< int() > fnc()
{
    //Se iniciliza x
    int x = 0;
    // Se retorna una lambda que captura x por valor
    // El modificador 'mutable' permite modificar la copia capturada
    // preservando el estado interno entre llamadas (cerradura).
    return [x]() mutable {
        return ++x;
        //retorna la funcion de incremento
    };
    
}

/*
Podemos simluar la misma funcion pero cuyo estado se almacena
en una ubicacion global compartida. Provocando un escenario en el 
que las cerraduras no preservan el ambiente lexico.

int x_dyn = 0;

function<int()> fnc_no_closure()
{
    // No se captura nada
    return []() {
        return ++x_dyn;
    };
}
*/


/*
Se implementa la funcion1
*/
void function1()
{
    //Declaracion de variables a ocupar dentro de las siguientes funciones
    int a ,x;
    //Declaracion de variables auxiliares
    int px = 5, pa = 7;
    
    //Indicacion de pre-procesamiento
    //bool preproccess = true;
    //Indicacion de modificaciones
    //bool sharemodified = false;
    
    //Se implementa la segunda funcion lambda, capturamos todas las variables visibles
    auto function2 = [&]()
    {
            //variables libres
            x = px;
            a = pa;
            x += 2;  // <- se modifica x dentro de la funcion2 
        // Imprime la funcion 2 con los valores de x y a
        cout << "In function2: x = " << x << ", a = " << a << '\n';
        //declaracion de function3
        auto function3 = [&]() // <<lambda para 3er funcion 
        { 
            cout << "In function3: x = " << x << ", a = " << a << '\n';
        };
        
        function3(); // llamada de la funcion3 
    };
    function2(); // llamada de la funcion2 
}

/*
Se iniciliza el main, para la demostracion de funciones
*/
int main(){
    //Generamos un closure
    auto clos = fnc();
    //closure de prueba para suma consecutiva
    for (int i=0; i<5; i++) cout << clos() << endl;
    cout << endl;
   /*  //Simulacion de closure para entorno compartido
    auto c1 = fnc_no_closure();
    auto c2 = fnc_no_closure();

    cout << c1() << endl; // 1
    cout << c1() << endl; // 2
    cout << c2() << endl; // 3  <- representa un ambiente compartido
 */
 
    // llamada de la funcion1 de prueba para la comprobacion de ambientes
    function1();
}

/*
Las variables son capturables por los L-closure en las funciones 2,3
    - Las lambdas pueden ver las variables exteriores, lo que contribuye a poder fluir en ambitos anidados.

    - Las lambdas anidadas constituyen una cerradura accediendo a las variables definidas anteriormente, 
    asi las llamadas indirectas permiten que las variables libres mantengan su valor.

    - En caso de que las cerraduras no preservaran el ambiente léxico, entonces los valores de las llamada de la funcion
    2 seria: pa = 0, px = 0, para la funcion 3: pa = 0 y px = 0, ya que no se preserva el ambiente con el que 
    se incio la cerradura ya que se inicilizarian por defecto. 
    
    Las lambdas no preservan el ambiente léxico por lo tanto las variables libres no conservan su ligadura original
    y se comportarian como si las variables externas no existieran inicailizandose en 0.

    -En un lenguaje sin la implementacion de cerraduras, las funciones no preservarian el ambiente lexico
    del punto donde fueron definidas. En consecuencia, las variables libres se resuleven en el contexto 
    en el cual fueron llamadas y no en el de la definicion.
*/