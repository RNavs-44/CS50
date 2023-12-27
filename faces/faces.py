def main() :
    string = convert(input())
    print(string)

def convert(s):
    s = s.replace(":)", "🙂")
    s = s.replace(":(", "😐")
    return s

main()
