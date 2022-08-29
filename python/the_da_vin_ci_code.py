import time
from random import randint

class Player(object):
    def __init__(self, name):
        self.name = name
        self.fault_number = 0
        self.is_fault = False
        self.lose_rounds = 0

    def __eq__(self, other):
        return self.name == other.name

    def __str__(self):
        return self.name

    def __repr__(self):
        return self.name

    def fault(self):
        self.fault_number += 1
        self.is_fault = True

    def no_fault(self):
        self.is_fault = False

    def lose_one_round(self):
        self.lose_rounds += 1

    def new_round(self):
        self.fault_number = 0
        self.is_fault = False

    def clear(self):
        self.fault_number = 0
        self.is_fault = False
        self.lose_rounds = 0

class Game(object):
    def __init__(self):
        self.player_number = self.get_player_number()
        self.player_list = self.get_player_list()
        self.min, self.max = self.get_min_max()
        self.min_bkup = self.min
        self.max_bkup = self.max
        self.lose_round_number_to_lose = 3
        self.fault_number_to_lost_round = 3
        self.first_run = True

    def get_player_number(self):
        while True:
            player_number = input('How many players are there to play \'the Da Vin Ci Code\'? ')
            if not player_number.isnumeric():
                print('Please enter a number.')
            elif int(player_number) <= 1:
                print('Player number should be at least two.')
            else:
                return int(player_number)

    def get_player_list(self):
        player_list = []
        for index in range(1, self.player_number + 1):
            while True:
                player = Player(input(f'Please enter player name number {index}: '))
                if player in player_list:
                    print(f'{player} already exist. Please try another one.')
                else:
                    player_list.append(player)
                    break
        return player_list

    def get_user_reply(self, question):
        answer = input(question)
        while answer != 'y' and answer != 'n':
            answer = input(question)
        return answer == 'y'

    def get_min_max(self, min = 1, max = 100):
        if not self.get_user_reply(f'Do you want to change the range, default is {min}~{max} (y/n)? '):
            return (min, max)
        while True:
            min = input('Please enter the lower limit of the game: ')
            if not min.isnumeric() or min == '0':
                print('Please enter a positive number.')
                continue
            max = input('Please enter the upper limit of the game: ')
            if not max.isnumeric():
                print('Please enter a positive number.')
                continue
            min, max = int(min), int(max)
            if min >= max:
                print('Please make sure your lower limit is smaller than upper limit.')
                continue
            elif max < min + 20:
                if self.get_user_reply(f'The range is too small that is won\'t be fun. (suggested range: {self.player_number * 20}) Still want to continue (y/n)? '):
                    return (min, max)
            else:
                return (min, max)

    def wait(self, second):
        start = time.time()
        while True:
            end = time.time()
            if end - start >= second:
                return

    def intro(self):
        greetings = 'Hello, '
        for index, player in enumerate(self.player_list):
            if index != self.player_number - 1:
                greetings += f'{player}, '
            else:
                greetings += f'and {player}'
        print(greetings)
        self.wait(1)
        print('Weclome to play \'the Da Vin Ci Code\'! Here are the rules I need you to follow.')
        self.wait(1)
        print(f'1. Every round there is a secret number between {self.min} and {self.max} (exclusive). Every player takes term guess it.')
        print(f'Whoever has the right guess loses that round! Who lost {self.lose_round_number_to_lose} rounds loses the game.')
        self.wait(3)
        print('2. The range of limit would become smaller as everyone guesses.')
        self.wait(3)
        print('3. Whoever has the guess outside the range or enter an invalid input would be punished by a fault.')
        print(f'When being punished by {self.fault_number_to_lost_round} times, that person automatically loses that round.')
        self.wait(3)
        print('4. The order of the players would swap for equality purposes.')
        self.wait(3)
        print('So, let\'s start the game!\n')
        self.wait(5)

    def guess_one_time(self, answer, player):
        print(f'range now: {self.min} ~ {self.max}')
        player_guess = input(f'{player}\'s term: ')
        if not player_guess.isnumeric():
            return False

        if 3 <= self.max - self.min <= 15:
            for times in range(3):
                print('.')
                self.wait(1)

        if self.min < int(player_guess) < answer:
            print(f'{player} guesses {player_guess}...\n')
            self.min = int(player_guess)
        elif self.max > int(player_guess) > answer:
            print(f'{player} guesses {player_guess}...\n')
            self.max = int(player_guess)
        elif int(player_guess) == answer:
            return True
        else:
            return False

    def get_answer(self):
        return randint(self.min + 1, self.max - 1)

    def play_one_round(self):
        answer = self.get_answer()
        index = 0
        while index < len(self.player_list):
            while True:
                player = self.player_list[index]
                result = self.guess_one_time(answer, player)
                if isinstance(result, bool):
                    if not result:
                        player.fault()
                        print(f'{player} fault #{player.fault_number}!')
                        if player.fault_number == self.fault_number_to_lost_round:
                            return player
                    else:
                        player.no_fault()
                        return player
                else:
                    player.no_fault()
                    index += 1
                    break
            if index == len(self.player_list):
                index = 0

    def shuffle(self):
        for index in range(len(self.player_list) - 1):
            self.player_list[index], self.player_list[index + 1] = self.player_list[index + 1], self.player_list[index]

    def get_longest_length(self):
        max_length = len(self.player_list[0].name)
        for player in self.player_list:
            if len(player.name) > max_length:
                max_length = len(player.name)
        return max_length

    def print_everone_loses(self):
        longest_length = self.get_longest_length()
        print('==============================')
        for player in self.player_list:
            print(f'{player.name:<{longest_length}}: {player.lose_rounds}')
        print('==============================')

    def play_one_time(self):
        if self.first_run:
            self.intro()
            self.first_run = False

        if self.player_number <= 1:
            print('Fatal! Player number is less than one! The game can\'t go on like this...')
            exit(0)

        round = 1
        while True:
            print(f'Round #{round}!')
            lose_player = self.play_one_round()
            print(f'{lose_player} loses this round!')
            lose_player.lose_one_round()
            for player in self.player_list:
                player.new_round()
            self.min = self.min_bkup
            self.max = self.max_bkup
            if lose_player.lose_rounds == self.lose_round_number_to_lose:
                print(f'{lose_player} loses the game!')
                return self.get_user_reply('Do you want to play again (y/n)? ')
            round += 1
            self.print_everone_loses()
            self.shuffle()

    def add_players(self):
        if not self.get_user_reply('Any more players (y/n)? '):
            return

        while True:
            add_numbers = input('How many new players are there? ')
            if not add_numbers.isnumeric() or add_numbers == '0':
                print('Please enter a positive number.')
            else:
                add_numbers = int(add_numbers)
                break

        for new_index in range(1, add_numbers + 1):
            while True:
                new_player = Player(input(f'Please enter new player name #{new_index}: '))
                if new_player in self.player_list:
                    print(f'{new_player} already exist. Please try again.')
                else:
                    self.player_list.append(new_player)
                    break
        self.player_number = len(self.player_list)

    def remove_players(self):
        if not self.get_user_reply('Any player wants to quit (y/n)? '):
            return

        while True:
            remove_numbers = input('How many players want to quit? ')
            if not remove_numbers.isnumeric() or remove_numbers == '0':
                print('Please enter a positive number.')
            else:
                remove_numbers = int(remove_numbers)
                break

        if self.player_number - remove_numbers <= 1:
            print('Warning! The number of players would be less than one! The game would automatically shut down')
            if not self.get_user_reply('Still want to continue (y/n)? '):
                return

        for remove_index in range(1, remove_numbers + 1):
            while True:
                remove_player = Player(input(f'Please enter quit player name #{remove_index}: '))
                if remove_player not in self.player_list:
                    print(f'{remove_player} not found. Please try again.')
                else:
                    self.player_list.remove(remove_player)
                    break
        self.player_number = len(self.player_list)

    def play(self):
        while self.play_one_time():
            for player in self.player_list:
                player.clear()
            self.add_players()
            self.remove_players()
            self.min, self.max = self.get_min_max()
            self.min_bkup, self.max_bkup = self.min, self.max

        print('Thank you for playing!')

g = Game()
g.play()
