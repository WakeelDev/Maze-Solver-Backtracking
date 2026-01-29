

# Maze Solver using Recursive Backtracking (C++)

This project was developed as part of the **Fundamentals of Computer Programming (FOCP)** laboratory course. It demonstrates the use of the **Recursive Backtracking** algorithm to solve a 2D maze by finding a valid route from the start point (**S**) to the exit (**E**).

## 👥 Contributors

* **Wakeel Khan**
* **Muhammad Hassan**
* **Department:** BS Artificial Intelligence, NUST Balochistan Campus

## 🚀 Project Description

The application automates maze solving by reading the maze structure from an external file and exploring possible paths to determine a solution while avoiding walls and repeated paths.

### Main Features

* **File-Based Input:** Loads the maze configuration from `input.txt`.
* **Automatic Position Detection:** Locates the start (`S`) and exit (`E`) points within the maze.
* **Pathfinding Algorithm:** Uses four-directional movement (Right, Down, Left, Up).
* **Backtracking Logic:** When a dead end is encountered, the program reverses its steps and tries an alternative route.
* **Execution Logs:** Prints a detailed trace of every cell visited during the solving process.

## 📊 Program Output

After successful execution, the program provides:

* **Solved Maze:** The correct path is highlighted using `*`.
* **Recursive Trace:** A step-by-step record of visited cells.
* **Performance Insight:** Displays the total number of recursive calls to indicate algorithm efficiency (for example, 13 calls for the sample maze).

## 📁 Project Files

* `main.cpp` – Contains the main program logic and recursive backtracking implementation.
* `input.txt` – Stores the maze layout.
* `output.txt` – Saves the final solved maze for reference.

---

**Instructor:** Dr. Bushra Qayyum
**Lab Engineer:** Ms. Zainab Zahid


