def main() :
    string = convert(input())
    print(f"{string}")

def convert(string):
    string.replace(":)", "🙂")
    string.replace(":(", "😐")
    return string

main()
