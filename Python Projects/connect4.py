# Written By Deepesh Nimma
import numpy as np
import random
import pygame
import sys
import math

blue = (0, 0, 255)
red = (255, 0, 0)
yellow = (0, 255, 0)
black = (0, 0, 0)

rows = 6
columns = 7

player = 0
ai = 1

empty = 0
player_piece = 1
ai_piece = 2

window_length = 4

def create_board():
    board = np.zeros((rows, columns))
    return board

def drop_piece(board, row, col, piece):
    board[row][col] = piece

def is_valid_location(board, col):
    return board[rows - 1][col] == 0

def get_next_open_row(board, col):
    for r in range(rows):
        if board[r][col] == 0:
            return r

def print_board(board):
    print(np.flip(board, 0))

def winning_move(board, piece):

    # Vertical
    for c in range(columns - 3):
        for r in range(rows):
            if board[r][c] == piece and board[r][c + 1] == piece and board[r][c + 2] == piece and board[r][c + 3] == piece:
                return True

    # Horizontal
    for c in range(columns - 3):
        for r in range(rows):
            if board[r][c] == piece and board[r + 1][c] == piece and board[r + 2][c] == piece and board[r + 3][c] == piece:
                return True

    # Positive Sloped
    for c in range(columns - 3):
        for r in range(rows):
            if board[r][c] == piece and board[r + 1][c + 1] == piece and board[r + 2][c + 2] == piece and board[r + 3][c + 3] == piece:
                return True

    # Negative Sloped
    for c in range(columns - 3):
        for r in range(rows):
            if board[r][c] == piece and board[r - 1][c + 1] == piece and board[r - 2][c + 2] == piece and board[r - 3][c + 3] == piece:
                return True

def evaluate_window(window, piece):
    score = 0
    opp_piece = player_piece

    if piece == player_piece:
        opp_piece = ai_piece

    if window.count(piece) == 4:
        score += 100

    elif window.count(piece) == 3 and window.count(empty) == 1:
        score += 5

    elif window.count(piece) == 2 and window.count(empty) == 2:
        score += 2


    if window.count(opp_piece) == 3 and window.count(empty) == 1:
        score -= 4

    return score

def score_position(board, piece):
    score = 0

    ## Score Centre Column
    center_array = [int(i) for i in list(board[:, columns // 2])]
    center_count = center_array.count(piece)
    score += center_count

    ## Score Horizontal
    for r in range(rows):
        row_array = [int(i) for i in list(board[r, :])]

        for c in range(columns - 3):
            window = row_array[c : c + window_length]
            score += evaluate_window(window, piece)

    ## Score Vertical
    for c in range(columns):
        col_array = [int(i) for i in list(board[:, c])]
        for r in range(rows - 3):
            window = col_array[r : r + window_length]
            score += evaluate_window(window, piece)

    # Score Positive Sloped Diagonal
    for r in range(rows - 3):
        for c in range(columns - 3):
            window = [board[r + i][c + i] for i in range(window_length)]
            score += evaluate_window(window, piece)

    for r in range(rows - 3):
        for c in range(columns - 3):
            window = [board[r + 3 - i][c + i] for i in range(window_length)]
            score += evaluate_window(window, piece)

    return score

def is_terminal_node(board):
    return winning_move(board, player_piece) or winning_move(board, ai_piece) or len(get_valid_locations(board)) == 0

def minimax(board, depth, alpha, beta, maximizingPlayer):
    valid_locations = get_valid_locations(board)
    is_terminal = is_terminal_node(board)
    if depth == 0 or is_terminal:
        if is_terminal:
            if winning_move(board, ai_piece):
                return(None, 100000000000000)
            elif winning_move(board, player_piece):
                return(None, -10000000000000)
            else: # Game is Over
                return(None, 0)
        else:
            return(None, score_position(board, ai_piece))

    if maximizingPlayer:
        value = -math.inf
        column = random.choice(valid_locations)

        for col in valid_locations:
            row = get_next_open_row(board, col)
            b_copy = board.copy()
            drop_piece(b_copy, row, col, ai_piece)
            new_score = minimax(b_copy, depth - 1, alpha, beta, False)[1]
            if new_score > value:
                value = new_score
                column = col

            alpha = max(alpha, value)

            if alpha >= beta:
                break

        return column, value

    else:
        value = math.inf
        column = random.choice(valid_locations)

        for col in valid_locations:
            row = get_next_open_row(board, col)
            b_copy = board.copy()
            drop_piece(b_copy, row, col, player_piece)
            new_score = minimax(b_copy, depth - 1, alpha, beta, True)[1]

            if new_score < value:
                value = new_score
                column = col

            beta = min(beta, value)

            if alpha >= beta:
                break

        return column, value

def get_valid_locations(board):
    valid_locations = []
    for col in range(columns):
        if is_valid_location(board, col):
            valid_locations.append(col)

    return valid_locations

def pick_best_move(board, piece):
    valid_locations = get_valid_locations(board)
    best_score = -10000
    best_col = random.choice(valid_locations)
    for col in valid_locations:
        row = get_next_open_row(board, col)
        temp_board = board.copy()

        drop_piece(temp_board, row, col, piece)
        if score > best_score:
            best_score = score_position
            best_col = col

    return best_col

def draw_board(board):
    for c in range(columns):
        for r in range(rows):
            pygame.draw.rect(screen, blue, (c * square_size, r * square_size + square_size, square_size, square_size))
            pygame.draw.circle(screen, black, (int(c * square_size + square_size / 2), int(r * square_size + square_size + square_size / 2)), radius)

    for c in range(columns):
        for r in range(rows):
            if board[r][c] == player_piece:
                pygame.draw.circle(screen, red, (int(c * square_size + square_size / 2), int(r * square_size + square_size + square_size / 2)), radius)
            elif board[r][c] == ai_piece:
                pygame.draw.circle(screen, yellow, (int(c * square_size + square_size / 2), int(r * square_size + square_size + square_size / 2)), radius)

    pygame.display.update()

board = create_board()
print_board(board)
game_over = False

pygame.init()

square_size = 100

width = columns * square_size
height = (rows + 1) * square_size

size = (width, height)

radius = int(square_size / 2 - 5)

screen = pygame.display.set_mode(size)
draw_board(board)
pygame.display.update()

myfont = pygame.font.SysFont("monospace", 75)

turn = random.randint(player, ai)

while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

        if event.type == pygame.MOUSEMOTION:
            pygame.draw.rect(screen, black, (0, 0, width, square_size))
            posx = event.pos[0]
            if turn == player:
                pygame.draw.circle(screen, red, (posx, int(square_size / 2)), radius)

        pygame.display.update()

        if event.type == pygame.MOUSEBUTTONDOWN:
            pygame.draw.rect(screen, black, (0, 0, width, square_size))

            if turn == player:
                posx = event.pos[0]
                col = int(math.floor(posx / square_size))

                if is_valid_location(board, col):
                    row = get_next_open_row(board, col)
                    drop_piece(board, row, col, player_piece)

                    if winning_move(board, player_piece):
                        label = myfont.render("PLAYER 1 WINS!", 1, red)
                        screen.blit(label, (40, 10))
                        game_over = True

                    turn += 1
                    turn = turn % 2

                    print_board(board)
                    draw_board(board)

    if turn == ai and not game_over:
        col, minimax_score = minimax(board, 5, -math.inf, math.inf, True)

        if is_valid_location(board, col):
            row = get_next_open_row(board, col)
            drop_piece(board, row, col, ai_piece)

            if winning_move(board, ai_piece):
                label = myfont.render("Player 2 Wins!", 1, yellow)
                screen.blit(label, (40, 10))
                game_over = True

            print_board(board)
            draw_board(board)

            turn += 1
            turn = turn % 2

    if game_over:
        pygame.time.wait(3000)
