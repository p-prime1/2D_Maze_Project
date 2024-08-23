2D Maze Project
Create a 3D maze application using raycasting

Team
Nwaka Nduka Precious (Developer)

Technologies
Simple DirectMedia Layer (SDL2) – Handles low-level access to audio, keyboard, mouse, and graphics hardware via OpenGL
Raycasting – This is the main engine of the game. It is essential for simulating 3D effects. Raycasting allows the creation of a pseudo-3D environment without the complexity of full 3D rendering

Challenge Statement
Develop a 3D maze game using raycasting, leveraging SDL2 for rendering. The game should function seamlessly on Linux platforms and subsequently on Windows

Goals: To implement a fully functional 3D maze with player movement, and ensure smooth cross-platform performance.

Risks
Complexity: Implementing raycasting can be challenging considering it's a novel technology to me.

Database: Integrating MySQL might raise a new set of challenges

Infrastructure
Trunk-based Development(No Branching) – This approach is efficient for solo development, Simplifying the workflow.

Testing – I intend to use Docker to emulate different Linux environments to ensure the application behaves consistently for different environments

Deployment – Utilizing Github for deployment.

Storage – Store game state, and user data scores using an SQL database, I intend to use the MySQL Connector/C library.

The program would be compiled using a GCC compiler

Existing Solutions
Similar solutions exist, such as Minecraft, Lego Worlds, and Terraria. This project though uses raycasting which sets it apart from its counterparts which are fully 3D environments


