# Essence of Object Oriented Notes
### What is code rot, and why does it happen?
- Code rot is bad program design.
- Specifically, code rot is known by its smells: viscosity (slowness and difficulty in testing), immobility (links between modules), rigidity (difficulty and cost to change), and fragility (How easily the code breaks when something somewhere else is changed).
- Code rot makes code harder and harder to expand programs.
- Code rot happens when developers are careless, and make modules that will need to keep growing with the program. Instead, modules and objects should be made to be used anywhere interchangeably throughout the program without change.
### What is the design of a software product?
- The design of a software product is the source code, the binary that runs it is the product.
### According to Uncle Bob, what is the essential characteristic of Object-Oriented design?
- The essential characteristic of OO is the ability to invert key dependencies.
- It's about managing dependencies.
- It prevents code rot if done correctly.
- Make the sender and recipient not be dependant on each other.