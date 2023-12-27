def main() :
    string = convert(input())
    print(string)

def convert(string):
    string.replace(":)", "🙂")
    string.replace(":(", "😐")
    return string

main()
