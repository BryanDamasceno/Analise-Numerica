/*========================== Calculadora de Método de Newton ========================= */
//Autor: Bryan Azevedo 
//Data: 09/2020


#include<iostream>
#define TAM 5       //Qauntidade de pontos máxima a ser utilizada 

struct ordem {
    double ordem1;
    double ordem2;
    double ordem3;
    double ordem4;

};
//Funções utilizadas no programa
void D (double*x, double *y, int n,ordem *O,double *DN,double valor);

double P (double *x,double *y,double *DN, int n, double valor);

void print (double *x,double *y,double *DN, double result, int n);

void printTabela(ordem*O,int n,double *y);


int main(){
    int n;
    double valor,result;
    double *x = new double[TAM];
    double *y = new double[TAM];
    double *DN = new double[TAM];
    ordem* O = new ordem[TAM];
   
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
//Função que calcula os coeficientes de Newton
  void D (double*x, double *y, int n,ordem *O,double *DN,double valor){
      if(n >= 3){

        DN[0] = y[0];
        for(int i = 0; i < n; i++){
             O[i].ordem1 = (y[i+1] - y[i]) / (x[i+1] - x[i]);
        }
        DN [1] = O[0].ordem1;

        for(int i = 0; i < n-1; i++){
            O[i].ordem2 = (O[i+1].ordem1 - O[i].ordem1) / (x[i+2] - x[i]);
        }
        DN [2] = O[0].ordem2;

    }


        if(n >= 4){
            for(int i = 0; i < 3; i++){
                O[i].ordem3 = (O[i+1].ordem2 - O[i].ordem2) / (x[i+3] - x[i]);
             }
            DN [3] = O[0].ordem3;
        }


        if(n >= 5){
            for(int i = 0; i < 2; i++){
                O[i].ordem4 = (O[i+1].ordem3 - O[i].ordem3) / (x[i+4] - x[i]);
            }
            DN [4] = O[0].ordem4;
        }

        return;
  }
//Função que calcula o polinômio de Newton 
  double P (double *x,double *y,double *DN, int n, double valor){

      double result = 0,
             aux = 1;

      for(int i = 0; i < n; i++){
          result = (DN[i+1] * (valor - x[i]) * aux) + result;
          aux = (valor - x[i])*aux; 
        
      }

      result = result + DN[0];

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

void printTabela(ordem *O,int n,double *y){
    std::cout << "\n\n" << "      ************************|TABELA DE DIFERENÇAS|************************" << "\n\n";


    for(int i = 0; i < n; i++){
        std::cout << y[i] << "    ";
        if((n>=2)&&(i < n-1)) std::cout << O[i].ordem1 << "    ";
        if(n==2) std::cout << std::endl; 

        if((n>=3)&&(i < n-2)) std::cout << O[i].ordem2 << "    ";
        if(i < n-2)std::cout << " " << "    ";
        if(n==3) std::cout << std::endl; 

        if((n>=4)&&(i < n-3)) std::cout << O[i].ordem3 << "    ";
        if(i < n-3) std::cout << " " << "    ";
        if(n==4) std::cout << std::endl; 

        if((n>=5)&&(i < n-4)) std::cout << O[i].ordem4 << "    ";
        if(i < n-4)std::cout << " " << "    ";
        if(n==5) std::cout << std::endl; 
    }
}


