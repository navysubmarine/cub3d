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
- A real-time minimap showing the player's position and orientation in the
  maze

# *⋆˚✰ ݁˖⭑. Instructions *⋆˚✰ ݁˖⭑.


# *⋆˚✰ ݁˖⭑. Resources  *⋆˚✰ ݁˖⭑.

Youtube : [Make your own Raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCXqoZAc8-tyDSaO8jnabOEFhdTQfx77_&index=1).
Medium : [3D Ray-casting Game with Cub3D by Abdilah CH](https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a).

# *⋆˚✰ ݁˖⭑. Use of AI  *⋆˚✰ ݁˖⭑.

AI (Claude by Anthropic) was used during this project for the following task:

