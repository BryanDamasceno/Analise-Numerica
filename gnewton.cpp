/*========================== Calculadora de Método de Gregory - Newton ========================= */
//Autor: Bryan Damasceno 
//Data: 09/2020


#include<iostream>
#define TAM 5       //Qauntidade de pontos máxima a ser utilizada 

struct delta {
    double delta1;
    double delta2;
    double delta3;
    double delta4;

};
//Funções utilizadas no programa
void D (double*x, double *y, int n,delta *O,double *DN,double valor);

double P (double *x,double *y,double *DN, int n, double valor);

void print (double *x,double *y,double *DN, double result, int n);

int fatorial (int numero);

void printTabela(delta*O,int n,double *y);


int main(){
    int n;
    double valor,result;
    double *x = new double[TAM];
    double *y = new double[TAM];
    double *DN = new double[TAM];
    delta* O = new delta[TAM];
   
    std::cout<<"Quantos pontos voce vai utilizar?"<<std::endl;
    std::cin>>n;

    std::cout<<"Qual ponto voce quer analisar?"<<std::endl;
    std::cin>>valor;

    std::cout << "Digite os valores das abscissas" << std::endl;
    for(int i=0; i < n; i++ ){  
        std::cin >> x[i];  
    }

    std::cout << "Digite os valores das ordenadas" << std::endl;
     for(int i=0; i < n; i++ ){ 
        std::cin >> y[i];   
     }

    D(x,y,n,O,DN,valor);            //Calcula os os coeficientes de Newton
    result = P(x, y, DN, n, valor); //Calcula o polinomio de Newton no ponto 
    print(x, y, DN, result, n); 
    printTabela(O,n,y);   


    delete [] O;
    delete [] x;
    delete [] y;
    delete [] DN;
    
    return 0;
}
//Declaração das funções 
//Função que calcula os coeficientes de Gregory-Newton
  void D (double*x, double *y, int n,delta *O,double *DN,double valor){
      if(n >= 3){

        DN[0] = y[0];
        for(int i = 0; i < n; i++){
             O[i].delta1 = (y[i+1] - y[i]);
        }
        DN [1] = O[0].delta1;

        for(int i = 0; i < n; i++){
            O[i].delta2 = (O[i+1].delta1 - O[i].delta1);
        }
        DN [2] = O[0].delta2;

    }


        if(n >= 4){
            for(int i = 0; i < n; i++){
                O[i].delta3 = (O[i+1].delta2 - O[i].delta2);
             }
            DN [3] = O[0].delta3;
        }


        if(n >= 5){
            for(int i = 0; i < n; i++){
                O[i].delta4 = (O[i+1].delta3 - O[i].delta3);
            }
            DN [4] = O[0].delta4;
        }

        return;
  }
//Função que calcula o polinômio de Gregory-Newton 
  double P (double *x,double *y,double *DN, int n, double valor){
      
      double u = (valor - x[0])/(x[2]-x[1]);
      double result = 0,
             prod = 1,
             sum = 0;

      
      for(int j = 0; j < n-1; j++){
         prod = prod * (u-j);
         sum = sum + ((DN[j+1]/fatorial(j+1)) * prod);  

      }
      
      result = DN[0] + sum;

      return result;

  } 
//Função que printa os resultados na tela
 void print (double *x,double *y,double *DN, double result, int n){

     std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
     std::cout << "Os pontos utilizados foram:" << std::endl;
   
    for(int i = 0; i < n; i++){ 
        std::cout << "X" << i << " = " << x[i]; 
        std::cout << "           Y" << i << " = " << y[i] << "\n\n";
    }
     std::cout << "Os coeficientes de Newton sao: " << "\n";
   
    for(int i = 0; i < n; i++){ 
        std::cout<< "D"<< i << " = " << DN[i]<< "\n\n";
    }
     std::cout << "\n";
     std::cout << "O valor de Y no ponto desejado: " << result << std::endl;

     return;
} 
//Calcula o fatorial de um numero
int fatorial (int numero){
    int result = numero;
    for(int i = 1; i < numero; i++){
        result = result * (numero - 1);
        numero = numero - 1;

    }

    return result;
}
void printTabela(delta*O,int n,double *y){
    std::cout << "\n\n" << "      ************************|TABELA DE DIFERENÇAS|************************" << "\n\n";


    for(int i = 0; i < n; i++){
        std::cout << y[i] << "    ";
        if((n>=2)&&(i < n-1)) std::cout << O[i].delta1 << "    ";
        if(n==2) std::cout << std::endl; 

        if((n>=3)&&(i < n-2)) std::cout << O[i].delta2 << "    ";
        if(i < n-2)std::cout << " " << "    ";
        if(n==3) std::cout << std::endl; 

        if((n>=4)&&(i < n-3)) std::cout << O[i].delta3 << "    ";
        if(i < n-3) std::cout << " " << "    ";
        if(n==4) std::cout << std::endl; 

        if((n>=5)&&(i < n-4)) std::cout << O[i].delta4 << "    ";
        if(i < n-4)std::cout << " " << "    ";
        if(n==5) std::cout << std::endl; 
    }
}
