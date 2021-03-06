# Wolf3D
###### made by tmaluh __(\_ipal)__
###### README.md contain not all info about project and after update project after last changes in libft its may work unstability
[![Video preview](https://raw.githubusercontent.com/Iipal/Wolf3D-42/master/screenshot.png)](https://youtu.be/s2rnZQIKDzw)
## Installation:

#### *SDL2*

__*Ubuntu:*__

```bash
sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev
```

__*Fedora:*__

```bash
sudo dnf install SDL2-devel SDL2_mixer-devel SDL2_ttf-devel
```

__*MacOS:*__

All ready for use. Just type **make**.

__*Windows:*__

- [MinGW](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/index.php).
- [Visual Studio](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvsnet2010u/index.php).

## Compiling

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.

When you have already installed SDL2 library you can use this simple rules:
- **make**: Compile all.
- **make clean**: Delete temporary files.
- **make del**: Delete temporary Wolf3D files only(if you changed code use `make del && make` for re-compile only Wolf3D executable without libft).
- **make fclean**: Delete executable Wolf3D file & libft.
- **make re**: It's rules - **make fclean** & **make** in one.

## Usage:

```bash
./wolf3d maps/map_name.w3d
```

- `[W | S]`: Moving forward | backward.
- `[A | D]`: Rotate left | right.
- `[T]`: Toggle Textured\Flat rendering method.
- `[M]`: Toggle mini-map rendering.
- `[F]`: Toggle Fog rendering.
- `[C]`: Switch Fog colors.
- `[LShift]`: Step & rotate boost.
- `[Z]` - Stop\Play steps sounds.
- `[Q]`: Stop\Play background in-game music.
- `[+ | -]`: Inc\Decrease background volume.
- `[R]`: Toggle FPS\ms rendering info.
- `[H]`: Toggle blur effect rendering.
- `[Y | N]`: Inc\Decreaase bluring effect.
- `[ESC]`: Close Wolf3D.

#### <===> MLX <===>

If you are crazy and want to run this project using MLX library and without many features - follow this rules:

```bash
git clone https://github.com/Iipal/Wolf3D-42.git wolf3d
cd wolf3d
git checkout 5acec91
make
```
