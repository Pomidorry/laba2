#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
using namespace std;
using namespace sf;
class cShape {
private:
	float x, y, r;
	Color c1;
public:
	CircleShape c;
	cShape() {};
	cShape(float X, float Y, float R, Color C1) {
		x = X;
		y = Y;
		r = R;
		c1 = C1;
		c.setFillColor(c1);
		c.setPosition(x, y);
		c.setRadius(r);
	};
	void Draw1(RenderWindow& window) {
		window.draw(c);
	}
};
class rShape {
private:
	float x, y, w, h;
	Color c1;
public:
	RectangleShape r;
	rShape() {};
	rShape(float X, float Y, float W, float H, Color C1) {
		x = X;
		y = Y;
		w = W;
		h = H;
		c1 = C1;
		r.setFillColor(c1);
		r.setPosition(x, y);
		r.setSize(Vector2f::Vector2(w, h));
	};
	void Draw2(RenderWindow& window) {
		window.draw(r);
	}
};
class Buttons {
private:
	float x, y, w, h;
	Color bBgColor;
	Color aBgColor;
	Color bTextColor;
	Color aTextColor;
	string text;
	Font font;
	RectangleShape s;
	Color cl;
public:
	bool buttonIsPressed;
	Text but;
	Buttons() {};
	Buttons(float X, float Y, float W, float H, String text1, Color bTextColor1, Color aTextColor1, Color bBgColor1, Color aBgColor1, RenderWindow& window) {
		x = X;
		y = Y;;
		h = H;
		w = W;
		text = text1;
		bTextColor = bTextColor1;
		aTextColor = aTextColor1;
		bBgColor = bBgColor1;
		aBgColor = aBgColor1;
		font.loadFromFile("CaviarDreams.ttf");
		but.setFont(font);
		but.setCharacterSize(20);
		but.setPosition(x, y);
		but.setFillColor(bTextColor);
		but.setString(text);
		but.setStyle(Text::Bold);
		s.setFillColor(bBgColor);
		s.setPosition(x, y);
		s.setSize(Vector2f::Vector2(w, h));
		if (IntRect(x, y, w, h).contains(Mouse::getPosition(window))) {
			s.setFillColor(aBgColor);
			but.setFillColor(aTextColor);
		}

	}
	void Draw(RenderWindow& window, Color aTextColor1, Color aBgColor1, Color bTextColor1, Color bBgColor1) {
		if (IntRect(x, y, w, h).contains(Mouse::getPosition(window))) {
			s.setFillColor(aBgColor);
			but.setFillColor(aTextColor);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				buttonIsPressed = true;
			}
			if (Mouse::isButtonPressed(Mouse::Right)) {
				buttonIsPressed = false;
			}
		}
		else {
			s.setFillColor(bBgColor);
			but.setFillColor(bTextColor);
		}
		window.draw(s);
		window.draw(but);
	}

	int bip(RenderWindow& window) {
		if (IntRect(x, y, w, h).contains(Mouse::getPosition(window))) {
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				buttonIsPressed = true;
			}
		}
		return buttonIsPressed;
	}
};


int main() {
	RenderWindow window(VideoMode(800, 500), "Shapes");
	int a = 0;
	int w = 0;
	Buttons b(50.0, 50.0, 150, 50, "Draw rectangle", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	Buttons b1(50, 110, 150, 50, "Draw circle", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	Buttons b2(50, 170, 150, 50, "Red circle", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	Buttons b3(50, 230, 150, 50, "Red rectangle", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	Buttons b4(50, 350, 150, 50, "", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	Buttons b5(50, 410, 150, 50, "", Color::Blue, Color::Black, Color::Green, Color::Magenta, window);
	b4.buttonIsPressed = false;
	b5.buttonIsPressed = false;
	b.bip(window);
	b1.bip(window);
	b2.bip(window);
	b3.bip(window);
	String input;
	String input1;
	Text txt;
	Font fnt;
	fnt.loadFromFile("CaviarDreams.ttf");
	txt.setFont(fnt);
	txt.setCharacterSize(40);
	txt.setPosition(50, 350);
	txt.setFillColor(Color::White);
	Font fnt1;
	Text txt1;
	fnt1.loadFromFile("CaviarDreams.ttf");
	txt1.setFont(fnt);
	txt1.setCharacterSize(40);
	txt1.setPosition(50, 410);
	txt1.setFillColor(Color::White);
	while (window.isOpen())
	{

		Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (b4.buttonIsPressed) {
				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128) {
						input += event.text.unicode;
						txt.setString(input);
					}
					if (event.key.code == '\b' && !input.isEmpty()) {
						input.clear();
						txt.setString(input);
					}
				}
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Enter && !input.isEmpty()) {
						b4.buttonIsPressed = false;
						istringstream iss(input, istringstream::in);
						iss >> a;
					}
					txt.setString(input);
				}
			}
			if (b5.buttonIsPressed) {
				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128) {
						input1 += event.text.unicode;
						txt1.setString(input1);
					}
					if (event.key.code == '\b' & !input1.isEmpty()) {
						input1.clear();
						txt1.setString(input1);
					}
				}
				if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Enter && !input1.isEmpty()) {
						b5.buttonIsPressed = false;
						istringstream iss1(input1, istringstream::in);
						iss1 >> w;
					}
					txt1.setString(input1);
				}
			}
		}
		rShape r0(400, 130, w, a, Color::Black);
		cShape c0(450, 130, 130, Color::Black);
		cShape c2(450, 130, 130, Color::Red);
		rShape r1(400, 130, w, a, Color::Red);
		window.clear(Color::White);
		rShape r(0, 0, 300, 500, Color::Black);
		r.Draw2(window);
	
		Text aw;
		ostringstream aw1;

		b4.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		b5.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		window.draw(txt);
		window.draw(txt1);
		b.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		b1.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		b2.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		b3.Draw(window, Color::Blue, Color::Black, Color::Green, Color::Magenta);
		if (b.buttonIsPressed== true) {
			r0.Draw2(window);
		}
		if (b1.buttonIsPressed == true) {
			c0.Draw1(window);
		}
		if (b2.buttonIsPressed == true) {
			c2.Draw1(window);
		}
		if (b3.buttonIsPressed == true) {
			r1.Draw2(window);
		}
		window.display();
	}
}

