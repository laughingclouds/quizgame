def join_str_path(base: str, *args: str) -> str:
    str_path = base
    for arg in args:
        str_path += '/' + arg
    return str_path

def main():
    SRC_DIR = './quiz-game'
    print(*[
        join_str_path(SRC_DIR, 'quiz-game.cpp'),
        join_str_path(SRC_DIR, 'utility', 'utility.cpp')
    ])

if __name__ == "__main__":
    main()