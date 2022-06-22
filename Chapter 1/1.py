def all_unique(string: str) -> bool:
    letter_dict = {}
    for letter in string:
        if letter in letter_dict:
            return False
        letter_dict[letter] = 1

    return True


def main():
    s = input('Input a string:')
    print(f'{s} has all unique characters: {all_unique(s)}')


if __name__ == '__main__':
    main()