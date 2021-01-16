#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>

using namespace std;

class Point2D {
public:
	Point2D();
	Point2D(float x, float y);
	float _x;
	float _y;
};


class Shape {
private:
	int _RGB[4];

public:
	Shape();
	Shape(Point2D position, int Red, int Green, int Blue, int Alpha);
	Point2D _Point2D;
	int GetRGB() {
		return(_RGB[0], _RGB[1], _RGB[2], _RGB[3]);
	}
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

	virtual void render(SDL_Renderer* renderer) {
		//cout << "RGB+alpha: ";
		//for (int x = 0; x < 4; x++) {
			//cout << _RGB[x] << ",";
		//}
		
		//SDL_RenderDrawLine(renderer);
	}

};

class Rectangle : public Shape {
private:
	float _Width;
	float _Height;

public:
	Rectangle();
	Rectangle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Width, float Height) : 
		Shape(position, Red, Green, Blue, Alpha),_Width(Width), _Height(Height) {};


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
		Shape::render(renderer);//call Shape's render here?
		/*cout << "Rectangle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetWidth() << " " << GetHeight();*/

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetWidth(), GetHeight());
		
	}
};

class Triangle : public Shape {
private:
	float _Base;
	float _Height;

public:
	Triangle();
	Triangle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Base, float Height) :
		Shape(position, Red, Green, Blue, Alpha), _Base(Base), _Height(Height) {};

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
		Shape::render(renderer);//??this here?
		/*cout << "Triangle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetBase() << " " << GetHeight();*/

		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), GetHeight());
		SDL_RenderDrawLine(renderer, GetBase(), _Point2D._y, GetBase(), GetHeight());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetBase(), _Point2D._y);
		
	}
};

class Circle : public Shape {
private:
	float _Radius;

public:
	Circle();
	Circle(Point2D position,
		int Red, int Green, int Blue, int Alpha, float Radius) :
		Shape(position, Red, Green, Blue, Alpha), _Radius(Radius) {};

	float GetRadius() {
		return(_Radius);
	}

	void SetRadius(float SetR) {
		_Radius = SetR;
	}

	virtual void render(SDL_Renderer* renderer) {
		Shape::render(renderer);//??this here?
		/*cout << "Circle " << "x: " << _Point2D._x <<
			"y: " << _Point2D._y << " " << GetRadius();*/


		SDL_SetRenderDrawColor(renderer, GetR(), GetG(), GetB(), GetAlpha());
		SDL_RenderDrawLine(renderer, _Point2D._x, _Point2D._y, GetRadius(), GetRadius());
		//get radius twice?
		
	}

};

