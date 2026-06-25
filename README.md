*This project has been created as part of the 42 curriculum by **marthoma** & **bdemouge**.*

[Subject](cdn.intra.42.fr/pdf/pdf/199846/en.subject.pdf)

# *⋆˚✰ ݁˖⭑. Description *⋆˚✰ ݁˖⭑.

cub3D is a first-person raycasting engine inspired by Wolfenstein 3D, the
game widely considered to be the ancestor of the modern FPS genre. The
program parses a custom scene description file (`.cub`) describing a 2D
maze, then renders a real-time 3D first-person view of that maze using the
raycasting algorithm and the MiniLibX graphics library.

The goal of the project was to implement, from scratch and in C, the core
mathematics and rendering pipeline behind raycasting: casting rays from the
player's position, computing wall intersections (DDA algorithm), and
projecting the result into a 3D-looking view, all while keeping the program
robust against malformed input.

### Features

- Real-time raycasting engine rendering a maze from a first-person view
- Four distinct wall textures, one per cardinal direction (North, South,
  East, West), correctly selected depending on which face of the wall is hit
- Configurable floor and ceiling colors, set independently via the scene
  file
- Smooth player movement (`W`, `A`, `S`, `D`) and camera rotation (`←`, `→`)
- Clean exit on `ESC` or on closing the window via the window manager
- Strict `.cub` scene file parser:
  - Accepts any valid ordering of texture/color elements
  - Tolerates extra blank lines and repeated spaces/tabs as separators
  - Validates map closure, allowed characters, and a single player start
    position
  - Rejects any malformed file with a clear, explicit error message

**Bonus features implemented:**
- Wall collisions, preventing the player from walking through walls
- A real-time minimap showing the player's position and orientation in the maze

# *⋆˚✰ ݁˖⭑. Instructions *⋆˚✰ ݁˖⭑.

### Dependencies

- A C compiler (`cc`)
- MiniLibX (and its own dependencies: an X11 server, Xext and Xrender)
- `make`

### Compilation

```bash
make        # builds the mandatory part
make bonus  # builds the mandatory part with bonus features included
```

Other available rules:

```bash
make clean   # remove object files
make fclean  # remove object files and the binary
make re      # fclean + all
make test    # tester with all available maps
```

### Running

```bash
./cub3D path/to/file.cub
```

The scene file must have the `.cub` extension and follow the format
described in the [Scene file format](#file-format) section below.

### Controls

| Key                | Action                       |
|---------------------|-------------------------------|
| `W` / `A` / `S` / `D` | Move forward / left / back / right |
| `←` / `→`           | Look left / right             |
| `ESC`               | Quit cleanly                  |
| Window close button | Quit cleanly                  |

### File format

A `.cub` file describes four wall textures, a floor color, a ceiling color,
and a map, e.g.:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

- `0` is an empty/walkable tile, `1` is a wall, and one of `N`, `S`, `E`,
  `W` marks the player's starting position and facing direction.
- The map must be fully enclosed by walls.
- Elements other than the map can appear in any order and can be separated
  by any number of blank lines or spaces/tabs.
- The map must always be the last element in the file.

Any malformed scene file is rejected with `Error\n` followed by a
descriptive message, and the program exits cleanly without leaking memory.

# *⋆˚✰ ݁˖⭑. Resources  *⋆˚✰ ݁˖⭑.

The forest texture background was made by Eder Muniz : https://edermunizz.itch.io/ - we added some characters on top of them.

Youtube : [Make your own Raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCXqoZAc8-tyDSaO8jnabOEFhdTQfx77_&index=1).
Medium : [3D Ray-casting Game with Cub3D by Abdilah CH](https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a).
Lodev : [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html).
[42's MiniLibX documentation](https://github.com/42Paris/minilibx-linux).

# *⋆˚✰ ݁˖⭑. Use of AI  *⋆˚✰ ݁˖⭑.

AI (Claude) was used primarily as a **debugging aid** during development, not as a code generator for core logic. It was also used to generate a batch of additional `.cub` test maps (valid and invalid) to test the parser against edge cases described in the subjec (duplicate identifiers, unclosed maps, out-of-range colors, jagged map rows, tabs as separators, etc.), and for this readme.

