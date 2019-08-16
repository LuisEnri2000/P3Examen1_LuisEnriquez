
// Clase soldado padre
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

using namespace std;

#ifndef SOLDADO_CPP
#define SOLDADO_CPP

class Soldado {
	protected:
		string nombre;
		int hp;
		int strength;
		
	public:
		
		Soldado(){}
		
		Soldado(string n, int h, int s) {
			nombre = n;
			hp = h;
			strength = s;
		}
		
		//funciomes virtuales puras:
		virtual int attack(int) = 0;
		virtual void defense(int, int) = 0;
		virtual void print() = 0;
		virtual int getTipo() = 0;
		virtual int getHP() = 0;
		virtual string getNombre() = 0;
		
		
		~Soldado(){}
};
#endif
