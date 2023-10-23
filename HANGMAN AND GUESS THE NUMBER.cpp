import java.util.Random;
import java.util.Scanner;

public class HangmanGuessTheNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // Hangman variables
        String[] words = {"programming", "hangman", "java", "computer", "keyboard"};
        String hangmanWord = words[random.nextInt(words.length)];
        int maxHangmanAttempts = 6;
        int hangmanAttempts = 0;
        boolean[] guessedLetters = new boolean[hangmanWord.length()];

        // Guess the Number variables
        int lowerBound = 1;
        int upperBound = 100;
        int secretNumber = random.nextInt(upperBound - lowerBound + 1) + lowerBound;
        int maxNumberAttempts = 10;
        int numberAttempts = 0;

        System.out.println("Welcome to Hangman and Guess the Number!");
        System.out.println("Choose a game: ");
        System.out.println("1. Hangman");
        System.out.println("2. Guess the Number");

        int gameChoice = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        if (gameChoice == 1) {
            playHangman(hangmanWord, maxHangmanAttempts, guessedLetters, scanner);
        } else if (gameChoice == 2) {
            playGuessTheNumber(secretNumber, maxNumberAttempts, scanner);
        } else {
            System.out.println("Invalid choice. Please choose 1 for Hangman or 2 for Guess the Number.");
        }

        scanner.close();
    }

    public static void playHangman(String word, int maxAttempts, boolean[] guessedLetters, Scanner scanner) {
        int attempts = 0;

        System.out.println("Welcome to Hangman!");
        
        while (attempts < maxAttempts) {
            System.out.println(displayWord(word, guessedLetters));
            System.out.println("Attempts left: " + (maxAttempts - attempts));

            System.out.print("Guess a letter: ");
            char guess = scanner.next().charAt(0);

            boolean correctGuess = false;
            for (int i = 0; i < word.length(); i++) {
                if (word.charAt(i) == guess) {
                    guessedLetters[i] = true;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                attempts++;
                System.out.println("Incorrect guess!");
            }

            if (isWordGuessed(guessedLetters)) {
                System.out.println("Congratulations! You guessed the word: " + word);
                break;
            }
        }

        if (attempts >= maxAttempts) {
            System.out.println("You ran out of attempts. The word was: " + word);
        }
    }

    public static void playGuessTheNumber(int secretNumber, int maxAttempts, Scanner scanner) {
        int attempts = 0;

        System.out.println("Welcome to Guess the Number!");
        System.out.println("I'm thinking of a number between 1 and 100.");
        
        while (attempts < maxAttempts) {
            System.out.print("Enter your guess: ");
            int guess = scanner.nextInt();
            attempts++;

            if (guess < secretNumber) {
                System.out.println("Try a higher number.");
            } else if (guess > secretNumber) {
                System.out.println("Try a lower number.");
            } else {
                System.out.println("Congratulations! You guessed the number " + secretNumber + " in " + attempts + " attempts.");
                break;
            }
        }
        
        if (attempts >= maxAttempts) {
            System.out.println("You've run out of attempts. The number was: " + secretNumber);
        }
    }

    public static String displayWord(String word, boolean[] guessedLetters) {
        StringBuilder display = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            if (guessedLetters[i]) {
                display.append(word.charAt(i));
            } else {
                display.append('_');
            }
            display.append(' ');
        }
        return display.toString();
    }

    public static boolean isWordGuessed(boolean[] guessedLetters) {
        for (boolean guessed : guessedLetters) {
            if (!guessed) {
                return false;
            }
        }
        return true;
}
}