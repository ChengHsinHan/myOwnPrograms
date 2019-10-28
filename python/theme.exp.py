# game 1 == far, game 2 == position, game 3 == height,
# game 4 ==shaking, game 5 == weighing
number_of_games = 5
number_of_teams = 10

# highest total score will be 100.0
highest_score_each_game = 100.0 / number_of_games

# store the final score of each team
score = [0.0] * number_of_teams

for game_index in range(1, number_of_games + 1):
    # store the score of each team in each game temporarily
    temp = []
    for team_index in range(1, number_of_teams + 1):
        while True:
            try:
                temp.append(float(input(f"the score of team {team_index} in game {game_index}: ")))
                break
            except ValueError:
                print("please enter a number")
    # act as a mark of who is the best team
    shift = highest_score_each_game / max(temp)
    for team_index in range(number_of_teams):
        # ensure the best team gets the highest score in that game, the others get less points
        score[team_index] += temp[team_index] * shift

# for formatting reason
print("\n")
for team_index in range(1, number_of_teams + 1):
    print(f"team {team_index} has final score of {score[team_index - 1]}\n")
