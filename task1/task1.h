#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <time.h>
#include <cstdlib>

using namespace std;

class Point2D {//stores x and y coordinates
public:
	Point2D();
	Point2D(float x, float y);
	float _x;
	float _y;
};


class Shape {//abstract base class for shapes
private:
	int _RGB[4];//colours and alpha

public:
	Shape();
	Shape(Point2D position, int Red, int Green, int Blue, int Alpha);
	Point2D _Point2D;
	/*int GetRGB() {
		return(_RGB[0], _RGB[1], _RGB[2], _RGB[3]);
	}*/
	int GetR() {
		return(_RGB[0]);
	}
	int GetG() {
		return(_RGB[1]);
	}
	int GetB() {
		return(_RGB[2]);
	}
	int GetAlpha() {
		return(_RGB[3]);
	}
	void SetR(int SetRed) {
		if (SetRed < 0 || SetRed > 255) {
			_RGB[0] = _RGB[0];
		}
		else {
			_RGB[0] = SetRed;
		}
	}
	void SetG(int SetGreen) {
		if (SetGreen < 0 || SetGreen > 255) {
			_RGB[1] = _RGB[1];
		}
		else {
			_RGB[1] = SetGreen;
		}
	}
	void SetB(int SetBlue) {
		if (SetBlue < 0 || SetBlue > 255) {
			_RGB[2] = _RGB[2];
		}
		else {
			_RGB[2] = SetBlue;
		}
	}
	void SetAlpha(int SetAlpha) {
		if (SetAlpha < 0 || SetAlpha > 255) {
			_RGB[3] = _RGB[3];
		}
		else {
			_RGB[3] = SetAlpha;
		}
	}

	virtual void render(SDL_Renderer* renderer) {//commented out code on all render
		//methods so that i dont have to see it constantly write.
		//cout << "RGB+alpha: ";
		//for (int x = 0; x < 4; x++) {
			//cout << _RGB[x] << ",";
		//}
		
	}

};

class Rectangle : public Shape {//inherits shape
private:
	float _Width;
	float _Height;

public:
	Rectangle();
	Rectangle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Width, float Height) : 
		Shape(position, Red, Green, Blue, Alpha),_Width(Width), _Height(Height) {};
	//initialiser list


	float GetWidth() {
		return(_Width);
	}
	float GetHeight() {
		return(_Height);
	}

	void SetWidth(float SetW) {
		_Width = SetW;
	}
	void SetHeight(float SetH) {
		_Height = SetH;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		/*cout << "Rectangle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetWidth() << " " << GetHeight();*/

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, _Point2D._x, GetHeight());
		SDL_RenderDrawLine(renderer, _Point2D._x, GetHeight(), GetWidth(), GetHeight());
		SDL_RenderDrawLine(renderer, GetWidth(), GetHeight(), GetWidth(), _Point2D._y);
		SDL_RenderDrawLine(renderer, GetWidth(), _Point2D._y, _Point2D._x, _Point2D._y);
		//draws a rectangle
		
	}
};

class Triangle : public Shape {// inherits shape
private:
	float _Base;
	float _Height;

public:
	Triangle();
	Triangle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Base, float Height) :
		Shape(position, Red, Green, Blue, Alpha), _Base(Base), _Height(Height) {};
	//initialiser list

	float GetBase() {
		return(_Base);
	}
	float GetHeight() {
		return(_Height);
	}

	void SetBase(float SetB) {
		_Base = SetB;
	}
	void SetHeight(float SetH) {
		_Height = SetH;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		/*cout << "Triangle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetBase() << " " << GetHeight();*/

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), GetHeight());
		SDL_RenderDrawLine(renderer, GetBase(), _Point2D._y, GetBase(), GetHeight());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), _Point2D._y);
		//draws a triangle

	}
};

class Circle : public Shape {// inherits shape
private:
	float _Radius;

public:
	Circle();
	Circle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Radius) :
		Shape(position, Red, Green, Blue, Alpha), _Radius(Radius) {};
	//initialiser list

	float GetRadius() {
		return(_Radius);
	}

	void SetRadius(float SetR) {
		_Radius = SetR;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);
		/*cout << "Circle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetRadius();*/

		int h = 120;
		int k = 100;
		int step = 15;
		int PrevX = _Point2D._x;
		int PrevY = _Point2D._y;

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		for (int theta = 0; theta <= 360; theta += step) {
			_Point2D._x = h + GetRadius()*cos((theta * 3.14159)/180);
			_Point2D._y = k + GetRadius()*sin((theta * 3.14159)/180);
			SDL_RenderDrawLine(renderer, PrevX, PrevY, _Point2D._x, _Point2D._y);
			PrevX = _Point2D._x;
			PrevY = _Point2D._y;

		}
		//draws a circle
		
		
	}

};

