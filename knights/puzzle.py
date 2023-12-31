from logic import *

AKnight = Symbol("A is a Knight")
AKnave = Symbol("A is a Knave")

BKnight = Symbol("B is a Knight")
BKnave = Symbol("B is a Knave")

CKnight = Symbol("C is a Knight")
CKnave = Symbol("C is a Knave")

# Puzzle 0
# A says "I am both a knight and a knave."
knowledge0 = And(
    # A is a knight or a knave
    And(Or(AKnight, AKnave), And(AKnight, AKnave)),
    # if A is a knight, it is both a knight and a knave i.e. telling truth
    Implication(AKnight, And(AKnight, AKnave)),
    #if A is a knave, it is not both a knight and a knave i.e. lying
    Implication(AKnave, Not(And(AKnight, AKnave)))
)

# Puzzle 1
# A says "We are both knaves."
# B says nothing.
knowledge1 = And(
    And(Or(AKnight, AKnave), And(AKnight, AKnave)),
    And(Or(BKnight, BKnave), And(BKnight, BKnave)),
    Implication(AKnight, And(AKnight, BKnight)),
    Implication(BKnight, Not(And(AKnight, BKnight)))
    # TODO
)

# Puzzle 2
# A says "We are the same kind."
# B says "We are of different kinds."
knowledge2 = And(
    And(Or(AKnight, AKnave), And(AKnight, AKnave)),
    And(Or(BKnight, BKnave), And(BKnight, BKnave)),
    Implication(AKnight, Or(And(AKnight, BKnight), And(AKnave, BKnave))),
    Implication(AKnave, Not(Or(And(AKnave, BKnave), And(AKnave, BKnave)))),
    Implication(BKnight, Or(And(AKnave, BKnight), And(BKnave, AKnight))),
    Implication(BKnave, Not(Or(And(AKnave, BKnight), And(BKnave, AKnight))))
    # TODO
)

# Puzzle 3
# A says either "I am a knight." or "I am a knave.", but you don't know which.
# B says "A said 'I am a knave'."
# B says "C is a knave."
# C says "A is a knight."
knowledge3 = And(
    And(Or(AKnight, AKnave), And(AKnight, AKnave)),
    And(Or(BKnight, BKnave), And(BKnight, BKnave)),
    Implication(AKnight, Or(And(AKnight, BKnight), And(AKnave, BKnave))),
    Implication(AKnave, Not(Or(And(AKnave, BKnave), And(AKnave, BKnave)))),
    Implication(BKnight, Or(And(AKnave, BKnight), And(BKnave, AKnight))),
    Implication(BKnave, Not(Or(And(AKnave, BKnight), And(BKnave, AKnight))))
    # TODO
)


def main():
    symbols = [AKnight, AKnave, BKnight, BKnave, CKnight, CKnave]
    puzzles = [
        ("Puzzle 0", knowledge0),
        ("Puzzle 1", knowledge1),
        ("Puzzle 2", knowledge2),
        ("Puzzle 3", knowledge3)
    ]
    for puzzle, knowledge in puzzles:
        print(puzzle)
        if len(knowledge.conjuncts) == 0:
            print("    Not yet implemented.")
        else:
            for symbol in symbols:
                if model_check(knowledge, symbol):
                    print(f"    {symbol}")


if __name__ == "__main__":
    main()
