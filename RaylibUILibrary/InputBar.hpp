#pragma once
#include <iostream>
#include <raylib.h>


class InputBar
{
public:
	InputBar(int x, int y, int width = 400, int height = 50, Color background_color = { 255, 255, 255, 255 }, Color foreground_color = { 0, 0, 0, 255 }, int padding = 5, std::string placeholder = "", Color placeholderColor = { 200, 200, 200, 255 }, int hasBorder = 0, int borderSize = 0, Color borderColor = { 0, 0, 0, 0 })
		: _x(x), _y(y), _w(width), _h(height), _bc(background_color), _fg(foreground_color), _padding(padding), _placeholder(placeholder), _ph(placeholderColor), _hasBorder(hasBorder), _borderSize(borderSize), _boc(borderColor)
	{}
	~InputBar() {}

	void Input() {
		if (_isFocused == 1) {
			int key = GetKeyPressed();
			while (key != 0) {
				if ((key >= 32) && (key <= 125)) {
					if ((IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) || !std::isalpha(key)) {
						_text += key;
					}
					else {
						_text += key + 32;
					}
				}
				key = GetKeyPressed();
			}
			if (IsKeyPressed(KEY_BACKSPACE)) {
				_text = _text.substr(0, _text.length() - 1);
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), { (float)_x, (float)_y, (float)_w + _padding * 2, (float)_h + _padding * 2 }) && IsMouseButtonPressed(0)) {
			_isFocused = 1;
		}
		if (!CheckCollisionPointRec(GetMousePosition(), { (float)_x, (float)_y, (float)_w + _padding * 2, (float)_h + _padding * 2 }) && IsMouseButtonPressed(0)) {
			_isFocused = 0;
		}
	}

	void Draw() {
		if (_hasBorder == 1) {
			DrawRectangle(_x - _borderSize, _y - _borderSize, _w + _padding * 2 + _borderSize * 2, _h + _padding * 2 + _borderSize * 2, _boc);
		}
		DrawRectangle(_x, _y, _w + _padding * 2, _h + _padding * 2, _bc);
		int width = MeasureText(_text.c_str(), _h / 1.5);
		if (_text.size() == 0) {
			int placeholderWidth = MeasureText(_text.c_str(), _h / 1.5);
			if (placeholderWidth > _w) {
				int i = 0;
				while (placeholderWidth > _w) {
					i++;
					placeholderWidth = MeasureText(_text.c_str(), _h / 1.5);
				}
				DrawText(_placeholder.substr(i, _placeholder.length()).c_str(), _x + _padding, _y + _h / 3 + _padding, _h / 1.5, _ph);
			}
			else {
				DrawText(_placeholder.c_str(), _x + _padding, _y + _padding + _h / 3, _h / 1.5, _ph);
			}
		}
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
		if (_isFocused == 1) {
			DrawRectangle(_x + _padding + width, _y + _padding + _h / 3, 1, _h / 1.5, _fg);
		}
	}

	std::string GetText() {
		return _text;
	}

private:
	int _isFocused = 0;
	int _x, _y;
	int _w, _h;
	int _padding;
	int _hasBorder, _borderSize;
	std::string _placeholder;
	Color _bc, _fg, _ph, _boc;
	std::string _text;

};