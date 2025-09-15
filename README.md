# Wordle-Style Game (C++ & Python)

A simple Wordle-style game implemented in **C++** and **Python**. The program picks a random **5-letter** secret word from `wordbank.txt`, then lets the user make up to **6 guesses**. For each letter in a guess, the game reports whether it is:
- **Correct & in the right position**
- **Present in the word but wrong position**
- **Not in the word**

All comparisons are case-insensitive (inputs and secrets are converted to uppercase internally).

---

## Project Summary

- **Languages**: C++ and Python versions
- **Word bank**: `wordbank.txt` (one 5-letter word per line)
- **Rules**: 6 guesses to find the secret 5-letter word
- **Feedback**: Per-letter feedback printed to the terminal
- **Randomness**: Secret word is randomly chosen on each run

---

## Repository Structure (suggested)

```
.
├── cpp/
│   ├── main.cpp        # C++ implementation (uses wordbank.txt)
│   └── wordbank.txt    # shared word list
└── python/
    ├── main.py         # Python implementation (uses wordbank.txt)
    └── wordbank.txt    # shared word list
```

> If your files are arranged differently, update the paths in your code or move `wordbank.txt` accordingly.

---

## Build & Run (C++)

> Requires a C++ compiler with **C++11** support (e.g., `g++`, Clang, MSVC).

```bash
# From the cpp/ directory
g++ -std=c++11 -O2 -o wordle main.cpp
./wordle
```

### C++ Flags/Constants
- `FILENAME = "wordbank.txt"`
- `NUM_LETTERS = 5`
- `NUM_GUESSES = 6`

> The program uppercases guesses and the secret. Ensure `wordbank.txt` contains 5-letter words (one per line).

---

## Run (Python)

> Requires Python 3.x.

```bash
# From the python/ directory
python main.py
```

---

## Example (C++ Console)

```
Guess #1:
crane
C is not in the word
R is in the word but not in position 2
A is in the word but not in position 3
N is not in the word
E is in position 5
...
You guessed the word!
```

> Messages may vary based on your implementation details; the core behavior is the same.

---

## wordbank.txt Format

- Plain text file, **one word per line**
- Prefer uppercase or lowercase 5-letter words; the program normalizes to uppercase
- Example:
  ```
  apple
  other
  crate
  berry
  ```

---

## Implementation Notes (C++)

- **Random selection**: seeded with `srand(time(nullptr))`
- **Input handling**: forces length == `NUM_LETTERS`; uppercases input with `toupper`
- **Letter checks**:
  - Exact match: `guess[i] == secret[i]`
  - In-word check: linear scan across the secret (simple approach)

> The simple in-word scan does not handle duplicate-letter accounting like the official Wordle. It’s intentionally kept straightforward for learning purposes. Feel free to extend it (e.g., count letters and track consumed matches).

---

## Possible Enhancements

- Colored output (green/yellow/gray) for a more authentic feel
- Duplicate-letter handling matching official Wordle rules
- Hard mode (must reuse known correct letters)
- Stats tracking (win streak, average guesses)
- Unit tests for the checker logic
