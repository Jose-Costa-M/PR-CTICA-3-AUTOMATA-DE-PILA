#include "header.h"

//definicion de los recorridos
unordered_set<string> transicion_numeros = {"0","1","2","3","4","5","6","7","8","9"};
unordered_set<string> transicion_signos = {"+","-","*","/","%"};
set<string> transicion_Letras = {"A","B","C","D","E","F","G","H","J","K","L","M","N","P","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","n","m","o","p","q","r","s","t","u","v","w","x","y","z"};
set<string> transicion_apertura = {"("};
set<string> transicion_cerradura = {")"}; 
set<string> transicion_pcoma = {";"};
set<string> transicion_equal = {"="};


// PILA: Z0 
// CADENA: ;
stack<string> pila;

void menu(){

    cout << " \n |------------------------------------| " ;
    cout << " \n |        - AUTOMATA DE PILA -        | " ;
    cout << " \n |-----------------|------------------| " ;
    cout << " \n | 1. PREDEFINIDAS | 2. INGRESAR      | " ;
    cout << " \n | 3. SALIR        |                  | " ;
    cout << " \n |-----------------|------------------| " ;
    cout << " \n " ;
    puts ( " \n Selecciona una opcion: " );


}

bool automataStack(string cadena){
    bool validacion;
    pila.push("Z0");
    validacion = estadoQ0(cadena);
    return validacion; 
}

 //   
bool estadoQ0(string c){

    bool q0_AC = false;
    string aux;
    aux = c[0];

    if(c.size()==0){
        return q0_AC;

    }else if( (transicion_apertura.count(aux) && pila.top() == "Z0") || (transicion_apertura.count(aux) && pila.top() == "X")){
        pila.push("X");
        c.erase(0,1);
        return estadoQ0(c);
    }else if(transicion_Letras.count(aux) && (pila.top() == "Z0" || pila.top() == "X")){
       //NOTA: EN ESTA TRANSICIÓN LA PILA SE QUEDA IGUAL
       c.erase(0,1);
       return estadoQ1(c); 
    }else{
        return q0_AC;
    }

}

bool estadoQ1(string c){

  bool q1_AC = false;
    string aux;
    aux = c[0];

    if(c.size()==0){
        return q1_AC;
    }else if( (transicion_Letras.count(aux) || transicion_numeros.count(aux)) && (pila.top() == "Z0" || pila.top() == "X")){
        c.erase(0,1);
        return estadoQ1(c);
    }else if(transicion_cerradura.count(aux) && pila.top() == "X"){
        pila.pop();
        c.erase(0,1);
       return estadoQ6(c);
    }else if(transicion_cerradura.count(aux) && pila.top() == "Z0"){
        return q1_AC;
    }else if(transicion_equal.count(aux) && pila.top() == "Z0"){
        c.erase(0,1);
        return estadoQ2(c);
    }else if(transicion_equal.count(aux) && pila.top() == "X"){
        return q1_AC;
    }else{
        return q1_AC;
    }

}

bool estadoQ2(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];

    if(aux.size()==0){
        return q1_AC;
    }else if(transicion_apertura.count(aux) && (pila.top() == "Z0" || pila.top() == "X")){
        pila.push("X");
        c.erase(0,1);
        return estadoQ2(c);
    }else if(transicion_numeros.count(aux) && (pila.top() == "Z0" || pila.top() == "X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ8(c);
    }else if(transicion_Letras.count(aux) && (pila.top() == "Z0" || pila.top() == "X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ3(c);
    }else{
        return q1_AC;
    }
}

bool estadoQ3(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];
   if(aux.size()==0){
    return q1_AC;
   }else if((transicion_Letras.count(aux) || transicion_numeros.count(aux)) && (pila.top()=="Z0" || pila.top()=="X") ){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ3(c);
   }else if(transicion_signos.count(aux) && (pila.top()=="Z0" || pila.top()=="X") ){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ4(c);
   }else if(transicion_pcoma.count(aux) && pila.top()=="Z0"){
        c.erase(0,1);
        return estadoQ5(c);
   }else if(transicion_cerradura.count(aux) && pila.top()=="X"){
        pila.pop();
        c.erase(0,1);
        return estadoQ7(c);
   }else{
        return q1_AC;
   }
}

bool estadoQ4(string c){
    bool q1_AC =false;
    string aux;
    aux = c[0];
    if(aux.size()==0){
        return q1_AC;
    }else if(transicion_apertura.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        pila.push("X");
        c.erase(0,1);
        return estadoQ2(c);
    }else if(transicion_numeros.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ8(c);
    }else if(transicion_Letras.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ3(c);
    }else{
        return q1_AC;
    }
}

bool estadoQ5(string c){
    bool q1_AC = true;
    string aux;
    aux = c[0];

    if(aux.size()== 1){
        return true;
    }else{
        return false;
    }
}

bool estadoQ6(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];

    if(aux.size()==0){
        return q1_AC;
    }else if(transicion_cerradura.count(aux) && pila.top() == "X"){
        pila.pop();
        c.erase(0,1);
        return estadoQ6(c);
    }else if(transicion_cerradura.count(aux) && pila.top() == "Z0"){
        return q1_AC;

    }else if(transicion_equal.count(aux) && pila.top() == "Z0"){
        c.erase(0,1);
        return estadoQ2(c);
    }else if(transicion_equal.count(aux) && pila.top() == "X"){
        return q1_AC;
    }else{
        return q1_AC;
    }    

}

bool estadoQ7(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];

    if(aux.size()==0){
        return q1_AC;
    }else if(transicion_cerradura.count(aux) && pila.top() == "X"){
        pila.pop();
        c.erase(0,1);
        return estadoQ7(c);
    }else if(transicion_cerradura.count(aux) && pila.top() == "Z0"){
        return q1_AC;
    }else if(transicion_signos.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ4(c);
    }else if(transicion_pcoma.count(aux) && pila.top()=="Z0"){
        c.erase(0,1);
        return estadoQ5(c);
    }else{
        return q1_AC;
    }
}

bool estadoQ8(string c){
    bool q1_AC = false;
    string aux;
    aux = c[0];

    if(aux.size()==0){
        return q1_AC;
    }else if(transicion_numeros.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ8(c);
    }else if(transicion_cerradura.count(aux) && pila.top()=="X"){
        pila.pop();
        c.erase(0,1);
        return estadoQ7(c);
    }else if(transicion_cerradura.count(aux) && pila.top()=="Z0"){
        return q1_AC;
    }else if(transicion_pcoma.count(aux) && pila.top()=="Z0"){
        c.erase(0,1);
        return estadoQ5(c);
    }else if(transicion_pcoma.count(aux) && pila.top()=="X"){
        return q1_AC;
    }else if(transicion_signos.count(aux) && (pila.top()=="Z0" || pila.top()=="X")){
        //NO SE AFECTA LA PILA
        c.erase(0,1);
        return estadoQ4(c);
    }else{
        return q1_AC;
    }
}