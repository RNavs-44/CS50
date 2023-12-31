"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
  """
    Returns starting state of the board.
    """
  return [[EMPTY, EMPTY, EMPTY], [EMPTY, EMPTY, EMPTY], [EMPTY, EMPTY, EMPTY]]


def player(board):
  """
    Returns player who has the next turn on a board.
    """
  n = 0
  for i in range(len(board)):
    for j in range(len(board[i])):
      if board[i][j] == EMPTY:
        n += 1
  return O if n % 2 == 0 else X


def actions(board):
  """
    Returns set of all possible actions (i, j) available on the board.
    """
  possible_actions = set()
  for i in range(len(board)):
    for j in range(len(board[i])):
      if board[i][j] == EMPTY:
        possible_actions.add((i, j))
  possible_actions = list(possible_actions)
  possible_actions.sort(key=evaluate_action, reverse=True)
  return possible_actions

def evaluate_action(action):
  multiplier = [[3, 2, 3], [2, 4, 2], [3, 2, 3]]
  return multiplier[action[0]][action[1]]


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
  # check rows
  for row in board:
    r_set = set(row)
    if len(r_set) == 1 and EMPTY not in r_set:
      if X in r_set:
        return X
      else:
        return O

  # check columns
  for col in range(len(board)):
    c_set = set(board[i][col] for i in range(len(board)))
    if len(c_set) == 1 and EMPTY not in c_set:
      if X in c_set:
        return X
      else:
        return O
  # check diagonals
  d1_set = set(board[i][i] for i in range(len(board)))
  d2_set = set(board[i][len(board) - i - 1] for i in range(len(board)))
  if len(d1_set) == 1 and EMPTY not in d1_set:
    if X in d1_set:
      return X
    else:
      return O
  if len(d2_set) == 1 and EMPTY not in d2_set:
    if X in d2_set:
      return X
    else:
      return O

  return None


def terminal(board):
  """
    Returns True if game is over, False otherwise.
    """
  # check if someone won game
  if winner(board) != None:
    return True
  for i in range(len(board)):
    for j in range(len(board[i])):
      if board[i][j] == EMPTY:
        return False
  return True


def utility(board):
  """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
  # assume that only called on terminal board
  player_winner = winner(board)
  if player_winner == X:
    return 1
  elif player_winner == O:
    return -1
  return 0


# alpha is best value a parent min node guaranteed to get
# beta is best value a parent max node guaranteed to get

def max_value(state, alpha, beta):
  if terminal(state):
    return (utility(state), None)
  v = float("-inf")
  v_action = None
  for action in actions(state):
    # v = max(v, min_value(result(state, action)))
    curr = min_value(result(state, action), alpha, beta)
    if curr[0] > v:
      v = curr[0]
      v_action = action
    alpha = max(alpha, curr[0])
    if alpha >= beta:
      break
    if curr[0] == 1:
      break
  return (v, v_action)


def min_value(state, alpha, beta):
  if terminal(state):
    return (utility(state), None)
  v = float("inf")
  v_action = None
  for action in actions(state):
    # v = min(v, max_value(result(state, action)))
    curr = max_value(result(state, action), alpha, beta)
    if curr[0] < v:
      v = curr[0]
      v_action = action
    beta = min(beta, curr[0])
    if alpha >= beta:
      break
    if curr[0] == -1:
      break
  return (v, v_action)


def minimax(board):
  curr_player = player(board)
  if curr_player == X:
    return max_value(board, float("-inf"), float("inf"))[1]
  elif curr_player == O:
    return min_value(board, float("-inf"), float("inf"))[1]
