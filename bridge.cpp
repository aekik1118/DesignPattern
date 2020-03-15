#include <iostream>

using namespace std;


//Implementor
class Drawing {
public:
	virtual void DrawLine() = 0;
	virtual void Fill() = 0;
};


//ConcreteImplementor
class AStyleDrawing : public Drawing {
public:
	void DrawLine() {
		cout << "Draw AStyle Line" << endl;
	}

	void Fill() {
		cout << "Fill AStyle" << endl;
	}
};

class BStyleDrawing : public Drawing {
public:
	void DrawLine() {
		cout << "Draw BStyle Line" << endl;
	}

	void Fill() {
		cout << "Fill BStyle" << endl;
	}
};


//Abstraction
class Shape {
	Drawing * drawing;
public:
	Shape(Drawing * drawing) {
		this->drawing = drawing;
	}

	virtual void Draw() = 0;

	void DrawLine() {
		drawing->DrawLine();
	}

	void Fill() {
		drawing->Fill();
	}
};


//RefinedAbstraction
//사각형 그리기는 선분 4개를 그리고 색 채우기
class Rectangle : public Shape {
public:
	Rectangle(Drawing* drawing) :Shape(drawing) {};
	void Draw() {
		cout << "Draw Rectangle" << endl;
		DrawLine();
		DrawLine();
		DrawLine();
		DrawLine();
		Fill();
		cout << endl;
	}
};


//삼각형 그리기는 선분 3개를 그리고 색 채우기
class Triangle : public Shape {
public:
	Triangle(Drawing* drawing) :Shape(drawing) {};
	void Draw() {
		cout << "Draw Triangle" << endl;
		DrawLine();
		DrawLine();
		DrawLine();
		Fill();
		cout << endl;
	}
};


//example
int main() {
	AStyleDrawing aStyleDrawing;
	BStyleDrawing bStyleDrawing;

	Triangle TriangleA(&aStyleDrawing);
	TriangleA.Draw();

	Triangle TriangleB(&bStyleDrawing);
	TriangleB.Draw();

	Rectangle rectangleA(&aStyleDrawing);
	rectangleA.Draw();

	Rectangle rectangleB(&bStyleDrawing);
	rectangleB.Draw();

	return 0;
}