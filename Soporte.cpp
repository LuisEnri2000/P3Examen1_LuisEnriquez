
// Soporte
// Soldado 
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Soldado.cpp"

using namespace std;

#ifndef SOPORTE
#define SOPORTE

class Soporte : public Soldado {
	private:
		int blindaje;
		int camuflaje;
		
	public:
		
		Soporte() : Soldado()  {}
		
		Soporte(string n, int h, int s, int v, int e) : Soldado(n,h,s) {
			blindaje = v;
			camuflaje = e;
		}
		
		~Soporte();
		
		int attack(int tipo) {
			if (tipo == 1) {
				return strength * (15 + camuflaje);
			}else{
				return strength * 10;
			}
		}
		
		void defense(int att, int tipo) {
			if (tipo == 1) {
				hp -=  (att / (blindaje * 2));
			}else{
				hp -= att;
			}
		}
		
		int getTipo() {
			return 2;
		}
		
		int getHP() {
			return hp;
		}
		
		string getNombre() {
			return nombre;
		}
		
		void print() {
			cout << "Soporte: " << nombre << endl;
		}
				
};
#endif
