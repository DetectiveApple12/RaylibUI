# Raylib UI

## Current Usable

- InputBar : #include "InputBar.hpp"
    - 
    ```cpp
    InputBar(
                int x, 
                int y, 
                int width = 400, 
                int height = 50, 
                Color background_color = {255, 255, 255, 255}, 
                Color foreground_color = {0, 0, 0, 255}, 
                int padding = 5, 
                std::string placeholder = "", 
                Color placeholderColor = {200, 200, 200, 255}, 
                int hasBorder = 0, 
                int borderSize = 0
            )
    InputBar.Draw(); // Draw the input bar.
    InputBar.Input(); // Get input.
    InputBar.GetText(); // Get text.
    ```