def main() :
    string = convert(input())
    print(string)

def convert(s):
    s.replace("hi", ":::")
    s.replace(":(", "j")
    return s

main()
