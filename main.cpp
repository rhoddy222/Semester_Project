#include <iostream>
#include <string>
#include <vector>

class HangmanFigure {
public:
    void draw(int incorrectGuesses) {
        switch (incorrectGuesses) {
            case 0:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 1:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 2:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << "  |     |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 3:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << " /|     |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 4:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << " /|\\    |\n";
                std::cout << "        |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 5:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << " /|\\    |\n";
                std::cout << " /      |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
            case 6:
                std::cout << "   _____\n";
                std::cout << "  |     |\n";
                std::cout << "  O     |\n";
                std::cout << " /|\\    |\n";
                std::cout << " / \\    |\n";
                std::cout << "        |\n";
                std::cout << "________|\n";
                break;
        }
    }
};

class HangmanGame {
private:
    std::string secretWord;
    std::string guessedWord;
    std::vector<char> guessedLetters;
    int maxIncorrectGuesses;
    int incorrectGuesses;
    HangmanFigure hangmanFigure;

public:
    HangmanGame(const std::string& word, int maxGuesses)
        : secretWord(word), maxIncorrectGuesses(maxGuesses), incorrectGuesses(0) {
        guessedWord = std::string(secretWord.length(), '_');
    }

    void displayGuessedWord() {
        std::cout << guessedWord << "\n";
    }

    void displayGuessedLetters() {
        std::cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            std::cout << letter << " ";
        }
        std::cout << "\n";
    }

    bool isGameWon() const {
        return guessedWord == secretWord;
    }

    bool isGameOver() const {
        return incorrectGuesses >= maxIncorrectGuesses;
    }

    void makeGuess(char letter) {
        guessedLetters.push_back(letter);
        bool found = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letter) {
                guessedWord[i] = letter;
                found = true;
            }
        }
        if (!found) {
            incorrectGuesses++;
        }
    }

    void play() {
        while (!isGameWon() && !isGameOver()) {
            std::cout << "\n";
            displayGuessedWord();
            displayGuessedLetters();
            hangmanFigure.draw(incorrectGuesses);

            char guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            makeGuess(guess);
        }

        std::cout << "\n";
        displayGuessedWord();
        hangmanFigure.draw(incorrectGuesses);

        if (isGameWon()) {
            std::cout << "Congratulations! You've won!\n";
        } else {
            std::cout << "Sorry, you've lost. The word was: " << secretWord << "\n";
        }
    }
};

int main() {
    HangmanGame game("hangman", 6);
    game.play();

    return 0;
}
