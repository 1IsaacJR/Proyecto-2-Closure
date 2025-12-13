#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
virtual function type function name(argument list)
{
function body
}
*/

//tamplate<typename T>
function< int() > fnc()
{
    //marcar definion con mutable <--  simulacion de closure
    int x = 0;
    return [x]() mutable {
        return ++x;
    };
    /*
    const std::function< int() > fn = [x]() { return x+1; };
    return fn ;
    */
}

void function1()
{
    int a ,x;
    int px = 5, pa = 7;
    bool preproccess = true;
    bool sharemodified = false;
    //declaracion de funciones con lambda
    auto function2 = [&]()
    {
        if(preproccess){
            x = px;
            a = pa;
            preproccess = false;
        }
        x += 2;   // modifica -> activar postprocesamiento
        sharemodified = true;
        // llamada de function2
        cout << "In function2: x = " << x << ", a = " << a << '\n';
        //declaracion de function3
        auto function3 = [&]() // <<lambda para 3er funcion 
        { 
            cout << "In function3: x = " << x << ", a = " << a << '\n';
        };
        
        function3(); // llamada de la funcion3 pre-procesamiento
    };

    function2();
    //comprobamos share true modificado en function2
    if(sharemodified){
        px = x;
        pa = a;
    }
    
}
int main(){
    auto clos = fnc();
    //closure de prueba para suma consecutiva
    for (int i=0; i<5; ++i) std::cout << clos() << endl;
    // llamada de la funcion1 de prueba
    function1();
    //prueba de funciiones lambda en c++ con <function>
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << endl;
    //segunda prueba
    function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << endl;
}
/*
Las variables son capturables por los L-closure en las funciones 2,3
    - Las lambdas pueden ver las variables exteriores. lo que contribuye a poder fluir en ambitos anidados.
    - Las lambdas anidadas constituyen una cerradura accediendo a las variables definidas anteriormente, asi las llamadas indirectas a él proporcionan
un acceso legítimo a la pila. 


*/