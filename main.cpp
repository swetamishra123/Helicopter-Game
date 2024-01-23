#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits> // Include for numeric_limits

using namespace std;

class HelicopterGame {
private:
    int helicopterPosition;
    int obstaclePosition;
    int score;

public:
    HelicopterGame() : helicopterPosition(10), obstaclePosition(30), score(0) {}

    void drawGame() {
        system("cls"); // Clear the console

        // Draw helicopter
        for (int i = 0; i < helicopterPosition; ++i)
            cout << ' ';
        cout << "H\n";

        // Draw obstacle
        for (int i = 0; i < obstaclePosition; ++i)
            cout << ' ';
        cout << "|\n";

        // Draw ground
        for (int i = 0; i < 40; ++i)
            cout << '-';
        cout << "\n";

        // Display score
        cout << "Score: " << score << "\n";
    }

    void updateGame() {
        // Move obstacle to the left
        obstaclePosition--;

        // Check for collision
        if (helicopterPosition == obstaclePosition) {
            gameOver();
        }

        // Check if obstacle passed
        if (obstaclePosition < 0) {
            obstaclePosition = 40; // Reset obstacle position
            score++; // Increment score
        }
    }

    void moveHelicopter(char input) {
        // Ensure smooth movement by clearing the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (input == 'w' && helicopterPosition > 0)
            helicopterPosition--;
        else if (input == 's' && helicopterPosition < 20)
            helicopterPosition++;
    }

    void gameOver() {
        system("cls");
        cout << "Game Over! Your score: " << score << "\n";
        exit(0);
    }
};

int main() {
    HelicopterGame game;

    while (true) {
        game.drawGame();
        game.updateGame();

        cout << "Press 'w' to move up, 's' to move down: ";

        char input;
        if (cin >> input) {
            game.moveHelicopter(input);
        }

        // Introduce a small delay to make the game playable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
