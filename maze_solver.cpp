#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;

char maze[MAX][MAX];
bool visited[MAX][MAX];

int rows = 0, cols = 0;
int startRow, startCol;
int exitRow, exitCol;

int recursiveCalls = 0;

// Function to check if a cell is valid
bool isValid(int r, int c)
{
    return (r >= 0 && r < rows && c >= 0 && c < cols &&
            maze[r][c] != '#' && !visited[r][c]);
}

// Recursive function to find path
bool findPath(int r, int c)
{
    recursiveCalls++;
    cout << "Entering cell (" << r << "," << c << ")" << endl;

    // Base case: reached exit
    if (r == exitRow && c == exitCol)
    {
        cout << "Exit found!" << endl;
        return true;
    }

    // If invalid cell
    if (!isValid(r, c))
        return false;

    visited[r][c] = true;

    // Mark path (do not overwrite S)
    if (maze[r][c] == '.')
        maze[r][c] = '*';

    // Move Right
    if (findPath(r, c + 1)) return true;
    // Move Down
    if (findPath(r + 1, c)) return true;
    // Move Left
    if (findPath(r, c - 1)) return true;
    // Move Up
    if (findPath(r - 1, c)) return true;

    // Backtracking
    cout << "Backtracking from (" << r << "," << c << ")" << endl;

    if (maze[r][c] == '*')
        maze[r][c] = '.';

    return false;
}

int main()
{
    ifstream file("input.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 0;
    }

    string line;
    while (getline(file, line))
    {
        cols = line.length();
        for (int j = 0; j < cols; j++)
        {
            maze[rows][j] = line[j];

            if (maze[rows][j] == 'S')
            {
                startRow = rows;
                startCol = j;
            }
            if (maze[rows][j] == 'E')
            {
                exitRow = rows;
                exitCol = j;
            }
        }
        rows++;
    }
    file.close();

    cout << "Maze loaded successfully!" << endl;

    if (findPath(startRow, startCol))
    {
        cout << "\nFinal Solved Maze:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << maze[i][j] << " ";
            cout << endl;
        }

        ofstream outFile("output.txt");
if(outFile)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            outFile << maze[i][j];
        outFile << endl;
    }
    outFile.close();
    cout << "Solved maze saved to output.txt" << endl;
}
    }
    else
    {
        cout << "No path found!" << endl;
    }

    cout << "\nTotal recursive calls: " 
    << recursiveCalls << endl;

    return 0;
}
