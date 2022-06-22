def compress_string(s: str)->str:
    last_letter = " "
    letter_cnt = 0
    ret = ""
    for letter in s:
        if letter_cnt == 0:
            letter_cnt = 1
            last_letter = letter
        elif letter != last_letter:
            ret += last_letter
            ret += str(letter_cnt)
            last_letter = letter
            letter_cnt = 1
        else:
            letter_cnt += 1

    if letter_cnt > 1:
        ret += last_letter
        ret += str(letter_cnt)

    return ret

def main():
    s = input('Input string: ')
    print(f'Output: {compress_string(s)}')

if __name__ == '__main__':
    main()