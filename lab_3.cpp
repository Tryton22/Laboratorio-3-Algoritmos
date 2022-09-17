#include<iostream>
#include<string.h>

using namespace std;

class NodoEnteroArbol {
    public:
        int dato;

        NodoEnteroArbol *izquierdo;
        NodoEnteroArbol *derecho;

        NodoEnteroArbol(int dato):dato(dato), izquierdo(NULL), derecho(NULL){}
};

class ArbolBinarioEntero {
    private:
        NodoEnteroArbol *raiz;

        NodoEnteroArbol *insertar(NodoEnteroArbol *root, int dato) {
            if (root == NULL)
                {
                  return new NodoEnteroArbol(dato);
                }

            else {
                if (dato >= root->dato) 
                    root->izquierdo = insertar(root->izquierdo, dato);
                else 
                    root->derecho = insertar(root->derecho, dato);
                
            }
            
            return root;
        }

    public:
        ArbolBinarioEntero() :raiz(NULL) {}

        

        void Agregar(int valor){
            raiz = insertar(raiz, valor);    
        }

        NodoEnteroArbol *getRaiz(){
            return (this->raiz);
        }

        void preorder(NodoEnteroArbol *raiz){
            if(raiz != NULL){
                cout<<" "<<raiz->dato;
                preorder(raiz->izquierdo);
                preorder(raiz->derecho);
            }
            return;
        }

        void inorder(NodoEnteroArbol *raiz){
            if(raiz != NULL){
                inorder(raiz->izquierdo);
                cout<<" "<<raiz->dato;
                inorder(raiz->derecho);
            }
            return;
        }

        void postorder(NodoEnteroArbol *raiz){
            if(raiz != NULL){
                postorder(raiz->izquierdo);
                postorder(raiz->derecho);
                cout<<" "<<raiz->dato;
            }
            return;
        }
};

int main(){
    ArbolBinarioEntero treePromedios;
    ArbolBinarioEntero treeMatriculas;
    int decision = 3;
    int info;

    cout << "Bienvenido a sistema de promedio y matricula de estudiantes" << endl;
    
    while (decision != 0){
        cout << "<1> Ingresar datos" << endl;
        cout << "<2> Ver datos" << endl;
        cout << "<0> Salir" << endl;
        cin >> decision;

        if (decision == 1){
            cout << "\nIngrese numero de matricula: ";
            cin >> info;
            cout<<"\n" << endl;
            treeMatriculas.Agregar(info);
            cout << "Ingrese promedio: ";
            cin >> info;
            cout<<"\n" << endl;
            treePromedios.Agregar(info);
        }
        else if(decision == 2){
            if (treePromedios.getRaiz() == NULL && treeMatriculas.getRaiz() == NULL)
                cout << "\nNo existen datos aun" << endl;
            else{
                cout << "\nComo desea ver los datos" << endl;
                cout << "<1> Pre Order" << endl;
                cout << "<2> In Order" << endl;
                cout << "<3> Post Order" << endl;
                cin >> info;
                if (info == 1){
                    cout << "\nMatriculas" << endl;
                    treeMatriculas.preorder(treeMatriculas.getRaiz());
                    cout<<"\n" << endl;
                    cout << "Promedios" << endl;
                    treePromedios.preorder(treePromedios.getRaiz());
                    cout<<"\n" << endl;
                }
                else if (info == 2){
                    cout << "\nMatriculas" << endl;
                    treeMatriculas.inorder(treeMatriculas.getRaiz());
                    cout<<"\n" << endl;
                    cout << "Promedios" << endl;
                    treePromedios.inorder(treePromedios.getRaiz());
                    cout<<"\n" << endl;
                }
                else if  (info == 3){
                    cout << "\nMatriculas" << endl;
                    treeMatriculas.postorder(treeMatriculas.getRaiz());
                    cout<<"\n" << endl;
                    cout << "Promedios" << endl;
                    treePromedios.postorder(treePromedios.getRaiz());
                    cout<<"\n" << endl;
                }           
            }
        }
        else if(decision == 0){
            break;
        }
        else{
            cout << "Ingrese un dato valido" << endl;
        }
    }
    return 0;
}