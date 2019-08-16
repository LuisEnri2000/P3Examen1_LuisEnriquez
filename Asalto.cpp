
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

#ifndef ASALTO
#define ASALTO

class Asalto : public Soldado {
	private:
		int velocidad;
		int extra;
		
	public:
		
		Asalto() : Soldado()  {}
		
		Asalto(string n, int h, int s, int v, int e) : Soldado(n,h,s) {
			velocidad = v;
			extra = e;
		}
		
		~Asalto();
		
		int attack(int tipo) {
			if (tipo == 1) {
				return strength * 10;
			}else{
				return strength * (10 + (velocidad * 2));
			}

		}
		
		void defense(int att, int tipo) {
			if (tipo == 1) {
				hp -= att;
			}else{
				hp -= att/extra;
			}
		}
		
		int getHP() {
			return hp;
		}
		
		string getNombre() {
			return nombre;
		}
		
		int getTipo() {
			return 1;
		}
		
		void print() {
			cout << "Asaltante: " << nombre << endl;
		}
				
};
#endif
