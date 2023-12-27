ans = input("Greeting: ").strip().lower()
if ans.startswith("h"):
    if ans.startswith("hello"):
        print("$0")
    else:
        print("$20")
else:
    print("$100")
