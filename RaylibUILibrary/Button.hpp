#pragma once
#include <iostream>
#include <raylib.h>
#include <functional>


class Button {
public:
	Button(int x, int y, std::string text, std::function<void(void*)> func = [](void* _){}, void* data = nullptr, int width = 200, int height = 50, Color background_color = {255, 255, 255, 255}, Color foreground_color = {0, 0, 0, 255}, int padding = 5, int hasBorder = 0, int borderSize = 0) : _x(x), _y(y), _w(width), _h(height), _bc(background_color), _fg(foreground_color), _padding(padding), _text(text), _hasBorder(hasBorder), _borderSize(borderSize), _callback(func), _data(data) {}
	~Button() {}
	void Input() {
		if (CheckCollisionPointRec(GetMousePosition(), { (float)_x, (float)_y, (float)_w + _padding * 2, (float)_h + _padding * 2 }) && IsMouseButtonPressed(0)) {
			_isFocused = 1;
			_callback(_data);
		}
		if (!CheckCollisionPointRec(GetMousePosition(), { (float)_x, (float)_y, (float)_w + _padding * 2, (float)_h + _padding * 2 }) && IsMouseButtonPressed(0)) {
			_isFocused = 0;
		}
	}

	void Draw() {
		if (_hasBorder == 1) {
			DrawRectangle(_x - _borderSize, _y - _borderSize, _w + _padding * 2 + _borderSize * 2, _h + _padding * 2 + _borderSize * 2, BLACK);
		}
		DrawRectangle(_x, _y, _w + _padding * 2, _h + _padding * 2, _bc);
		int width = MeasureText(_text.c_str(), _h / 1.5);
		if (width > _w) {
			int i = 0;
			while (width > _w) {
				i++;
				width = MeasureText(_text.substr(i, _text.length()).c_str(), _h / 1.5);
			}
			DrawText(_text.substr(i, _text.length()).c_str(), _x + _padding, _y + _h / 3 + _padding, _h / 1.5, _fg);
		}
		else {
			DrawText(_text.c_str(), _x + _padding, _y + _padding + _h / 3, _h / 1.5, _fg);
		}
	}

private:
	int _isFocused = 0;
	int _x, _y;
	int _w, _h;
	int _padding;
	int _hasBorder, _borderSize;
	std::function<void(void*)> _callback;
	void* _data;
	Color _bc, _fg;
	std::string _text;
};