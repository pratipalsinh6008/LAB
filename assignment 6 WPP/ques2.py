'''2. Write a class called Rock_paper_scissors that implements the logic of the game Rock paper-
scissors.  For  this  game  the  user  plays  against  the  computer  for  a  certain  number  of  rounds. 
Your class should have fields for the how many rounds there will be, the current round number, 
and the number of wins each player has. There should be methods for getting the computer’s 
choice,  finding  the  winner  of  a  round,  and  checking  to  see  if  someone  has  one  the  (entire) 
game. You may want more methods.'''


import random

class RPS:
    def __init__(self, rounds):
        self.rounds = rounds
        self.current = 0
        self.user_score = 0
        self.comp_score = 0
        self.choices = ["rock", "paper", "scissors"]

    def comp_choice(self):
        return random.choice(self.choices)

    def winner(self, user, comp):
        if user == comp:
            return "Tie!"
        elif (user == "rock" and comp == "scissors") or \
             (user == "scissors" and comp == "paper") or \
             (user == "paper" and comp == "rock"):
            self.user_score += 1
            return "You win!"
        else:
            self.comp_score += 1
            return "Computer wins!"

    def check_winner(self):
        if self.user_score > self.rounds // 2:
            return "You win the game!"
        elif self.comp_score > self.rounds // 2:
            return "Computer wins the game!"
        return None

    def play(self):
        print(f"Best of {self.rounds} rounds.")

        while self.current < self.rounds:
            user = input("rock, paper, scissors? ").lower()
            if user not in self.choices:
                print("Invalid! Try again.")
                continue

            comp = self.comp_choice()
            print(f"Computer: {comp}")
            print(self.winner(user, comp))

            self.current += 1
            game_winner = self.check_winner()
            if game_winner:
                print(game_winner)
                break

        print(f"Final Score - You: {self.user_score} | Computer: {self.comp_score}")
        if self.user_score == self.comp_score:
            print("It's a tie!")

rounds = int(input("Enter rounds: "))
game = RPS(rounds)
game.play()
