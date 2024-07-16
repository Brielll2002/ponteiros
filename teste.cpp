#include <iostream>
#include <locale.h>
#include <memory>

int ponteiroBruto(int x){

    int i = x;
    int* p = &i;//o ponteiro(p) recebe o endereço de memória da variável 'i'
    int j = *p;//'j' recebe o valor que está associado ao endereço de memória de 'i'
    return j;
}

int ponteiroConst(int x){
    
    int i = x;
    const int *p = &i;//Para declarar o objeto apontado pelo ponteiro como const
    int * const p2 = &i;//Para declarar o valor do ponteiro, ou seja, o endereço real armazenado no ponteiro, como const
    int j = *p;//'j' recebe o valor que está associado ao endereço de memória de 'i'
    
    return j;
}

class exObject{
    public:
        int doSomething(int x){
            return x;
        }
};

int ponteiroInteligente(int x){
    std::unique_ptr<exObject> pExemple(new exObject());//O ponteiro inteligente(std::unique_ptro) é responsável pela exclusão da memória especificada pelo ponteiro bruto, seu destruidor é chamado quando o ponteiro inteligente fica fora do escopo.
    return pExemple->doSomething(x);
}

int main(){
    setlocale(LC_ALL, "");

    std::cout<<ponteiroBruto(4);
    std::cout<<'\n';
    std::cout<<ponteiroConst(5);
    std::cout<<'\n';
    std::cout<<ponteiroInteligente(6);

    return 0;
}