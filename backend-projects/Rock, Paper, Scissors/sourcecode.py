import random

user_score = 0
bot_score = 0


def print_score(uscore, bscore):
    print("Bot Score: ", bscore)
    print("User Score: ", uscore)
    print("\n")


def understand_bot_play(temp_n):
    if temp_n == 0:
        return 'p'
    elif temp_n == 1:
        return 's'
    elif temp_n == 2:
        return 'r'


def random_number_generator():
    return random.randint(0, 2)


def what_bot_plays():
    return understand_bot_play(random_number_generator())


def logic(temp_bot_play, temp_user_play):
    if temp_bot_play == 'r' and temp_user_play == 's':
        print('Bot Wins')
        bot_score += 1
    elif temp_bot_play == 's' and temp_user_play == 'p':
        print('Bot Wins')
        bot_score += 1

    elif temp_bot_play == 'p' and temp_user_play == 'r':
        print('Bot Wins')
        bot_score += 1

    elif temp_bot_play == 's' and temp_user_play == 'r':
        print('User Wins')
        user_score += 1

    elif temp_bot_play == 'r' and temp_user_play == 'p':
        print('User Wins')
        user_score += 1

    elif temp_bot_play == 'p' and temp_user_play == 's':
        print('User Wins')
        user_score += 1

    else:
        print("Draw")
