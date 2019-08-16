
// Main 
#include<vector>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Soldado.cpp"
#include "Asalto.cpp"
#include "Soporte.cpp"

using namespace std;

void equipar();
string token(string,string,int);
void listar();

vector<Soldado*> blu;
vector<Soldado*> red;

vector<Soldado*> * ataque;
vector<Soldado*> * defensa;

int main() {
	
	srand(time(NULL));
	
	equipar();
	
	int op = 0;
	int sim = 0;
	
	while (op != 3) {
		cout << "....:::: SOLDADOS ::::...." << endl;
		cout << "Examen 1 de programacion 3" << endl << endl;
		cout << "Main menu" << endl;
		cout << "1. Listar equipos" << endl;
		cout << "2. Iniciar simulacion" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: "; cin >> op;
		
		system("CLS");
		
		if (op == 1) {
			listar();
			system("pause");
		}
		
		if (op == 2 and sim == 0) {
			cout << "..:: SIMULACION ::.." << endl;
			int turno = 0;
			
			while (blu.size() > 0 && red.size() > 0) {
				if (turno == 0) {
					// Turno de atacar del blu
					int atacante = (rand()%blu.size());
					int vistima = (rand()%red.size());
					
					
					
					int dano = blu.at(atacante)->attack(red.at(vistima)->getTipo());
					
					// Danar
					red.at(vistima)->defense(dano, blu.at(atacante)->getTipo());
					
					//cout << "Atacante: " << blu.at(atacante)->getNombre();
					//cout << "Vida de la victima: " << red.at(vistima)->getHP();
					
					// Ver si murio
					if (red.at(vistima)->getHP() <= 0) {
						red.erase(red.begin() + vistima);
					}
					
					// Cambiar turno
					turno = 1;
				}else{
					// Turno de atacar del red				
					int atacante = (rand()%red.size());
					int vistima = (rand()%blu.size());
					
					int dano = red.at(atacante)->attack(blu.at(vistima)->getTipo());
					
					// Danar
					blu.at(vistima)->defense(dano, red.at(atacante)->getTipo());
					
					// Ver si murio
					if (blu.at(vistima)->getHP() <= 0) {
						blu.erase(blu.begin() + vistima);
					}
					
					// Cambiar turno
					turno = 0;
				}			
			}
			
			if (blu.size() == 0) {
				cout << "Gano el equipo RED!" << endl;
				string n;
				ofstream Escribir;
				Escribir.open("./Scoreboard.txt",ios::app);
				Escribir << "Gano el equipo RED con los soldados: " << endl;
				
				for (int i = 0; i < red.size(); i++) {
					n = red.at(i)->getNombre();
					Escribir << (i+1) << ". " << n << endl;
				}
				
				Escribir << endl;
				
				Escribir.close();
			}else{
				cout << "Gano el equipo BLU!" << endl;
				string n;
				ofstream Escribir;
				Escribir.open("./Scoreboard.txt",ios::app);
				Escribir << "Gano el equipo BLU con los soldados: " << endl;
				
				for (int i = 0; i < blu.size(); i++) {
					n = blu.at(i)->getNombre();
					Escribir << (i+1) << ". " << n << endl;
				}
				
				Escribir << endl;
				
				Escribir.close();
			}
			
			cout << "Revise la carpeta de origen para el resumen." << endl;
			sim = 1;
			
			system("pause");
			
		}else{
			if (op == 2) {
				cout << "Cierre y vuelva a abrir para simular de nuevo!" << endl;
				system("pause");
			}
		}
		
		
		system("CLS");
	}
	
	
	


}

void listar() {
	cout << "..:: Equipo BLU ::.." << endl;
	for (int i = 0; i < blu.size(); i++) {
		cout << (1+i) << ". ";
		blu.at(i)->print();
	}
	
	cout << endl;
	
	cout << "..:: Equipo RED ::.." << endl;
	for (int i = 0; i < blu.size(); i++) {
		cout << (1+i) << ". ";
		red.at(i)->print();
	}
}

void equipar() {
	fstream Leer;
	string linea;
	
	Leer.open("./Save1.txt");
	
	getline(Leer, linea);
	
	string b, r;
	
	b = token(linea,"&",1);
	r = token(linea,"&",2);
	
	//cout << b << endl;
	//cout << r << endl;
	
	int i = 1;
	
	linea = b;
	
	//cout << "b: " << b << endl;
	//cout << "r: " << r << endl;
	
	while (true) {
		if(token(linea,"/",i) == "")
			break;
			
		string tipo = token(linea,"/",i);
		string n = token(linea,"/",(i + 1));
		stringstream convert;
		int h, s, v, e;
		
		convert << token(linea,"/",i + 2);
		convert >> h;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 3);
		convert >> s;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 4);
		convert >> v;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 5);
		convert >> e;
		convert.str("");
		convert.clear();
		
		//cout << "Agregado: " << n << " indice: "<< i << " size b: "<< b.size()<<endl; 
		
		if (tipo == "Asalto") {
			blu.push_back(new Asalto(n,h,s,v,e));
		}else{
			blu.push_back(new Soporte(n,h,s,v,e));
		}
		
		i+=6;
	}
	
	i = 1;
	linea = r;
	
	while (true) {
		if(token(linea,"/",i) == "")
			break;
		string tipo = token(linea,"/",i);
		string n = token(linea,"/",(i + 1));
		stringstream convert;
		int h, s, v, e;
		
		convert << token(linea,"/",i + 2);
		convert >> h;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 3);
		convert >> s;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 4);
		convert >> v;
		convert.str("");
		convert.clear();
		convert << token(linea,"/",i + 5);
		convert >> e;
		convert.str("");
		convert.clear();
		
		//cout << "Agregado: " << n << " indice: "<< i << " size b: "<< b.size()<<endl;
		
		if (tipo == "Asalto") {
			red.push_back(new Asalto(n,h,s,v,e));
		}else{
			red.push_back(new Soporte(n,h,s,v,e));
		}
		
		i+=6;
	}
	
	//cout <<endl << blu.size() <<endl;
}

string token(string cadena, string divisor, int pos) {
       if(cadena.size()>0){
         char oracion[cadena.size()]; 
         for (int i=0;i<=cadena.size();i++)
         {
               oracion[i]=cadena[i];
         }                    
         char *ptrtoken; 
         int num=1;
         const char* d=divisor.c_str();
         ptrtoken = strtok(oracion , d);             
         while(ptrtoken){
             if(num==pos){ 
                return ptrtoken;                    
             }                 
             ptrtoken = strtok(NULL, d);
             num++;
         }
         return "";
       }else{
             return "";
       }
}
