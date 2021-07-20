#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

//prototipos
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
Nodo *arbol = NULL;
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);
void ingresarNodo(int);
void recorrer(char);

int main()
{
    menu();
    cout << "Adios" << endl;
    return 0;
}
//funcion menu
void menu(){
    int dato,opcion,contador=0,opin;

    do{
        cout<<"\t :MENU: ."<<endl;
        cout<<"1. Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar arbol"<<endl;
        cout<<"3. Buscar un elemento"<<endl;
        cout<<"4. Recorrer el arbol en PreOrden"<<endl;
        cout<<"5. Recorrer el arbol en inOrden"<<endl;
        cout<<"6. Recorrer el arbol en postOrden"<<endl;
        cout<<"7. Eliminar un nodo del arbol"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion:"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1: cout<<"\nDe que forma queires insertar los datos?:  ";
                    cout<<"\n1. Insertar uno por uno:"<<endl;
                    cout<<"\n2. Insertar los nodos separados por comas:"<<endl;
                    cin>>opcion;
                    ingresarNodo(opcion);

              //      insertarNodo(arbol,dato,NULL); //Insertamos un nuevo nodo
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: cout<<"\nMostrando el arbol completo: \n\n";
                    mostrarArbol(arbol,contador);
                    cout<<"\n";
                    system("pause");
                    break;
            case 3: cout<<"\nDigite el elemento a buscar: \n\n";
                    cin>>dato;
                    if(busqueda(arbol,dato)){
                        cout<<"\nElemento "<<dato<<" ha sido encontrado"<<endl;
                    }
                    else{
                         cout<<"\nElemento "<<dato<<" no ha sido encontrado"<<endl;
                    }
                    cout<<"\n";
                    system("pause");
                    break;
            case 4: cout<<"\nArbol mostrado en preorden"<<endl;
                    preOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;
            case 5: cout<<"\nArbol mostrado en inOrden"<<endl;
                    inOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;
            case 6: cout<<"\nArbol mostrado en postOrden"<<endl;
                    postOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;
            case 7: cout<<"\nDigite el numero a eliminar: "<<endl;
                    cin>>dato;
                    eliminar(arbol,dato);
                    cout<<"\n\n";
                    system("pause");
                    break;

        }
        system("cls");
    }while(opcion!=8);


}
//Funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol,int cont){
    if(arbol == NULL){
        return;
    }
    else{
        mostrarArbol(arbol->der , cont+1);
        for(int i=0; i<cont; i++){
            cout<< "---";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq, cont+1);
    }

}


//Function para crear un nuevo nodo
Nodo *crearNodo(int n,Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre =padre;

    return nuevo_nodo;
}

//Function para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n,Nodo *padre){
    if(arbol == NULL) {//si el árbol está vacio
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol =  nuevo_nodo;
       }

    else{//siel arbol tiene un nodo o mas
        int valorRaiz = arbol -> dato; //obtenemos el valor de la raiz
        if(n < valorRaiz){//si el elemento es menor a la raiz, insertamos en izq
                insertarNodo(arbol -> izq , n,arbol);
            }
        else{             //si el elemento es mayor a la raiz, insertamos en der
                insertarNodo(arbol -> der , n,arbol);
            }
       }
}
//funcion para recorrer los datos separados por comas
void recorrer(char arrDato[100]){
    int entero;
    //string arreglo;
    for(int i=0; i<=strlen(arrDato); i++){
        if(arrDato[i] !=  ','){

            entero=arrDato[i]-0;
            insertarNodo(arbol,entero,NULL);
            }
    }
}
//funcion para ingresar el nodo
void ingresarNodo(int opcion){
    int datoa;
    char ver;
    char arrDatos[100];
    if(opcion==1){//si se eligio el metodo uno por uno

        do{
            //system("cls");
            cout<<"\n Digite S para salir o digite un nuevo dato: ";
            scanf ("%d",&datoa);
            ver = (char)datoa;
            if(ver!='s'){
                insertarNodo(arbol,datoa,NULL);
                system("pause");
            }
            else{
                cout<<"vas a salir";
                system("pause");
            }
            }while(ver!='s');

    }else if(opcion==2){//si se eligio el metodo todos separados por comas
                //system("cls");
                cout<<"\n Digite los datos separados por comas luego presione enter: ";
                cin.getline(arrDatos,100);
                recorrer(arrDatos);
                system("pause");

            }else{system("pause");}
}

//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol,int n){
    if(arbol == NULL){//Si el arbol esta vacio
            return false;
    }
    else if(arbol->dato ==n){//Si el nodo es igual al elemento
        return true;
    }
    else if(n < arbol->dato){//Si el nodo es menor al elemento
        return busqueda(arbol->izq,n);
    }
    else{
        return busqueda(arbol->der,n);
    }

    }
//Funcion para recorrer el arbol completo preeorden
void preOrden(Nodo *arbol){
    if(arbol == NULL){//si el arbol esta vacio
        return;
    }
    else{
        cout<<arbol->dato<<"--";
        preOrden(arbol->izq);
        preOrden(arbol->der);

           }
}
//Funion para recorrido inOrden
void inOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }
    else{
        inOrden(arbol->izq);
        cout<<arbol->dato<<"--";
        inOrden(arbol->der);

    }

}
//Funion para recorrido posOrden
void postOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }
    else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<"--";

    }

}
//Funcion para eliminar un nodo del arbol
void eliminar(Nodo *arbol,int n){
    if(arbol == NULL){//Si el elemento esta vacio
        return;//No haces nada
    }
    else if(n < arbol->dato){//Si el valor es menor
        eliminar(arbol->izq,n);//Busca por la izquierda
    }
    else if(n > arbol->dato){//Si el valor es mayor
        eliminar(arbol->der,n);//Busca por la derecha
    }
    else{//si ya encontraste el valor del nodo
        eliminarNodo(arbol);
    }
}
//Funcion para determinar el nodo mas izquerdo posible
Nodo *minimo(Nodo *arbol){
    if(arbol == NULL){
        return NULL;
    }
    if(arbol->izq){//si tiene hijo izq
        return minimo(arbol->izq);//buscar la parte mas izquierda posible
    }
    else{//si no tiene hijo izq
        return arbol;//retornamos el mismo nodo
    }
}
//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
    if(arbol->padre){
        //arbol->padre hay que asignarle su nuevo hijo
        if(arbol->dato == arbol->padre->izq->dato){
            arbol->padre->izq = nuevoNodo;
        }
        else if(arbol->dato == arbol->padre->der->dato ){
            arbol->padre->der = nuevoNodo;
        }
    }
    if(nuevoNodo){
        //procedemos a asignarle su nuevo padre
        nuevoNodo->padre=arbol->padre;
    }
}
//Funcion para destuir un nodo
void destruirNodo(Nodo *nodo){
    nodo->der=NULL;
    nodo->izq=NULL;

    delete nodo;
}
//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar ->izq){//si tiene hijo izquierdo
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar ->der){//si tiene hijo derecho
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }else{//si u nodo no tiene hijos es un nodo hoja
        reemplazar(nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
}
