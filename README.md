# 🕹️ so_long

A simple 2D tile-based game written in C using the [MLX42](https://github.com/codam-coding-college/MLX42) graphics library. This project was developed as part of the curriculum at School 42 and received a score of 100/100.

## 📸 Screenshots

![Gameplay Screenshot](assets/screenshot.png)

## 🗂️ Project Structure

```
.
├── Makefile
├── inc/
│   └── so_long.h
├── libft_extended/      # Cloned automatically by Makefile
├── MLX42/               # Cloned automatically by Makefile
├── maps/
├── obj/                 # Object files (generated)
├── src/
│   ├── exit.c
│   ├── flood_fill.c
│   ├── flood_fill_utils.c
│   ├── game.c
│   ├── input.c
│   ├── main.c
│   ├── map.c
│   ├── map_utils.c
│   └── render.c
└── textures/
```

## 🧠 Game Objective

The player navigates a character through a map filled with walls, collectibles, and an exit. The goal is to collect all collectibles and reach the exit.

## ⚙️ Compilation

To compile the project, simply run:

```bash
make
```

This will:
- Clone and build `libft_extended` (from [this repo](https://github.com/Vspaceman11/libft_extended))
- Clone and build `MLX42`
- Compile all sources and link them into the `so_long` executable

## ▶️ Running the Game

```bash
./so_long maps/maze.ber
```

The map must have a `.ber` extension and follow specific formatting rules (rectangular shape, surrounded by walls, exactly one player and exit, at least one collectible, etc.).

## 🎮 Controls

- `W / ↑` – move up
- `S / ↓` – move down
- `A / ←` – move left
- `D / →` – move right
- `ESC` – quit the game

## 📦 Dependencies

- C compiler with C99 support
- `make`, `cmake`, and `git`
- X11 / OpenGL (for MLX42)
- Linux or macOS

## 💡 Notes

- No animations are used in this version.
- Code is modular and placed in `src/`, headers in `inc/`.
- The map validator includes flood fill for path validation.
- Be cautious: on very large maps, the recursive flood fill can cause a stack overflow (segfault).

## 📜 License

This project is educational and part of the 42 curriculum. Please do not use this code for plagiarism.
All original assets (e.g. textures) are free to use unless otherwise stated.
