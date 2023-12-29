"""
Tic Tac Toe Player
"""

import math

X = "X"
O = "O"
EMPTY = None

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    n = 0
    for row in board:
        for sqr in row:
            if board[row][sqr] == EMPTY: n += 1
    return O if n % 2 == 0 else X


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions = set()
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == EMPTY:
                actions.add((i, j))
    return actions


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board) or terminal(board):
        raise Exception("invalid action")
    board_copy = copy.deepcopy(board)
    board_copy[action[0]][action[1]] = player(board)
    return board_copy

def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    is_winner = False
    # check rows
    for row in board:
        r_set = set(row)
        if len(r_set) == 1 and r_set[0] != EMPTY:
            is_winner = True

    # check columns
    for col in len(board):
        c_set = set(board[i][col] for i in range(len(board)))
        if len(c_set) == 1 and c_set[0] != EMPTY:
            is_winner = True

    # check diagonals
    d1_set = set(board[i][i] for i in range(len(board)))
    d2_set = set(board[i][len(board)-i-1] for i in range(len(board)))
    if len(d1_set) == 1 and d1_set[0] != EMPTY:
        is_winner = True
    if len(d2_set) == 1 and d2_set[0] != EMPTY:
        is_winner = True

    return is_winner


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    # check if someone won game
    if winner(board) != None:
        return True
    for row in board:
        for sqr in row:
            if board[row][sqr] == EMPTY: return False
    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    # assume that only called on terminal board
    if winner(board) == X:
        return 1
    if winner(board) == O:
        return -1
    return 0

def max_value(state):
    if terminal(state):
        return utility(state)
    v = float("-inf")
    v_action = (-1, -1)
    for action in actions(state):
        # v = max(v, min_value(result(state, action)))
        curr = min_value(result(state, action))[0]
        if curr > v:
            v = curr
            v_action = action
    return (v, v_action)

def min_value(state):
    if terminal(state):
        return utility(state)
    v = float("inf")
    v_action = (-1, -1)
    for action in actions(state):
        # v = min(v, max_value(result(state, action)))
        curr = max_value(result(state, action))[0]
        if curr > v:
            v = curr
            v_action = action
    return (v, v_action)


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    player = player(board)
    if player == O:
        return min_value(board)[1]
    elif player == X:
        return max_value(board)[1]
    raise NotImplementedError
