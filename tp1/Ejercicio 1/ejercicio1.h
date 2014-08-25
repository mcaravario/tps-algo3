

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;



/*
int saltos = 0;
list<int> tablones_recorridos;
*/


int siguiente_salto(int actual, vector<int> puente, int c){
	int n = 0; 							//variable para evitar bugs cuando estoy fuera del puente
	int res = c;						//cuanto voy a poder saltar
	
	if(actual+c >= puente.size()){
		
		return actual+c;} //si con mi capacidad logro salir del puente salgo
	
	if(actual == -1){ 					//chequeo del primer salto
		n=0;
		

	}else{
		n=actual;
		}
	while(res!=0 && puente[n+res]==1){ //voy reduciendo mi capacidad de salto hasta encontrar el primer tablon sano a saltar
		res--;
		}
	return res+actual;					//retorno la posicion del proximo tablon donde salto
}




bool saltar_puente(vector<int> puente, int c, int& saltos, vector<int>& tablones_recorridos ){

int actual = 0; 						//arranco fuera del puente

while (actual <= puente.size()-1){ 		//recorro hasta salir del puente

	int whereTo = siguiente_salto(actual,puente,c); 	//calculo mi proximo salto

	if (whereTo == actual){ 						//significa que no hay salto posible
	
		return false;
	
	}else{ 
		actual = whereTo; 				//me muevo al proximo tablon
		saltos++;		  				//incremento los saltos que realice
		tablones_recorridos.push_back(actual); //grabo los tablones por donde pase

		}
}
 	


return true;
}
