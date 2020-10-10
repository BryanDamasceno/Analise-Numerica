/*========================== Calculadora de Lagrange ========================= */
//Autor: Bryan Damasceno 
//Data: 09/2020


#include <iostream>

//Funções do programa
void L (double*x,int N,double*LK,double valor);
double polinomio(double* y, double* LK, int N);
void print (double *x,double *y,double *LK, double result, int N);

int main(){
    int N;
    double valor,result;

    std::cout<<"Quantos pontos voce vai utilizar?"<<std::endl;
    std::cin>>N;

     double *x = new double[N];
     double *y = new double[N];
     double *LK = new double[N];

    std::cout<<"Qual ponto voce quer analisar?"<<std::endl;
    std::cin>>valor;

    std::cout << "Digite os valores das abscissas" << std::endl;
    for(int i=0; i < N; i++ ){  
        std::cin >> x[i];  
    }

    std::cout << "Digite os valores das ordenadas" << std::endl;
    for(int i=0; i < N; i++ ){ 
        std::cin >> y[i];   
    }

    L(x,N,LK,valor);             //Calcula os coeficiente de Lagrange no ponto 
    result = polinomio(y,LK,N);  //Calcula o resultado do polinômio de Lagrange 

    print(x,y,LK,result,N); 

    delete [] x;
    delete [] y;
    delete [] LK;
}
//Declaração das funções 
//Calcula o coeficiente de Lagrange 
void L (double*x,int N,double*LK,double valor){ 
 
   for(int j = 0; j < N; j++){ 
       double aux[2] = {1,1};


           for(int i=0; i < N; i++){
              if(i != j){
                  
                aux[0] = (valor - x[i]) * aux[0]; 
                aux[1] = (x[j] - x[i]) * aux[1]; 
              
           }
       }  
        LK[j] = (aux[0]/aux[1]);

   }
}
//Calcula o polinomio de Langrange
  double polinomio(double* y, double* LK, int N){
     double P=0;
       for(int i=0; i < N; i++){
          P = P + (y[i] * LK[i]);
    }
        return P; 
}
//Printa na tela todos os valores 
  void print (double *x,double *y,double *LK, double result, int N){

     std::cout << "      ************************|RESULTADOS|************************" << "\n\n";
     std::cout << "Os pontos utilizados foram:" << std::endl;
   
    for(int i = 0; i < N; i++){ 
        std::cout << "X" << i << " = " << x[i]; 
        std::cout << "           Y" << i << " = " << y[i] << "\n\n";
    }
     std::cout << "Os coeficientes de Lagrange sao: " << "\n";
   
    for(int i = 0; i < N; i++){ 
        std::cout<< "L"<< i << " = " << LK[i]<< "\n\n";
    }
     std::cout << "\n";
     std::cout << "O valor de Y no ponto desejado: " << result << std::endl;
}
