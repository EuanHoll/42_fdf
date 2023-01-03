# FDF

FDF is a 3D wireframe viewer that runs on Linux and MacOS. It reads `.fdf` files and uses my LibFT library for some heavy lifting and 42's MiniLibX for window management and display. The program is written in C.

## Installation

To install the program, use the following command in the terminal:

```bash
./install.bash
```

## Usage

To run the program, use the following command in the terminal, followed by the path to the .fdf file you want to view:

```bash
./fdf /path/to/file.fdf
```

## Controls

The following controls are available:

- Rotate the view using the arrow keys
- Reset the view using R
- Change the projection using P
- Move the camera using WASD and ZX keys
- Zoom in and out using the mouse wheel
- Close the program using the escape key

## Libraries

- 42's MiniLibx: https://github.com/pbondoer/MinilibX
- My own Libft library: https://github.com/EuanHoll/42_libft

## License

This project is released under the Creative Commons Attribution-NonCommercial (CC BY-NC) license. No commercial use is allowed. You can find more information about this license at the following link: https://creativecommons.org/licenses/by-nc/4.0/
