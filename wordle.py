# wordle.py is a program for a simplified version of the word game wordle.
# This is fully implemented in python, and you should use it as a reference

import random

# open word back file and pick and return a random word from it
def get_word():
	f = open(filename)
	all_words = f.readlines()
	f.close()
	word = all_words[random.randrange(len(all_words))].strip().upper()
	return word

# solicit a guess from a user; require 5 letters and capitalize automatically
def get_guess(prompt):
	guess = input(prompt).upper()
	while len(guess) != num_letters:
		print('Your guess must be',num_letters,'letters.')
		guess = input(prompt).upper()
	return guess

# report the letter-by-letter similarity of a guess to a secret word
def process_guess(guess, secret):
	for i in range(num_letters):
		letter = guess[i]
		# check whether the ith letter is in the correct spot
		if secret[i] == letter:
			print(letter,'is in position',i+1)
		else:
			# check whether the ith letter is (elsewhere) in the secret
			in_word = False
			for j in range(num_letters):
				if secret[j] == letter:
					in_word = True
					break
			if in_word:
				print(letter,'is in the word but not in position',i+1)
			else:
				print(letter,'is not in the word')

# specify word back filename, word length, and max number of guesses
filename = 'wordbank.txt'
num_letters = 5
num_guesses = 6

# pick secret word
secret = get_word()
#secret = 'PLANE' # feel free to hardcode your own words when testing
#print(secret) # you may also print out the word for testing
print('The secret word has been selected. Start guessing!')

# play game
for i in range(num_guesses):
	guess = get_guess('Guess #' + str(i+1) + ': ')
	if guess == secret: break
	process_guess(guess,secret)

# report outcome
if guess == secret:
	print('You guessed the word!')
else:
	print('You ran out of guesses before guessing the word:',secret)
