#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <limits>

class TextRectangle
{
private:
	int width_;
	int height_;

public:
	//Constructeur
	TextRectangle(int width, int height) : width(width), height(height) {
		setWidth(width);
		setHeight(height);
	}

	// Getters
	int getWidth() const { return width_; }
	int getHeight() const { return height_; }

	// Setters
	bool setWidth(int width) {
		if (width > 0 && width < 10) { width_ = width; return true; }
		return false;
	}

	bool setHeight(int height) {
		if (height > 0 && height < 10) { height_ = height; return true; }
		return false;
	}

	//surface
	int getArea() const {
		return width_ * height_;
	}

	// Périmètre
	int getPerimeter() const {
		return 2 * (width_ + height_);
	}

	// Affichage des caractéristiques du rectangle
	void print() const {
		std::cout << "La largeur du rectangle est : " << width_
			<< ", la hauteur = " << height_
			<< ", la surface = " << getArea()
			<< ", et le perimetre = " << getPerimeter()
			<< '\n';
	}

	//Dessin du rectangle en version text
	void drawArea(const char& pattern) const {
		for (int r =0; r< height_; r++) {
			for (int c = 0; c < width_; c++) {
				std::cout << pattern;
			}
			std::cout << '\n';
		}
	}

	//Dessin du périmètre avec le motif
	void drawPerimeter(const char& pattern) const {
		for (int r=0; r < height_; ++r) {
			for (int c = 0; c < width_; c++) {
				if (r == 0 || r == height_ - 1 {
					// Première ou dernière ligne : ligne pleine
					for (int c = 0; c < width_; ++c) std::cout << pattern;
					std::cout << '\n';
				}
				else {
					// Lignes intermédiaires : caractère puis espaces puis caractère
					if (width_ == 1) {
						// Colonne unique
						std::cout << pattern << '\n';
					}
					else {
						std::cout << pattern;                           // bord gauche
						for (int c = 0; c < width_ - 2; ++c) std::cout << ' ';
						std::cout << pattern << '\n';                  // bord droit
					}
				}
			}
		}
	};

	int main() {
		TextRectangle rect;

		int w = 0, h = 0;
		// Lecture de la largeur (1..9)
		do {
			std::cout << "Entrez la largeur (1..9) : ";
			if (!(std::cin >> w)) {
				// si entrée invalide, vider l'état et ignorer la ligne
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				w = 0;
				continue;
			}
		} while (!rect.setWidth(w));

		// Lecture de la hauteur (1..9)
		do {
			std::cout << "Entrez la hauteur (1..9) : ";
			if (!(std::cin >> h)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				h = 0;
				continue;
			}
		} while (!rect.setHeight(h));

		// Lecture du motif (un seul caractère)
		char motif = '*';
		std::cout << "Entrez un caractere pour le motif (ex: * # @) : ";
		std::cin >> motif;

		// Affichage des informations et dessins
		rect.print();
		std::cout << "\nDessiner la zone remplie :\n";
		rect.drawArea(motif);

		std::cout << "\nDessiner le perimetre :\n";
		rect.drawPerimeter(motif);

		return EXIT_SUCCESS;
	}